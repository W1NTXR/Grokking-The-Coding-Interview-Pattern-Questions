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

struct check{
    bool operator()(node* x, node* y){return x->data>y->data;}          // we created this struct check for the min heap
};                                                                      // this will be the condition that our priority queue            
                                                                        //will use to decide which is the smaller one
node* mergeKLists(vector<node*> lists){
    priority_queue<node*, vector<node*>, check> minh;               //we create a min heap to solve this question
    for(auto i: lists) minh.push(i);                            //initially we push all the root nodes into the heap
    node *resHead = NULL;       //this will be the head of our final list
    node *resTail = NULL;   //notice how we did node *resTail instead of node* resHead because if we didnt then it would throw us an error at line 46
    while(!minh.empty()){   // now we will keep putting the elements in the result list until our minHeap or priority queue is empty
        node* p = minh.top();   // we will store the top element because it will be the smallest
        minh.pop(); // we will then pop the element from the minHeap
        if(resHead == NULL) resHead = resTail = p;  //this is if our final lists are empty then the new node will be the both tail and head
        else {
            resTail->next=p;    //if they arent then we will simply add this node next to tail
            resTail = resTail->next;    // and update the tail
        }
        if(p->next != NULL) minh.push(p->next); //now if there is another element in the list since initially we pushed
    }   //only root nodes in the queue we will push it into the minHeap
    return resHead; // we will return the head of our final linked list

}

int main() {
    
    LL x;
    LL y;
    LL z;
    x.pb(1);
    x.pb(5);
    x.pb(8);
    y.pb(4);
    y.pb(7);
    y.pb(8);
    z.pb(2);
    z.pb(5);
    z.pb(11);

    LL ans;
    vector<node*> t;
    t.push_back(x.head);
    t.push_back(y.head);
    t.push_back(z.head);
    ans.head=mergeKLists(t);
    ans.disp();
    return 0;

    return 0;
}