// T(N) = O(N) + O(N / 2)
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

        int middleNode() {
            ListNode *p = head;
            ListNode *q = head;
            int ll_size = 1; 
            int middle_node_idx = 1;

            while (q -> next != NULL) {
                ll_size++;
                q = q -> next;
            }

            while (middle_node_idx < ceil( (ll_size + 1) / 2.0 )) {
                middle_node_idx++;
                p = p -> next;
            }

            return p -> val;

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
    vector<int> node_values = {1, 2, 3, 4, 5, 6};
    List list1(node_values);
    list1.printList();
    cout << list1.middleNode() << endl;

    return 0;
}