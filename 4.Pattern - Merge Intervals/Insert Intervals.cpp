/*
Leetcode Link: https://leetcode.com/problems/insert-interval/description/
Description:
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the
ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that 
represents the start and end of another interval.
Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have 
any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.
Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 

Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 105

*/
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
    return 0;
}