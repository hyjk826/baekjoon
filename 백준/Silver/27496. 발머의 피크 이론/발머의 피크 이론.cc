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
    int N, L;
    cin >> N >> L;
    vi vec(N);
    for(int i{0}; i < N; ++i){
        cin >> vec[i];
    }
    vi pre(N);
    int ans{0};
    for(int i{0}; i < N; ++i){
        pre[i] += vec[i];
        if(i + L < N) pre[i + L] -= vec[i];
        if(i) pre[i] += pre[i - 1];
        if(pre[i] >= 129 && pre[i] <= 138) ans++;
    }
    cout << ans;
}
