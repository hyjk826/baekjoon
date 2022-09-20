// 2022-09-20
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    int n, k;
    cin >> n >> k;
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    vi bag(k);
    for(int i{0}; i < k; ++i){
        cin >> bag[i];
    }
    sort(vec.begin(), vec.end());
    sort(bag.begin(), bag.end());
    int idx{0};
    priority_queue<int> pQ;
    ll ans{0};
    for(int i{0}; i < k; ++i){
        while(idx < n && vec[idx].first <= bag[i]){
            pQ.push(vec[idx].second);
            idx++;
        }
        if(!pQ.empty()){
            ans += pQ.top();
            pQ.pop();
        }
    }
    cout << ans;
}
	

