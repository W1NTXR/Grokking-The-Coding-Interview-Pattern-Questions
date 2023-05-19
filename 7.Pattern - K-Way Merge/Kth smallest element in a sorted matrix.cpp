#include<bits/stdc++.h>
using namespace std;

int kthSmallest(vector<vector<int>> matrix, int k){
    if(k==1) return matrix[0][0];
    priority_queue<int> maxh;
    for(auto i: matrix) {
        for(auto j: i) {
            maxh.push(j);
            if(maxh.size()>k) maxh.pop();
        }
    }
    return maxh.top();
}

int main() {

    vector<vector<int>> x = {{1,2,3},{4,5,6},{8,11,11,16}};
    int k = 4;


    return 0;
}