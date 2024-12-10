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
    /*
        Time Complexity - 
            O(n)
        Space Compelxity - 
            O(1)
    */
    bool circularOrNot() {
        // If the list is empty or has only one node, it's not circular
        if (tail == nullptr || tail->next == nullptr) {
            return false;
        }

        Node* curr = tail->next;  // Start from the head (tail->next in a circular list)
        while (curr != nullptr && curr != tail) {
            curr = curr->next;
        }

        // If we encountered the tail again, the list is circular
        if (curr == tail) {
            return true;
        }

        // If we reached the end (nullptr), it's not circular
        return false;
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

  if (list->circularOrNot()) {
    cout << "It is a circular list" << endl;
  }else {
    cout << "It is not a circular list" << endl;
  }


  delete list;

  return 0;
}