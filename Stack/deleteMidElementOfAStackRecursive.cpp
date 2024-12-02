#include <iostream>
#include <stack>
using namespace std;

// Helper function to recursively delete the middle element
void helper(stack<int>& st, int cnt, int n) {
    if (cnt == n / 2) {
        st.pop(); // Remove the middle element
        return;
    }

    int store = st.top();
    st.pop();

    // Recursive call
    helper(st, cnt + 1, n);

    // Push back the stored element
    st.push(store);
}

// Function to delete the middle element of a stack (Recursive approach)
void deleteMid(stack<int>& st, int n) {
    helper(st, 0, n);
}

int main() {
    stack<int> st;
    int n;

    // Take input for the stack size
    cout << "Enter the number of elements in the stack: ";
    cin >> n;

    // Take input for the stack elements
    cout << "Enter the elements (from bottom to top): ";
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        st.push(element);
    }

    // Print original stack
    cout << "Original stack (top to bottom): ";
    stack<int> temp = st;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    // Delete the middle element
    deleteMid(st, n);

    // Print modified stack
    cout << "Stack after deleting the middle element (top to bottom): ";
    temp = st;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    return 0;
}
