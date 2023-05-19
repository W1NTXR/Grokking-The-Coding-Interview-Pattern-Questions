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

node* swapPairs(node* head){
    if(!head) return head;
    if(!head->next) return head;
    node* dum = new node(0);
    node* pre=dum;
    node* cur=head;
    while(cur && cur->next){
        pre->next=cur->next;
        cur->next=pre->next->next;
        pre->next->next=cur;

        pre=cur;
        cur=cur->next;
    }

    return dum->next;   
}

node* swapPairsrec(node* head){
    if(!head || !head->next) return head;
    node* s;
    s=head->next;
    head->next=swapPairsrec(head->next->next);
    s->next=head;

    return s;
}

int main() {
    int n;
    cin>>n;
    LL x;
    for(int i = 0; i <n;i++) {
        int t;
        cin >> t;
        x.pb(t);
    }
    x.head=swapPairs(x.head);
    x.disp();
    return 0;
}