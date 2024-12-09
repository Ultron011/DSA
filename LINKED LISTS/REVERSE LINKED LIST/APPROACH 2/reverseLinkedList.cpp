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

    /* 
       Time Complexity - O(n)
       Space Compleixty- O(n)
    */
    Node* reverse(Node* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        Node* newHead = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;

        return newHead;


    }

    void reverseList() {
        head =  reverse(head);
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

  list->insertAtFront(40);
  list->insertAtFront(30);
  list->insertAtFront(20);
  list->insertAtFront(10);

  list->printValues();
  list->getHeadValue();

  list->reverseList();
  list->printValues();
  list->getHeadValue();

  return 0;
}