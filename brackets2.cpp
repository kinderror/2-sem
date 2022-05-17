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
    // checks if brackets are right
    bool check(string val) {
        if (val == "(") {
            push(val);
            return true;
        } else if (val == ")") {
            if (top == nullptr) {
                return false;
            } else if (get() == "(") {
                pop();
                return true;
            } else {
                return false;
            }
        } else if (val == "{") {
            push(val);
            return true;
        } else if (val == "}") {
            if (top == nullptr) {
                return false;
            } else if (get() == "{") {
                pop();
                return true;
            } else {
                return false;
            }
        } else if (val == "[") {
            push(val);
            return true;
        } else if (val == "]") {
            if (top == nullptr) {
                return false;
            } else if (get() == "[") {
                pop();
                return true;
            } else {
                return false;
            }
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
        if (not stack.check(val)) {
            cout << -1;
            return 0;
        }
    }
    if (stack.top == nullptr) {
        cout << 0;
    } else {
        cout << -1;
    }
    return 0;
}
