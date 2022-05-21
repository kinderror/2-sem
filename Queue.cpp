#include <iostream>

using namespace std;

struct Queue {
    int *data;
    int size;
    Queue() {
        data = new int[0];
        size = 0;
        cout << "Queue is created..." << endl;
    }
    // checks if queue is empty
    bool isempty() {
        return size == 0;
    }
    // gets value of the front element
    int peek() {
        if (isempty()) {
            cout << "Queue is empty" << endl;
        } else {
            return data[0];
        }
    }
    // adds new element 
    void enqueue(int val) {
        int *temp = new int[size + 1];
        for (int i = 0; i < size; i++) {
            temp[i] = data[i];
        }
        temp[size] = val;
        delete [] data;
        data = temp;
        size++;
    }
    // deletes the front element
    void dequeue() {
        if (isempty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        size--;
        int *temp = new int[size];
        for (int i = 0; i < size; i++) {
            temp[i] = data[i + 1];
        }
        delete [] data;
        data = temp;
    }
};

// example of using all functions
int main() {
    Queue queue = Queue(); // create queue {1 2 3 4 5 6 7}
    for (int i = 0; i < 7; i++) {
        queue.enqueue(i + 1);
    }
    cout << "Empty? "; // Empty? No
    if (queue.isempty()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    queue.dequeue();
    cout << "Front element after dequeue(): " << queue.peek() << endl; // 2
    queue.enqueue(57);
    for (int i = 0; i < 6; i++) {
        queue.dequeue();
    }
    cout << "Front element after enqueue(): " << queue.peek() << endl; // 57
    return 0;
}
