#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &st, int num){
    if(st.empty()){
        st.push(num);
        return;
    }

    int n=st.top();
    st.pop();

    insertAtBottom(st,num);
    st.push(n);
}

void reverseStack(stack<int> &st){
    // base case
    if(st.empty()){
        return;
    }

    int topNum=st.top();
    st.pop();

    // recursive call
    reverseStack(st);

    insertAtBottom(st,topNum);
}

void printStack(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
}

int main()
{
    stack<int> s;

    s.push(1);   
    s.push(2);   
    s.push(3);   
    s.push(4);   
    s.push(5);   

    cout<<endl<<"Before reversing the stack is : "<<endl;
    printStack(s);
    cout<<endl;

    reverseStack(s);

    cout<<"After reversing the stack is : "<<endl;
    printStack(s);
    cout<<endl;
    
    return 0;
}