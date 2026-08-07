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


No Code: ON

---

## The New Feature: Stop-Loss

You already have a working trading strategy. Now you will add **risk management**.

---

### Step 1 — Big Idea 🧠

**What is the one idea this topic is trying to teach?**

**The Big Idea:** "A strategy tells you when to enter. Risk management tells you when to exit to survive."

Your current program only sells when SMA5 crosses below SMA20 (the "death cross"). But what if the price drops 20% before that happens? Your strategy would hold the stock all the way down, losing massive money.

A **stop-loss** is a rule that says: *"If the price drops X% below my buy price, sell immediately to limit losses."*

This is the difference between a strategy that works in theory and one that works in reality.

---

### Step 2 — Mental Models 💡

**How do experts think about this?**

1. **The "Emergency Exit" Model:** Think of a stop-loss like a fire exit. You don't plan to use it, but if there's a fire (price crashes), you're glad it's there. It saves you from catastrophic loss.

2. **The "Insurance" Model:** A stop-loss is insurance. You pay a small cost (selling at a loss) to protect against a huge disaster (holding all the way to zero).

3. **The "Sleep Well" Model:** With a stop-loss, you don't have to watch the market every second. You know that even in the worst case, your maximum loss is limited.

---

### Step 3 — Common Mistakes ⚠️

**What do beginners usually mess up?**

1. **Setting the stop-loss too tight (e.g., 2%).** Normal price fluctuations will trigger the stop-loss, and you'll sell on a temporary dip, missing the big move up.

2. **Setting the stop-loss too wide (e.g., 50%).** The stop-loss never triggers, and you take a huge loss when the market crashes.

3. **Forgetting to track the buy price.** You need to remember the price you bought at so you can calculate the current loss percentage.

4. **Selling on stop-loss even if the signal says BUY.** The stop-loss should override the signal. Loss protection is more important than sticking to the strategy.

---

### Step 4 — Deep Questions ❓

**Answer these before writing code:**

1. What percentage loss should trigger the stop-loss? (Common values: 5%, 8%, 10%)

2. How do you know the buy price of your current holdings? (Hint: When you BUY, you need to store the price somewhere.)

3. If the stop-loss triggers, what should happen to the `holdings` and `cash`?

4. Should the stop-loss apply during a SELL signal, or only during HOLD days?

5. What should you do if the stop-loss triggers but the death cross hasn't happened yet?

---

### Step 5 — The Logic (In Plain English)

**Current logic (without stop-loss):**

```
For each day:
    If signal == BUY → buy
    Else if signal == SELL → sell
    Else → do nothing
```

**New logic (with stop-loss):**

```
For each day:
    If signal == BUY → buy (store the buy price)
    Else if signal == SELL → sell
    Else if stop-loss triggered → sell (emergency exit)
    Else → do nothing
```

---

### Step 6 — What You Need to Add

| What | Where |
| :--- | :--- |
| A variable to store the buy price | In `main()` or `portfolio.c` |
| A variable for the stop-loss percentage | In `main()` (e.g., `STOP_LOSS_PERCENT = 0.05` for 5%) |
| A function that checks the stop-loss | In `portfolio.c` |
| A call to that function in the main loop | In `main.c` |

---

### Your Task (Design First)

**Write a plain English design for the stop-loss feature. Answer these questions:**

1. What variable will you use to store the buy price? Where will you set it?

2. What condition will trigger the stop-loss? (Hint: `(buy_price - current_price) / buy_price >= stop_loss_percent`)

3. If the stop-loss triggers, what signal should you send to `execute_trade`?

4. After a stop-loss triggers, what should happen to the `holdings` and `cash`?

5. What should happen to the `buy_price` variable after a stop-loss?

6. Should you use a fixed stop-loss (e.g., 5% for all trades) or a dynamic one? (For now, use a fixed value.)

---