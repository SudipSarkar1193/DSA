# Minimum Cost to Make Brackets Valid

## Problem Statement

Given a string `str` consisting of only `{` and `}` brackets, determine the **minimum cost** to make the string valid. A string is valid if:
- For every opening bracket `{`, there is a corresponding closing bracket `}`.
- The brackets are balanced and in the correct order.

You can perform the following operation at a cost of 1:
- Flip an opening bracket `{` to a closing bracket `}` or vice versa.

Return the **minimum cost** to make the string valid. If it's not possible to make the string valid, return `-1`.

---

## Approach

### Step 1: Early Impossibility Check
If the length of the string is odd, it is **impossible** to make the string valid because each `{` requires a matching `}`. Therefore, if `str.length() % 2 != 0`, return `-1`.

---

### Step 2: Removing Valid Parts
We iterate through the string and use a **stack** to remove all valid parts of the string:
- Push `{` into the stack.
- When encountering `}`:
  - If the stack is not empty, pop a `{` from the stack (a valid pair `{}` is found).
  - Otherwise, add `}` to the result string (an unmatched `}`).
- After processing, any remaining `{` in the stack are unmatched and added to the result string.

The number of unmatched `{` and `}` is stored in two counters, `open` and `close`, respectively.

---

### Step 3: Calculating the Cost
After identifying the unmatched parts:
- If the total number of unmatched brackets is odd, return `-1` (impossible to balance).
- Otherwise:
  - If both `open` and `close` are even:
    - Each pair of `{` and `}` takes one operation. The cost is `open/2 + close/2`.
  - If either `open` or `close` is odd:
    - Combine one unmatched `{` with one unmatched `}` (2 flips), then calculate the remaining as `open/2 + close/2`.

---

### Code Implementation

#### Function Definitions
```cpp
#include <bits/stdc++.h>
using namespace std;

// Helper function to remove valid parts
string removeValidPart(string str, int *open, int *close) {
    string ans = "";
    stack<char> st;

    for (char ch : str) {
        if (ch == '{') {
            st.push(ch);
        } else {
            if (!st.empty()) {
                st.pop(); // Valid pair
            } else {
                ans += ch; // Unmatched '}'
                (*close)++;
            }
        }
    }

    while (!st.empty()) {
        ans += st.top(); // Remaining unmatched '{'
        (*open)++;
        st.pop();
    }

    return ans;
}

// Function to calculate the minimum cost
int findMinimumCost(string str) {
    if (str.length() % 2 != 0) {
        return -1; // Impossible
    }

    int open = 0, close = 0;
    string invalidPart = removeValidPart(str, &open, &close);

    if (invalidPart.length() % 2 != 0) {
        return -1; // Impossible
    }

    // Cost calculation
    if (open % 2 == 0) {
        return open / 2 + close / 2;
    } else {
        return (open - 1) / 2 + (close - 1) / 2 + 2;
    }
}
```

## Walkthrough with Test Cases

### Test Case 1: Already Valid String
#### Input:
`str = "{{}}"`

#### Steps:
1. The string is already valid with no unmatched `{` or `}`.
2. **Open Count:** `0`, **Close Count:** `0`.
3. No operations are required.

#### Output:
`0`

---

### Test Case 2: Simple Flip
#### Input:
`str = "}{{}"`

#### Steps:
1. Initial string: `"}{{}"`.
2. Process the string using the `removeValidPart` function:
   - First character is `}`: it is unmatched, so **Close Count** becomes `1`.
   - Next two characters are `{`: they are added to the stack.
   - Last character is `}`: it forms a valid pair with one `{` from the stack.
3. Remaining unmatched brackets: **Open Count:** `1`, **Close Count:** `1`.
4. Calculate the cost:
   - Since both counts are even, the cost is `Open Count / 2 + Close Count / 2 = 1 / 2 + 1 / 2 = 1`.

#### Output:
`1`

---

### Test Case 3: Multiple Flips Required
#### Input:
`str = "{{{{}}"`

#### Steps:
1. Initial string: `"{{{{}}"`.
2. Process the string using the `removeValidPart` function:
   - First three characters are `{`: they are added to the stack.
   - Next two characters are `}`: they form valid pairs with two `{` from the stack.
   - Last character is `{`: it remains unmatched.
3. Remaining unmatched brackets: **Open Count:** `2`, **Close Count:** `0`.
4. Calculate the cost:
   - Both counts are even, so the cost is `Open Count / 2 + Close Count / 2 = 2 / 2 + 0 / 2 = 1`.

#### Output:
`1`

---

### Test Case 4: Impossible Case
#### Input:
`str = "{{{}}}"`

#### Steps:
1. The length of the string is `7`, which is odd.
2. A valid string requires an even length. Therefore, it is impossible to balance the string.

#### Output:
`-1`

---

### Test Case 5: Complex Case
#### Input:
`str = "}{{}}{}}{"`

#### Steps:
1. Initial string: `"}{{}}{}}{"`.
2. Process the string using the `removeValidPart` function:
   - First character is `}`: it is unmatched, so **Close Count:** `1`.
   - Next two characters are `{`: they are added to the stack.
   - Next two characters are `}`: they form valid pairs with two `{` from the stack.
   - Sixth character is `{`: it is added to the stack.
   - Seventh and eighth characters are `}`: one forms a valid pair with `{` from the stack, and one is unmatched. **Close Count:** `2`.
   - Last character is `{`: it is unmatched. **Open Count:** `1`.
3. Remaining unmatched brackets: **Open Count:** `1`, **Close Count:** `2`.
4. Calculate the cost:
   - Since one count is odd, adjust: `(Open Count - 1) / 2 + (Close Count - 1) / 2 + 2 = (1 - 1) / 2 + (2 - 1) / 2 + 2 = 0 + 0 + 2 = 2`.

#### Output:
`2`




## Optimized Approach

The above approach uses a stack to identify valid and invalid parts of the string, followed by a calculation to determine the minimum cost. However, we can optimize the space complexity by avoiding the use of an explicit stack and instead use counters to track unmatched `{` and `}` brackets during a single pass.

---

### Optimized Algorithm

1. **Initialization:**
   - Use two counters: `open` to count unmatched `{` and `close` to count unmatched `}`.

2. **Single Pass:**
   - Iterate through the string:
     - If the character is `{`, increment the `open` counter.
     - If the character is `}`:
       - If `open > 0`, decrement `open` (a valid `{}` pair is formed).
       - Otherwise, increment the `close` counter (unmatched `}`).

3. **Calculate Cost:**
   - If the total unmatched brackets (`open + close`) is odd, return `-1` (impossible to balance).
   - Otherwise:
     - Divide `open` and `close` by 2 (since each flip fixes one unmatched bracket).
     - If both are even, return `open / 2 + close / 2`.
     - If one is odd, add 2 flips for the mismatched pair and calculate the rest as `(open - 1) / 2 + (close - 1) / 2 + 2`.

---

### Optimized Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int findMinimumCostOptimized(string str) {
    if (str.length() % 2 != 0) {
        return -1; // Impossible to balance
    }

    int open = 0, close = 0;

    for (char ch : str) {
        if (ch == '{') {
            open++;
        } else { // ch == '}'
            if (open > 0) {
                open--; // Pair a valid {}
            } else {
                close++; // Unmatched }
            }
        }
    }

    // If total unmatched brackets is odd, it's impossible to balance
    if ((open + close) % 2 != 0) {
        return -1;
    }

    // Calculate cost
    return (open / 2) + (close / 2) + (open % 2) * 2;
}
```