## Why Use `enum` Instead of a String?

### What You Are Suggesting

```c
char signal[5];

if (condition) {
    strcpy(signal, "BUY");
} else {
    strcpy(signal, "HOLD");
}

if (strcmp(signal, "BUY") == 0) {
    // Do something
}
```

**What this does:** Stores the actual letters `'B'`, `'U'`, `'Y'` in memory.

---

### What `enum` Does

```c
enum Signal { HOLD = 0, BUY = 1, SELL = -1 };
enum Signal signal;

if (condition) {
    signal = BUY;
} else {
    signal = HOLD;
}

if (signal == BUY) {
    // Do something
}
```

**What this does:** Stores the **number** `1` in memory.

---

### The 4 Reasons Experts Choose `enum`

**1. Speed (Comparison)**

| Operation | `enum` | `char[]` string |
| :--- | :--- | :--- |
| Compare to check if it's BUY | `if (signal == BUY)` → Compares two numbers in 1 nanosecond | `if (strcmp(signal, "BUY") == 0)` → Walks through 3 letters (`B`, `U`, `Y`) to compare. |

**2. Safety (Compiler Catches Typos)**

| Mistake | `enum` | `char[]` string |
| :--- | :--- | :--- |
| You type `BYU` instead of `BUY` | Compiler says: *"Error: 'BYU' is not defined."* ✅ | Compiler says: *"Fine, here is your string 'BYU'."* Your program runs, but the logic is broken (you miss the BUY signal). ❌ |

**3. Memory (Size)**

| Storage | `enum` | `char[]` string |
| :--- | :--- | :--- |
| Memory used | Always 4 bytes (an integer). | 5 bytes (`'B'`, `'U'`, `'Y'`, `'\0'`) or more. |
| If you have 1000 signals, | 4000 bytes | 5000+ bytes (wasteful). |

**4. Logic Separation (The Most Important One)**

**The Core Rule:** The program's **logic** (the decision) should not depend on **words** (the display).

- `enum` is for **logic**: `if (signal == BUY)` means "execute the buy action."
- The string (`"BUY"`) is for **display**: `printf("Signal: %s", signalName)` means "print BUY to the screen."

Your `char signal[5]` approach mixes them together. You are storing the *display text* to represent the *decision state*. This is fragile and slow.

---
