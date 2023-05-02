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
    vp vec(n + 2);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    vec[n + 1].first = vec[n + 1].second = 10000;
    int l{1}, r{1500};
    int ans{-1};
    while(l <= r){
        int mid{(l + r) >> 1};
        queue<int> Q;
        Q.push(0);
        vi ch(n + 2, -1);
        ch[0] = 0;
        while(!Q.empty()){
            int idx = Q.front();
            int x{vec[Q.front()].first};
            int y{vec[Q.front()].second};
            Q.pop();
            for(int i{0}; i <= n + 1; ++i){
                int nx{vec[i].first};
                int ny{vec[i].second};
                int dist = (x - nx) * (x - nx) + (y - ny) * (y - ny);
                if(ch[i] == -1 && dist <= 100 * mid * mid){
                    ch[i] = ch[idx] + 1;
                    Q.push(i);
                }
            }
        }
        if(ch[n + 1] != -1 && ch[n + 1] - 1 <= k){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
}
