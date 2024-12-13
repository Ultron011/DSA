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
    LinkedList(): head(nullptr) {}

    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }

        Node* tail = head;
        while (tail->next) tail = tail->next;
        tail->next = newNode;
    }

    void reverse() {
        if (!head || !head->next) {
            return;
        }

        Node* curr = head;
        Node* prev = nullptr;
        Node* nextNode = nullptr;
        while (curr) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        head = prev;
    }

    /* 
        Time complexity - 
            O(m + n)
        
        Space commpleixty - 
            O(max(m, n))
    */

    static LinkedList addLists(LinkedList& first, LinkedList& second) {
        /* Reverse both lists */
        first.reverse();
        second.reverse();

        LinkedList result;
        /* Add both lists */
        int carry = 0;
        Node* curr1 = first.head;
        Node* curr2 = second.head;

        while (curr1 || curr2 || carry) {
            int sum = carry;
            if (curr1) sum += curr1->value;
            if (curr2) sum += curr2->value;

            int digit = sum % 10;
            result.append(digit);
            carry = carry / 10;


            if (curr1) curr1 = curr1->next;
            if (curr2) curr2 = curr2->next;
        }


        /* Reverse the ans list */
        first.reverse();
        second.reverse();

        result.reverse();
        return result;
    }    

    void printValues() {
        if (!head) {
            cout << "Empty List !" << endl;
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

    LinkedList list1;
    list1.append(3);
    list1.append(4);
    list1.append(0);

    LinkedList list2;
    list2.append(4);
    list2.append(2);

    cout << "List 1: ";
    list1.printValues();

    cout << "List 2: ";
    list2.printValues();

    LinkedList result = LinkedList::addLists(list1, list2);

    cout << "Result: ";
    result.printValues();
  

  return 0;
}