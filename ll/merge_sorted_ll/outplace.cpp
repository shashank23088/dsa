// T(N) = O(N1 + N2)
// S(N) = O(N1 + N2)
// outplace

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
    ListNode *p = list1; 
    ListNode *q = list2;
    ListNode *r = NULL; 
    ListNode *head3;

    while(p != NULL && q != NULL) {

        if (p -> val < q -> val) {
            ListNode *temp = new ListNode(p -> val);
            if (r == NULL) {
                r = temp;
                head3 = r;
                p = p -> next;
                continue;
            }
            r -> next = temp;
            r = r -> next;
            p = p -> next;
        }

        else {
            ListNode *temp = new ListNode(q -> val);
            if (r == NULL) {
                r = temp;
                head3 = r;
                q = q -> next;
                continue;
            }
            r -> next = temp;
            r = r -> next;
            q = q -> next;
        }

    }

    while (p != NULL) {
        ListNode *temp = new ListNode(p -> val);
        if (r == NULL) {
            r = temp;
            head3 = r;
            p = p -> next;
            continue;
        }
        r -> next = temp;
        r = r -> next;
        p = p -> next;
    }

    while (q != NULL) {
        ListNode *temp = new ListNode(q -> val);
        if (r == NULL) {
            r = temp;
            head3 = r;
            q = q -> next;
            continue;
        }
        r -> next = temp;
        r = r -> next;
        q = q -> next;
    }

    return head3;

}


int main() {
    vector<int> list1_values = {};
    vector<int> list2_values = {0};

    List list1 = List(list1_values);
    List list2 = List(list2_values);
    List list3 = List({});

    list3.head = mergeTwoLists(list1.head, list2.head);

    list1.printList();
    list2.printList();
    list3.printList();

    return 0;
}