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
            if (!head) {
                return head;
            }

            // step 1 - create a clone list
            Node* cloneHead = nullptr;
            Node* cloneTail = nullptr;
            Node* temp = head;
            while (temp) {
                append(cloneHead, cloneTail, temp->value);
                temp = temp->next;
            }

            // step 2 - Add clone nodes in between original list
            Node* originalNode = head;
            Node* cloneNode = cloneHead;
            while (originalNode && cloneNode) {
                Node* next = originalNode->next;
                originalNode->next = cloneNode;
                originalNode = next;

                next = cloneNode->next;
                cloneNode->next = originalNode;
                cloneNode = next;
            }

            // step 3 - Copy random pointers
            Node* curr = head;
            while (curr) {
                if (curr->next) {
                    curr->next->random = curr->random ? curr->random->next : curr->random;
                }
                curr = curr->next->next;
            }

            // step 4 - Revert back the changes made in step 2
            originalNode = head;
            cloneNode = cloneHead;
            while (originalNode && cloneNode) {
                originalNode->next = cloneNode->next;
                originalNode = originalNode->next;
                
                if (originalNode) {
                    cloneNode->next = originalNode->next;
                }
                cloneNode = cloneNode->next;
            }

            // step 5 - return ans
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
