#include<bits/stdc++.h>
using namespace std;

int findMaximizedCapital(int k, int w, vector<int> profits, vector<int> capital){

    int n=profits.size();
    vector<pair<int, int>> x;
    for(int i = 0; i <n; i++) x.push_back(make_pair(capital[i],profits[i]));
    
    sort(x.begin(),x.end());
    int ptr=0;
    priority_queue<int> q;
    for(int i = 0; i < k; i++) {
        while(ptr < n && x[ptr].first <= w) q.push(x[ptr++].second);
        if(q.empty()) break;
        w += q.top();
        q.pop();
    }

    return w;

}

int main() {

    int n,k,w;
    cin >> n;
    vector<int> p(n,0);
    vector<int> c(n,0);
    for(int i = 0; i <n;i++) {
        cin >> p[i];
    }
    for(int i = 0; i < n; i ++) {
        cin >> c[i];
    }
    cin >> k >> w;

    cout << findMaximizedCapital(k,w,p,c);

    return 0;
}