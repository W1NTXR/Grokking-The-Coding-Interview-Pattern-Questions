#include<bits/stdc++.h>
using namespace std;

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

int main () {
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << characterReplacement(s,k);

    return 0;
}