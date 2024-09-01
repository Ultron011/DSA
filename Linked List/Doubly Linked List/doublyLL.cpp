#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* prev;
        Node* next;

        Node (int d) : data(d), prev(NULL), next(NULL) {}

        ~Node() {
            int val = this->data;
            if (next != NULL) {
                next = NULL;
                delete next;
            }
            cout << "Node with value " << data << " is deleted " << endl;
        }
};

/* Traversing a doubly linked list */
void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

/* Returning the Length of a doubly linked list */
int getLength(Node* head) {
    Node* temp = head;
    int len = 0;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

/* Inserting at the beginning of a doubly linked list */
void insertAtBeg(Node* &head, Node* &tail, int d) {
    if (head == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
        return;
    }
    Node* temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node* &tail, Node* &head, int d) {
    if (tail == NULL) {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
        return;
    }
    Node* temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPos(Node* &head, Node* &tail,int pos, int d) {
    Node* newNode = new Node(d);
    Node* temp = head;

    if (pos == 1) {
        insertAtBeg(head,tail, d);
        return;
    }

    int cnt = 1;
    while (cnt < pos - 1) {
        temp = temp->next;
        cnt++;
    }

    if (pos >= getLength(head)) {
        insertAtTail(tail,head, d);
        return;
    }
    
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteNode(Node* &head,Node* &tail, int pos) {
    if (pos == 1) {
        Node* temp = head;
        head = temp->next;
        head->prev - NULL;
        delete temp;
        return;
    }
    
    Node* curr = head;
    Node* prev= NULL;

    int cnt = 1;
    while(cnt < pos ) {
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    if (curr->next == NULL) {
        curr->prev = NULL;
        tail = prev;
        prev->next = NULL;
        delete curr;
        return;
    }
    curr->prev = NULL;
    prev->next = curr->next;
    curr->next->prev = prev;
    delete curr;
}

int main () {

  Node* head = NULL;
  Node* tail = NULL;
  print(head);
  cout << "Length of the Linked List : " << getLength(head) << endl;

  insertAtBeg(head, tail, 33);
  insertAtBeg(head,tail,  43);
  print(head);

  insertAtTail(tail,head, 12);
  insertAtTail(tail,head, 69);
  print(head);

  insertAtPos(head, tail, 2, 100);
  print(head);
  insertAtPos(head, tail, 1, 55);
  print(head);
  insertAtPos(head, tail, 8, 79);
  print(head);

  deleteNode(head,tail, 1);
  print(head);
  deleteNode(head,tail, 5);
  print(head);
  deleteNode(head, tail, 5);
  print(head);


  return 0;
}