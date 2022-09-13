// 2022-09-14
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
    ll k;
    cin >> k;
    int n, m;
    cin >> n;
    vl A(n);
    for(int i{0}; i < n; ++i){
        cin >> A[i];
    }
    cin >> m;
    vl B(m);
    for(int i{0}; i < m; ++i){
        cin >> B[i];
    }
    map<ll, ll> mp1, mp2;
    for(int i{0}; i < n; ++i){
        ll sum{0};
        for(int j{i}; j < n; ++j){
            sum += A[j];
            mp1[sum]++;
        }
    }
    for(int i{0}; i < m; ++i){
        ll sum{0};
        for(int j{i}; j < m; ++j){
            sum += B[j];
            mp2[sum]++;
        }
    }
    ll ans{0};
    for(auto& i : mp1){
        if(mp2.count(k - i.first)){
            ans += i.second * mp2[k - i.first];
        }
    }
    cout << ans;
}
	

