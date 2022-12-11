// 2022-12-11
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vp vector<pi>
#define vpl vector<pl>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    int n;
    cin >> n;
    vp vec(n);
    int ans{0};
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
        if(vec[i].first > vec[i].second) swap(vec[i].first, vec[i].second);
    }
    sort(vec.begin(), vec.end(), [&](pi a, pi b){
        return a.second < b.second;
    });
    int idx{0};
    int d;
    cin >> d;
    priority_queue<int, vector<int>, greater<int> > pQ;
    for(int i{0}; i < n; ++i){
        pQ.push(vec[i].first);
        while(!pQ.empty() && vec[i].second - pQ.top() > d) pQ.pop();
        ans = max(ans, (int)pQ.size());
    }
    cout << ans;
}
	
