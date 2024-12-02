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

// Function to reverse the stack
void reverseStack(stack<int>& st) {
    if (st.empty()) {
        return;
    }

    // Store the top element and pop it
    int num = st.top();
    st.pop();

    // Recursively reverse the rest of the stack
    reverseStack(st);

    // Push the stored element at the bottom of the stack
    pushAtBottom(st, num);
}

int main() {
    stack<int> st;
    int n;

    // Taking user input for the stack size
    cout << "Enter the number of elements in the stack: ";
    cin >> n;

    // Taking user input for the stack elements
    cout << "Enter the elements of the stack:" << endl;
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        st.push(element);
    }

    // Reverse the stack
    reverseStack(st);

    // Printing the reversed stack
    cout << "Reversed stack: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
