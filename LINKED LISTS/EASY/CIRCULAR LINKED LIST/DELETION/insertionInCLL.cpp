#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int value;
    Node* next;

    Node(int data) : value(data), next(nullptr) {}
};

class LinkedList {
public:
    Node* tail;

    LinkedList() : tail(nullptr) {}

    void insertAtEnd(int value) {
        cout << "Inserting " << value << " at the end." << endl;
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            tail = newNode;
            newNode->next = newNode;
            return;
        }

        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }

    void insertAfterValue(int element, int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            tail = newNode;
            newNode->next = newNode;
            return;
        } 
        else {
            Node* curr = tail->next; 
            bool found = false;
            do {
                if (curr->value == element) {
                    found = true;
                    break;
                }
                curr = curr->next;
            } while (curr != tail->next); 

            if (!found) {
                cout << "Element " << element << " not found in the list." << endl;
                delete newNode;
                return;
            }
            cout << "Inserting " << value << " after " << element << endl;
            newNode->next = curr->next;
            curr->next = newNode;
            if (curr == tail) {
                tail = newNode;
            }
        }
    }

    void deleteByValue(int value) {
        if (tail == nullptr) {
            cout << "The list is empty!";
            return;
        }

        if (tail->next->value == value) {
            cout << "Deleting node with value " << value << endl;
            Node* temp = tail->next;
            if (temp->next == temp) { // List only contains one node
                tail = nullptr;
            } else {
                tail->next = temp->next;
            }
            delete temp;
            return;
        }

        Node* curr = tail->next;
        while (curr->next != tail->next && curr->next->value != value) {
            curr = curr->next;
        }

        if (curr->next->value == value) {
            cout << "Deleting node with value " << value << endl;
            Node* temp = curr->next;
            curr->next = curr->next->next;
            if (temp == tail) {
                tail = curr;
            }
            delete temp;
        } else {
            cout << value << " not found in the list." << endl;
        }
    }

    void printValues() {
        if (tail == nullptr) {
            cout << "The list is empty!" << endl;
            return;
        } else {
            Node* current = tail->next;
            do {
                cout << current->value << ' ';
                current = current->next;
            } while (current != tail->next);

            cout << '\n';
        }
    }

    void getTailValue() {
        if (tail == nullptr) {
            cout << "The list is empty!" << endl;
            return;
        }
        cout << "Tail is at " << tail->value << endl;
    }

    ~LinkedList() {
        if (tail != nullptr) {
            Node* current = tail->next;
            do {
                Node* nextNode = current->next;
                delete current;
                current = nextNode;
            } while (current != tail->next);
        }
    }
};

int main() {

  LinkedList* list = new LinkedList();

  list->insertAtEnd(15);
  list->insertAtEnd(14);
  list->insertAtEnd(46);
  list->printValues();
  list->getTailValue();

  list->insertAfterValue(14, 42);
  list->insertAfterValue(15, 69);
  list->printValues();
  list->getTailValue();

  list->deleteByValue(14);
  list->deleteByValue(46);
  list->deleteByValue(15);
  list->printValues();
  list->getTailValue();

  delete list;

  return 0;
}