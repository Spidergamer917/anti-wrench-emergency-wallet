#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>

void SetColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void PrintBanner() {
    SetColor(12);
    std::cout << R"(
    ╔══════════════════════════════════════════════════════════╗
    ║  █████╗ ███╗   ██╗████████╗██╗    ██╗██████╗ ███████╗███╗   ██╗ ██████╗██╗  ██╗ ║
    ║ ██╔══██╗████╗  ██║╚══██╔══╝██║    ██║██╔══██╗██╔════╝████╗  ██║██╔════╝██║  ██║ ║
    ║ ███████║██╔██╗ ██║   ██║   ██║ █╗ ██║██████╔╝█████╗  ██╔██╗ ██║██║     ███████║ ║
    ║ ██╔══██║██║╚██╗██║   ██║   ██║███╗██║██╔══██╗██╔══╝  ██║╚██╗██║██║     ██╔══██║ ║
    ║ ██║  ██║██║ ╚████║   ██║   ╚███╔███╔╝██║  ██║███████╗██║ ╚████║╚██████╗██║  ██║ ║
    ║ ╚═╝  ╚═╝╚═╝  ╚═══╝   ╚═╝    ╚══╝╚══╝ ╚═╝  ╚═╝╚══════╝╚═╝  ╚═══╝ ╚═════╝╚═╝  ╚═╝ ║
    ║                       EMERGENCY WALLET SYSTEM v1.0                        ║
    ╚══════════════════════════════════════════════════════════╝
    )" << std::endl;
    SetColor(7);
    std::cout << "               Protect yourself from wrench attacks\n";
    std::cout << "               =====================================\n\n";
}

class EmergencyWallet {
private:
    std::string real_seed;
    std::vector<std::pair<std::string, double>> decoys;
    std::string panic_password;
    std::string emergency_address;
    bool panic_mode = false;

    bool check_password(const std::string& input) {
        // In real version, would check against stored hash
        // For demo, simulate
        return input == "secret123";
    }

public:
    void setup() {
        std::cout << "\n=== SETUP WIZARD ===\n";
        std::cout << "This will configure your emergency wallet.\n\n";

        // Real wallet setup
        std::cout << "Enter your real wallet seed phrase (or leave empty to generate new): ";
        std::getline(std::cin, real_seed);
        if (real_seed.empty()) {
            real_seed = "abandon abandon abandon ..."; // dummy
            std::cout << "Generated new seed (back this up!)\n";
        }

        // Decoy wallets
        int num_decoys;
        std::cout << "\nHow many decoy wallets do you want? (1-5): ";
        std::cin >> num_decoys;
        std::cin.ignore();
        for (int i = 0; i < num_decoys; i++) {
            std::string name;
            double balance;
            std::cout << "Decoy " << i+1 << " name (e.g., 'Spending wallet'): ";
            std::getline(std::cin, name);
            std::cout << "Decoy " << i+1 << " balance (in BTC): ";
            std::cin >> balance;
            std::cin.ignore();
            decoys.push_back({name, balance});
        }

        // Panic password
        std::cout << "\nSet panic password (wrong password will trigger decoy mode): ";
        std::getline(std::cin, panic_password);

        // Emergency transfer
        std::cout << "\nEmergency transfer address (leave empty to disable): ";
        std::getline(std::cin, emergency_address);

        std::cout << "\n[✓] Setup complete!\n";
    }

    void run() {
        std::cout << "\n=== WALLET ACCESS ===\n";
        std::cout << "Enter password: ";
        std::string input;
        std::getline(std::cin, input);

        if (input == panic_password) {
            panic_mode = true;
            std::cout << "\n⚠️  PANIC MODE ACTIVATED\n";
            std::cout << "Showing decoy wallets...\n";
            for (const auto& d : decoys) {
                std::cout << "  " << d.first << ": " << d.second << " BTC\n";
            }
            if (!emergency_address.empty()) {
                std::cout << "\nEmergency transfer initiated to " << emergency_address << "\n";
            }
        } else if (check_password(input)) {
            std::cout << "\nAccess granted. Real wallet balance: 24.5 BTC\n";
            // In real app, would show real balances
        } else {
            std::cout << "Incorrect password.\n";
        }
    }
};

int main() {
    PrintBanner();

    EmergencyWallet wallet;
    char choice;
    std::cout << "1. First-time setup\n";
    std::cout << "2. Run wallet\n";
    std::cout << "Choice: ";
    std::cin >> choice;
    std::cin.ignore();

    if (choice == '1') {
        wallet.setup();
    } else {
        wallet.run();
    }

    std::cout << "\nPress Enter to exit...";
    std::cin.get();
    return 0;
}