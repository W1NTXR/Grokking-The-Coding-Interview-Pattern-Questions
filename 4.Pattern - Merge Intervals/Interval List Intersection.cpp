/*
LeetCode Link: https://leetcode.com/problems/interval-list-intersections/description/
Description:
You are given two lists of closed intervals, firstList and secondList, 
where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.

The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. 
For example, the intersection of [1, 3] and [2, 4] is [2, 3].

Example 1:
Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]

Example 2:
Input: firstList = [[1,3],[5,9]], secondList = []
Output: []

Constraints:

0 <= firstList.length, secondList.length <= 1000
firstList.length + secondList.length >= 1
0 <= starti < endi <= 109
endi < starti+1
0 <= startj < endj <= 109 
endj < startj+1
*/
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