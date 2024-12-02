# String Reversal using Stack

## Overview
This C++ program demonstrates how to reverse a string using a stack data structure. It utilizes the stack's Last-In-First-Out (LIFO) property to reverse the characters in a string efficiently.

## Approach

### 1. **Using a Stack**:
   - A stack is used to temporarily store the characters of the input string.
   - Each character of the string is pushed onto the stack. Since stacks operate on a LIFO basis, the characters are then popped in reverse order.
   
### 2. **Reversing the String**:
   - The program takes the input string as a vector of characters (`vector<char>`).
   - It first pushes each character onto the stack.
   - Then, the characters are popped from the stack one by one and placed back into the original vector, effectively reversing the string.

### 3. **Algorithm**:
   - **Step 1**: Iterate over the input string and push each character onto the stack.
   - **Step 2**: Pop each character from the stack and overwrite the original string in reverse order.

## Code Execution

1. **Input**: A string is given as a vector of characters (e.g., `{'h', 'e', 'l', 'l', 'o'}`).
2. **Output**: The program prints both the original and reversed strings.

### Example:
Given an input string: `"hello"`, the program will output:

Original string: hello Reversed string: olleh



## Time Complexity
- **Push operation**: O(n), where `n` is the number of characters in the string.
- **Pop operation**: O(n), where `n` is the number of characters in the string.

Thus, the total time complexity of reversing the string is O(n).

## Space Complexity
- The space complexity is O(n), as the stack temporarily holds all the characters of the string during the reversal process.

## Conclusion
This solution efficiently reverses a string using a stack, leveraging the LIFO behavior of the stack to reverse the order of characters with an O(n) time complexity.
