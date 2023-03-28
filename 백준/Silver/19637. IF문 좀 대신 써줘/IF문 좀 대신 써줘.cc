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
    int n, q;
    cin >> n >> q;
    vs A(n);
    vi B(n);
    for(int i{0}; i < n; ++i){
        cin >> A[i] >> B[i];
    }
    while(q--){
        int x;
        cin >> x;
        int idx = lower_bound(B.begin(), B.end(), x) - B.begin();
        cout << A[idx] << "\n";
    }
}
