// Name: Brad "Cody" Jones
// Professor: Christina Mulu
// Course: CSC-300 Fall 2026
// Filename: sqa.cpp
// Purpose: Implementation file for the Stack and Queue classes, plus two additional tasks

#include "sqa.h"                   // bring in class declarations and helpers

/* ===================== STACK (linked list) ===================== */

Stack::Stack() {                   // create an empty stack
    top = nullptr;                 // no nodes yet, so top points nowhere
}

Stack::~Stack() {                  // destroy the stack
    while (!isEmpty()) {           // as long as nodes remain
        pop();                     // remove and delete the top node
    }
}

void Stack::push(int value) {      // Task 1: push value onto the stack
    StackNode* node = new StackNode(value); // allocate a new node holding value
    node->next = top;              // new node points at the old top
    top = node;                    // new node is now the top
}

int Stack::pop() {                 // Task 1: pop the top value
    if (isEmpty()) {               // cannot pop from an empty stack
        cout << "Stack underflow" << endl; // report the error
        return -1;                 // sentinel return value
    }
    StackNode* temp = top;         // keep a handle to the node we will delete
    int val = temp->data;          // copy out the stored integer
    top = top->next;               // move top down one node
    delete temp;                   // free the old top node
    return val;                    // give the caller the popped value
}

int Stack::peek() const {          // inspect the top without removing it
    if (isEmpty()) {               // nothing to peek at
        cout << "Stack is empty" << endl;
        return -1;                 // sentinel
    }
    return top->data;              // return the top integer
}

bool Stack::isEmpty() const {      // emptiness test
    return top == nullptr;         // empty iff there is no top node
}

void Stack::display() const {      // print the stack
    if (isEmpty()) {               // nothing to print
        cout << "Stack is empty" << endl;
        return;                    // leave the function
    }
    cout << "Stack elements (top to bottom): "; // label the output
    StackNode* curr = top;         // start at the top
    while (curr) {                 // walk until nullptr (bottom)
        cout << curr->data << " "; // print this node's value
        curr = curr->next;         // move one node down
    }
    cout << endl;                  // end the line
}

/* ===================== QUEUE (linked list) ===================== */

Queue::Queue() {                   // create an empty queue
    front = rear = nullptr;        // no front and no rear
    qsize = 0;                     // zero elements
}

Queue::~Queue() {                  // destroy the queue
    while (!isEmpty()) {           // as long as nodes remain
        dequeue();                 // remove and delete the front node
    }
}

void Queue::enqueue(int value) {   // Task 2: add value at the rear
    QueueNode* node = new QueueNode(value); // allocate a new node
    if (isEmpty()) {               // first element in an empty queue
        front = rear = node;       // front and rear both point at it
    } else {                       // queue already has at least one node
        rear->next = node;         // old rear links to the new node
        rear = node;               // new node becomes the rear
    }
    qsize++;                       // one more element
}

int Queue::dequeue() {             // Task 2: remove the front value
    if (isEmpty()) {               // cannot dequeue from an empty queue
        cout << "Queue underflow" << endl;
        return -1;                 // sentinel
    }
    QueueNode* temp = front;       // keep a handle to the node we will delete
    int val = temp->data;          // copy out the stored integer
    front = front->next;           // move front forward one node
    if (front == nullptr) {        // we just removed the last node
        rear = nullptr;            // rear must also become null
    }
    delete temp;                   // free the old front node
    qsize--;                       // one fewer element
    return val;                    // give the caller the dequeued value
}

int Queue::peek() const {          // inspect the front without removing it
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return front->data;            // front value
}

bool Queue::isEmpty() const {      // emptiness test
    return front == nullptr;       // empty iff there is no front node
}

int Queue::size() const {          // current length
    return qsize;                  // O(1) because we track it
}

void Queue::display() const {      // print the queue
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue elements (front to rear): ";
    QueueNode* curr = front;       // start at the front
    while (curr) {                 // walk until nullptr (past rear)
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

/* ========== Task 3: Dijkstra’s two-stack algorithm ========== */

static double applyOp(char op, double left, double right) { // apply one binary operator
    switch (op) {                  // choose the arithmetic by the operator character
        case '+': return left + right; // addition
        case '-': return left - right; // subtraction (left minus right)
        case '*': return left * right; // multiplication
        case '/': return (right == 0.0) ? 0.0 : left / right; // division; 0 if divide-by-zero
        case '^': return pow(left, right); // exponent: left raised to right
        default:  return 0.0;      // unknown operator: return 0
    }
}

double evaluateExpression(const string& expr) { // Task 3
    Stack ops;                     // operator stack (stores char codes as int)
    double vals[256];              // operand stack as doubles (int Stack would truncate)
    int vtop = -1;                 // index of the current top operand; -1 means empty

    stringstream ss(expr);         // wrap the expression so we can extract tokens
    string token;                  // current token: "(", ")", operator, or number

    while (ss >> token) {          // read next whitespace-separated token
        if (token == "(") {        // left parenthesis
            continue;              // fully parenthesized: ignore "("
        } else if (token == "+" || token == "-" ||
                   token == "*" || token == "/" || token == "^") { // an operator
            ops.push(static_cast<int>(token[0])); // push the operator character
        } else if (token == ")") { // right parenthesis: evaluate one subexpression
            char op = static_cast<char>(ops.pop()); // operator for this pair of parens
            double right = vals[vtop--]; // most recently pushed operand is the right one
            double left  = vals[vtop--]; // next is the left operand
            vals[++vtop] = applyOp(op, left, right); // push the computed result
        } else {                   // token is a number
            vals[++vtop] = stod(token); // convert text to double and push
        }
    }

    return vals[vtop];             // the last remaining operand is the answer
}

/* ========== Task 4: Josephus with the linked queue ========== */

int josephus(int N, int k) {       // Task 4: N soldiers, count every k-th
    if (N <= 0) return -1;         // invalid number of soldiers
    if (k <= 0) k = 1;             // treat non-positive k as "count 1"

    Queue q;                       // circle simulated by a FIFO queue
    for (int i = 1; i <= N; ++i) { // soldiers numbered 1 through N
        q.enqueue(i);              // stand them in line / around the circle
    }

    while (q.size() > 1) {         // repeat until one soldier remains
        for (int i = 1; i < k; ++i) { // skip k-1 soldiers
            q.enqueue(q.dequeue()); // move skipped soldier from front to rear
        }
        q.dequeue();               // the k-th soldier is eliminated
    }
    return q.dequeue();            // last remaining soldier
}