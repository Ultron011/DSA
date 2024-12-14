#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int value;
    Node* next;
    Node(int d): value(d), next(nullptr) {}
};

class LinkedList{
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

    void sort() {
        if (!head || !head->next) {
            return;
        } 

        int cntZero = 0, cntOne = 0, cntTwo = 0;
        Node* curr = head;
        while (curr) {
            if (curr->value == 0) cntZero++;
            else if (curr->value == 1) cntOne++;
            else cntTwo++;
            curr = curr->next;
        }

        curr = head;
        while (curr) {
            if (cntZero > 0) {
                curr->value = 0;
                cntZero--;
            }
            else if (cntOne > 0) {
                curr->value = 1;
                cntOne--;
            }
            else {
                curr->value = 2;
                cntTwo--;
            }
            curr = curr->next;
        }
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

  list.printValues();
  list.sort();

  list.printValues();
  

  return 0;
}