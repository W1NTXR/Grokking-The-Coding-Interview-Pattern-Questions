#include<bits/stdc++.h>
using namespace std;

class medianFinder{
    priority_queue<int> p;
    priority_queue<int> q;

    public:
        medianFinder();
        void addNum(int num){
            p.push(num);
            q.push(-p.top());
            p.pop();
            if(p.size()<q.size()) {
                p.push(-q.top());
                q.pop();
            }
        }

        double findMedian() {
            return p.size()>q.size()?p.top():(p.top()-q.top())/2.0; 
        }
};

int main() {
    
    int n;
    cin>>n;
    medianFinder x;
    for(int i = 0; i < n; i ++) {
        int c = 0;
        cout<<"Enter Choice /n1.Add Number /n2.Find Median /n3.Exit"<<endl;
        cin >> c;
        if(c==1) {
            int k;
            cin >> k;
            x.addNum(k);
        }
        else if(c==2) cout<<x.findMedian()<<'\n';
        else break;
    }
    return 0;
}