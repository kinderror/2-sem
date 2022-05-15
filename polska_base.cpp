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
    int get() {
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
    void translate(string val, string *out) {
        if (val == "(") {
            push(val);
        } else if (val == ")") {
            while (get() != "(") {
                out = out + " " + get();
                pop();
            }
            pop();
        } else if (val == "+" or val == "-") {
            while (get() == "+" or get() == "-" or get() == "*" or get() == "/") {
                out = out + " " + get();
                pop();
            }
            push(val);
        } else if (val == "*" or val == "/") {
            while (get() == "*" or get() == "/") {
                out = out + " " + get();
                pop();
            }
            push(val);
        } else {
            out = out + " " + val;
        }
    }
};

int main() {
    Stack stack = Stack(); 
    string val, out = "";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        stack.translate(val, out);
    }
    while (stack.top != nullptr) {
        out = out + " " + stack.get();
        stack.pop();
    }
    cout << out;
    return 0;
}
