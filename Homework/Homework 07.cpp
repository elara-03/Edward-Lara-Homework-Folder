#include <iostream>
#include <bitset>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <string>
#include <stdexcept>

class MotorStatus {
private:
    uint8_t motorState;              // Each bit represents the status of a motor (on/off)
    uint8_t overheatingMotors = 0;   // Motors that are overheating
    int turnCount;

    // Function to randomly initialize motors (on/off) and overheat one motor
    void initialize() {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        do {
            motorState = static_cast<uint8_t>(std::rand() % 256);
        } while (motorState == 0); // Ensure at least one motor is ON
        turnCount = 0;
        updateOverheating();
        displayStatus();
    }

    // Incrementally overheat motors with each turn, ensuring the motor is ON and not already overheating
    void updateOverheating() {
        if ((motorState & static_cast<uint8_t>(~overheatingMotors)) == 0) {
            // All ON motors are already overheating (or no motors ON).
            // No change to overheatingMotors.
            turnCount++; // Still counts as a "turn event"
            return;
        } else {
            int newMotor = 0;
            do {
                newMotor = std::rand() % 8; // Pick a random bit index 0..7
            } while (((static_cast<uint8_t>(1u << newMotor) & motorState) == 0)  // must be ON
                  || ((static_cast<uint8_t>(1u << newMotor) & overheatingMotors) != 0)); // not already overheating

            overheatingMotors |= static_cast<uint8_t>(1u << newMotor);
            turnCount++;
        }
    }

    void displayStatus() {
        std::cout << "Motor State (ON/OFF): " << std::bitset<8>(motorState) << std::endl;
        std::cout << "Overheating Motors: " << std::bitset<8>(overheatingMotors) << std::endl;
        std::cout << "Turn Count: " << turnCount << std::endl;
    }

public:
    MotorStatus() { initialize(); }
    void showStatus() { displayStatus(); }

    // =====================================
    // =====YOU MAY EDIT THIS FUNCTION======
    // =====================================
    bool turnOff(uint8_t guess) {
        // 1) Turn OFF only motors that are BOTH overheating AND guessed.
        // 2) If guess tries to turn off a motor that is NOT overheating leave state unchanged.
        // 3) Correct guess means guess matches overheatingMotors EXACTLY (same 1-bits).
        // 4) If incorrect guess: call updateOverheating() to add one more overheating motor.
        // 5) Return true ONLY if correct guess.

        uint8_t affected = static_cast<uint8_t>(overheatingMotors & guess);

        if (affected == 0) {
            std::cout << "Incorrect guess! No overheating motors matched.\n";
            updateOverheating(); // add one more overheating motor
            return false;
        }

        motorState        &= static_cast<uint8_t>(~affected);
        overheatingMotors &= static_cast<uint8_t>(~affected);

        if (overheatingMotors == 0) {
            std::cout << "Correct! All overheating motors are now off.\n";
            return true;
        } else {
            std::cout << "Partial correct! Some overheating motors are still on.\n";
            updateOverheating(); // add one new overheating motor
            return false;
        }
    }
};

int checkInput(const std::string& s, uint8_t &guess) {
    unsigned long value = 0;

    // Parse binary
    if (s.size() == 8 && s.find_first_not_of("01") == std::string::npos) {
        for (char c : s) value = (value << 1) | (c - '0');
        guess = static_cast<uint8_t>(value);
        return 0;
    }
    // Parse hex (0x..)
    else if (s.size() >= 3 && (s.rfind("0x", 0) == 0 || s.rfind("0X", 0) == 0)) {
        try {
            value = std::stoul(s, nullptr, 16);
            if (value > 255) throw std::out_of_range("value > 255");
            guess = static_cast<uint8_t>(value);
            return 0;
        } catch (...) {
            std::cout << "invalid hex value\n";
            return -1;
        }
    }

    std::cout << "Invalid input. Use 8-bit binary (e.g., 00101000) or hex (e.g., 0x28).\n";
    return -1;
}

// Main
int main() {
    MotorStatus motorStatus;
    uint8_t guess = 0;
    std::string s;

    std::cout << "Motor Meltdown\n";
    std::cout << "Enter your guess as:\n";
    std::cout << " - 8-bit binary (e.g., 00101000)\n";
    std::cout << " - hex (e.g., 0x28)\n";
    std::cout << "Type 'q' to quit.\n\n";

    while (true) {
        motorStatus.showStatus(); // status display
        std::cout << "Your guess:\n";
        std::cin >> s;

        if (!std::cin) break;
        if (s == "q" || s == "Q") break;
        if (checkInput(s, guess) == -1) continue;
        if (motorStatus.turnOff(guess)) break;
    }

    std::cout << "Game over.\n";
    return 0;
}
