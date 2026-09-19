// Name: Brad "Cody" Jones
// Professor: Christina Mulu
// Course: CSC-300 Fall 2026
// Filename: mainq.cpp
// Purpose: Main program for the queue menu

#include "sqa.h"                   // Queue class lives in sqa.h / sqa.cpp

int main() {                       // program entry point for the queue menu
    int choice, data;              // choice = menu option; data = value to enqueue

    Queue queue;                   // create an empty linked-list queue

    do {                           // repeat the menu until the user exits
        cout << endl;
        cout << "Queue Implementation (Linked List)" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. IsEmpty" << endl;
        cout << "5. Size" << endl;
        cout << "6. Display" << endl;
        cout << "7. Exit" << endl;
        cout << endl;

        cin >> choice;             // read the user's menu choice

        switch (choice) {
            case 1:                // Enqueue
                cout << "Enter value to enqueue: ";
                cin >> data;
                queue.enqueue(data); // Task 2: add at rear
                break;

            case 2:                // Dequeue
                queue.dequeue();   // Task 2: remove from front
                break;

            case 3:                // Peek
                if (!queue.isEmpty()) {
                    cout << "Front of queue: " << queue.peek() << endl;
                } else {
                    cout << "Queue is empty" << endl;
                }
                break;

            case 4:                // IsEmpty
                cout << "Is Empty: " << (queue.isEmpty() ? "Yes" : "No") << endl;
                break;

            case 5:                // Size
                cout << "Queue size: " << queue.size() << endl;
                break;

            case 6:                // Display
                queue.display();   // print front-to-rear
                break;

            case 7:                // Exit
                cout << "See you" << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
        }

    } while (choice != 7);         // keep looping until Exit

    return 0;
}