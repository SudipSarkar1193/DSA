#include <bits/stdc++.h>
using namespace std;

class TwoStack {
private:
    int *arr;  // Pointer to dynamically allocate the array
    int n;     // Size of the array
    int top1;  // Top of Stack 1
    int top2;  // Top of Stack 2

public:
    // Constructor to initialize the TwoStack object
    TwoStack(int size) {
        n = size;
        arr = new int[n];
        top1 = -1;
        top2 = n;
    }

    // Function to push an integer into stack1
    void push1(int x) {
        if (top1 < top2 - 1) { // Ensure there's space between top1 and top2
            arr[++top1] = x;
        } else {
            cout << "Stack1 Overflow" << endl;
        }
    }

    // Function to push an integer into stack2
    void push2(int x) {
        if (top1 < top2 - 1) { // Ensure there's space between top1 and top2
            arr[--top2] = x;
        } else {
            cout << "Stack2 Overflow" << endl;
        }
    }

    // Function to remove an element from the top of stack1
    int pop1() {
        if (top1 >= 0) {
            return arr[top1--];
        } else {
            return -1; // Stack1 Underflow
        }
    }

    // Function to remove an element from the top of stack2
    int pop2() {
        if (top2 < n) {
            return arr[top2++];
        } else {
            return -1; // Stack2 Underflow
        }
    }
};

// Main function to test the TwoStack implementation
int main() {
    int size = 5; // Define the size of the array
    TwoStack ts(size);

    // Test Stack 1
    ts.push1(10);
    ts.push1(20);
    ts.push1(30);

    // Test Stack 2
    ts.push2(40);
    ts.push2(50);

    // Pop elements from Stack 1
    cout << "Popping from Stack1: ";
    cout << ts.pop1() << " "; // Output: 30
    cout << ts.pop1() << " "; // Output: 20

    // Pop elements from Stack 2
    cout << "\nPopping from Stack2: ";
    cout << ts.pop2() << " "; // Output: 50
    cout << ts.pop2() << endl; // Output: 40

    // Test Overflow and Underflow
    ts.push1(60);
    ts.push1(70);
    ts.push1(80); // Should cause overflow
    ts.push2(90); // Should cause overflow

    cout << "Popping from Stack1 after overflow: " << ts.pop1() << endl; // Output: 70
    cout << "Popping from Stack2 after overflow: " << ts.pop2() << endl; // Output: -1

    return 0;
}
