/*
Leetcode Link: https://leetcode.com/problems/max-consecutive-ones-iii/


*/
#include<bits/stdc++.h>
using namespace std;

int longestOnes(vector<int> &nums, int k){
    int zerocnt = 0;
        int i = 0;
        int ans = 0;
        for(int j = 0 ; j < nums.size(); j ++) {
            if(nums[j]==0){
                zerocnt ++;
            }
            while(zerocnt > k){
                if(nums[i]==0)
                    zerocnt--;
                i ++;
            }
            ans = max(ans,j-i+1);
        }
        return ans;
}

int main (){
    int y;
    vector<int> x;
    cin >> y;
    for(int i = 0; i < y; i++) {
        int t;
        cin >> t;
        x.push_back(t);
    }

    int k;
    cin >> k;
    cout << longestOnes(x,k);

    return 0;
}