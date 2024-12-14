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

    Node* solve(Node* first, Node* second) {
        Node* curr1 = first;
        Node* curr2 = second;

        // Traverse both lists and merge them
        while (curr1 && curr2) {
            if (!curr1->next || (curr2->value >= curr1->value && curr2->value <= curr1->next->value)) {
                Node* temp = curr2->next; // Store next of curr2
                curr2->next = curr1->next; // Link curr2 to curr1's next
                curr1->next = curr2; // Link curr1 to curr2
                curr2 = temp; // Move curr2 forward
            } else {
                curr1 = curr1->next; // Move curr1 forward
            }
        }

        // If there are remaining nodes in second, append them
        if (curr2) {
            curr1->next = curr2;
        }

        return first;
    }

    Node* mergeSortedLists(Node* first, Node* second) {
        if (!first) return second;
        if (!second) return first;

        if (first->value < second->value) {
            return solve(first, second);
        } else {
            return solve(second, first);
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
    LinkedList list1, list2;

    // Populate the first sorted linked list
    list1.append(1);
    list1.append(4);
    list1.append(5);

    // Populate the second sorted linked list
    list2.append(2);
    list2.append(3);
    list2.append(5);

    // Merge the two sorted lists
    LinkedList result;
    result.head = result.mergeSortedLists(list1.head, list2.head);

    // Print the merged sorted list
    cout << "Merged Sorted List: ";
    result.printValues();

    return 0;
}
