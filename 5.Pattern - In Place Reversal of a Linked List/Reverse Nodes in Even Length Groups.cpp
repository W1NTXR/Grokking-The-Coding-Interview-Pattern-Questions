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

node* revList(node* head){
    if(!head) return head;
    node* pre=NULL;
    while(head){
        node* temp=head->next;
        head->next=pre;
        pre=head;
        head=temp;
    }

    return pre;
}

node* reverseEvenLengthGroups(node* head){
   node* dum= new node(0);
   dum->next=head;//for preserving the head
   node* pre=dum;//will point to the previous node before the to be reversed node
   for(int i = 1; head; i++){ //i will keep track of the length of the groups
        node* tail=head;    //tail will point to the head node of the group to be reversed (which will later be the tail after reversing)
        node* nhead;    //head will be the head node of the next group
        int j =1;   //j will keep count of the number of nodes in the group 
        while(j<i && tail && tail->next){
            tail=tail->next;    //tail is traversing to the last node of the group
            j++;
        }
        nhead=tail->next;   //the head of the next group will obviously the next of tail node
        if(j%2==0){             //doing j%2==0 as we only have to reverse the group which has even length
            tail->next=NULL;    //we will isolate the group to reverse it
            pre->next=revList(head);    //head is pointing to the head of the group about to be reversed and pre will always be
                                        //the node previous to head
            pre=head;                   //now the list is reversed so the head node will be pointing to the last node of the group
                                        //which makes it the node previous to the head of the next group
            head->next=nhead;           //we will join back the LL which we isolated in line 70
            head=nhead;                 //now the head will be the head of the new group
        }
        else{
            pre=tail;                   //now since it is the group with odd length so we dont have to reverse it
                                        //we will just set up our pre and head nodes for the next group as the next group
                                        //will be of even length(if it exists)
            head=nhead;
        }
   }
   return dum->next;   //since initially the next of dummy node pointed towards head so we will return that node
}

int main() {
    int n;
    cin>>n;
    LL x;
    for(int i = 0; i<n;i++){
        int k;
        cin>>k;
        x.pb(k);
    }

    x.head=reverseEvenLengthGroups(x.head);
    x.disp();
    return 0;
}