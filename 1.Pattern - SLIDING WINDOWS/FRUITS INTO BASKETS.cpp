#include<bits/stdc++.h>
using namespace std;

int totalfruit(vector<int> fruits) {
    unordered_map<int, int> basket;
    int left=0;
    int ans=INT16_MIN;
    for(int i = 0; i < fruits.size(); i ++) {
        basket[fruits[i]]++;
        while (basket.size() > 2)
        {
            basket[fruits[left]]--;
            if(basket[fruits[left]] == 0)
                basket.erase(fruits[left]);
            left ++;
        }
        ans = max(ans,i-left+1);
        
    }
    return ans;
}

int main() {
    int k;
    vector<int> fruits;
    cin >> k;
    for(int i = 0; i < k; i ++) {
        int x;
        cin >> x;
        fruits.push_back(x);
    }

    cout << totalfruit(fruits);
    return 0;
}