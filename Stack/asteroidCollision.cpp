#include<bits/stdc++.h>
using namespace std ;

vector<int> asteroidCollision(vector<int>& arr) {
    stack<int> st;

    for (int e : arr) {
        if (e > 0) {
            // Positive asteroids are always pushed to the stack
            st.push(e);
        } else {
            // Process collisions for negative asteroids
            while (!st.empty() && st.top() > 0 && abs(e) > st.top()) {
                st.pop(); // Positive asteroid explodes
            }

            if (st.empty() || st.top() < 0) {
                // No more collisions, or top is a negative asteroid
                st.push(e);
            } else if (st.top() == abs(e)) {
                // Both asteroids have the same size and explode
                st.pop();
            }
        }
    }

    // Collect remaining asteroids from the stack
    vector<int> ans(st.size());
    for (int i = st.size() - 1; i >= 0; --i) {
        ans[i] = st.top();
        st.pop();
    }

    return ans;
}