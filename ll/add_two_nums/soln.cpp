// T(N) = O(max(N1, N2))
// S(N) = O(max(N1, N2))

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

        void printList() {

            ListNode* travel = head;
            while (travel != NULL) {
                cout << travel -> val << " ";
                travel = travel -> next;
            }
            cout << endl;
        }    
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *head = new ListNode();
    ListNode *temp = head;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = 0;

        if (l1) {
            sum += l1 -> val;
            l1 = l1 -> next;
        }

        if (l2) {
            sum += l2 -> val;
            l2 = l2 -> next;
        }

        if (carry) {
            sum += carry;
            carry = 0;
        }

        ListNode *dummy;

        if (sum >= 10) {
            carry = sum / 10;
            dummy = new ListNode(sum % 10);
        }
        else {
            dummy = new ListNode(sum);
        }

        temp -> next = dummy;
        temp = temp -> next;
    }

    head = head -> next;
    return head;
}


int main() {
    vector<int> node_values1 = {2, 4, 3};
    vector<int> node_values2 = {5, 6, 7, 9};
    List list1(node_values1);
    list1.printList();
    List list2(node_values2);
    list2.printList();
    List list3({});
    list3.head = addTwoNumbers(list1.head, list2.head);
    list3.printList();

    return 0;
}