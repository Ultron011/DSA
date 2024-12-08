#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int value;
    Node* next;
    
    // Constructor to initialize the node with a given value
    Node(int val): value(val), next(nullptr) {}
};

class LinkedList {
    public:
    Node* head;
    Node* tail;

    LinkedList() : head(nullptr), tail(nullptr) {}
    
    void insertFront(int value) {
        cout << "Inserting " << value << " at the front." << endl;

        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;

        if (tail == nullptr) {
            tail = newNode;
        }
    }

    void insertAtEnd(int value) {
        cout << "Inserting " << value << " at the end." << endl;

        Node* newNode = new Node(value);

        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        } 

        tail->next = newNode;
        tail = newNode;
    }

    void insertAfterK(int value, int k) {
        if (k <= 0) {
            cout << "Invalid position. Position should be greater than 0." << endl;
            return;
        }

        if (k == 1) {
            insertFront(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* current = head;

        for (int i = 1; i < k-1 && current != nullptr; i++) {
            current = current->next;
        }

        if (current == nullptr || current->next == nullptr) {
            insertAtEnd(value);
            return;
        } 

        newNode->next = current->next;
        current->next = newNode;

    }

    void printValues() {
        if (head == nullptr) {
            cout << "The list is empty!" << endl;
        }

        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->value << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void getHeadValue() {
        cout << "Head is at : " << head->value << endl;
    }

    void getTailValue() {
        cout << "Tail is at : " << tail->value << endl;
    }

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
};

int main() {
    LinkedList list;

    list.insertFront(3);
    list.insertFront(2);

    list.printValues();

    list.insertAtEnd(10);
    list.insertAtEnd(20);

    list.printValues();

    list.insertAfterK(5, 3);
    list.insertAfterK(6, 1);

    list.printValues();
    list.getHeadValue();
    list.getTailValue();
    
}