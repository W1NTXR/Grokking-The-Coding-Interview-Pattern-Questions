#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node* next;
    node(int x): data(x), next(NULL){}
};

struct LL{
    public:
    node* head;
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

int len(node* head) {
    int c=0;
    
    while(head!=NULL){
        head=head->next;
        c++;
    }
    
    return c;
}



node* revKNodes(node* &head, int k) {
    int n = len(head);
    node* dum=new node(0);

    dum->next=head;
    node* pre=dum;
    node* cur;
    node* nex;
    
    while(n>=k){
        cur=pre->next;
        nex=cur->next;
        for(int i =1; i < k; i++) {
            cur->next=nex->next;
            nex->next=pre->next;
            pre->next=nex;
            nex=cur->next;
        }
        pre=cur;
        n-=k;
    }
    return dum->next;
}
int main() {
int n;
cin>>n;
LL x;
for(int i =0; i<n;i++) {
    int t;
    cin >> t;
    x.pb(t);
}


int k;
cin >> k;

LL y;
y.head=revKNodes(x.head,k);
y.disp();
return 0;
}