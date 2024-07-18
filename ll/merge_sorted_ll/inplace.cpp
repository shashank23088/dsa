// T(N) = O(N1 + N2)
// S(N) = O(1)
// inplace

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


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }

    ListNode *p;
    ListNode *q;
    ListNode *head;

    if (list1 -> val < list2 -> val) {
        p = list1;
        q = list2;
        head = list1;
    }
    else {
        p = list2;
        q = list1;
        head = list2;
    }

    ListNode *temp = p;    // temp stores latest value less than q
    p = p -> next;
    while (p != NULL) {
        if (p -> val > q -> val) {
            temp -> next = q;
            swap(p, q);
        }
        temp = p;
        p = p -> next;
    }
    temp -> next = q;

    return head;

}


int main() {
    vector<int> list1_values = {1, 2, 4};
    vector<int> list2_values = {1, 3, 4};

    List list1 = List(list1_values);
    List list2 = List(list2_values);

    list1.printList();
    list2.printList();

    list2.head = mergeTwoLists(list1.head, list2.head);

    list2.printList();

    return 0;
}