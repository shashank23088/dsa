// T(N) = O(M + N)
// S(N) = O(1)

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

        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            if (!headA || !headB) {
                return NULL;
            }

            ListNode *p = headA;
            ListNode *q = headB;

            while (p != q) {
                p = (p == NULL) ? headB : p -> next;
                q = (q == NULL) ? headA : q -> next;
            }

            return p;
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
    vector<int> node_values1 = {2, 3};
    vector<int> node_values2 = {3};

    int m = 1; 
    int n = 0;

    List list1(node_values1);
    list1.printList();
    List list2(node_values2);
    list2.printList();

    ListNode *temp1 = list1.head;
    ListNode *temp2 = list2.head;

    if (m == 0 && n != 0) {
        while (n-- - 1) {
            temp2 = temp2 -> next;
        }
        temp2 -> next = temp1;
    }

    else {
        while (n--) {
            temp2 = temp2 -> next;
        }

        while (m-- - 1) {
            temp1 = temp1 -> next;
        }
        temp1 -> next = temp2;
    }
    // successfully merged both the lists

    cout << list1.getIntersectionNode(list1.head, list2.head) -> val << endl;

    return 0;
}