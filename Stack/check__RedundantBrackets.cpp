#include <bits/stdc++.h> 
using namespace std;


bool isArithmeticOperator(char ch) {
    // Check if the character is one of the arithmetic operators
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%');
}

bool findRedundantBrackets(string &s) {
    stack<char> st;

    for(char ch : s){
        if(ch=='(' || isArithmeticOperator(ch)){
            st.push(ch);
        }else if(ch==')'){

            bool isRedundant = true;
            
            while (st.empty()||st.top()!='(')
            {
                if(isArithmeticOperator(st.top())) {
                    isRedundant = false;
                }
                st.pop();
            }

            st.pop();

            if(isRedundant) return true;
            
        }
    }
    return false;
}
