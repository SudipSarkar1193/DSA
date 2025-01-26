#include<bits/stdc++.h>
using namespace std ;
int largestRectangleArea(vector<int>& arr) {
    stack<int> st; // Stack to store indices of the array
    int n = arr.size(); // Size of the input array
    int maxArea = 0; // Variable to store the maximum area found

    // Iterate through each element in the array
    for (int i = 0; i < n; i++) {
        int e = arr[i]; // Current element

        // While the stack is not empty and the current element is less than or equal to
        // the element at the index stored at the top of the stack
        while (!st.empty() && arr[st.top()] >= e) {
            int top = st.top(); // Get the index at the top of the stack
            st.pop(); // Pop the top element from the stack

            // The next smaller element (NSE) for the popped element is the current element at index 'i'
            int nseIndex = i;

            // The previous smaller element (PSE) for the popped element is the element at the new top of the stack
            // If the stack is empty, it means there is no previous smaller element, so we use -1
            int pseIndex = st.empty() ? -1 : st.top();

            // Calculate the area of the rectangle with height arr[top] and width (nseIndex - pseIndex - 1)
            int currentArea = arr[top] * (nseIndex - pseIndex - 1);

            // Update maxArea if the currentArea is greater
            maxArea = max(maxArea, currentArea);
        }

        // Push the current index onto the stack
        st.push(i);
    }

    // After processing all elements, there might be some elements left in the stack
    // These elements do not have a next smaller element in the array
    while (!st.empty()) {
        int top = st.top(); // Get the index at the top of the stack
        st.pop(); // Pop the top element from the stack

        // The next smaller element (NSE) for the popped element is beyond the array, so we use 'n'
        int nseIndex = n;

        // The previous smaller element (PSE) for the popped element is the element at the new top of the stack
        // If the stack is empty, it means there is no previous smaller element, so we use -1
        int pseIndex = st.empty() ? -1 : st.top();

        // Calculate the area of the rectangle with height arr[top] and width (nseIndex - pseIndex - 1)
        int currentArea = arr[top] * (nseIndex - pseIndex - 1);

        // Update maxArea if the currentArea is greater
        maxArea = max(maxArea, currentArea);
    }

    // Return the maximum area found
    return maxArea;
}