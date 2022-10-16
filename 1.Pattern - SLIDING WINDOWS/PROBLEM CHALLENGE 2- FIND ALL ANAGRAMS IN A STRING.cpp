#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> x, vector<int> y) {
        for(int i = 0; i < 26; i ++) {
            if(x[i] != y[i]) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size())
            return {};
        vector<int> f1(26,0);
        vector<int> f2(26,0);
        vector<int> ans;
        for(int i = 0; i < p.size(); i ++) {
            f1[p[i]-'a']++;
            f2[s[i]-'a']++;
        }
        int i;
        for( i = 0; i<s.size()-p.size(); i++) {
            if(check(f2,f1))
                ans.push_back(i);
            
            
                f2[s[i+p.size()]-'a']++;
                f2[s[i]-'a']--;
            
        }
        if(check(f1,f2)) ans.push_back(i);
        
        return ans;
    }

int main () {
    string s,p;
    cin>> s;
    cin >> p;
    vector<int> sol(findAnagrams(s,p));
    for(auto i: sol){
        cout << i << " ";
    }
    return 0;
}