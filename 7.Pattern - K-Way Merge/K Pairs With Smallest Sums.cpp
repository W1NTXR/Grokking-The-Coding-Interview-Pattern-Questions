#include<bits/stdc++.h>
using namespace std;

struct check{
    bool operator()(pair<int,int> x, pair<int, int> y){return x.first > y.first;}
};

vector<vector<int>> kSmallestPairs(vector<int> nums1, vector<int> nums2, int k){
    
    priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int,int>>>> minH;
    vector<vector<int>> ans;
    int n = nums1.size();
    int m = nums2.size();
    set<pair<int, int>> s;
    minH.push(make_pair(nums1[0]+nums2[0], make_pair(0,0)));
    bool fl = true;
    for(int i = 0; i < k && fl; i++) {
        pair<int, pair<int,int>> t=minH.top();
        minH.pop();

        int x = t.second.first;
        int y = t.second.second;

        ans.push_back({x,y});
        fl=false;
        if(x+1<n) {
            int sum = nums1[x+1] + nums2[y];
            pair<int, int> t1 = make_pair(x+1,y);
            if(s.find(t1)==s.end()) {
                minH.push(make_pair(sum,t1));
                s.insert(t1);
            }
            fl=true;
        }

        if(y+1 < m) {
            int sum = nums1[x] + nums2[y+1];
            pair<int, int> t1= make_pair(x,y+1);
            if(s.find(t1) == s.end()) {
                minH.push(make_pair(sum,t1));
                s.insert(t1);
            }
            fl=true;
        }
    }

    return ans;
}

int main() {

    vector<int> x = {1,2};
    vector<int> y = {3};
    for(auto i : kSmallestPairs(x,y,2)){
        cout << i[0] << " " << i[1] << '\n';
    }

    return 0;
}