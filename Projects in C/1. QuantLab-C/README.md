
---

# 📈 QuantLab-C

## 📖 Topic
**Learning C Concepts Through a Quant-Focused Sandbox**

QuantLab-C is a learning project built to practice core C programming skills. Quantitative finance (stock data, moving averages, and trading logic) serves as the engaging theme—but the real goal is to master file I/O, pointers, dynamic memory, structs, enums, modular design, and build management.

---

## 🎯 Function of This Project
This project uses a simple stock trading simulation as the vehicle to apply C fundamentals. It reads historical CSV price data, calculates basic moving averages, generates BUY/SELL/HOLD signals based on crossover logic, simulates a portfolio with $10,000 starting cash, and adds a stop-loss mechanism. Every feature was chosen to reinforce a specific C concept, not to build a production-grade quant system.

---

## 🧩 Features (By Phase)

### Phase 1 — Data Loading
- Reads CSV files using `fopen`, `fgets`
- Parses text with `strtok`
- Dynamically stores unknown rows using `malloc` and `realloc`
- Groups data with a custom `Stocks` struct

### Phase 2 — Indicators
- Calculates SMA5 and SMA20 using nested loops
- Computes daily returns with arithmetic logic
- Practices loop control and array manipulation

### Phase 3 — Signals
- Generates BUY/SELL/HOLD decisions using `enum`
- Applies crossover logic (Golden Cross / Death Cross)
- Handles missing data cases for the first 19 days

### Phase 4 — Portfolio
- Tracks cash, holdings, and total wealth
- Executes simulated trades at closing price
- Applies pointers to modify values inside functions

### Phase 5 — Stop-Loss
- Implements a 10% stop-loss rule
- Overrides signals to SELL when loss threshold is met
- Practices conditional logic and edge-case handling

### Phase 6 — Code Engineering
- Splits logic into separate `.c` and `.h` files
- Uses header guards (`#ifndef ... #endif`)
- Compiles multiple files together with `gcc`
- Demonstrates modular program organization

---

## 📁 Project Structure

```
QuantLab-C/
├── main.c              # Entry point, main loop, orchestration
├── indicator.c         # SMA and daily return calculations
├── indicator.h         # Indicator prototypes
├── portfolio.c         # Trade execution, stop-loss, wealth
├── portfolio.h         # Portfolio prototypes
├── utils.c             # CSV parsing, printing, helpers
├── utils.h             # Utility prototypes
├── stocks.h            # Stocks struct definition
├── data.csv            # Input stock data
└── output/
    └── main.exe        # Compiled executable
```

---

## 🧠 What I Learned (C Fundamentals)

| Concept | Applied Through |
| :--- | :--- |
| **File I/O** | Reading and parsing CSV data |
| **Dynamic Memory** | Using `malloc`, `realloc`, and `free` to handle unknown data sizes |
| **Pointers** | Passing addresses to modify `cash`, `holdings`, and `signal` inside functions |
| **Structs** | Grouping stock OHLCV data into a single type |
| **Enums** | Replacing magic numbers with readable `BUY`/`SELL`/`HOLD` constants |
| **Modular Design** | Organizing code into separated modules with clear responsibilities |
| **Header Guards** | Preventing duplicate includes with `#ifndef`/`#define`/`#endif` |
| **Pointer Arithmetic** | Accessing array elements with both `arr[i]` and `*(arr + i)` |
| **Build Process** | Compiling multiple files with `gcc` and managing output folders |

---

**Status:** ✅ Complete — C fundamentals practiced through a quant-themed project

*Last updated: August 2026*