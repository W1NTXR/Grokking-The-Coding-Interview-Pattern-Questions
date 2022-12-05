#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

struct LL{
    ListNode* head;
    public:
    LL(): head(NULL) {}
    void pb(int val) {
        ListNode* nnode = new ListNode(val);
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
            cout<< t->val<< " ";
            t = t->next;
        }
    }
};

ListNode* revLL(ListNode* head){
    ListNode* pre=NULL;
    ListNode* nex=NULL;        
    while(head){
        nex=head->next;
        head->next=pre;
        pre=head;
        head=nex;
    }        
    return pre;
}

bool isPalindrome(ListNode* head) {
    ListNode* f=head;
    ListNode* mid=head;
    ListNode* s=head;
    while(f->next&&f->next->next){
        mid=mid->next;
        f=f->next->next;
    }
    mid->next=revLL(mid->next);
    mid=mid->next;
    while(mid){
        if(s->val!=mid->val) return false;
        s=s->next;
        mid=mid->next;
    }
    return true;        
}

int main() {
    int N;
    cin >> N;
    LL t;
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        t.pb(x);
    }

    cout << isPalindrome(t.head);
    return 0;
}