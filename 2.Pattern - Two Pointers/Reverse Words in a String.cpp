#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s){
	string result;
	int i = 0;
	int n = s.size();
	while(i < n){
		while(i < n && s[i] == ' ') i++;
		if(i >= n) break;
		int j = i+1;
		while(j < n && s[j] != ' ') j++;
		string w = s.substr(i,j-i);
		
		if(result.size() == 0) result = w;
		else result = w + " " + result;
		i = j+1;
	}
	return result;
}

int main(){
	string s;
	cin >> s;
	cout << reverseWords(s);

	return 0;
}