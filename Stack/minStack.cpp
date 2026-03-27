#include <stack>
using namespace std;

class MinStack{
public:
    MinStack() {

    };
    void push(int val){
        numStack.push(val);
        if(minStack.empty()||val<= minStack.top()){
            minStack.push(val);
        }
    }
    void pop(){
        int num = numStack.top();
        numStack.pop();
        if(num == minStack.top()){
            minStack.pop();
        }
    }
    int top() {
        return numStack.top();
    };
    int getMin(){
        return minStack.top();
    }
protected:
    stack<int> numStack;
    stack<int> minStack;
};