# Asteroid Collision Problem

## Problem Statement
We are given an array `asteroids` of integers representing asteroids in a row.

- Each asteroid's absolute value represents its size, and the sign represents its direction:
  - Positive: moving to the right.
  - Negative: moving to the left.
- Asteroids move at the same speed. 
- If two asteroids meet:
  - The smaller one explodes.
  - If both are the same size, both explode.
  - Asteroids moving in the same direction never meet.

The goal is to find the state of the asteroids after all possible collisions.

### Link 
(LeetCode link)[https://leetcode.com/problems/asteroid-collision/]



## Intuition
The problem involves resolving the collisions of asteroids while maintaining their order of movement. A **stack** is a natural choice to model this process because it allows us to efficiently handle situations where:
- An asteroid is destroyed.
- An asteroid causes multiple previous asteroids to explode.

By iterating through the `asteroids` array:
- Positive asteroids are added to the stack since they can only collide with a future negative asteroid.
- Negative asteroids are checked against the stack (which stores positive asteroids) to resolve collisions.

---

## Approach
1. **Initialization:**
   - Use a stack to simulate the process of collisions.
2. **Processing Each Asteroid:**
   - If the asteroid is positive, push it onto the stack (it moves to the right and won't collide with anything currently in the stack).
   - If the asteroid is negative, check for collisions with the top of the stack:
     - While the stack is not empty, and the top of the stack is a positive asteroid:
       - If the absolute value of the current asteroid is larger, the top of the stack explodes.
       - If the absolute values are equal, both explode, and the negative asteroid is ignored.
       - If the absolute value of the current asteroid is smaller, the negative asteroid is ignored.
   - If no collision occurs or the stack becomes empty, push the negative asteroid onto the stack.
3. **Finalize Result:**
   - The remaining asteroids in the stack represent the final state.
   - Reverse the stack to get the result in order.

---

## Complexity Analysis
### Time Complexity:
- **O(n):** Each asteroid is processed at most once. Pushing and popping from the stack are \(O(1)\) operations.

### Space Complexity:
- **O(n):** The stack can store up to \(n\) asteroids in the worst case (no collisions).

---

## Code
```cpp
#include <vector>
#include <stack>
using namespace std;

vector<int> asteroidCollision(vector<int>& arr) {
    stack<int> st;

    for (int e : arr) {
        if (e > 0) {
            // Positive asteroids are always pushed to the stack
            st.push(e);
        } else {
            // Process collisions for negative asteroids
            while (!st.empty() && st.top() > 0 && abs(e) > st.top()) {
                st.pop(); // Positive asteroid explodes
            }

            if (st.empty() || st.top() < 0) {
                // No more collisions, or top is a negative asteroid
                st.push(e);
            } else if (st.top() == abs(e)) {
                // Both asteroids have the same size and explode
                st.pop();
            }
        }
    }

    // Collect remaining asteroids from the stack
    vector<int> ans(st.size());
    for (int i = st.size() - 1; i >= 0; --i) {
        ans[i] = st.top();
        st.pop();
    }

    return ans;
}
```