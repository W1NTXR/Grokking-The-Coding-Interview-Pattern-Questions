/*
Leetcode Link:

Problem Description:
Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray
[numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, 
return 0 instead.


Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
 

Constraints:

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104
 


*/

#include<bits/stdc++.h>
using namespace std;

int minSubArrayLen(vector<int> nums, int target) {
    int ans = INT_MAX;
    int sum = 0;
    int left = 0;
    for(int i = 0; i < nums.size(); i ++) {
        sum += nums[i];
        while(sum >= target) {
            ans = min(ans,i-left+1);
            sum -= nums[left++];
        }
    }

    return (ans != INT_MAX)? ans : 0;
}

int main () {
    int t;
    vector<int> x;
    cin >> t;
    for(int i =0; i < t; i ++) {
        int j;
        cin >> j;
        x.push_back(j);
    }
    int k;
    cin >> k;

    cout << minSubArrayLen(x,k);
}