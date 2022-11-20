// 2022-11-20
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
	int n, k;
    cin >> n >> k;
    vi prime((int)1e4);
    prime[1] = 1;
    for(int i{2}; i < (int)1e4; ++i){
        if(prime[i] == 0){
            for(int j{i * i}; j < (int)1e4; j += i){
                prime[j] = 1;
            }
        }
    }
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    vi ans;
    for(int i{0}; i < (1 << n); ++i){
        if(__builtin_popcount(i) != k) continue;
        int sum{0};
        for(int j{0}; j < n; ++j){
            if((i >> j) & 1) sum += vec[j];
        }
        if(prime[sum] == 0) ans.push_back(sum);
    }
    if(ans.size() == 0){
        cout << -1; return 0;
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for(auto& i : ans){
        cout << i << " ";
    }
}
	

