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
                O(1)
        */

       Node* getMid() {
            Node* slow = head;
            Node* fast = head;
            while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
       }

       Node* reverse(Node* head) {
            Node* curr = head;
            Node* prev = nullptr;

            while (curr) {
                Node* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }
            return prev;
       }

        bool palindromeList() {
            if (!head || !head->next) {
                return false;
            }  

            /* Step 1 : Find middle */
            Node* middle = getMid();

            /* Step 2 : Reverse after middle */
            Node* temp = middle -> next;
            middle->next = reverse(temp);

            /* Step 3 - Compare both halfs */
            Node* start1 = head;
            Node* start2 = middle->next;
            bool ans = true;
            while (start2) {
                if (start1->value != start2->value) {
                    ans = false;
                    break;
                }
                start1 = start1->next;
                start2 = start2->next;
            }

            /* Step 4 - Reverse after middle again to get original list */
            temp = middle->next;
            middle->next = reverse(temp);        

            return ans;    
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
  if (list.palindromeList()) {
    cout << "It is a palindrome list" << endl;
  } else {
    cout << "It is not a palindrome list" << endl;
  }

  list.printValues();

  return 0;
}