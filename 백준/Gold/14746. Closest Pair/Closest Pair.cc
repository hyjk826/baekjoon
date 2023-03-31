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
    int n, m;
    cin >> n >> m;
    int c1, c2;
    cin >> c1 >> c2;
    int mn{MAX}, cnt{0};
    vi A(n), B(m);
    for(int i{0}; i < n; ++i){
        cin >> A[i];
    }
    for(int i{0}; i < m; ++i){
        cin >> B[i];
    }
    sort(A.begin(), A.end());
    for(int i{0}; i < m; ++i){
        auto it = lower_bound(A.begin(), A.end(), B[i]);
        if(it != A.end()){
            int k = abs(B[i] - *it);
            if(k < mn){
                mn = k;
                cnt = 1;
            }
            else if(k == mn) cnt++;
        }
        if(it != A.begin()){
            it--;
            int k = abs(B[i] - *it);
            if(k < mn){
                mn = k;
                cnt = 1;
            }
            else if(k == mn) cnt++;
        }
    }
    cout << mn + abs(c1 - c2) << " " << cnt;
}
