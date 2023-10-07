#include <iostream>
#include <stack>

class MinStack {
private:
    std::stack<int> s;
    std::stack<int> minStack;

public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        s.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    void pop() {
        if (s.top() == minStack.top()) {
            minStack.pop();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack minStack;

    // Push elements onto the stack
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    // Get the minimum element from the stack
    int minElement = minStack.getMin();
    std::cout << "Minimum element: " << minElement << std::endl;

    // Pop an element from the stack
    minStack.pop();

    // Get the top element of the stack
    int topElement = minStack.top();
    std::cout << "Top element: " << topElement << std::endl;

    // Get the minimum element again
    minElement = minStack.getMin();
    std::cout << "Minimum element after popping: " << minElement << std::endl;

    return 0;
}
