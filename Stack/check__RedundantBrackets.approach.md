# Problem: Check for Redundant Brackets

### Problem Description

Given a string `s` that represents a mathematical expression, determine whether it contains **redundant brackets**. A redundant bracket is a pair of brackets `()` that do not contribute to the expression's result or grouping.

For example:
- `(a + b)` is **not redundant** because the brackets group the addition operation.
- `((a + b))` contains **redundant brackets** because the outer brackets are unnecessary.
- `(a)` contains **redundant brackets** because a single variable does not require grouping.

The task is to return `true` if there are any redundant brackets and `false` otherwise.

---

### Approach

To solve this problem, we use a **stack data structure**. The main idea is to process the expression character by character, tracking brackets and arithmetic operators. 

#### Algorithm

1. **Initialization**: Create an empty stack `st` to keep track of characters.
2. **Iterate Through the String**: For each character in the string:
   - **Opening Bracket or Operator**:
     - If the character is an opening bracket `(` or an arithmetic operator (`+`, `-`, `*`, `/`, `%`), push it onto the stack.
   - **Closing Bracket**:
     - When a closing bracket `)` is encountered, check the contents inside the brackets:
       1. Assume the brackets are **redundant** initially by setting a flag `isRedundant = true`.
       2. Pop characters from the stack until an opening bracket `(` is found.
       3. If an arithmetic operator is encountered during this process, set `isRedundant = false` because it means the brackets have a valid purpose.
       4. If the brackets are redundant (`isRedundant == true`), return `true`.
     - Finally, pop the opening bracket `(` from the stack.
3. **Final Check**: If the entire string is processed without finding redundant brackets, return `false`.

---

### Code

```cpp
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isArithmeticOperator(char ch) {
    // Check if the character is one of the arithmetic operators
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%');
}

bool findRedundantBrackets(string &s) {
    stack<char> st;

    for(char ch : s){
        if(ch == '(' || isArithmeticOperator(ch)){
            st.push(ch);
        } else if(ch == ')') {
            bool isRedundant = true;
            
            // Check the contents inside the brackets
            while (!st.empty() && st.top() != '(') {
                if(isArithmeticOperator(st.top())) {
                    isRedundant = false;
                }
                st.pop();
            }

            // Pop the opening bracket
            if (!st.empty()) st.pop();

            if(isRedundant) return true;
        }
    }
    return false;
}
```

# Walkthrough of Test Cases

Let's walk through some test cases to better understand how the solution works and why it is effective.

---

## Test Case 1: `s = "(a + b)"`

### Input:
`"(a + b)"`

### Execution:

1. **Initialization**: The stack is empty at the start: `st = []`.
2. **Iterate through the string**:
   - `ch = '('`: Push to the stack.  
     Stack: `['(']`
   - `ch = 'a'`: Ignore since it's neither an operator nor a bracket.
   - `ch = '+'`: Push to the stack.  
     Stack: `['(', '+']`
   - `ch = 'b'`: Ignore since it's neither an operator nor a bracket.
   - `ch = ')'`: Check for redundancy:
     - Pop `+`: Marks the presence of an operator, so `isRedundant = false`.
     - Pop `(`: End of the group.
   - Stack is now empty.
3. **Final Result**: No redundant brackets were found.  
   **Output**: `false`

---

## Test Case 2: `s = "((a + b))"`

### Input:
`"((a + b))"`

### Execution:

1. **Initialization**: The stack is empty: `st = []`.
2. **Iterate through the string**:
   - `ch = '('`: Push to the stack.  
     Stack: `['(']`
   - `ch = '('`: Push to the stack.  
     Stack: `['(', '(']`
   - `ch = 'a'`: Ignore since it's neither an operator nor a bracket.
   - `ch = '+'`: Push to the stack.  
     Stack: `['(', '(', '+']`
   - `ch = 'b'`: Ignore since it's neither an operator nor a bracket.
   - `ch = ')'`: Check for redundancy:
     - Pop `+`: Marks the presence of an operator, so `isRedundant = false`.
     - Pop `(`: End of the group.
   - `ch = ')'`: Check for redundancy:
     - Pop `(`: This group has no operator, so `isRedundant = true`.
3. **Final Result**: Redundant brackets were found.  
   **Output**: `true`

---

## Test Case 3: `s = "(a)"`

### Input:
`"(a)"`

### Execution:

1. **Initialization**: The stack is empty: `st = []`.
2. **Iterate through the string**:
   - `ch = '('`: Push to the stack.  
     Stack: `['(']`
   - `ch = 'a'`: Ignore since it's neither an operator nor a bracket.
   - `ch = ')'`: Check for redundancy:
     - Pop `(`: This group has no operator, so `isRedundant = true`.
3. **Final Result**: Redundant brackets were found.  
   **Output**: `true`

---

## Test Case 4: `s = "a + (b * c)"`

### Input:
`"a + (b * c)"`

### Execution:

1. **Initialization**: The stack is empty: `st = []`.
2. **Iterate through the string**:
   - `ch = 'a'`: Ignore since it's neither an operator nor a bracket.
   - `ch = '+'`: Push to the stack.  
     Stack: `['+']`
   - `ch = '('`: Push to the stack.  
     Stack: `['+', '(']`
   - `ch = 'b'`: Ignore since it's neither an operator nor a bracket.
   - `ch = '*'`: Push to the stack.  
     Stack: `['+', '(', '*']`
   - `ch = 'c'`: Ignore since it's neither an operator nor a bracket.
   - `ch = ')'`: Check for redundancy:
     - Pop `*`: Marks the presence of an operator, so `isRedundant = false`.
     - Pop `(`: End of the group.
3. **Final Result**: No redundant brackets were found.  
   **Output**: `false`

---

## Test Case 5: `s = "a + ((b))"`

### Input:
`"a + ((b))"`

### Execution:

1. **Initialization**: The stack is empty: `st = []`.
2. **Iterate through the string**:
   - `ch = 'a'`: Ignore since it's neither an operator nor a bracket.
   - `ch = '+'`: Push to the stack.  
     Stack: `['+']`
   - `ch = '('`: Push to the stack.  
     Stack: `['+', '(']`
   - `ch = '('`: Push to the stack.  
     Stack: `['+', '(', '(']`
   - `ch = 'b'`: Ignore since it's neither an operator nor a bracket.
   - `ch = ')'`: Check for redundancy:
     - Pop `(`: This group has no operator, so `isRedundant = true`.
   - `ch = ')'`: Check for redundancy:
     - Pop `(`: This group has no operator, so `isRedundant = true`.
3. **Final Result**: Redundant brackets were found.  
   **Output**: `true`

---

### Summary of Results

| Test Case | Expression          | Output  |
|-----------|---------------------|---------|
| 1         | `(a + b)`           | `false` |
| 2         | `((a + b))`         | `true`  |
| 3         | `(a)`               | `true`  |
| 4         | `a + (b * c)`       | `false` |
| 5         | `a + ((b))`         | `true`  |

By analyzing these test cases, it is clear how the stack-based solution works efficiently to identify redundant brackets.



