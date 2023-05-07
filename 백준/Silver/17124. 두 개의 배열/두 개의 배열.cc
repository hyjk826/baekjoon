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
	int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vi A(n), B(m);
        for(int i{0}; i < n; ++i){
            cin >> A[i];
        }
        for(int i{0}; i < m; ++i){
            cin >> B[i];
        }
        sort(B.begin(), B.end());
        ll sum{0};
        for(int i{0}; i < n; ++i){
            auto it = lower_bound(B.begin(), B.end(), A[i]);
            int mn{MAX};
            vp C;
            if(it != B.end()) C.push_back({abs(A[i] - *it), *it});
            if(it != B.begin()) C.push_back({abs(A[i] - *(prev(it))), *(prev(it))});
            sort(C.begin(), C.end());
            sum += C.front().second;
        }
        cout << sum << '\n';
    }
}
