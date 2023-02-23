#include<bits/stdc++.h>
using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<string, int> t;
    for(int i = 0; i < s.size(); i ++) {
        if(t.empty() || i+9<s.size()){
            t[s.substr(i,10)]++;
        }
    }
    vector<string> ans;
    for(auto i: t) {
        if(i.second > 1) ans.push_back(i.first);
    }

    return ans;
}

int main() {
    string s;
    cin >> s;
    for(auto i: findRepeatedDnaSequences(s)) cout << i << " ";
    return 0;
}