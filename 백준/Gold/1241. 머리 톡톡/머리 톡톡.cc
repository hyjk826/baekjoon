// 2022-12-01
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
    vi vec(n);
    int one = 0;
    vi cnt2((int)1e6 + 1);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        cnt2[vec[i]]++;
        if(vec[i] == 1) one++;
    }
    vi cnt((int)1e6 + 1, one);
    vi A = vec;
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    for(int i{0}; i < (int)A.size(); ++i){
        if(A[i] == 1) continue;
        for(int j{A[i]}; j <= (int)1e6; j += A[i]){
            cnt[j] += cnt2[A[i]];
        }
    }
    for(int i{0}; i < n; ++i){
        cout << cnt[vec[i]] - 1 << "\n";
    }
}
	
