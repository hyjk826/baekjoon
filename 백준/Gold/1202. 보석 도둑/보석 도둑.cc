// 2022-09-14
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
    vp A(n);
    for(int i{0}; i < n; ++i){
        cin >> A[i].first >> A[i].second;
    }
    sort(A.begin(), A.end());
    vi C(k);
    for(int i{0}; i < k; ++i){
        cin >> C[i];
    }
    sort(C.begin(), C.end());
    int idx{0};
    priority_queue<int> pQ;
    ll ans{0};
    for(int i{0}; i < k; ++i){
        while(idx < n && A[idx].first <= C[i]){
            pQ.push(A[idx].second);
            idx++;
        }
        if(!pQ.empty()){
            ans += pQ.top();
            pQ.pop();
        }
    }
    cout << ans;
    
}
	

