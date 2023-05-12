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

int cnt[20];

int main(){
	fastio;
	int n;
    cin >> n;
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        for(int j{0}; j < 20; ++j){
            if((a >> j) & 1) cnt[j]++;
        }
    }
    int mx{0};
    for(int i{0}; i < 20; ++i){
        mx = max(mx, cnt[i]);
    }
    cout << mx;
}
