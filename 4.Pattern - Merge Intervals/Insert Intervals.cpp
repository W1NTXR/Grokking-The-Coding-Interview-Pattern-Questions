#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>intervals, vector<int> newInterval){
int N=intervals.size();
    int i=0,j=N-1;
    while(i < N && intervals[i][1] < newInterval[0] ) ++i;
    while(j >= 0 && intervals[j][0] > newInterval[1]) --j;
    if(i <= j) {
        intervals[j][0]=min(intervals[i][0], newInterval[0]);
        intervals[j][1]=max(intervals[j][1], newInterval[1]);
        intervals.erase(intervals.begin()+i, intervals.begin()+j);
    }
    else intervals.insert(intervals.begin()+i,newInterval);

    return intervals;
}

int main(){
    int N;
    cin >> N;
    vector<vector<int>> x(N,vector<int>(2,0));
    vector<int> y(2,0);
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < 2; j ++) {
            cin >> x[i][j];
        }
    }
    cin >> y[0] >> y[1];
    for(auto i: insert(x,y)) cout << i[0] <<","<<i[1]<<" ";
}