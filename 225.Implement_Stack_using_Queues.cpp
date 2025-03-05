/* Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.*/

#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> queue1, queue2;

public:
    MyStack() {}

    void push(int x) {
        queue1.push(x);
    }

    int pop() {
        while (queue1.size() > 1) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        int topElement = queue1.front();
        queue1.pop();
        swap(queue1, queue2);
        return topElement;
    }

    int top() {
        while (queue1.size() > 1) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        int topElement = queue1.front();
        queue2.push(queue1.front());
        queue1.pop();
        swap(queue1, queue2);
        return topElement;
    }

    bool empty() {
        return queue1.empty();
    }
};
