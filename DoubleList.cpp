#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *prev;
    Node *next;
    Node(int val) {
        value = val;
        next = nullptr;
        prev = nullptr;
    }
}; 

struct List {
    int size;
    Node *head;
    Node *tail;
    List() {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }
    // print all elements of the list
    void print() {
        if (size == 0) return;
        Node *p = head;
        while (p != nullptr) {
            cout << p->value << " ";
            p = p->next;
        }
        cout << endl;
    }
    // adds new node with value new_val to the end
    void push_back(int new_val) { 
        Node *p = new Node(new_val);
        if (size == 0) {
            size++;
            head = p;
            tail = p;
            return;
        }
        size++;
        p->prev = tail;
        tail->next = p;
        tail = p;
    }
    // add new node with value new_val to the front
    void push_front(int new_val) {
        Node *p = new Node(new_val);
        if (size == 0) {
            size++;
            head = p;
            tail = p;
            return;
        }
        size++;
        p->next = head;
        head->prev = p;
        head = p;
    }
    // add new node with value new_val in front of i‘th node
    void insert(int new_val, int index) {
        Node *p_new = new Node(new_val);
        Node *p = &(*head);
        if (index == 1) {
            push_front(new_val);
            return;
        }
        for (int i = 0; i < index - 2; i++) {
            p = p->next;
        }
        size++;
        p_new->prev = p;
        p_new->next = p->next;
        p->next->prev = p_new;
        p->next = p_new;
    }
    // get the last element value and delete last element
    int pop_back() {
        int val = tail->value;
        if (size == 1) {
            size--;
            delete tail;
            tail = nullptr;
            head = nullptr;
            return val;
        }
        size--;
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
        return val;
    }
    // get the front element value and delete front element
    int pop_front() {
        int val = head->value;
        if (size == 1) {
            size--;
            delete head;
            head = nullptr;
            tail = nullptr;
            return val;
        }
        size--;
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
        return val;
    }
    // delete i‘th element
    void remove(int index) {
        if (size == 1) {
            size--;
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }
        if (index == 1) {
            pop_front();
            return;
        }
        if (index == size) {
            pop_back();
            return;
        }
        Node *p = &(*head);
        for (int i = 0; i < index - 2; i++) {
            p = p->next;
        }
        size--;
        p->next = p->next->next;
        delete p->next->prev;
        p->next->prev = p;
    }
    // get the i‘th element by index
    int get(int index) {
        Node *p = &(*head);
        for (int i = 1; i < index; i++) {
            p = p->next;
        }
        return p->value;
    }
    // clear all elements of the list
    void clear() {
        while (size != 0) remove(1);
    }
};

// example of using all functions
int main() {
    List list = List(); // create list
    for (int i = 0; i < 7; i++) {
        list.push_back(i + 4);
    }
    for (int i = 0; i < 3; i++) {
        list.push_front(3 - i);
    }
    list.print(); // 1 2 3 4 5 6 7 8 9 10
    list.insert(17, 5); // add two elements
    list.insert(13, 9);
    list.print(); // 1 2 3 4 17 5 6 7 13 8 9 10
    cout << list.pop_back() << " " << list.pop_front() << endl; // 10 1
    list.remove(6); // remove 6'th element
    list.print(); // 2 3 4 17 5 7 13 8 9
    cout << list.get(4) << endl; // 17
    list.clear(); 
    list.print(); // empty list
    return 0;
}
