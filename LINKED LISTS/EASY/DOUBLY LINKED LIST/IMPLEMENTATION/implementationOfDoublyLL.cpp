#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int value;
    Node* prev;
    Node* next;

    Node(int data) : value(data) , prev(nullptr), next(nullptr) {}
};



void printValues(Node* &head) {
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



int main() {

  Node* node1 = new Node(12);
  Node* node2 = new Node(13);
  Node* node3 = new Node(14);
  Node* node4 = new Node(15);
  Node* node5 = new Node(16);

  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;
  node5->next = NULL;

  node1->prev = NULL;
  node2->prev = node1;
  node3->prev = node2;
  node4->prev = node3;
  node5->prev = node4;

  Node* head = node1;
  printValues(head);


  return 0;
}