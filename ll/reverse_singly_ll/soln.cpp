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

        void reverseList() {
            ListNode *temp = NULL;
            
            while (head != NULL) {
                ListNode *nxt = head -> next;
                head -> next = temp;
                temp = head;
                head = nxt;
            }
            head = temp;

            return;
        }

        void printList() {

            ListNode* travel = head;
            cout << "[ ";
            while (travel != NULL) {
                cout << travel -> val << ", ";
                travel = travel -> next;
            }
            cout << " ]" << endl;
        }    
};


int main() {
    vector<int> node_values = {1, 2, 3, 4, 5};
    List list1(node_values);
    cout << "original list: ";
    list1.printList();
    list1.reverseList();
    cout << "reversed list: ";
    list1.printList();

    return 0;
}