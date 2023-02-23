/*
Leetcode Link: https://leetcode.com/problems/reverse-words-in-a-string/
Problem Description:
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
*/


#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s){
	string result;
	int i = 0;
	int n = s.size();
	while(i < n){
		while(i < n && s[i] == ' ') i++;
		if(i >= n) break;
		int j = i+1;
		while(j < n && s[j] != ' ') j++;
		string w = s.substr(i,j-i);
		
		if(result.size() == 0) result = w;
		else result = w + " " + result;
		i = j+1;
	}
	return result;

}


int main(){
	string s;
	getline(cin,s);
	cout << reverseWords(s);

	return 0;
}