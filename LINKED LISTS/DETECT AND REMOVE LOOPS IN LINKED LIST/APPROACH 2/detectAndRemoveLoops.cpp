/* FLOYD'S CYCLE DETECTION */

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

    void floydCycleDetectAndRemove() {
        if (!head || !head->next) {
            return;
        }

        Node* slow = head;
        Node* fast = head;

        // Detect loop using Floyd's Cycle Detection
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                cout << "Loop Detected!" << endl;
                break;
            }
        }

        // If no loop was detected, return
        if (slow != fast) {
            cout << "No Loop Detected!" << endl;
            return;
        }

        // Find where the loop starts
        slow = head;
        if (slow == fast) {
            cout << "Loop starts at node : " << slow->value << endl;
            while (fast->next != slow) fast = fast->next;
        } else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
            cout << "Loop starts at node : " << slow->next->value << endl;
        }


        // Break the loop
        fast->next = nullptr;
        cout << "Loop Removed" << endl;
        
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

  list.floydCycleDetectAndRemove();
  list.printValues();

  return 0;
}