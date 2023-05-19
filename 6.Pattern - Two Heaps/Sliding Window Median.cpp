#include<bits/stdc++.h>
using namespace std;

vector<double> medianSlidingWindow(vector<int> nums, int k) {
    priority_queue<int, vector<int>,greater<int>> minHeap;
    priority_queue<int> maxHeap;
    vector<double> sol;
    unordered_map<int, int> x;
    int t = nums.size();
    int i = 0;

    while(i<k) {
        maxHeap.push(nums[i++]);
    }
    for(int c=0; c < k/2; c++){
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }
    while(true){
        if(k%2==1) sol.push_back(minHeap.top());
        else sol.push_back((minHeap.top()+maxHeap.top())/2.00);

        if(i==t) break;
        int m = nums[i-k];
        int n = nums[i++];
        int bal = 0;

        if(m <= maxHeap.top()) {
            --bal;
            if(m==maxHeap.top()) maxHeap.pop();
            else ++x[m];
        }

        else{
            ++bal;
            if(m==minHeap.top()) minHeap.pop();
            else ++x[m];
        }

        if(!maxHeap.empty() && n <= maxHeap.top()) {
            ++bal;
            maxHeap.push(n);
        }
        else {
            --bal;
            minHeap.push(n);
        }

        if(bal < 0) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        else if (bal > 0) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        while(!maxHeap.empty() && x[maxHeap.top()]) {
            --x[maxHeap.top()];
            maxHeap.pop();
        }

        while(!minHeap.empty() && x[minHeap.top()]) {
            --x[minHeap.top()];
            minHeap.pop();
        }

        
    }
    return sol; 
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n,0);
    for(int i = 0; i < n; i ++) {
        cin >> p[i];
    }
    int k;
    cin >> k;
    for(auto i: medianSlidingWindow(p,k)) cout << i << " " ;
    return 0;
}