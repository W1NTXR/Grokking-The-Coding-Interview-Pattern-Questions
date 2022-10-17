/*
Leetcode link: https://leetcode.com/problems/substring-with-concatenation-of-all-words/

*/
#include<bits/stdc++.h>
using namespace std;

vector<int> findSubstring(string s, vector<string> words){
    if(s.size() < words.size()*words[0].size()) return {};
    int k = words[0].size();
    int left = 0;
    unordered_map<string, int> freq,freq1;
    for(auto i: words) {
        freq[i]++;
    }
    vector<int> ans;
    unordered_map<string, int> temp(freq);
    for(int i = 0; i < s.size(); i += k) {
        string x = s.substr(i,k);
        temp[x]--;
        if(temp[x] == 0) temp.erase(x);
        if(temp.empty()) ans.push_back(left);
        if(temp[x] < 0) {
            left=i;
            temp=freq;
            temp[x]--;
            if(temp[x] < 0) temp.erase(x);
        }
    }

    return ans;
}

int main () {
    string s;
    vector<string> words;
    int k;
    cin >> k;
    cin >> s;
    for(int i = 0; i < k; i ++){
        string z;
        cin >> z;
        words.push_back(z);
    }

    vector<int> ans(findSubstring(s,words));
    for(auto i: ans) cout << i << " ";
    
    return 0;
}