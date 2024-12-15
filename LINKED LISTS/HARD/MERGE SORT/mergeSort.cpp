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

    void append(int value) {
        Node* newNode = new Node(value);
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

    Node* getMid(Node* head) {
        Node* fast = head->next;
        Node* slow = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node* merge(Node* left, Node* right) {
        if (!left) return right;
        if (!right) return left;

        Node* dummy = new Node(-1); // Dummy node
        Node* temp = dummy;

        while (left && right) {
            if (left->value < right->value) {
                temp->next = left;
                temp = left;
                left = left->next;
            } else {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }

        while (left) {
            temp->next = left;
            temp = left;
            left = left->next; 
        }
        while (right) {
            temp->next = right;
            temp = right; 
            right = right->next; 
        }

        Node* result = dummy->next;
        delete dummy; // Delete the dummy node
        return result;
    }

    Node* mergeSort(Node* head) {
        if (!head || !head->next) return head;

        Node* mid = getMid(head);

        Node* left = head;
        Node* right = mid->next;
        mid->next = nullptr;

        left = mergeSort(left);
        right = mergeSort(right);

        return merge(left, right);
    }

    void printValues() {
        if (!head) {
            cout << "Empty Linked List!" << endl;
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
    list.append(5);
    list.append(45);
    list.append(12);
    list.append(36);
    list.append(1);
    list.append(15);
    list.append(49);

    cout << "Original List:" << endl;
    list.printValues();

    list.head = list.mergeSort(list.head);

    cout << "Sorted List:" << endl;
    list.printValues();

    return 0;
}
