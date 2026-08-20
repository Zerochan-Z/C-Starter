# 📚 C Learning Roadmap — Completed Progress

---

## 📁 Projects Completed

| Project | Description | Concepts Covered | Status |
| :--- | :--- | :--- | :--- |
| **QuantLab-C** | Stock trading simulator with CSV data loading, SMA indicators, BUY/SELL/HOLD signals, portfolio tracking, and stop-loss protection | **File I/O (`fopen`/`fgets`/`fclose`)**, **Dynamic Memory (`malloc`/`realloc`/`free`)**, **Pointers & Pointer Arithmetic**, **Structs & Enums**, **Modular Design (`.h`/`.c` files)**, **Header Guards**, **SMA Indicators**, **Portfolio Simulation**, **Stop-Loss Logic** | ✅ |
| **Task Tracker (C)** | CLI task management system with add, view, edit, delete, mark complete, auto-status updates, and file persistence | **Dynamic Memory (`malloc`/`realloc`/`free`)**, **File I/O (`fopen`/`fprintf`/`fgets`/`fclose`)**, **Structs & Enums**, **Pointers & Pointer Arithmetic**, **Bubble Sort** (two-tier), **String Manipulation** (`strcmp`, `strcpy`, `strtok`), **Date Handling** (`time.h`), **Input Validation**, **Menu System** | ✅ |

---

## 🧪 Practice Progress

| Topic | Description | Status |
| :--- | :--- | :--- |
| **File I/O** | Reading and parsing CSV data with `fopen`, `fgets`, `strtok`; saving/loading tasks with `fprintf`/`fgets` | ✅ |
| **Dynamic Memory** | Using `malloc`, `realloc`, and `free` to handle unknown data sizes and grow arrays dynamically | ✅ |
| **Pointers** | Passing addresses to modify `cash`, `holdings`, `signal`, `buy_price` inside functions; array of pointers for sorting | ✅ |
| **Pointer Arithmetic** | Accessing array elements with both `arr[i]` and `*(arr + i)` | ✅ |
| **Structs** | Grouping stock OHLCV data into a single `Stocks` type; `Task` struct with ID, title, description, due_date, status, priority | ✅ |
| **Enums** | Replacing magic numbers with readable `BUY`/`SELL`/`HOLD` constants; `Status` and `Priority` enums for task management | ✅ |
| **Modular Design** | Organizing code into separated modules (`main.c`, `indicator.c`, `portfolio.c`, `utils.c`) with clear responsibilities | ✅ |
| **Header Guards** | Preventing duplicate includes with `#ifndef`/`#define`/`#endif` | ✅ |
| **Sorting Algorithms** | Bubble sort with two-tier comparison (due date → priority) for task management | ✅ |
| **String Manipulation** | `strcmp`, `strcpy`, `strlen`, `strtok`, `fgets` newline removal | ✅ |
| **Date Handling** | `time.h` for current date; `sscanf`/`sprintf` for date formatting (`YYYY-MM-DD`) | ✅ |
| **Input Validation** | Menu validation, confirm delete prompts, duplicate checks | ✅ |
| **Technical Indicators** | Calculating 5-day and 20-day Simple Moving Averages (SMA5, SMA20) | ✅ |
| **Trading Signals** | Generating BUY (Golden Cross) and SELL (Death Cross) signals based on SMA crossover | ✅ |
| **Portfolio Simulation** | Tracking cash, holdings, total wealth, and profit/loss with $10,000 starting capital | ✅ |
| **Risk Management** | Implementing 10% stop-loss protection that overrides trading signals | ✅ |
| **Recursion** | Functions calling themselves (factorial, sum of array, reverse string, binary search) | ✅ |
| **Linked Lists** | Singly linked list with insert, delete, reverse, find middle, detect cycle, merge two sorted lists | ✅ |
| **Stacks** | Array-based and linked-list implementations (`push`, `pop`, `peek`, `isEmpty`) | ✅ |
| **Queues** | Circular array-based and linked-list implementations (`enqueue`, `dequeue`, `peek`, `isEmpty`) | ✅ |

---

## 📌 Next C Topics

| Topic | Description | Status |
| :--- | :--- | :--- |
| **Function Pointers** | Storing and calling functions through pointers; callback mechanisms | ⏳ |
| **Bitwise Operations** | Manipulating individual bits using `&`, `|`, `^`, `<<`, `>>` | ⏳ |
| **Command-line Arguments** | Using `argc` and `argv` to pass arguments to `main()` | ⏳ |
| **Preprocessor Directives** | Macros, conditional compilation (`#ifdef`, `#ifndef`), `#pragma` | ⏳ |
| **Multi-file Projects** | Advanced `.h`/`.c` organization, static libraries, Makefiles | ⏳ |
| **Union** | Shared memory space for different data types | ⏳ |
| **Typedef** | Creating aliases for complex types (practiced, but can deepen) | ✅ |

---

> *Last updated: 21 August 2026*
