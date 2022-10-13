/*
Leetcode Link: https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

*/

#include<bits/stdc++.h>
using namespace std;

int longestSubstring(string s, int k) {
    unordered_map<char, int> freq;
    int left = 0;
    int ans = INT_MIN;
    for(int  i = 0; i < s.size()-1; i ++) {
        freq[s[i]]++;
        while(freq.size() > k) {
            freq[s[left]]--;
            if(freq[s[left]]==0)
                freq.erase(s[left]);
            left ++;
        }
        ans = max(ans,i-left+1);
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