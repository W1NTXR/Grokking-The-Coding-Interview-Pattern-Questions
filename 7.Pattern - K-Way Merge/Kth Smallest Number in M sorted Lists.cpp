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


int KthSmallNumberInLists(vector<LL> lists, int k){
    priority_queue<int, vector<int>, greater<int>> minH;
    for(auto i: lists) {
        node* t = i.head;
        while(t) {
            minH.push(t->data);
            t=t->next;
        }
    }
    while(--k) minH.pop();
    
    return minH.top();
}

int main() {

    LL x;
    LL y;
    LL z;
    x.pb(1);
    x.pb(4);
    x.pb(5);
    y.pb(4);
    y.pb(7);
    y.pb(8);
    z.pb(2);
    z.pb(6);
    z.pb(9);
    vector<LL> q({x,y,z});

    cout << KthSmallNumberInLists(q,1);

    return 0;
}