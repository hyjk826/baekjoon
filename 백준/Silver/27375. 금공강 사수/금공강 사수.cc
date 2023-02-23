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
    int n, k;
    cin >> n >> k;
    struct st{
        int w, s, e;
    };
    vector<st> vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].w >> vec[i].s >> vec[i].e;
    }
    int ans{0};
    for(int i{0}; i < (1 << n); ++i){
        bool flag = true;
        int sum{0};
        vector<vi> ch(6, vi(11));
        for(int j{0}; j < n; ++j){
            if((i >> j) & 1){
                if(vec[j].w == 5) flag = false;
                sum += vec[j].e - vec[j].s + 1;
                for(int a{vec[j].s}; a <= vec[j].e; ++a){
                    if(ch[vec[j].w][a]) flag = false;
                    ch[vec[j].w][a] = 1;
                }
            }
        }
        if(sum != k) flag = false;
        if(flag) ans++;
    }
    cout << ans;
}
