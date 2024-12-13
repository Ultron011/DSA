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
            while (curr->next) {
                curr = curr->next;
            }
            curr->next = newNode;
        }

        /*
            Time complexity - 
                O(n)

            Space complexity - 
                O(n)
        */

        bool isPalindrome(vector<int> arr) {
            int s= 0, e= arr.size() - 1;
            while (s <= e) {
                if (arr[s] != arr[e]) {
                    return false;
                }
                s++;
                e--;
            }
        }

        void palindromeList() {
            vector<int> arr;
            Node* curr = head;
            while (curr) {
                arr.push_back(curr->value);
                curr = curr->next;
            }

            if (isPalindrome(arr)) {
                cout << "It is a Palindrome Linked List" << endl;
            } else {
                cout << "It is not a Palindrome Linked List" << endl;
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

  LinkedList list;
  list.append(10);
  list.append(20);
  list.append(30);
  list.append(20);
  list.append(10);

  list.printValues();
  list.palindromeList();

  return 0;
}