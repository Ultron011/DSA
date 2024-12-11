#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int value;
    Node* next;
    
    Node(int data): value(data), next(nullptr) {}
};

class LinkedList {
    public:
    Node* head;
    LinkedList(): head(nullptr) {}

    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void createLoop(int pos) {
        if (pos == 0) return;
        Node* loopNode = head;
        Node* tail = head;

        for (int i = 1; i < pos && loopNode != nullptr; i++) {
            loopNode = loopNode -> next;
        }

        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = loopNode;
    }

    bool detectLoopUsingMap() {
        if (!head) {
            return false;
        }

        unordered_map<Node* , bool> visited;
        Node* curr = head;
        while (curr) {
            // cycle is present
            if (visited[curr] == true) {
                cout << "Loop Detected!" << endl;
                return true;
            }
            visited[curr] = true;
            curr = curr->next;
        }

        cout << "No Loop Detected!" << endl;
        return false;
    }

    bool detectLoopUsingSet() {
        if (!head) {
            return false;
        }

        unordered_set<Node* > seen;
        Node* curr = head;
        while (curr) {
            if (seen.find(curr) != seen.end()) {
                cout << "Loop Detected!" << endl;
                return true;
            }
            seen.insert(curr);
            curr = curr->next;
        }

        cout << "No Loop Detected!" << endl;
        return false;
    }


    void printValues() {
        if (head == nullptr) {
            cout << "Empty List!" << endl;
            return;
        }
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->value << " ";
            curr = curr->next;
        }
        cout << endl;
    }

};

int main() {

  LinkedList list;
  list.append(10);
  list.append(20);
  list.append(30);
  list.append(40);
  list.printValues();

  // Create a loop for testing
  list.createLoop(3);

  list.detectLoopUsingMap();
  list.detectLoopUsingSet();

  return 0;
}