#include<iostream>
#include<stack>
using namespace std;

void sortedInsert(stack<int> &s, int num){
    //  base case
    // insert into stack if the top element is less than num or stack is empty

    if((s.empty()) || (s.top() < num)){
        s.push(num);
        return;
    }

    int n=s.top();
    s.pop();

    // recursive call
    sortedInsert(s,num);

    s.push(n);
}

void sortStack(stack<int> &s){
    // base case
    if(s.empty()){
        return;
    }

    // keep top element aside
    int num=s.top();
    s.pop();

    //recursive call
    sortStack(s);

    // inserted the element kept aside in sorted order
    sortedInsert(s,num);
}

void printStack(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
}

int main()
{
    stack<int> st;
    st.push(5);   
    st.push(-6);   
    st.push(9);   
    st.push(-2);   
    st.push(1);   

    cout<<"Before sorting the stack is : "<<endl;
    printStack(st);

    sortStack(st);

    cout<<"After sorting the stack is : "<<endl;
    printStack(st);
    return 0;
}