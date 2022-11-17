/*
Leetcode Link: https://leetcode.com/problems/valid-palindrome/
Problem Description:
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/
#include <bits/stdc++.h>
using namespace std;
 
 
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vc vector<char>
#define vb vector<bool>
#define vll vector<ll>
#define vvi vector <vi>
#define vvc vector<vc>
#define vvb vector<vb>
#define vvll vector <vll>
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define umap unordered_map<long long, long long>
#define umapii unordered_map<int, int>
#define umapcl unordered_map<char, long long>
#define mem(a,val) memset(a,val,sizeof(a))
#define ha cout<<"YES\n"
#define na cout<<"NO\n"
#define pb push_back
#define lul <<"\n"
int vow(char x) {
	if (x == 'A' or x == 'E' or x == 'I' or x == 'O' or x == 'U') return 1;
	else return 0;
}
ll digic(ll n) {
	ll k = floor(log10(n) + 1);
	return k;
}
bool solve(string s) {
	
	if(s.size()==0||s.size()==1) return true;

	transform(s.begin(),s.end(),s.begin(),::toupper);
	int l=0,r=s.size()-1;
	while(l < r && l < s.size() && r >= 0) {
		while(!isalnum(s[l]) && l < s.size()) l++;
		while(!isalnum(s[r]) && r >= 0) r--;
		if(r < 0 || l > s.size()) return true;
		if(s[l] != s[r]) return false;
		l++;
		r--;
	}
	return true;
}
 
 
int main()
{
#ifdef ONLINEJUDGE
	clock_t tStart = clock();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
 
	int TC = 1;
	//cin >> TC;
	for (int T = 1; T <= TC; T++) {
		string s;
		cin >> s;
		cout << solve(s);
	}
	return 0;
}