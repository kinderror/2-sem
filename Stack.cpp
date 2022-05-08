#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next;
    Node(int val) {
        value = val;
        next = nullptr;
    }
}; 

struct Stack {
    Node *top;
    Stack() {
        top = nullptr;
    }
    // checks if stack is empty
    bool empty() {
        return top == nullptr;
    }
    // gets value of the top element
    int get() {
        return top->value;
    }
    // adds new element on top
    void push(int val) {
        Node *p = new Node(val);
        p->next = top;
        top = p;
    }
    // deletes the top element
    void pop() {
        Node *p = &(*(top->next));
        delete top;
        top = p;
    }
};

// example of using all functions
int main() {
    Stack stack = Stack(); // create stack {1 2 3 4 5 6 7}
    for (int i = 0; i < 7; i++) {
        stack.push(i + 1);
    }
    cout << "Empty? "; // Empty? No
    if (stack.empty()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    stack.pop();
    cout << "Top element after pop(): " << stack.get() << endl; // 6
    stack.push(57);
    cout << "Top element after push(): " << stack.get() << endl; // 57
    return 0;
}
