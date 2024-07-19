// T(N) : O(N) + O(N)
// S(N) : O(N)

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

        bool isPalindrome(ListNode* head) {
            if (!head) {
                return false;
            }

            if (!head -> next) {
                return true;
            }

            vector<int> list_values;
            while (head) {
                list_values.emplace_back(head -> val);
                head = head -> next;
            }

            int n = list_values.size();
            for (int i = 0; i < n; i++) {
                if (list_values[i] != list_values[n - 1 - i]) {
                    return false;
                }
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