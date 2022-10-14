/*
Leetcode Link: https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

Problem Description:

Given a string, find the length of the longest substring in it with no more than K distinct characters.
Example 1:
Input: String="araaci", K=2
Output: 4
Explanation: The longest substring with no more than '2' distinct characters is "araa".
Example 2:
Input: String="araaci", K=1
Output: 2
Explanation: The longest substring with no more than '1' distinct characters is "aa".
Example 3:
Input: String="cbbebi", K=3
Output: 5
Explanation: The longest substrings with no more than '3' distinct characters are "cbbeb" & "bbebi".
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