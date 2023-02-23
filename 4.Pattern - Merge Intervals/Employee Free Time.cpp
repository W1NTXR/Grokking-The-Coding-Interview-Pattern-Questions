#include<bits/stdc++.h>
using namespace std;

vector<int> EmployeeFreeTime(vector<vector<int>> schedule){
    sort(schedule.begin(),schedule.end());
    int n = schedule.size();
    int i=0,max=schedule[0].back(),min;
    while(i<n) {
        if(max < schedule[i].back()) {
            if(max<schedule[i].front()) return {max,schedule[i].front()};
            max=schedule[i].back();
        }
        i++;
    }
    return {-1,-1};
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> x(n,vector<int>(2,0));
    for(int i = 0; i < n; i++) cin >> x[i][0] >> x[i][1];
    for(auto i: EmployeeFreeTime(x)) cout << i<< " ";
}