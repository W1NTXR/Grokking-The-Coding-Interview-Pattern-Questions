#include<bits/stdc++.h>
using namespace std;

int Tasks(vector<vector<int>> task){

    return -1;

}

int main() {

    int n;
    vector<vector<int>> x(n,{0,0});
    for(int i = 0; i <n; i++) {
        cin >> x[i][0] >> x[i][1];
    }

    cout<< Tasks(x);

    return 0;
}