// Name: Brad "Cody" Jones
// Professor: Christina Mulu
// Course: CSC-300 Fall 2026
// Filename: mains.cpp
// Purpose: Main program for the stack menu

#include "sqa.h"                   // Stack class lives in sqa.h / sqa.cpp

int main() {                       // program entry point for the stack menu
    int choice, data;              // choice = menu option; data = value to push

    Stack stack;                   // create an empty linked-list stack

    do {                           // repeat the menu until the user exits
        cout << endl;              // blank line before the menu
        cout << "Stack Implementation (Linked List)" << endl; // title
        cout << "1. Push" << endl; // option 1
        cout << "2. Pop" << endl;  // option 2
        cout << "3. Peek" << endl; // option 3
        cout << "4. IsEmpty" << endl; // option 4
        cout << "5. Display" << endl; // option 5
        cout << "6. Exit" << endl; // option 6
        cout << endl;              // blank line after the menu

        cin >> choice;             // read the user's menu choice

        switch (choice) {          // dispatch on that choice
            case 1:                // Push
                cout << "Enter value to push: "; // prompt
                cin >> data;       // read the integer
                stack.push(data);  // Task 1: push it
                break;             // leave the switch

            case 2:                // Pop
                stack.pop();       // Task 1: pop (also prints underflow if empty)
                break;

            case 3:                // Peek
                if (!stack.isEmpty()) { // only peek when there is a top
                    cout << "Top of stack: " << stack.peek() << endl;
                } else {
                    cout << "Stack is empty" << endl;
                }
                break;

            case 4:                // IsEmpty
                cout << "Is Empty: " << (stack.isEmpty() ? "Yes" : "No") << endl;
                break;

            case 5:                // Display
                stack.display();   // print top-to-bottom
                break;

            case 6:                // Exit
                cout << "See you" << endl;
                break;

            default:               // any other number
                cout << "Invalid choice" << endl;
        }

    } while (choice != 6);         // keep looping until Exit

    return 0;                      // success
}