// 2022-12-21
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

int main(){
	fastio;
	int n;
    cin >> n;
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    int L, P;
    cin >> L >> P;
    sort(vec.begin(), vec.end());
    int idx{0};
    priority_queue<int> pQ;
    int ans{0};
    while(P < L){
        while(idx < n && vec[idx].first <= P){
            pQ.push(vec[idx].second);
            idx++;
        }
        if(pQ.empty()) break;
        P += pQ.top();
        pQ.pop();
        ans++;
    }
    if(P < L) cout << -1;
    else cout << ans;
}
	
