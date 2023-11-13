#include "Queue.h"
#include "infixToPostfix.h"

int main() {
    Queue queue;

    // add some elements to the queue (at rear)
    queue.add(43);
    queue.add(21);
    queue.add(48);
    queue.add(36);
    queue.add(95);

    queue.display();

    // remove front element of queue
    cout << "Removing front element... " << queue.remove() << endl;

    // Return present first element
    cout << "Present front element of queue: " << queue.front() << endl;

    // Display current queue
    cout << "Current Queue: " << endl;
    queue.display();

    // Check if queue is empty
    cout << "Queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;

    // Return total number of elements present in the queue
    cout << "Size of queue: " << queue.size() << endl;

    // converts infix expression to postfix expression based on user input
    string infix;
    cout << "\nEnter the infix expression: ";
    cin >> infix;
    if (balancedCheck(infix)) {
        string postfix = infix_to_postfix(infix);
        cout << "Postfix Expression: " << postfix << endl;
    }
    else {
        cout << "The expression is invalid." << endl;
    }

    return 0;
}
