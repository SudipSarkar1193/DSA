#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if a character is a closing bracket
bool isClosing(char ch) {
    return ch == ')' || ch == '}' || ch == ']';
}

// Function to check if a pair of brackets match
bool isMatch(char o, char c) {
    return (o == '(' && c == ')') || (o == '{' && c == '}') || (o == '[' && c == ']');
}

// Function to check if a string of brackets is valid
bool isValid(string s) {

    if(s.length()%2) return false;

    stack<char> st;

    for (char ch : s) {
        if (!isClosing(ch)) {
            st.push(ch);
        } else {
            if (st.empty() || !isMatch(st.top(), ch)) return false;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string s;

    // Take input from the user
    cout << "Enter a string of brackets: ";
    cin >> s;

    // Check if the string of brackets is valid
    if (isValid(s)) {
        cout << "The string of brackets is valid." << endl;
    } else {
        cout << "The string of brackets is invalid." << endl;
    }

    return 0;
}
