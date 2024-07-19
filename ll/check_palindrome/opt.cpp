// T(N) : O(3N/2)
// S(N) : O(1)

#include <bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class List {
    public:

        ListNode *head = NULL;

        List (vector<int> node_values) {

            for (auto itr : node_values) {
                addNode(itr);
            }
        }

        void addNode(int x) {

            ListNode *temp = new ListNode(x);

            if (head == NULL) {
                head = temp;
                return;
            }

            ListNode* travel = head;
            while (travel -> next != NULL) {
                travel = travel -> next;
            }
            travel -> next = temp;
            return;
        }

        ListNode* reverseLL(ListNode *head) {
            ListNode *temp = NULL;
            while (head) {    // O(N/2)
                ListNode *nxt = head -> next;
                head -> next = temp;
                temp = head;
                head = nxt;
            }
            return temp;
        }

        bool isPalindrome(ListNode* head) {
            if (!head) {
                return false;
            }

            if (!head -> next) {
                return true;
            }

            ListNode *fast = head;
            ListNode *slow = head;

            while (fast && fast -> next && fast -> next -> next) {    // O(N/2)
                fast = fast -> next -> next;
                slow = slow -> next;
            }
            // now slow is in middle
            // now reverse LL from ahead of slow
            // also compare the two halves of LL for palindrome

            fast = head;    // first half starts from
            slow = reverseLL(slow -> next);    // where next half starts from 

            while (slow) {    // O(N/2)
                if (fast -> val != slow -> val) {
                    return false;
                }
                slow = slow -> next;
                fast = fast -> next;
            }

            return true;
        }

        void printList() {

            ListNode* travel = head;

            while (travel != NULL) {
                cout << travel -> val << " ";
                travel = travel -> next;
            }
            cout << endl;
        }    
};


int main() {
    vector<int> node_values = {1, 2, 2, 1};
    List list1(node_values);
    list1.printList();

    cout << list1.isPalindrome(list1.head) << endl;

    return 0;
}