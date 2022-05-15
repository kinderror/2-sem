#include <iostream>
#include <string>

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
    // pushes value or calculates
    void calc(string val) {
        if (top == nullptr or top->next == nullptr) {
            push(stoi(val));
            return;
        }
        int a = top->value, b = top->next->value;
        if (val == "+") {
            pop();
            pop();
            push(a + b);
        } else if (val == "-") {
            pop();
            pop();
            push(b - a);
        } else if (val == "*") {
            pop();
            pop();
            push(a * b);
        } else if (val == "/") {
            pop();
            pop();
            push(b / a);
        } else {
            push(stoi(val));
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
        stack.calc(val);
    }
    cout << stack.get();
    return 0;
}
