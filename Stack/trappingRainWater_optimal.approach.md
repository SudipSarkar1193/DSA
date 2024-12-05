# Trapping Rainwater Problem

[leetcode link](https://leetcode.com/problems/trapping-rain-water/)

## Problem Statement

Given an array `arr` where each element represents the height of a bar, calculate how much rainwater can be trapped between the bars after a rainfall.

---

## Intuition

- To trap water at a given position, the amount of water that can be held depends on the **minimum** of the maximum heights of bars to the left and right of the current bar, minus the height of the current bar itself.
- If the height of the bar at the current position is greater than or equal to the heights of bars on either side, no water can be trapped above it.

### Key Observations

1. For each bar `i`, the amount of water trapped is determined by:

   \[
   \text{water_trapped} = \max(0, \min(\text{left_max}, \text{right_max}) - \text{arr}[i])
   \]

2. We can use two pointers (`l` and `r`) to traverse the array and maintain the maximum height encountered so far from the left (`leftMax`) and the right (`rightMax`).

---

## Approach

### Two-Pointer Technique

1. **Initialize Pointers**:

   - `l` pointing to the leftmost bar.
   - `r` pointing to the rightmost bar.

2. **Maintain Two Variables**:

   - `leftMax` to store the maximum height seen so far from the left.
   - `rightMax` to store the maximum height seen so far from the right.

3. **Iterate with Conditions**:

   - Move the pointer (`l` or `r`) that points to the smaller bar, because water trapped is limited by the smaller bar.
   - Calculate the water trapped based on the current `leftMax` or `rightMax` and update the `sum`.

4. **Repeat Until the Pointers Meet**:
   - Continue adjusting the pointers and updating `leftMax`, `rightMax`, and `sum`.

---

## Code Explanation

### Functions

- **`trap`**: Core logic for calculating trapped rainwater using the two-pointer technique.
  - Inputs: `vector<int> &arr` — the array of bar heights.
  - Returns: The total amount of trapped water.

### Steps in Code

1. **Initialization**:
   - `l` (left pointer), `r` (right pointer), `leftMax`, `rightMax`, and `sum` are initialized.
2. **Two-Pointer Logic**:

   - Move `l` or `r` based on the comparison of `arr[l]` and `arr[r]`.
   - Update `leftMax` or `rightMax` dynamically as you traverse the array.
   - If the current bar (`arr[l]` or `arr[r]`) is smaller than its respective maximum, calculate the water that can be trapped above it and add it to `sum`.

3. **Output**:
   - Return the total water trapped (`sum`).

---

## Code

```cpp
#include<bits/stdc++.h>
using namespace std;

int trap(vector<int> &arr) {
    int l = 0,                 // Left pointer
        r = arr.size() - 1,    // Right pointer
        leftMax = 0,           // Maximum height from the left
        rightMax = 0,          // Maximum height from the right
        sum = 0;               // Total trapped water

    // Loop until the two pointers meet
    while (r >= l) {
        if (arr[l] < arr[r]) { // Left bar is smaller
            if (arr[l] < leftMax) {
                sum += leftMax - arr[l]; // Calculate trapped water
            } else {
                leftMax = arr[l];       // Update leftMax
            }
            l++; // Move left pointer
        } else { // Right bar is smaller
            if (arr[r] < rightMax) {
                sum += rightMax - arr[r]; // Calculate trapped water
            } else {
                rightMax = arr[r];       // Update rightMax
            }
            r--; // Move right pointer
        }
    }

    return sum; // Return the total trapped water
}

int main() {
    vector<int> v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Total Trapped Water: " << trap(v) << endl;
}
```

# Complexity Analysis for Trapping Rainwater Problem

The **Trapping Rainwater Problem** calculates the amount of water that can be trapped between bars of varying heights. Using the two-pointer approach, the solution is optimized for both **time complexity** and **space complexity**. Below is a detailed breakdown of the complexities involved.

---

## **Time Complexity**

### Step-by-Step Breakdown

1. **Initialization**:

   - Initializing pointers (`l` and `r`) and variables (`leftMax`, `rightMax`, and `sum`) takes **O(1)** time.

2. **While Loop Execution**:

   - The `while` loop runs as long as `l <= r`. Since `l` and `r` move inward one step at a time, each iteration reduces the range by one, leading to at most **n** iterations (where `n` is the size of the array).
   - Each iteration involves simple comparisons, updates to `leftMax` or `rightMax`, and, occasionally, addition to `sum`, all of which are **O(1)** operations.

3. **Overall Time Complexity**:
   - Since the loop executes once for each element in the array and the operations within the loop are constant time, the overall time complexity is:
     \[
     \text{Time Complexity} = O(n)
     \]

### Key Observations

- The two-pointer technique avoids nested loops and redundant calculations, ensuring a linear traversal.
- This approach is significantly faster than a brute-force solution, which has a **O(n^2)** time complexity due to double looping.

---

## **Space Complexity**

### Step-by-Step Breakdown

1. **Variables**:

   - The algorithm uses a fixed number of variables (`l`, `r`, `leftMax`, `rightMax`, and `sum`), which occupy constant space, i.e., **O(1)**.

2. **Input Array**:

   - The input array `arr` is not modified, and no additional data structures (e.g., stacks or arrays) are used to store intermediate results.

3. **Overall Space Complexity**:
   - Since no extra memory is allocated beyond a few variables, the space complexity is:
     \[
     \text{Space Complexity} = O(1)
     \]

---

## Comparison with Other Approaches

### **1. Brute-Force Approach**

#### Description:

- For every bar, calculate the maximum height to its left and right and determine the trapped water.

#### Complexities:

- **Time Complexity**: **O(n^2)** (nested loops for left and right maximum calculations).
- **Space Complexity**: **O(1)** (only a few variables).

---

### **2. Dynamic Programming Approach**

#### Description:

- Pre-compute `leftMax` and `rightMax` for all elements and use them to calculate the trapped water.

#### Complexities:

- **Time Complexity**: **O(n)** (two passes to precompute and one pass to calculate the result).
- **Space Complexity**: **O(n)** (two arrays to store `leftMax` and `rightMax`).

---

### **3. Two-Pointer Approach (Optimal)**

#### Description:

- Use two pointers (`l` and `r`) and two variables (`leftMax` and `rightMax`) to dynamically track the maximum heights.

#### Complexities:

- **Time Complexity**: **O(n)** (single traversal).
- **Space Complexity**: **O(1)** (constant space for variables).

---

## Why is the Two-Pointer Approach Optimal?

1. **Time Efficiency**:

   - By avoiding redundant calculations and pre-computations, the two-pointer approach achieves linear time complexity.

2. **Space Efficiency**:

   - Unlike the dynamic programming approach, which requires additional space for `leftMax` and `rightMax` arrays, this approach uses constant space.

3. **Simplicity**:
   - The algorithm is straightforward and leverages real-time updates to maintain the maximum heights, reducing memory overhead and improving readability.

---

## Summary Table

| **Approach**          | **Time Complexity** | **Space Complexity** | **Remarks**                          |
| --------------------- | ------------------- | -------------------- | ------------------------------------ |
| Brute Force           | O(n²)               | O(1)                 | Inefficient for large inputs.        |
| Dynamic Programming   | O(n)                | O(n)                 | Time-efficient but memory-intensive. |
| Two-Pointer (Optimal) | O(n)                | O(1)                 | Best combination of time and space.  |

---

## Edge Cases and Their Complexity Impact

1. **Empty Array**:

   - **Input**: `[]`
   - **Time Complexity**: **O(1)** (loop never executes).
   - **Space Complexity**: **O(1)** (only variables are initialized).

2. **Flat Surface**:

   - **Input**: `[0, 0, 0, 0]` or `[3, 3, 3, 3]`
   - **Time Complexity**: **O(n)** (linear traversal with no additions to `sum`).
   - **Space Complexity**: **O(1)** (no extra space used).

3. **Single Bar or Two Bars**:
   - **Input**: `[3]` or `[3, 4]`
   - **Time Complexity**: **O(1)** (loop executes minimally).
   - **Space Complexity**: **O(1)**.

---

## Conclusion

- The **Two-Pointer Approach** is the most efficient solution for the **Trapping Rainwater Problem** in terms of both **time complexity** and **space complexity**.
- By leveraging dynamic updates and constant space, it is suitable for real-world scenarios with large datasets.

---
