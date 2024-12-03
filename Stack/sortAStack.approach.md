# Sorting a Stack Using Recursion

## **Objective**
The goal is to sort a stack such that the smallest element is at the top.

---

## **Approach and Thought Process**
This sorting logic works using **recursion** and a helper function `insertInSortedWay`. The recursive function `sortStack` achieves sorting by breaking the problem into smaller subproblems.

### **Recursive Insight for Sorting**
To sort a stack, you can reduce the problem by:
1. Removing the top element of the stack.
2. Recursively sorting the rest of the stack.
3. Using `insertInSortedWay` to insert the removed element back into the sorted stack.

---

### **Helper Function - `insertInSortedWay`**
The `insertInSortedWay` function ensures that an element is inserted into its correct position in a sorted stack.

---

### **Base Case**
- If the stack is empty, there's nothing to sort, so you return immediately.

---

### **Recursive Case**
1. Remove the top element.
2. Recursively sort the smaller stack using `sortStack`.
3. Insert the removed element back into the sorted stack using `insertInSortedWay`.

---

## **Execution Flow**
Consider a stack `st = [4, 1, 3, 2]` (from bottom to top).

### **Initial Call**
- Top of the stack is `2`.
- Remove `2` and recursively sort the rest of the stack: `[4, 1, 3]`.

### **Second Call**
- Top of the stack is `3`.
- Remove `3` and recursively sort the rest of the stack: `[4, 1]`.

### **Third Call**
- Top of the stack is `1`.
- Remove `1` and recursively sort the rest of the stack: `[4]`.

### **Fourth Call**
- Top of the stack is `4`.
- Remove `4` and recursively sort the rest of the stack: `[]` (base case).

---

### **Start Returning**
1. In the fourth call, the stack is empty. Push `4` back using `insertInSortedWay`.  
   Stack becomes `[4]`.

2. In the third call, insert `1` into `[4]`.  
   Stack becomes `[1, 4]`.

3. In the second call, insert `3` into `[1, 4]`.  
   Stack becomes `[1, 3, 4]`.

4. In the first call, insert `2` into `[1, 3, 4]`.  
   Stack becomes `[1, 2, 3, 4]`.

---

## **Why This Works?**
- The recursion ensures that at each step, the problem size decreases as the top element is removed and the smaller stack is sorted.
- The helper function `insertInSortedWay` ensures that each element is inserted in its correct position as the stack is rebuilt.

---

## **Correctness of the Code**

### **Base Case**
- When the stack is empty (`st.empty()`), no further operations are needed. This prevents infinite recursion.

### **Recursive Case**
- The recursive calls handle progressively smaller stacks.
- The removed elements are reinserted into their correct positions using the helper function.

---

## **Complexity Analysis**

### **Time Complexity**
- Sorting involves removing and reinserting each element, which takes **O(n)** for each element due to the recursive calls in `insertInSortedWay`.
- For `n` elements in the stack, the overall complexity is **O(n²)**.

### **Space Complexity**
- The recursion depth can go up to `n` for `sortStack`, and each `insertInSortedWay` call may use additional space.
- Hence, the space complexity is **O(n)** for the recursion stack.

---

## **Summary**
The `sortStack` function is correct and effectively sorts the stack using recursion and the helper function `insertInSortedWay`. The approach is elegant and demonstrates a clear understanding of recursive problem-solving with stacks.



### Function Breakdown
- **insertInSortedWay function**:
  - Places an element `x` into its correct position in the stack.
- **sortStack function**:
  - Recursively sorts the stack by utilizing `insertInSortedWay`.



# Time and Space Complexity Analysis

## Time Complexity

### Step 1: Recursive Calls in `sortStack`
- The `sortStack` function makes a recursive call for each element in the stack.
- Each call **removes one element** from the stack and works on the smaller stack.
    - **First call**: Stack has `n` elements, 1 is popped.
    - **Second call**: Stack has `n-1` elements, 1 is popped.
    - ...
    - **Last call**: Stack has 1 element, which is popped.
- This means there are **exactly `n` recursive calls**, one for each element.

---

### Step 2: Work Done in Each Call (`insertInSortedWay`)
- After the smaller stack is sorted, the `insertInSortedWay` function is used to place the popped element into its correct position.
- In the **worst case**, inserting an element into a sorted stack of size `k` requires:
    - **Popping all `k` elements** to find the correct position.
    - **Pushing those `k` elements back** after inserting the new element.
- Thus, the time complexity of `insertInSortedWay` is **O(k)** for a stack of size `k`.

---

### Step 3: Total Work Done
- For `n` recursive calls, the size of the stack during each call decreases as follows:
    - First call: Work for stack of size `1`.
    - Second call: Work for stack of size `2`.
    - ...
    - Last call: Work for stack of size `n`.
- Total work:
\[
1 + 2 + 3 + \dots + n = \frac{n(n+1)}{2}
\]
- This simplifies to **O(n²)** for large `n`.

---

## Space Complexity

### Step 1: Understanding the Recursion Stack
- The recursion stack grows with each recursive call.
- Every time `sortStack` is called, a new **stack frame** is added to hold:
    - Local variables (e.g., `num`).
    - The state of the function.
- The recursion continues until the stack is empty.

---

### Step 2: Maximum Depth of Recursion
- The recursion depth is equal to the number of elements in the stack, as `sortStack` calls itself until the stack becomes empty.
- For a stack with `n` elements:
    - **First call**: The stack has `n` elements.
    - **Second call**: The stack has `n-1` elements.
    - ...
    - **Last call**: The stack has 1 element.
- At its deepest point, the recursion stack will have **`n` frames**.

---

### Total Space Used
- The recursion stack uses **O(n)** space because it grows linearly with the number of elements in the stack.

---

## Final Complexity Summary

- **Time Complexity:** **O(n²)**  
    - Sorting involves `n` recursive calls, and each call takes up to `n` operations in the worst case.
- **Space Complexity:** **O(n)**  
    - The recursion stack depth is equal to the number of elements in the input stack.



## Conclusion

This approach efficiently sorts a stack using recursion, adhering to the constraints of not using additional data structures.
