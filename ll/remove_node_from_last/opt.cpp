// T(N) = O(N)
// S(N) = O(1)

#include <bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}    // dummy node
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

        void removeNthFromEnd(int n) {
            ListNode *temp = new ListNode();
            temp -> next = head;
            ListNode *fast = temp;
            ListNode *slow = temp;

            for (int i = 0; i < n; i++) {
                fast = fast -> next;
            }    // now fast has travelled till n, so slow will travel N - n, that what was required

            while (fast -> next != NULL) {    
                slow = slow -> next;
                fast = fast -> next;
            }

            if (slow == temp) {
                head = head -> next;
                slow -> next -> next = NULL;
                slow -> next = NULL;
            }

            else {
                ListNode *dummy = slow -> next;
                slow -> next = slow -> next -> next;
                dummy -> next = NULL;
            }

            return;
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
    int n = 2;

    List list1(node_values);
    list1.printList();
    list1.removeNthFromEnd(n);
    list1.printList();

    return 0;
}