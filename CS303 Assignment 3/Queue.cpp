#include "Queue.h"

// add an element to the rear of the queue
void Queue::add(int val) {
    q.push(val);
}

// remove an element from the front of the queue
int Queue::remove() {
    if (!q.empty()) {
        int front = q.front();
        q.pop();
        return front;
    }
    return -1;
}

// returns front value in queue
int Queue::front() {
    if (!q.empty()) {
        return q.front();
    }
    return -1;
}

// checks if the queue is empty
bool Queue::isEmpty() {
    return q.empty();
}

// returns number of elements in the queue
int Queue::size() {
    return q.size();
}

// displays the queue
void Queue::display() {
    cout << "Queue is: ";
    queue<int> tempQ = q;
    while (!tempQ.empty()) {
        cout << tempQ.front() << " ";
        tempQ.pop();
    }
    cout << endl;
}
