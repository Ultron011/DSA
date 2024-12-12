#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int value;
    Node* next;

    Node(int data) : value(data), next(nullptr) {}
};

class LinkedList {
    Node* head;
    public:
        LinkedList() : head(nullptr) {}

        void append(int value) {
            Node* newNode = new Node(value);
            if (!head) {
                head = newNode;
                return;
            }

            Node* curr = head;
            while (curr->next) curr = curr->next;
            curr->next = newNode;
        }

        void removeDuplicates() {
            if (!head || !head->next) {
                return;
            }

            Node* curr = head;
            while (curr && curr->next) {
                if (curr->value == curr->next->value) {
                    Node* temp = curr->next;
                    curr->next = curr->next->next;
                    delete temp;
                } else {
                    curr = curr->next;
                }
            }
        }


        void printValues() {
            if (!head) {
                cout << "Empty list!" << endl;
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
  list.append(2);
  list.append(2);
  list.append(3);
  list.append(3);
  list.append(3);
  list.append(3);
  list.append(4);

  list.printValues();

  list.removeDuplicates();
  list.printValues();

  return 0;
}