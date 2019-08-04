#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<stack>
#include<climits>

using namespace std;

class MinStack {
private:
    std::stack<int> data;
    std::stack<int> minstack;
    
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        data.push(x);
        
        if(minstack.empty()){
            minstack.push(x);
        }else{
            int min = x > minstack.top() ? minstack.top() : x;
            minstack.push(min);
        }
    }
    
    void pop() {
        if(!minstack.empty() && !data.empty()){
            minstack.pop();
            data.pop();
        }
    }
    
    int top() {
        if(!data.empty()){
            return data.top();
        }
        
        return -1;
    }
    
    int getMin() {
        if(!minstack.empty()){
            return minstack.top();
        }
        
        return -1;
    }
};

int main(void){

    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin();   //--> Returns -3.
    minStack.pop();
    minStack.top();      //--> Returns 0.
    minStack.getMin();   //--> Returns -2.

    return true;
}
