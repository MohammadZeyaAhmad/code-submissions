#include <iostream>
#include <stdexcept>
using namespace std;

class Node {
public:
    int data;
    int current_max;
    int current_min;
    Node* next;

    Node(int data) {
        this->data = data;
        this->current_max = data;
        this->current_min = data;
        this->next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    bool is_empty() {
        return top == nullptr;
    }

    void push(int data) {
        Node* new_node = new Node(data);

        if (!is_empty()) {
            new_node->current_max = max(data, top->current_max);
            new_node->current_min = min(data, top->current_min);
            new_node->next = top;
        }

        top = new_node;
    }

    int pop() {
        if (is_empty()) {
            throw underflow_error("Stack Underflow");
        }

        int popped_value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return popped_value;
    }

    int get_max() {
        if (is_empty()) {
            throw runtime_error("Stack is empty");
        }
        return top->current_max;
    }

    int get_min() {
        if (is_empty()) {
            throw runtime_error("Stack is empty");
        }
        return top->current_min;
    }

    void print_stack() {
        Node* curr = top;
        cout << "Stack: ";
        while (curr != nullptr) {
            cout << "(" << curr->data << ", max=" << curr->current_max << ", min=" << curr->current_min << ") ";
            curr = curr->next;
        }
        cout << endl;
    }

    ~Stack() {
        while (!is_empty()) {
            pop();
        }
    }
};

int main() {
    Stack stack;

    stack.push(5);  // Stack: (5, max=5, min=5)
    stack.push(3);  // Stack: (3, max=5, min=3) -> (5, max=5, min=5)
    stack.push(8);  // Stack: (8, max=8, min=3) -> (3, max=5, min=3) -> (5, max=5, min=5)
    stack.print_stack();

    cout << "Max: " << stack.get_max() << endl;  // Output: 8
    cout << "Min: " << stack.get_min() << endl;  // Output: 3

    stack.pop();  // Removes 8
    cout << "After pop:" << endl;
    stack.print_stack();  // Stack: (3, max=5, min=3) -> (5, max=5, min=5)
    cout << "Max: " << stack.get_max() << endl;  // Output: 5
    cout << "Min: " << stack.get_min() << endl;  // Output: 3

    return 0;
}
