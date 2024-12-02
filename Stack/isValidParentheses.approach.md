# Valid Parentheses - Explanation and Analysis

## Problem Overview
The goal is to determine whether a given string of brackets (`()`, `{}`, `[]`) is valid. A string is considered valid if:
1. Every opening bracket has a corresponding closing bracket of the same type.
2. Brackets are closed in the correct order.

---

## Approach

### Stack Data Structure
- Use a stack to track unmatched opening brackets.
- Push an opening bracket onto the stack when encountered.
- For a closing bracket:
  - If the stack is empty, the string is invalid (extra closing bracket).
  - Check if the top of the stack matches the current closing bracket. If not, the string is invalid.
  - Pop the stack once a matching pair is found.

### Final Check
- After processing the entire string, if the stack is empty, the input is valid. Otherwise, it’s invalid (unmatched opening brackets remain).

---

## Pseudocode
1. Traverse the string character by character:
   - If it’s an opening bracket, push it onto the stack.
   - If it’s a closing bracket:
     - Return `false` if the stack is empty or the top of the stack doesn’t match.
     - Otherwise, pop the stack.
2. At the end, return `true` if the stack is empty; otherwise, return `false`.

---

## Optimized Approach

### Key Improvements

- **Length Check**: The string length is checked initially. If it's odd, it can never be valid, as every opening bracket must have a matching closing bracket.
```
    if(s.length() % 2) return false; // Early exit for odd-length strings
```

- **Simplified Stack Operations**: The stack is used only to store unmatched opening brackets. For closing brackets, the stack is directly checked for matching.


---

## Complexity Analysis

### Time Complexity: **O(n)**
- **Reason**:
  - Each character in the string is processed exactly once in the loop.
  - Stack operations (`push` and `pop`) take **O(1)** each.
  - For a string of length `n`, the total time complexity is **O(n)**.

### Space Complexity: **O(n)**
- **Reason**:
  - In the worst case, all characters in the string are opening brackets and lenght of the string is even (e.g., `"(((((("`), requiring all of them to be pushed onto the stack.
  - This results in **O(n)** space for the stack, where `n` is the length of the input string.

---

## Example Run

### Input:
`"{[()]}"`

### Execution:
1. Push `{`, `[`, `(` onto the stack.
2. Match `)` with `(`, pop.
3. Match `]` with `[`, pop.
4. Match `}` with `{`, pop.
5. Stack is empty at the end.

### Output:
`Valid`

---

### Input:
`"{[(])}"`

### Execution:
1. Push `{`, `[`, `(` onto the stack.
2. Match `)` with `(`, pop.
3. Attempt to match `]` with `[`, fails as they are mismatched.

### Output:
`Invalid`

---

## Conclusion
This approach ensures the validation of a string of brackets in linear time while maintaining optimal space usage, leveraging the LIFO nature of stacks.
