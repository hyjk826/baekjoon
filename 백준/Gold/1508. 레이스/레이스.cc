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
    int n, m, k;
    cin >> n >> m >> k;
    vi vec(k);
    for(int i{0}; i < k; ++i){
        cin >> vec[i];
    }
    int l{1}, r{n};
    int ans{-1};
    while(l <= r){
        int mid{(l + r) >> 1};
        int idx{0};
        bool ok = true;
        for(int i{0}; i < m - 1; ++i){
            int a = lower_bound(vec.begin(), vec.end(), vec[idx] + mid) - vec.begin();
            if(a == k){
                ok = false; break;
            }
            idx = a;
        }
        if(ok){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    vi ch(k);
    ch[0] = 1;
    int idx{0};
    for(int i{0}; i < m - 1; ++i){
        int a = lower_bound(vec.begin(), vec.end(), vec[idx] + ans) - vec.begin();
        idx = a;
        ch[idx] = 1;
    }
    for(auto& i : ch) cout << i;
}
