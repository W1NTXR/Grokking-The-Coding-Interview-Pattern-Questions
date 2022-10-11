/*
Leetcode Link: https://leetcode.com/problems/maximum-subarray/
53. Maximum Subarray

Description:
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
 

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle
*/
#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> nums, int k) {
    int maxSum = INT_MIN;
    int curSum = 0;
    for(int i = 0; i < nums.size(); i ++) {
        curSum += nums[i];
        if(curSum > maxSum) {
            maxSum = curSum;
        }
        if(curSum < 0) {
            curSum = 0;
        }
    }

    return maxSum;
}

int main() {
    vector<int> x;
    int k, t;
    cin >> t;
    for(int i = 0; i < t; i ++) {
        int r;
        cin >> r;
        x.push_back(r);
    }
    cin >> k;
    cout << maxSubArray(x,k);
    return 0;
}

