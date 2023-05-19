/*
Leetcode Link: https://leetcode.com/problems/reverse-linked-list-ii/
Problem Description: Given the head of a singly linked list and two integers left and right where left <= right,
reverse the nodes of the list from position left to position right, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:
Input: head = [5], left = 1, right = 1
Output: [5]

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n

*/

#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;
    node(int x): data(x), next(NULL){}
};
struct LL{
    node* head;
    public:
    LL(): head(NULL) {}
    void pb(int data) {
        node* nnode = new node(data);
        if(head == NULL) {
            head = nnode;
            return;
        }
        node* t = head;
        while(t->next != NULL) {
            t = t->next;
        }
        t->next = nnode;
    }
    void disp() {
        node* t = head;
        while(t != NULL) {
            cout<< t->data<<' ';
            t = t->next;
        }
    }
};
//similar to reverse normally
//nex = head->next;
//head->next=pre
//pre=head
//head=next
//just in ths case 
node* revInRange(node* head, int l, int r){
    node* cur=head;
    node* pre=NULL;
    int i = 1;
    for(i = 1; i<l;i++){
        pre=cur;
        cur=cur->next;
    }

    node* rtail=cur;
    node* rhead=NULL;
    while(i<=r) {
        node* nex = cur->next;
        cur->next=rhead;
        rhead = cur;
        cur=nex;
        i++;
    }

    if(pre != NULL){
        pre->next=rhead;
    }
    else head=rhead;

    rtail->next=cur;

    return head;

}

void disp(node* head){
    while(head!=NULL){
        cout<<head->data<<' ';
        head=head->next;
    }
    cout<<'\n';
}

int main() {

    int n;
    cin>>n;
    LL p;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        p.pb(t);
    }

    int l,r;
    cin>>l>>r;
    // p.head=revInRange(p.head,l,r);
    // p.disp();
    disp(revInRange(p.head,l,r));

    return 0;
}