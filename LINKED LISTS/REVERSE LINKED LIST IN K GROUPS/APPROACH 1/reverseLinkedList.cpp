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
            O(n/k)

        Space compleixty -
            O(n)
    */

    Node* reverseListInKGroups(Node* head,int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        /* To reverse first K nodes */
        Node* curr = head;
        Node* prev = nullptr;
        Node* nextNode = nullptr;
        for (int i = 1; i <= k && curr != nullptr; i++) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        if (nextNode != nullptr) {
            head->next = reverseListInKGroups(nextNode, k);
        }

        return prev;

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

  list->insertAtFront(40);
  list->insertAtFront(30);
  list->insertAtFront(20);
  list->insertAtFront(10);

  list->printValues();
  list->getHeadValue();

  list->head = list->reverseListInKGroups(list->head, 2);
  list->printValues();
  list->getHeadValue();

  return 0;
}