#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {

    priority_queue<int> maxh;
    int m = nums1.size();
    int n =  nums2.size();
    for(auto i: nums1) {
        maxh.push(i);
        if(maxh.size() > ((m+n)/2) + 1) {
            maxh.pop();
        }
    }
    for(auto i: nums2) {
        maxh.push(i);
        if(maxh.size() > ((m+n)/2) + 1 ) {
            maxh.pop();
        }
    }

    if((m+n)%2 == 0) {
        double x = (double)maxh.top();
        maxh.pop();
        return (x+(double)maxh.top())/2.0;
    }

    return double(maxh.top());

}

int main() {

    vector<int> x = {1,2};
    vector<int> y = {3,4};

    cout << findMedianSortedArrays(x,y);

    return 0;
}