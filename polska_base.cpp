#include <iostream>
#include <string>

using namespace std;

struct Node {
    string value;
    Node *next;
    Node(string val) {
        value = val;
        next = nullptr;
    }
}; 

struct Stack {
    Node *top;
    Stack() {
        top = nullptr;
    }
    // gets value of the top element
    string get() {
        return top->value;
    }
    // adds new element on top
    void push(string val) {
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
    // outputs or pushes element
    void translate(string val) {
        if (val == "(") {
            push(val);
        } else if (val == ")") {
            while (top != nullptr and get() != "(") {
                cout << get() << " ";
                pop();
            }
            pop();
        } else if (val == "+" or val == "-") {
            while (top != nullptr and (get() == "+" or get() == "-" or get() == "*" or get() == "/")) {
                cout << get() << " ";
                pop();
            }
            push(val);
        } else if (val == "*" or val == "/") {
            while (top != nullptr and (get() == "*" or get() == "/")) {
                cout << get() << " ";
                pop();
            }
            push(val);
        } else {
            cout << val << " ";
        }
    }
};

int main() {
    Stack stack = Stack();
    string val;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        stack.translate(val);
    }
    while (stack.top != nullptr) {
        cout << stack.get() << " ";
        stack.pop();
    }
    return 0;
}
