#include <iostream>
#include <stack>
using namespace std;

// Function to delete the middle element of a stack
void deleteMid(stack<int>& st, int n) {
    int* arr = new int[n / 2 + 1];

    // Remove the top `n/2 + 1` elements and store them in a temporary array
    for (int i = 0; i <= n / 2; i++) {
        arr[i] = st.top();
        st.pop();
    }

    // Push all but the middle element back to the stack
    for (int i = n / 2 - 1; i >= 0; i--) {
        st.push(arr[i]);
    }

    delete[] arr; // Free dynamically allocated memory
}

int main() {
    // Sample stack
    stack<int> st;
    int n = 5;

    // Push elements to the stack
    for (int i = 1; i <= n; i++) {
        st.push(i);
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
