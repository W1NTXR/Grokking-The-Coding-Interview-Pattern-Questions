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
bool fap(string s1, string s2){
	if(s2.find(s1) != string::npos) return true;
	return false;
}
void solve() {
	string s;
	cin>>s;

	string s2="Y";
	for(int i = 1; i <= 50; i++) {
		if(i%3==0) s2+="Y";
		else if(i%3==1) s2+="e";
		else s2+= "s";
	}
	
	if(fap(s,s2)) ha;
	else na;
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