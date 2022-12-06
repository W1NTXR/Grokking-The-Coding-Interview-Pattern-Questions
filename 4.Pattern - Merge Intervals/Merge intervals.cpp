#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> intervals){
sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;
    for (auto interval : intervals) {
        if (merged.empty() || merged.back()[1] < interval[0]) {
            merged.push_back(interval);
        }
        
        else {
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }
    return merged;
}

int main(){
    int N;
    cin >> N;
    vector<vector<int>> x(N, vector<int> (2,0));
    for(int i = 0; i < N ; i++) for(int j = 0; j < 2; j ++) cin >> x[i][j];

    for(auto i: merge(x) ) {
        cout << i[0]<<","<<i[1]<< " ";
    }
}