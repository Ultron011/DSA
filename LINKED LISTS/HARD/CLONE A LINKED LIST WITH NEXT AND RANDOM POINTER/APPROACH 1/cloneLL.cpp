#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int value;
        Node* next;
        Node* random;

        Node(int d) : value(d), next(nullptr), random(nullptr) {}
};

/* 
    Time complexity - O(n)
    Space complexity - O(n)

*/
class LinkedList {
    public:
        Node* head;
        LinkedList() : head(nullptr) {}

        // Modify append function to pass head and tail by reference
        void append(Node*& head, Node*& tail, int d) {
            Node* newNode = new Node(d);
            if (!head) {
                head = newNode;
                tail = newNode;
                return;
            }
            tail->next = newNode;
            tail = newNode;
        }

        // Clone the list and maintain the random pointers
        Node* cloneList(Node* head) {
            if (!head) return nullptr;  // Edge case for empty list

            Node* cloneHead = nullptr;
            Node* cloneTail = nullptr;

            // Step 1: Create a clone list by copying the values
            Node* curr = head;
            while (curr) {
                append(cloneHead, cloneTail, curr->value);
                curr = curr->next;
            }

            // Step 2: Create a map to store original node to clone node mapping
            unordered_map<Node*, Node*> oldToNewNode;
            Node* originalNode = head;
            Node* cloneNode = cloneHead;
            while (originalNode && cloneNode) {
                oldToNewNode[originalNode] = cloneNode;
                originalNode = originalNode->next;
                cloneNode = cloneNode->next;
            }

            // Step 3: Set the random pointers in the cloned list
            originalNode = head;
            cloneNode = cloneHead;
            while (originalNode) {
                if (originalNode->random) {
                    cloneNode->random = oldToNewNode[originalNode->random];
                }
                cloneNode = cloneNode->next;
                originalNode = originalNode->next;
            }

            return cloneHead;
        }

        // Utility function to print the list (including random pointers if necessary)
        void printValues(Node* head) {
            if (!head) {
                cout << "Empty Linked list!" << endl;
                return;
            }

            Node* curr = head;
            while (curr) {
                cout << "Value: " << curr->value;
                if (curr->random) {
                    cout << ", Random: " << curr->random->value;
                } else {
                    cout << ", Random: nullptr";
                }
                cout << endl;
                curr = curr->next;
            }
        }
};

int main() {

    LinkedList list;
    list.head = new Node(1);
    list.head->next = new Node(2);
    list.head->next->next = new Node(3);
    list.head->next->next->next = new Node(4);
    list.head->next->next->next->next = new Node(5);
    list.head->next->next->next->next->next = nullptr;

    list.head->random = list.head->next->next;
    list.head->next->random = list.head;
    list.head->next->next->random = list.head->next->next->next->next;
    list.head->next->next->next->random = list.head->next->next;
    list.head->next->next->next->next->random = list.head->next;

    cout << "Original List:" << endl;
    list.printValues(list.head);

    // Clone the list
    LinkedList clone;
    clone.head = list.cloneList(list.head);

    cout << "\nCloned List:" << endl;
    clone.printValues(clone.head);

    return 0;
}
