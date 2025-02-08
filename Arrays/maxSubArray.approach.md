# Finding the Subarray with the Largest Sum using Kadane's Algorithm


## CODE :

```cpp

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int max_sum = nums[0]; // Initialize with first element
    int current_sum = nums[0];

    for (size_t i = 1; i < nums.size(); i++) {
        current_sum = max(nums[i], current_sum + nums[i]); // Start fresh or continue
        max_sum = max(max_sum, current_sum);
    }

    return max_sum;
}

```

## **Interview Scenario**

### **Interviewer:** How would you find the subarray with the largest sum in a given integer array?

### **You:**
"To solve this problem efficiently, I use **Kadane’s Algorithm**, which is an optimized approach that runs in **O(n) time complexity**.

### **The Idea:**
I keep track of two variables:
- `current_sum` → This stores the sum of the current subarray.
- `max_sum` → This keeps track of the maximum sum found so far.

### **How it Works:**
As I iterate through the array, I have two choices at each step:
1. Either **`extend the existing subarray` by adding the current element.**
2. Or **`start a new subarray with the current element` if adding it makes the sum worse.**

I update `max_sum` whenever `current_sum` exceeds it.

The key trick is that **if `current_sum` becomes negative, I discard it and start fresh**, because a negative sum will only make the next elements worse.

### **Example Dry Run:**
#### **Input:** `nums = [-2,1,-3,4,-1,2,1,-5,4]`

| Index | `nums[i]` | `current_sum` (max of `nums[i]` or `current_sum + nums[i]`) | `max_sum` (max of `max_sum` or `current_sum`) |
|--------|----------|--------------------------------------------------|----------------------------------|
| **0**  | **-2**  | -2 | -2  |
| **1**  | **1**  | max(1, -2 + 1) = 1  | max(-2, 1) = **1**  |
| **2**  | **-3**  | max(-3, 1 + -3) = -2  | max(1, -2) = **1**  |
| **3**  | **4**  | max(4, -2 + 4) = 4  | max(1, 4) = **4**  |
| **4**  | **-1**  | max(-1, 4 + -1) = 3  | max(4, 3) = **4**  |
| **5**  | **2**  | max(2, 3 + 2) = 5  | max(4, 5) = **5**  |
| **6**  | **1**  | max(1, 5 + 1) = 6  | max(5, 6) = **6**  |
| **7**  | **-5**  | max(-5, 6 + -5) = 1  | max(6, 1) = **6**  |
| **8**  | **4**  | max(4, 1 + 4) = 5  | max(6, 5) = **6**  |

**Final Output:** `6`, with the subarray `[4, -1, 2, 1]`.

This approach is very efficient because it **only requires one pass through the array and constant extra space**. It’s a great example of a **greedy algorithm combined with dynamic programming principles** to optimize the solution!

---

## **Handling an Array with All Negative Numbers**

### **Interviewer:** How does your approach handle an array with all negative numbers?

### **You:**
"That’s a great question! **Kadane’s Algorithm naturally handles arrays with all negative numbers without any extra conditions.**

### **Why Does It Work?**

1. **I initialize `max_sum` and `current_sum` with the first element (`nums[0]`)**, rather than `0`.

2. **I never reset `current_sum` to `0`**, **because in an all-negative array, that would incorrectly return `0` instead of the least negative number**.

3. **As I iterate, I keep updating `current_sum` using `max(nums[i], current_sum + nums[i])`**, **ensuring I `either extend the subarray` or `start fresh`.**

4. **Since `max_sum` is always updated with the largest value encountered, it correctly picks the "least negative" number.**

### **Example:**
#### **Input:** `nums = [-3, -5, -1, -7]`

| Index | `nums[i]` | `current_sum` | `max_sum` |
|--------|----------|--------------|------------|
| **0**  | **-3**  | -3 | -3  |
| **1**  | **-5**  | max(-5, -3 + -5) = -5 | max(-3, -5) = **-3**  |
| **2**  | **-1**  | max(-1, -5 + -1) = -1 | max(-3, -1) = **-1**  |
| **3**  | **-7**  | max(-7, -1 + -7) = -7 | max(-1, -7) = **-1**  |

**Final Output:** `-1` (the least negative number in the array).

So, even with all negative numbers, **Kadane’s Algorithm still works without modifications, returning the largest (least negative) value!**

---

## **Time and Space Complexity Analysis**

### **Time Complexity:**
- The algorithm **traverses the array once**, making it **O(n)**.
- Each element is processed in **constant time O(1)**.
- Therefore, the overall complexity is **O(n)**.

### **Space Complexity:**
- Since we use only a few extra variables (`current_sum`, `max_sum`), the space complexity is **O(1)** (constant space).
- No additional data structures are required.

**Final Complexity:**
- **Time Complexity: O(n)**
- **Space Complexity: O(1)**

---

### **Conclusion**
Kadane’s Algorithm is an **optimal** and **simple** way to find the maximum subarray sum. It efficiently handles:
- **Positive & negative numbers**
- **Mixed numbers**
- **All negative arrays** (without modifications!)

It’s a great example of using a **`greedy approach`** with **`dynamic programming principles`** to solve problems in linear time."

# Why is Kadane's Algorithm Considered Dynamic Programming?

Kadane's Algorithm is often considered a **dynamic programming (DP) approach** because it solves a complex problem by breaking it down into simpler overlapping subproblems and using optimal substructure.

## What is Dynamic Programming (DP)?
Dynamic Programming is a technique used to solve problems by breaking them into smaller subproblems, solving each subproblem once, and storing the results to avoid redundant computations. It is particularly useful when a problem has **overlapping subproblems** and **optimal substructure**.

- **Overlapping Subproblems**: The problem can be broken down into subproblems, which are solved repeatedly.
- **Optimal Substructure**: The solution to the problem can be constructed efficiently from the solutions to its subproblems.

## How Does Kadane’s Algorithm Use Dynamic Programming?
Kadane’s Algorithm maintains a running sum (`current_sum`) while iterating through the array and makes optimal decisions at each step based on past calculations. The **key DP aspect** here is that we are reusing the previously computed subarray sum instead of recomputing sums for every possible subarray from scratch.

1. **Subproblem Definition**:
   - Let `current_sum[i]` be the maximum subarray sum ending at index `i`.
   - The recurrence relation is:
     
     ```
     current_sum[i] = max(nums[i], current_sum[i-1] + nums[i])
     ```
     This means that we either extend the previous subarray or start a new one at index `i`.

2. **Optimal Substructure**:
   - The best solution for the entire array can be determined from the best solutions of smaller subarrays.
   - The global maximum (`max_sum`) is updated dynamically as we traverse the array.

3. **Overlapping Subproblems Avoided**:
   - Instead of recomputing subarray sums for every possible subarray (which would be inefficient), we maintain and update just two values (`current_sum` and `max_sum`).
   - This avoids unnecessary recomputation, similar to how DP stores computed results.

## Complexity Analysis
- **Time Complexity**: **O(n)**, since we traverse the array once.
- **Space Complexity**: **O(1)**, as only a few variables (`current_sum` and `max_sum`) are used without additional data structures.

## Conclusion
While Kadane’s Algorithm does not explicitly use memoization or a DP table, it follows **dynamic programming principles** because:
- It solves subproblems incrementally and builds up the final solution efficiently.
- It avoids recomputation by maintaining state variables (`current_sum` and `max_sum`).
- It optimally decides whether to extend a previous solution or start fresh at each step.

Thus, Kadane's Algorithm is an example of **an implicit DP approach combined with a greedy strategy** for optimal results in linear time.

