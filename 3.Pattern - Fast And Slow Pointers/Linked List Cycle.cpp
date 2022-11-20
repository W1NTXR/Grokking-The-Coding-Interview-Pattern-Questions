/*
Leetcode link: https://leetcode.com/problems/linked-list-cycle/
Problem Description: 
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Example 3:
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
*/
#include<iostream>
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
            cout << t->data << " ";
            t = t->next;
        }
    }
};

bool hasCycle(ListNode *head){
if(head == NULL) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL) {
            
            slow=slow->next;
            fast=fast->next->next;
            if(slow == fast) return true;
        }

        return false;
}

int main(){
    int n;
    LL x;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        int l;
        cin >> l;
        x.pb(l);
    }

    return 0;
}