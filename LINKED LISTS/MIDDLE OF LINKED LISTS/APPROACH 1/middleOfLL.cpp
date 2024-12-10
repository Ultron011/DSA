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
    Node* head;

    void insertAtFront(int value) {
        cout << "Inserting " << value << " at the front." << endl;
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }


        newNode->next = head;
        head = newNode;
    }

    /* 
        Time complexity - 
            O(n) + O(n/2) = O(n)
        
        Space complexity - 
            O(1)
    */

    void middleOfList() {
        int len = getLength();
        if (len == 0) {
            cout << "Empty List! ";
            return;
        }
        int middle = (len/2) + 1;

        Node* curr = head;
        for(int i = 1; i < middle; i++) {
            curr = curr->next;
        }        
        
        cout << "Middle of list is at position : " << middle << endl;
        cout << "Middle Node is : " << curr->value << endl;
    }

    int getLength() {
        if (head == nullptr) {
            return 0;
        }
        Node* curr = head;
        int len = 0;
        while (curr != nullptr) {
            len++;
            curr = curr->next;
        }
        return len;
    }

    void printValues() {
        if (head == nullptr) {
            cout << "The list is empty!" << endl;
            return;
        }
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->value << " ";
            curr= curr->next;
        }
        cout << endl;
    }

    void getHeadValue() {
        if (head == nullptr) {
            cout << "The list is empty!" << endl;
            return;
        }

        cout << "Head is at " << head->value << endl;
    }


};

int main() {

  LinkedList* list = new LinkedList();

  list->insertAtFront(50);
  list->insertAtFront(40);
  list->insertAtFront(30);
  list->insertAtFront(20);
  list->insertAtFront(10);

  list->printValues();
  list->getHeadValue();
  list->middleOfList();

  return 0;
}