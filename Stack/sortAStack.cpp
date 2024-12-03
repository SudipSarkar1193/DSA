#include <bits/stdc++.h> 

using namespace std;


void insertInSortedWay(stack<int> &st,int x){


	//If the stack is empty or the top of the stack (st.top()) is less than x, then x can be directly pushed onto the stack. This is the point where the recursion stops.
	if(st.empty() || st.top() < x){  
        st.push(x);
        return ;
    }

    //If the current top of the stack is greater than x, we :

    //Temporarily remove the top element.
    int store = st.top();
    st.pop();

    //Call insertInSortedWay on the smaller stack to recursively find the correct position for x.
    insertInSortedWay(st,x);

    //After x is inserted in the sorted stack, push back the previously removed element to restore the stack.
    st.push(store);
}




// Function to sort the stack using recursion
void sortStack(stack<int>& st) {
    if (st.empty()) {
        return;
    }

    // Pop the top element
    int num = st.top();
    st.pop();

    // Recursively sort the remaining stack
    sortStack(st);

    // Insert the popped element in sorted order
    insertInSortedWay(st, num);
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

    // Sort the stack
    sortStack(st);

    // Printing the sorted stack
    cout << "Sorted stack: ";
    stack<int> sortedStack;
    while (!st.empty()) {
        sortedStack.push(st.top());
        st.pop();
    }
    while (!sortedStack.empty()) {
        cout << sortedStack.top() << " ";
        sortedStack.pop();
    }
    cout << endl;

    return 0;
}