#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>x, vector<int>y){
        for(int i = 0; i < 26; i ++) {
            if(x[i] != y[i]) return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        
        if(s1.size()>s2.size()) return false;
        
        vector<int> freq1(26,0);
        vector<int> freq2(freq1);
        for(int i = 0; i < s1.size(); i ++){
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }
        
        for(int i = 0; i < s2.size()-s1.size(); i ++){
            if(check(freq1,freq2)) return true;
            freq2[s2[i+s1.size()]-'a']++;
            freq2[s2[i]-'a']--;
        }
        
        return check(freq1,freq2);
    }

int main () {
    string s1,s2;
    cin >> s1;
    cin >> s2;
    cout << checkInclusion(s1,s2);

    return 0;
}