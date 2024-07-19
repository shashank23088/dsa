// brute: hash-map to store nodes, return first node which traversed twice: T(N), S(N): O(N) 
// T(N) : O(N)
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

        ListNode *detectCycle(ListNode *head) {
            if (!head || !head -> next) {
                return NULL;
            }

            ListNode *slow = head;
            ListNode *fast = head;

            do {
                if (!fast || !fast -> next) {
                    return NULL;
                }
                
                fast = fast -> next -> next;
                slow = slow -> next;

            } while (slow != fast);    // finding first collision, moving both ptrs at diff pace

            fast = head;
            while (slow != fast) {    // finding second collision, moving both ptrs at same pace
                slow = slow -> next;
                fast = fast -> next;
            }

            return fast;
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
    vector<int> node_values = {1, 2, 3, 4, 5};
    List list1(node_values);
    list1.printList();

    ListNode *p = list1.head;
    while (p -> next) {
        p = p -> next;
    }
    p -> next = list1.head -> next;

    ListNode *start = list1.detectCycle(list1.head);
    int result;
    if (!start) {
        result = -1;
    }
    else {
        result = start -> val;
    }
    cout << result << endl;

    return 0;
}