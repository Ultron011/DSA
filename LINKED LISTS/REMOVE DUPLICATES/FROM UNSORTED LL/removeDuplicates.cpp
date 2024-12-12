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

        /*
            Time complexity - 
                O(n)
            Space complexity-
                O(n)
        */

        void removeDuplicates() {
            if (!head || !head->next) {
                return;
            }

            unordered_set<int> seen;
            Node* curr = head;
            seen.insert(curr->value);

            while (curr->next) {
                if (seen.find(curr->next->value) != seen.end()) {
                    Node* temp = curr->next;
                    curr->next = curr->next->next;
                    delete temp;
                } else{
                    seen.insert(curr->next->value);
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
  list.append(4);
  list.append(2);
  list.append(5);
  list.append(4);
  list.append(2);
  list.append(2);

  list.printValues();
  list.removeDuplicates();
  list.printValues();


  return 0;
}