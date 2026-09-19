// Name: Brad "Cody" Jones
// Professor: Christina Mulu
// Course: CSC-300 Fall 2026
// Filename: sqa.h
// Purpose: Header file for the Stack and Queue classes, plus two additional tasks

#ifndef SQA_H                      // if this include guard is not already defined
#define SQA_H                      // define it so this header is processed only once

#include <iostream>                // cout / cin for messages in stack and queue methods
#include <string>                  // string type used by evaluateExpression
#include <sstream>                 // stringstream splits the expression into tokens
#include <cmath>                   // pow() used for the ^ operator
using namespace std;               // allow cout, string, etc. without std::

/* ===================== LINKED LIST STACK ===================== */

struct StackNode {                 // one node in the stack's singly linked list
    int data;                      // the integer stored in this node
    StackNode* next;               // pointer to the node beneath this one
    StackNode(int val)             // constructor: create a node holding val
        : data(val), next(nullptr) {} // initialize data and set next to null
};

class Stack {                      // LIFO stack built from StackNode links
private:
    StackNode* top;                // points at the most recently pushed node

public:
    Stack();                       // constructor: empty stack
    ~Stack();                      // destructor: free every remaining node

    void push(int value);          // Task 1: insert value at the top
    int pop();                     // Task 1: remove and return the top value

    int peek() const;              // look at top without removing it
    bool isEmpty() const;          // true when top is nullptr
    void display() const;          // print top-to-bottom
};

/* ===================== LINKED LIST QUEUE ===================== */

struct QueueNode {                 // one node in the queue's singly linked list
    int data;                      // the integer stored in this node
    QueueNode* next;               // pointer to the next node toward the rear
    QueueNode(int val)             // constructor: create a node holding val
        : data(val), next(nullptr) {} // initialize data and set next to null
};

class Queue {                      // FIFO queue built from QueueNode links
private:
    QueueNode* front;              // first node to be dequeued
    QueueNode* rear;               // last node that was enqueued
    int qsize;                     // how many nodes are currently in the queue

public:
    Queue();                       // constructor: empty queue
    ~Queue();                      // destructor: free every remaining node

    void enqueue(int value);       // Task 2: insert value at the rear
    int dequeue();                 // Task 2: remove and return the front value

    int peek() const;              // look at front without removing it
    bool isEmpty() const;          // true when front is nullptr
    int size() const;              // return qsize
    void display() const;          // print front-to-rear
};

/* ========== Task 3: Dijkstra’s two-stack expression evaluator ========== */

double evaluateExpression(const string& expr); // evaluate a fully parenthesized expression

/* ========== Task 4: Josephus problem ========== */

int josephus(int N, int k);        // last remaining soldier among N, counting by k

#endif                             // end of include guard