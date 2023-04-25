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
    int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    vi ch(100001);
    int j{0};
    ll ans{0};
    for(int i{0}; i < n; ++i){
        while(j < n && ch[vec[j]] == 0){
            ch[vec[j]] = 1;
            j++;
        }
        ans += j - i;
        ch[vec[i]]--;
    }
    cout << ans;
}
