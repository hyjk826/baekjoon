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
    int n, m;
    cin >> n >> m;
    vi vec;
    for(int i{0}; i < n; ++i){
        int p, l;
        cin >> p >> l;
        vi A(p);
        for(int j{0}; j < p; ++j) cin >> A[j];
        if(p < l){
            vec.push_back(1);
            continue;
        }
        sort(A.rbegin(), A.rend());
        int k = A[l - 1];
        vec.push_back(k);
    }
    int ans{0};
    int sum{0};
    sort(vec.begin(), vec.end());
    for(int i{0}; i < (int)vec.size(); ++i){
        if(sum + vec[i] > m) break;
        sum += vec[i];
        ans++;
    }
    cout << ans;
}
	

