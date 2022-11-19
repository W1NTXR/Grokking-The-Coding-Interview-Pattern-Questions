#include<iostream>
using namespace std;

struct node {
    int data;
    node* next;

    node(int x) : data(x), next(NULL){}
    

    
};
void pb(int x, node *head) {
        if(head==NULL) {new node(x); return;}
        node* h = new node(x);
        node* t = h;
        while(t != NULL) {
            t = head->next;
        }
        t -> next = h;
    }
void disp(node *head) {
        node* t = head;
        while(t != NULL) {
            cout << t << " ";
            t = t->next;
        }
    }

bool hasCycle(node *head){
    return false;
}

int main(){
    int n;
    node *x;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        int l;
        cin >> l;
        pb(l, x);
    }

    disp(x);
}