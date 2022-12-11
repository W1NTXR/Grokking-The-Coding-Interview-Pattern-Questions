#include<bits/stdc++.h>
using namespace std;

int maxMeetings(int start[],int end[], int N) {
  pair<int, int> a[N + 1];
    int i;
    for (i = 0; i < N; i++) {
        a[i].first = end[i];
        a[i].second = i;
    }
    sort(a, a + N);
    int time_limit = a[0].first;
    vector<int> m;
    m.push_back(a[0].second + 1);
    for (i = 1; i < N; i++) {
        if (start[a[i].second] > time_limit) {
            m.push_back(a[i].second + 1);
            time_limit = a[i].first;
        }
    }
    return m.size();
}

int main() {
    int n;
    cin >> n;
    int start[n],end[n];
    for(int i = 0; i < n; i ++) {
        cin >> start[i];
    }
    for(int i = 0; i < n; i ++) {
        cin >> end[i];
    }

    cout << maxMeetings(start, end, n);

    return 0;
}