/*
Leetcode link: https://leetcode.com/problems/substring-with-concatenation-of-all-words/

*/
#include<bits/stdc++.h>
using namespace std;

bool check(string s, unordered_map<string, int> y, int k) {
    for(int i = 0; i < s.size(); i +=k) {
        string l = s.substr(i,k);
        if(y.find(l) != y.end()) {
            if(--y[l] == -1) return false;
        }
        else return false;
    }

    return true;
}

vector<int> findSubstring(string s, vector<string> words){
    if(s.size() < words.size()*words[0].size()) return {};
    vector<int> ans;
    int k=words[0].size();
    int n=words.size();
    unordered_map<string, int> freq;
    for(auto i: words) freq[i]++;
    int i = 0;
    while(i + n*k <= s.size()){
        if(check(s.substr(i,n*k),freq,k)) {
            ans.push_back(i);

        }
        i++;
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