# Next Greater Element Solution

## Intuition
The problem requires finding the next greater element for each element in an array or list. The **next greater element** for an element `x` is the first element to the right of `x` in the array that is greater than `x`. If no such element exists, the answer is `-1`.

To solve this efficiently, we can use a **monotonic stack**, which helps to maintain order and quickly identify the next greater element.

---

## Approach

### Key Observations
1. Traversing from **right to left** in the array simplifies finding the next greater element since the stack will hold elements in a decreasing order.
2. By using a `map`, we can store the next greater element for every number in `nums2` for constant-time lookups later when processing `nums1`.

---

## Algorithm

1. **Initialization:**
   - Use an empty stack to keep track of candidates for the next greater element.
   - Use a dictionary (or map) to store the next greater element for each number in `nums2`.

2. **Process `nums2` in Reverse Order:**
   - Iterate through `nums2` from the last element to the first.
   - For each element, pop elements from the stack that are smaller or equal to the current element (they cannot be the next greater element for this or any earlier element).
   - If the stack is not empty, the top element of the stack is the next greater element for the current number. Otherwise, the next greater element is `-1`.
   - Push the current element onto the stack.

3. **Find Results for `nums1`:**
   - For each element in `nums1`, use the dictionary to retrieve the precomputed next greater element.

4. **Output Results:**
   - Return the list of next greater elements for `nums1`.

---

## Complexity Analysis
- **Time Complexity:**
  - Processing `nums2` takes \(O(n)\), where \(n\) is the length of `nums2`, as each element is pushed and popped from the stack at most once.
  - Querying the map for `nums1` takes \(O(m)\), where \(m\) is the length of `nums1`.
  - Total: \(O(n + m)\).

- **Space Complexity:**
  - The stack and the map both require \(O(n)\) space.

---

## Implementation

### Python Code
```python
def nextGreaterElement(nums1, nums2):
    # Map to store the next greater element for each number in nums2
    next_greater = {}
    stack = []

    # Process nums2 from right to left
    for num in reversed(nums2):
        # Remove elements from the stack that are smaller or equal to the current num
        while stack and stack[-1] <= num:
            stack.pop()
        
        # If stack is not empty, the top element is the next greater; otherwise, it's -1
        next_greater[num] = stack[-1] if stack else -1
        
        # Push the current number onto the stack
        stack.append(num)

    # Build the result for nums1 based on the map
    return [next_greater[num] for num in nums1]
```

## Complexity Analysis

### Time Complexity
- Processing `nums2`: \(O(n)\), where \(n\) is the length of `nums2`. Each element is pushed and popped from the stack at most once.
- Building the result for `nums1`: \(O(m)\), where \(m\) is the length of `nums1`. Each lookup in the map is \(O(1)\).
- **Total Complexity:** \(O(n + m)\).

### Space Complexity
- The stack can hold at most \(n\) elements, requiring \(O(n)\) space.
- The dictionary (map) storing the next greater elements also requires \(O(n)\) space.
- **Total Space Complexity:** \(O(n)\).

---

## Conclusion
The solution leverages a **monotonic stack** and a dictionary to efficiently compute the next greater element for each element in \(nums1\). This approach ensures:
- **Optimal performance:** Each element is processed at most twice (push and pop operations on the stack).
- **Simplicity and clarity:** The algorithm handles edge cases like no greater element, duplicate values, and decreasing sequences seamlessly.
- **Scalability:** It works efficiently even for large input sizes due to its \(O(n + m)\) time complexity.

This makes it a robust and practical solution for finding the next greater element in linear time.
