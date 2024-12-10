#include <bits/stdc++.h>
using namespace std;
class MinStack {
public:
    stack<int> st ;
    
    vector<int> minArray;
    

    MinStack() {
        minArray.push_back(INT_MAX); // Initialize with INT_MAX in the constructor
    }
    
    void push(int x) {
        if( x <= minArray.back() ){
            minArray.push_back(x);
        }
        st.push(x);
    }
    
    void pop() {
        if( st.top() == minArray.back() ){
            minArray.pop_back();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minArray.back() ;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */