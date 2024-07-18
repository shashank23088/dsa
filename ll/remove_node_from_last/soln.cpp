// T(N) = O(N / 2)
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

        void removeNthFromEnd(int n) {
            ListNode *p = head; 
            ListNode *q = head;

            int i = 1;
            int count = 0;
            while (q != NULL) {
                q = q -> next;
                count++;
            }

            if (count == 1) {
                return;
            }

            if (count == n) {
                head = head -> next;
                p -> next = NULL;
                return;
            }

            q = head;
            p = head;
            while (i < (count - n) + 1) {
                p = q;
                q = q -> next;
                i++;
            }

            if (q -> next != NULL) {
                p -> next = q -> next;
                q -> next = NULL;
            }
            else {
                p -> next = NULL;
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