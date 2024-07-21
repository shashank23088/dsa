// T(N) : O(N) + O(N - (N % K)) = O(N)
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

        ListNode* rotateRight(ListNode* head, int k) {

            if (!head || !head -> next || !k) {
                return head;
            }

            int len = 1;
            ListNode *p = head;

            while (p -> next) {    // O(N)
                p = p -> next;
                len++;
            }

            k = k % len;
            p -> next = head;
            p = head;
            k = len - k;

            while(--k) {
                p = p -> next;
            }

            head = p -> next;
            p -> next = NULL;

            return head;

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
    int k = 2;
    List list1(node_values);
    list1.printList();

    list1.head = list1.rotateRight(list1.head, k);
    list1.printList();

    return 0;
}