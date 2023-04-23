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

int ch[2600001];

int main(){
	fastio;
    int n;
    cin >> n;
    vi vec(n);
    int sum{0};
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        sum += vec[i];
    }
    function<void(int,int)> f = [&](int sum, int k){
        ch[abs(sum)] = 1;
        if(k >= n) return;
        for(int j{0}; j < 3; ++j){
            if(j == 0) f(sum + vec[k], k + 1);
            else if(j == 1) f(sum, k + 1);
            else f(sum - vec[k], k + 1);
        }
    };
    f(0, 0);
    int ans{0};
    for(int i{1}; i <= sum; ++i){
        if(ch[i] == 0) ans++;
    }
    cout << ans;

}
