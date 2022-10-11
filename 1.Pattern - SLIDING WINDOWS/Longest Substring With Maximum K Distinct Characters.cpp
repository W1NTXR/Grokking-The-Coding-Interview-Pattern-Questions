/*
Leetcode Link: https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

*/

#include<bits/stdc++.h>
using namespace std;

int longestSubstring(string s, int k) {
    int left = 0;
    int ans = INT32_MIN;
    int count = 1;
    for(int i = 1; i < s.size(); i ++) {
        
        if(s[i-1] != s[i])
            count ++;

        if(count > k) {
            ans =  max(ans,i-left);
            do {
                left ++;
            }while(s[left] == s[left+1]);
            count--;
        }
            
    }

    return ans;
}

int main () {
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << longestSubstring(s,k);

    return 0;
}