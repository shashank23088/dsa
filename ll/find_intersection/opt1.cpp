// T(N) = O(M) + O(N) + O(max(M, N))
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
            int len1 = 0;
            int len2 = 0;

            while (p) {
                p = p -> next;
                len1++;
            }

            while (q) {
                q = q -> next;
                len2++;
            }

            p = headA;
            q = headB;
            int diff = len1 - len2;

            if (diff > 0) {
                while (diff--) {
                    p = p -> next;
                }
            }

            else if (diff < 0) {
                diff = -diff;
                while (diff--) {
                    q = q -> next;
                }
            }

            while (p && q) {
                if (p == q) {
                    return p;
                }

                p = p -> next;
                q = q -> next;
            }

            return NULL;
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
    vector<int> node_values1 = {4, 1, 8, 4, 5};
    vector<int> node_values2 = {5, 6, 1, 8, 4, 5};

    int m = 2; 
    int n = 3;

    List list1(node_values1);
    list1.printList();
    List list2(node_values2);
    list2.printList();

    ListNode *temp1 = list1.head;
    ListNode *temp2 = list2.head;

    while (n--) {
        temp2 = temp2 -> next;
    }

    while (m-- - 1) {
        temp1 = temp1 -> next;
    }

    temp1 -> next = temp2;
    // successfully merged both the lists

    cout << list1.getIntersectionNode(list1.head, list2.head) -> val << endl;

    return 0;
}