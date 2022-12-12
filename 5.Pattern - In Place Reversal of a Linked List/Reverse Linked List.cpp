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
            cout<< t->data<< " ";
            t = t->next;
        }
    }
};

void disp(node* head) {
    node* t = head;
    while(t != NULL) {
        cout<< t->data<< " ";
        t = t->next;
    }
}

node* revList(node* head){
    node* prev=NULL;
    node* nex=NULL;
    while(head != NULL) {
        nex=head->next;
        head->next=prev;
        prev=head;
        head=nex;
    }

    return prev;
}

int main() {
    LL x;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        x.pb(t);
    }
    disp(revList(x.head));

    return 0;
}