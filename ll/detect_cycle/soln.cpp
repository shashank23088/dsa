// brute soln: hash-table, keep track of visited nodes and check at each iteration: T(N), S(N) = O(N)
// opt: T(N), S(N) : O(N), O(1)
// intution: if no cycle, slow ptr can't catch fast ptr, if cycle, there will be a point when slow = fast.

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

        bool hasCycle(ListNode *head) {
            if (!head) {
                return false;
            }

            ListNode *slow = head;
            ListNode *fast = head;

            while (slow && fast && fast -> next) {
                slow = slow -> next;
                fast = fast -> next -> next;
                if (slow == fast) {
                    return true;
                }
            }

            return false;
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
    p -> next = list1.head;

    cout << list1.hasCycle(list1.head) << endl;

    return 0;
}