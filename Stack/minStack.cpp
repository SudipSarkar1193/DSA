#include<bits/stdc++.h>
using namespace std ;

class MinStack {
public:
    stack<pair<int, int>> st;
    MinStack() {}

    void push(int x) {
        int currentMin = st.empty() ? x : min(x, st.top().second);
        st.push({x, currentMin}); // Push the value and the current minimum
    }
    
    void pop() {
        st.pop(); // Remove the top element
    }
    
    int top() {
        return st.top().first; // Return the value part of the top pair
    }
    
    int getMin() {
        return st.top().second; // Return the minimum part of the top pair
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