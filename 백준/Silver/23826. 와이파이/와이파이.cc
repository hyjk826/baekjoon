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

int dist(int a, int b, int c, int d){
    return abs(a - c) + abs(b - d);
}

struct st{
    int x, y, e;
};

int main(){
	fastio;
    int n;
    cin >> n;
    int x, y, e;
    cin >> x >> y >> e;
    vector<st> vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].x >> vec[i].y >> vec[i].e;
    }
    int ans{0};
    for(int i{0}; i < n; ++i){
        int sum = e - dist(vec[i].x, vec[i].y, x, y);
        for(int j{0}; j < n; ++j){
            sum -= max(0, vec[j].e - dist(vec[i].x, vec[i].y, vec[j].x, vec[j].y));
        }
        ans = max(ans, sum);
    }
    if(ans) cout << ans;
    else cout << "IMPOSSIBLE";
}
