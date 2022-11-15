/*
Problem Description:
Given an array of integers, nums, and an integer value, target, determine 
if there are any three integers in nums whose sum equals the target. 
Return TRUE if three such integers are found in the array. Otherwise, 
return FALSE.

Constraints:
3 <=nums.length<=1000
-10^3<=nums[i]<=10^3
-10^3<=target<=10^3

Example:
nums=[1,-1,0]
target=2
output False
Explanation: Since there does not exist any triplet that has the sum 2.
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
bool FindSumOfThree(vector<int> nums, int target){
	sort(nums.begin(),nums.end());
	
	for(int i=1; i < nums.size()-1; i++) {
		int l = 0, r=nums.size()-1;
		while(l < i && r > i){
			if(nums[l]+nums[i]+nums[r] == target) return true;
			else if(nums[l]+nums[i]+nums[r] < target) l++;
			else r--;
		}
	}
	return false;
}
void solve() {
	int n;
	cin>>n;
	vi x;
	for(int i = 0; i <n;i ++){
		int r;
		cin >> r;
		x.push_back(r);
	}
	int target;
	cin>>target;
	cout << FindSumOfThree(x,target);
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
	cin >> TC;
	for (int T = 1; T <= TC; T++) {
	// cout << "Case #" << T << ": ";
		solve();
	}
	return 0;
}