#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> intervalIntersection(vector<vector<int>> firstList, vector<vector<int>> secondList){
    vector<vector<int>> ans;
    if(firstList.empty() || secondList.empty()) return ans;
    
    int i = 0,j=0;
    int N=firstList.size();
    int M=secondList.size();
    while(i < N && j < M) {
        if(firstList[i].back() < secondList[j].front()) {
            i++;
            continue;
        }
        else if(secondList[j].back() < firstList[i].front()) {
            j++;
            continue;
        }
        else{
            vector<int> x = {max(firstList[i].front(),secondList[j].front()),min(firstList[i].back(),secondList[j].back())};
            ans.push_back(x);
            if(firstList[i].back() > secondList[j].back()) {
                j++;
                continue;
            }
            else i++;
            continue;
        }

    }

    return ans;
}

int main() {
    int m,n;
    cin >> m >> n;
    vector<vector<int>> x(m,vector<int>(2,0));
    vector<vector<int>> y(n,vector<int>(2,0));
    for(int i = 0; i < m; i ++) {
        cin >> x[i][0] >> x[i][1];
    }
    for(int i = 0; i < n; i ++) {
        cin>>y[i][0]>>y[i][1];
    }
    for(auto i: intervalIntersection(x,y)) {
        cout << i[0]<<","<<i[1]<<" ";
    }
    return 0;
}