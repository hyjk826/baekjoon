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
    int n, m, L;
    cin >> n >> m >> L;
    vi vec(n + 2);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
    }
    vec[n + 1] = L;
    sort(vec.begin() + 1, vec.begin() + n + 1);
    int l{1}, r{1000};
    int ans{0};
    while(l <= r){
        int mid{(l + r) >> 1};
        int sum{0};
        for(int i{0}; i <= n; ++i){
            sum += (vec[i + 1] - vec[i] - 1) / mid;
        }
        if(sum <= m){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
}
