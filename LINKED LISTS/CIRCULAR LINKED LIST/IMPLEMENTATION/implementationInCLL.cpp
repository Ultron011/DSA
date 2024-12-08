#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int value;
    Node* next;

    Node(int data) : value(data), next(nullptr) {}

    ~Node() {
        int value = this->value;
        if (this->next != nullptr) {
            delete next;
            next = NULL;
        }
        cout << "Memory is freed for node with data  " << value << endl;
    }
};

void printValues(Node* head) {
    if (head == nullptr) {
        cout << "The list is empty!";
        return;
    }

    Node* curr = head;
    while (curr != head) {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {

  Node* node1 = new Node(10);
  Node* node2 = new Node(20);
  Node* node3 = new Node(30);
  Node* node4 = new Node(40);

  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node1;

  Node* head = node1;

  printValues(head);


  return 0;
}