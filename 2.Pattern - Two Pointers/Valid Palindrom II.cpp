/*
Leetcode Link: https://leetcode.com/problems/valid-palindrome-ii/
Problem Description:
Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
*/
#include<bits/stdc++.h>
using namespace std;

bool ans(int i, int j, string s){
    while(i<j) {
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}
bool validPalindrome(string s) {
    int i=0;
    int j=s.size()-1;
    while(i<=j) {
        if(s[i]==s[j]) {
            i ++;
            j--;
        }
        else return (ans(i,j-1,s)||ans(i+1,j,s));
        }
    return true;
}

int main() {
    string s;
    cin >> s;
    cout << validPalindrome(s);

    return 0;
}