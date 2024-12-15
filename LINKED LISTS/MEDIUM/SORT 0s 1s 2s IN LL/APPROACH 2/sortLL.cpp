#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node(int d) : value(d), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void append(int d) {
        Node* newNode = new Node(d);
        if (!head) {
            head = newNode;
            return;
        }
        Node* tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = newNode;
    }

    void insertAtTail(Node*& tail, Node* curr) {
        tail->next = curr;
        tail = curr;
        curr->next = nullptr;
    }

    void sort() {
        if (!head || !head->next) {
            return;  // No need to sort if list is empty or has one element
        }

        Node* zeroHead = new Node(-1);
        Node* zeroTail = zeroHead;
        Node* oneHead = new Node(-1);
        Node* oneTail = oneHead;
        Node* twoHead = new Node(-1);
        Node* twoTail = twoHead;

        Node* curr = head;
        while (curr) {
            Node* newNode = new Node(curr->value); // Create a new node
            if (curr->value == 0) {
                insertAtTail(zeroTail, newNode);
            }
            else if (curr->value == 1) {
                insertAtTail(oneTail, newNode);
            } else {
                insertAtTail(twoTail, newNode);
            }
            curr = curr->next;
        }

        // Merge all three sublists: zero, one, two
        if (oneHead->next) {
            zeroTail->next = oneHead->next;
        } else {
            zeroTail->next = twoHead->next; // If there's no 1, link directly to the 2 list
        }

        oneTail->next = twoHead->next;
        twoTail->next = nullptr;

        head = zeroHead->next;
        
        // Clean up temporary head nodes
        delete zeroHead;
        delete oneHead;
        delete twoHead;
    }

    void printValues() {
        if (!head) {
            cout << "Empty List!" << endl;
            return;
        }

        Node* curr = head;
        while (curr) {
            cout << curr->value << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {

  LinkedList list;
  list.append(1);
  list.append(0);
  list.append(2);
  list.append(1);
  list.append(2);

  cout << "Original List: ";
  list.printValues();

  list.sort();

  cout << "Sorted List: ";
  list.printValues();

  return 0;
}
