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

int len(node* head){
    int c=0;
    while(head){
        head=head->next;
        c++;
    }
    return c;
}

node* swapNodes(node* head, int k) {
    node* s1;
    node* s2;
    node* temp=head;
    int n=len(head);
    for(int i = 1;i<=n;i++){
        if(i==k) s1=temp;
        if(i==n-k+1) s2=temp;
        temp=temp->next;
    }
    int tmp=s1->data;
    s1->data=s2->data;
    s2->data=tmp;
    return head;
}

int main() {
    int n,k;
    cin>>n;
    LL x;
    for(int i=0;i<n;i++){
        int q;
        cin>>q;
        x.pb(q);
    }
    cin>>k;
    x.head=swapNodes(x.head,k);
    x.disp();
    
return 0;
}