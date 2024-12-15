#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* down;

    Node(int val) : value(val), next(nullptr), down(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    // Merge two sorted linked lists
    Node* merge(Node* left, Node* right) {
        if (!left) return right;
        if (!right) return left;

        Node* result = nullptr;

        // Initialize result to the smaller node
        if (left->value < right->value) {
            result = left;
            result->down = merge(left->down, right);
        } else {
            result = right;
            result->down = merge(left, right->down);
        }
        return result;
    }

    // Flatten the linked list
    Node* flatten(Node* head) {
        if (!head || !head->next) {
            return head;
        }

        head->next = flatten(head->next);

        head = merge(head, head->next);
        return head;
    }

    // Utility function to print the list
    void printFlattenedList(Node* head) {
        Node* temp = head;
        while (temp) {
            cout << temp->value << " ";
            temp = temp->down;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    // Creating the linked list
    list.head = new Node(5);
    list.head->down = new Node(7);
    list.head->down->down = new Node(8);
    list.head->down->down->down = new Node(30);

    list.head->next = new Node(10);
    list.head->next->down = new Node(20);

    list.head->next->next = new Node(19);
    list.head->next->next->down = new Node(22);
    list.head->next->next->down->down = new Node(50);

    list.head->next->next->next = new Node(28);
    list.head->next->next->next->down = new Node(35);
    list.head->next->next->next->down->down = new Node(40);
    list.head->next->next->next->down->down->down = new Node(45);

    // Flatten the list
    Node* flattenedHead = list.flatten(list.head);

    // Print the flattened list
    list.printFlattenedList(flattenedHead);

    return 0;
}
