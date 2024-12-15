#include<bits/stdc++.h>
using namespace std;

/* Defining a Node */
class Node {
    public:
        int data;
        Node* next;

    // Constructor to initialize the node with a given value
        Node (int value) : data(value), next(nullptr) {}
};

void traverseList(Node* &head) {
    if (head == NULL) {
        cout << "The List is empty!" << endl;
        return;
    }

    Node* curr = head;
    
    while (curr != NULL) {
        // Print the value of current node 
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "\n";
}


int main() {

  Node* head = NULL;

  Node* node1 = new Node(12);
  node1->next = new Node(16);
  node1->next->next = new Node(46);
  node1->next->next->next = new Node(32);

  head = node1;

  traverseList(head);



  return 0;
}