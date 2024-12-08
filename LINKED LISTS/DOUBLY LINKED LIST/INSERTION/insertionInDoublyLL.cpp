#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int value;
    Node* prev;
    Node* next;

    Node(int data) : value(data) , prev(nullptr), next(nullptr) {}
};

class LinkedList {
    public:
    Node* head;
    Node* tail;

    void insertAtFront(int value) {
        cout << "Inserting " << value << " at the front." << endl;
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }

        newNode -> next = head;
        head->prev = newNode;
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
    }

    void insertAtEnd(int value) {
        cout << "Inserting " << value << " at the end." << endl;

        Node* newNode = new Node(value);

        if (tail == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void insertAfterK(int k, int value) {
        if (k <= 0) {
            cout << "Invalid Position . K should be greater than 0" << endl;
            return;
        }

        if (k == 1) {
            insertAtFront(value);
            return;
        }

        if (k == getLength()) {
            insertAtEnd(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* curr = head;

        for (int i = 1; i < k - 1 && curr != NULL; i++) {
            curr= curr->next;
        }

        if (curr == NULL || curr->next == NULL) {
            insertAtEnd(value);
            return;
        }  

        cout << "Inserting " << value << " at " << k << " position." << endl;

        newNode->next = curr->next;
        curr->next->prev = newNode;
        newNode->prev = curr;
        curr->next = newNode;
     }

    int getLength() {
        if (head == NULL) {
            cout << "The list is empty!" << endl;
            return 0;
        }

        int len = 0;
        Node* curr = head;
        while (curr != NULL) {
            curr = curr->next;
            len++;
        }
        return len;
    }

    void printValues() {
        if (head == NULL) {
            cout << "The list is empty!" << endl;
            return;
        }
        Node* curr = head;
        while (curr != NULL) {
            cout << curr -> value << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void getHeadValue() {
        if (head == NULL) {
            cout << "The list is empty!" << endl;
            return;
        }

        cout << "Head is at : " << head->value << endl;
    }

    void getTailValue() {
        if (tail == NULL) {
            cout << "The list is empty!" << endl;
            return;
        }
        cout << "Tail is at : " << tail->value << endl;
    }
};



int main() {

  LinkedList* list = new LinkedList();
  
  list->insertAtFront(12);
  list->insertAtFront(13);
  list->insertAtFront(14);
  list->printValues();
  list->getLength();
  list->getHeadValue();
  list->getTailValue();

  list->insertAtEnd(10);
  list->insertAtEnd(20);
  list->insertAtEnd(30);
  list->printValues();
  list->getHeadValue();
  list->getTailValue();

  list->insertAfterK(1, 45);
  list->insertAfterK(7, 29);
  list->insertAfterK(3, 69);
  list->printValues();
  list->getHeadValue();
  list->getTailValue();
  
  delete list;


  return 0;
}