#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int value;
    Node* next;

    Node (int data) : value(data), next(nullptr) {}
};

class LinkedList {
    public:
    Node* head;
    Node* tail;

    LinkedList() : head(nullptr), tail(nullptr) {}

    void insertAtFront(int value) {
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
        Node* curr = head;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }
        
        tail->next = newNode;
        tail = newNode;
    }

    void insertAfterK(int k , int value) {
        if (k <= 0) {
            cout << "Invalid Position. K should be greater than 0" << endl;
            return;
        }

        if (k == 1) {
            insertAtFront(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* curr = head;

        for  (int i = 1; i < k-1 && curr != nullptr; i++) {
            curr = curr->next;
        }

        if (curr == nullptr || curr->next == nullptr) {
            insertAtEnd(value);
            return;
        }

        cout << "Inserting " << value << " at " << k << " position." << endl;
        newNode->next = curr->next;
        curr->next = newNode;
    }

    void deleteNodeAtPos(int pos) {

        if (pos <= 0) {
            cout << "Invalid Position. Position should be greater than 0" << endl;
            return;
        }

        if (pos == 1) {
            cout << "Deleting node at  " << pos << " position." << endl;
            Node* temp = head;
            head = head->next;
            if (head == nullptr) {
                tail = nullptr;
            }
            delete temp;
            return;
        }

        Node* curr = head;

        for (int i = 1; i < pos - 1 && curr != nullptr; i++) {
            curr = curr->next;
        }

        if (curr == nullptr || curr->next == nullptr) {
            cout << "Position" << pos << " out of range." << endl;
            return;
        }
        
        cout << "Deleting node at " << pos << " position." << endl;
        Node*temp = curr->next;
        curr->next = curr->next->next;
        if (curr->next == nullptr) {
            tail = curr;
        }
        delete temp;
    }

    void deleteNodeWithValue(int value) {

        if (head == nullptr) {
            cout << "The list is empty!" << endl;
            return;
        }

        // Check if the head node has the given value
        if (head -> value == value) {
            cout << "Deleting node with " << value << " value." << endl;
            Node* temp = head;
            head = head -> next;
            if (head == nullptr) {
                tail = nullptr;
            }
            delete temp;
            return;
        } 

        // Traverse the list to find the node with the given value
        Node* curr = head;
        while (curr->next != NULL) {
            if (curr->next->value == value) {
                cout << "Deleting node with " << value << " value." << endl;
                Node* temp = curr->next;
                curr->next = curr->next->next;
                if (curr->next == nullptr) {
                    tail = curr;
                }
                delete temp;
                return;
            }
            curr = curr -> next;
        }

        cout << "Node with value " << value << " not found in the list." << endl;
    }

    void printValues() {
        if (head == nullptr) {
            cout << "The list is emtpy!" << endl;
        }

        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->value << " ";
            curr = curr->next;
        }
        cout << "\n";
    }

    void getHeadValue() {
        if (head == nullptr) {
            cout << "Empty List! " << endl;
            return;
        }

        cout << "Head is at : " << head->value << endl;
    }

    void getTailValue() {
        if (tail == nullptr) {
            cout << "Empty List!" << endl;
            return;
        }
        
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
  list.insertAtFront(10);
  list.insertAtFront(5);
  list.insertAtFront(9);

  list.printValues();
  list.getHeadValue();
  list.getTailValue();

  list.insertAtEnd(12);
  list.insertAtEnd(36);
  list.printValues();
  list.getHeadValue();
  list.getTailValue();

  list.insertAfterK(2, 155);
  list.insertAfterK(3, 45);
  list.insertAfterK(1, 23);
  list.insertAfterK(9, 69);
  list.printValues();
  list.getHeadValue();
  list.getTailValue();

  list.deleteNodeAtPos(1);
  list.deleteNodeAtPos(8);
  list.deleteNodeAtPos(9);
  list.printValues();
  list.getHeadValue();
  list.getTailValue();


  list.deleteNodeWithValue(155);
  list.deleteNodeWithValue(36);
  list.deleteNodeWithValue(12);
  list.printValues();
  list.getHeadValue();
  list.getTailValue();



  return 0;
}