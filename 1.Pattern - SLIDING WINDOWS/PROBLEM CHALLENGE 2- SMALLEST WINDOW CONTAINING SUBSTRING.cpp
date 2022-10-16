#include<bits/stdc++.h>
using namespace std;

bool check(unordered_map<char, int> x, unordered_map<char, int> y, string q){
    for(int i = 0; i < q.size(); i++) {
        if(x[q[i]] > y[q[i]])
            return false;
    }
    return true;
}

string minWindow(string s, string t){
    if(s.size()<t.size()) return "";
    unordered_map<char, int> f1;
    unordered_map<char, int> f2;
    for(int i=0; i < t.size(); i ++){
        f1[t[i]]++;
    }
    int l = 0,r=0;
    int window=INT_MAX;
    int fl,fr;
    while(r<s.size()){
        f2[s[r]]++;
        if(check(f1,f2,t)){
            window=min(window,r-l+1);
            fl=l;
            fr=r;
            f2[s[l++]]--;
            cout << fl << "," << fr << " ";
        }
        else{
            r++;
        }
    }
    
        
    return "";

}

int main () {
    string x,y;
    cin >> x;
    cin >> y;
    cout << minWindow(x,y);
    return 0;
}