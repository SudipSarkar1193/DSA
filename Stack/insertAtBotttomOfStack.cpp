#include <bits/stdc++.h>
using namespace std;

// Helper function to push the element to the bottom of the stack
void helper(stack<int>& st, int x) {
    // Base case: If the stack is empty, push the element
    if (st.empty()) {
        st.push(x);
        return;
    }

    // Store the top element and pop it
    int store = st.top();
    st.pop();

    // Recursively call the helper function
    helper(st, x);

    // Push the stored element back to the stack
    st.push(store);
}

// Function to push an element at the bottom of the stack
stack<int> pushAtBottom(stack<int>& st, int x) {
    helper(st, x);
    return st;
}

int main() {
    stack<int> st;

    // Pushing elements into the stack
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    int x = 5;

    // Push the element at the bottom of the stack
    stack<int> result = pushAtBottom(st, x);

    // Printing the modified stack
    cout << "Modified stack: ";
    while (!result.empty()) {
        cout << result.top() << " ";
        result.pop();
    }
    cout << endl;

    return 0;
}
