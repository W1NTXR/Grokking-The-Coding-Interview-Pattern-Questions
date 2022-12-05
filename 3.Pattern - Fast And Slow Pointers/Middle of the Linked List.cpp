/*
Leetcode Link: https://leetcode.com/problems/middle-of-the-linked-list/description/
Problem Description:
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.
Example 1:
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
Example 2:
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
Constraints:

The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100

*/
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int x): data(x), next(NULL){}
};

struct LL{
    ListNode* head;
    public:
    LL(): head(NULL) {}
    void pb(int data) {
        ListNode* nnode = new ListNode(data);
        if(head == NULL) {
            head = nnode;
            return;
        }

        ListNode* t = head;
        while(t->next != NULL) {
            t = t->next;
        }

        t->next = nnode;    
    }

    void disp() {
        ListNode* t = head;
        while(t != NULL) {
            cout<< t->data<< " ";
            t = t->next;
        }
    }
};

ListNode* middleNode(ListNode* head){
    ListNode* f=head;
    ListNode* s=head;
    while(f && f->next){
        f=f->next->next;
        s=s->next;
    }

    return s;
}

int main(){
    int x;
    cin >> x;
    LL r;
    for(int i = 0; i<x; i++) {
        int q;
        cin >> q;
        r.pb(q);
    }
    cout << middleNode(r.head)->data;

    return 0;
}