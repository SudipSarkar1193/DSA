#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to reverse the string
void reverseString(vector<char>& s) {
    stack<char> st;

    // Push all characters onto the stack
    for (char ch : s) {
        st.push(ch);
    }

    // Pop characters from the stack and overwrite the original vector
    int i = 0;
    while (!st.empty()) {
        s[i++] = st.top();
        st.pop();
    }
}

int main() {
    // Input string as a vector of characters
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    // Print the original string
    cout << "Original string: ";
    for (char ch : s) {
        cout << ch;
    }
    cout << endl;

    // Reverse the string
    reverseString(s);

    // Print the reversed string
    cout << "Reversed string: ";
    for (char ch : s) {
        cout << ch;
    }
    cout << endl;

    return 0;
}
