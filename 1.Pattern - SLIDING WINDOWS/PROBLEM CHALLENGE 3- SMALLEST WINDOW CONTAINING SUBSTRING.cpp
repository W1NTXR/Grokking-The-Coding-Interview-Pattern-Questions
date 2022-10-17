#include<bits/stdc++.h>
using namespace std;

string minWindow(string s, string t){
    if(s.size()<t.size()) return "";
    unordered_map<char, int> freq;
    int fl = 0;
    int l=0,r=0;
    for(auto i: t) freq[i]++;
    int count = freq.size();
    int ans = INT_MAX;
    while(r < s.size()){
        freq[s[r]]--;
        if(freq[s[r]]==0) count--;

        while(count == 0) {
            if(ans > r-l+1) {
                ans=r-l+1;
                fl = l;
            }
            freq[s[l]]++;
            if(freq[s[l]] > 0) count ++;

            l ++;
        }

        r++;
    }
    if(ans != INT_MAX) return s.substr(fl,ans);
    return "";
}

int main () {
    string x,y;
    cin >> x;
    cin >> y;
    cout << minWindow(x,y);
    return 0;
}