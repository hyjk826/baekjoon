// 2022-10-20
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

struct st{
    int a, b, c;
};

int main() {
	fastio;
    int n, k;
    cin >> n >> k;
    vector<st> vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].a >> vec[i].b >> vec[i].c;
    }
    int ans{MAX};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            for(int l{0}; l < n; ++l){
                int cnt{0};
                for(int r{0}; r < n; ++r){
                    if(vec[i].a >= vec[r].a && vec[j].b >= vec[r].b && vec[l].c >= vec[r].c) cnt++;
                }
                if(cnt >= k) ans = min(ans, vec[i].a + vec[j].b + vec[l].c);
            }
        }
    }
    cout << ans;
}
	

