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
            O(n/2)
        
        Space complexity - 
            O(1)
    */

    void middleOfList() {
    if (head == nullptr) {
        return; // handle empty list
    }

    Node* middle = head;
    Node* runner = head;
    int cnt = 1;
    while (runner != nullptr && runner->next != nullptr) {
        runner = runner->next->next;
        middle = middle->next;
        cnt++;
    }

    cout << "Middle of list is at position : " << cnt << endl;
    cout << "Middle Node is : " << middle->value << endl;
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