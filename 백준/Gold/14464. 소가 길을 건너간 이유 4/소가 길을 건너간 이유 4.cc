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

void solve(){
	int n, m;
    cin >> n >> m;
    vi A(n);
    vp B(m);
    priority_queue<int, vi, greater<int> > pQ;
    for(int i{0}; i < n; ++i){
        cin >> A[i];
    }
    for(int i{0}; i < m; ++i){
        cin >> B[i].first >> B[i].second;
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int ans{0};
    int idx{0};
    for(int i{0}; i < n; ++i){     
        while(idx < m && A[i] > B[idx].second) idx++;   
        while(idx < m && B[idx].first <= A[i] && A[i] <= B[idx].second){
            pQ.push(B[idx].second);
            idx++;
        }
        while(!pQ.empty() && pQ.top() < A[i]) pQ.pop();
        if(!pQ.empty()) {
            pQ.pop();
            ans++;
        }
    }
    cout << ans << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
