// 2022-12-23
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

struct st{
    int d;
    vi p;
};

int main(){
	fastio;
    int n, k, D;
    cin >> n >> k >> D;
    vi ch(31);
    vector<st> vec(n);
    for(int i{0}; i < n; ++i){
        int a, b;
        cin >> a >> b;
        vec[i].d = b;
        for(int j{0}; j < a; ++j){
            int k;
            cin >> k;
            vec[i].p.push_back(k);
        }
    }
    sort(vec.begin(), vec.end(), [&](st& a, st& b){
        return a.d < b.d;
    });
    int ans{0};
    for(int i{0}, j{0}; i < n; ++i){
        while(j < n && vec[j].d - vec[i].d <= D){
            for(auto& a : vec[j].p){
                ch[a]++;
            }
            j++;
        }
        int x, y;
        x = y = 0;
        for(int k{1}; k <= 30; ++k){
            if(ch[k]) x++;
            if(ch[k] == j - i) y++;
        }
        ans = max(ans, (x - y) * (j - i));
        for(auto& a : vec[i].p){
            ch[a]--;
        }
    }
    cout << ans;
}
