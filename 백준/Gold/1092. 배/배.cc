// 2022-09-21
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
    int n;
    cin >> n;
    vi A(n);
    for(int i{0}; i < n; ++i) cin >> A[i];
    int m;
    cin >> m;
    multiset<int> ms;
    for(int i{0}; i < m; ++i) {
        int a;
        cin >> a;
        ms.insert(a);
    }
    sort(A.rbegin(), A.rend());
    int ans{0};
    if(A.front() < *ms.rbegin()) cout << -1;
    else{
        while(1){
            vi vec;
            for(int i{0}; i < n; ++i){
                auto it = ms.upper_bound(A[i]);
                if(it == ms.begin()) break;
                it--;
                ms.erase(it);
                if(ms.empty()) break;
            }
            ans++;
            if(ms.empty()) break;
        }
        cout << ans;
    }
}
	

