/*
Leetcode Link: https://leetcode.com/problems/longest-repeating-character-replacement/
Problem Description:
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
 

Constraints:

1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length
*/


#include<bits/stdc++.h>
using namespace std;

//solution function
int characterReplacement(string s, int k){
    if(s.size() <= 1){
            return s.size();
        }
        int left=0;
        unordered_map<char, int> freq;
        int ans=INT_MIN;
        int maxfreq=INT_MIN;
        for(int i =0; i < s.size(); i++) {
            freq[s[i]]++;
            maxfreq=max(maxfreq,freq[s[i]]);
            if(i-left+1-maxfreq>k) {
                freq[s[left++]]--;
            }
            ans=max(ans,i-left+1);
        }
        return ans;
}

//Driver Function
int main () {
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << characterReplacement(s,k);

    return 0;
}