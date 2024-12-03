# Minimum Add to Make Parentheses Valid

This repository contains the solution to the problem of determining the minimum number of parentheses insertions required to make a parentheses string valid.

## Problem Statement

A parentheses string is valid if and only if:
1. It is the empty string.
2. It can be written as AB (A concatenated with B), where A and B are valid strings.
3. It can be written as `(A)`, where A is a valid string.

You are given a parentheses string `s`. In one move, you can insert a parenthesis at any position of the string.

### Example Inputs and Outputs

**Example 1:**
input: s = `"())"` 
`Output: 1`

**Example 2:**
Input: s = `"((("` 
`Output: 3`


## Constraints

- `1 <= s.length <= 1000`
- `s[i]` is either `'('` or `')'`.

---

## Approach

The problem requires determining how many insertions are needed to balance the string. To solve this, we use two counters:
1. **`open`**: Tracks the number of unmatched opening parentheses `'('`.
2. **`close`**: Tracks the number of unmatched closing parentheses `')'`.

### Steps:
1. Traverse through the string:
   - If the character is `'('`, increment the `open` counter.
   - If the character is `')'`:
     - Check if there's a pending unmatched opening parenthesis (`open > 0`):
       - If true, decrement the `open` counter (match it with the closing parenthesis).
       - Otherwise, increment the `close` counter (indicating a new unmatched closing parenthesis).
2. At the end of the traversal:
   - The `open` counter will contain unmatched opening parentheses.
   - The `close` counter will contain unmatched closing parentheses.
3. The result is the sum of `open` and `close`.

### Time Complexity
- **Time Complexity**: \(O(n)\), where \(n\) is the length of the string. We perform a single traversal of the string.
- **Space Complexity**: \(O(1)\), as we only use two counters for the solution.

---

## Solution Code

Below is the solution code:

```cpp
#include <string>
using namespace std;

/**
 * Function to compute the minimum number of moves to make a parentheses string valid.
 * @param str - The input parentheses string.
 * @return The minimum number of moves required.
 */
int minAddToMakeValid(string str) {
    // `open` counts unmatched opening parentheses '('
    // `close` counts unmatched closing parentheses ')'
    int open = 0, close = 0;

    // Traverse each character in the string
    for (char ch : str) {
        if (ch == '(') {
            // Increment `open` when encountering an opening parenthesis
            open++;
        } else if (ch == ')') {
            if (open > 0) {
                // Match the closing parenthesis with an unmatched opening parenthesis
                open--;
            } else {
                // Increment `close` when there's no unmatched opening parenthesis
                close++;
            }
        }
    }

    // The total number of moves is the sum of unmatched opening and closing parentheses
    return open + close;
}
```