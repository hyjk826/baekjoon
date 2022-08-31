// 2022-08-31
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
    int n, l, w;
    cin >> n >> l >> w;
    queue<pi> Q;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    int k{0};
    int sum{0};
    int ans{0};
    while(1){   
        int sz = Q.size();
        if(k == n && sz == 0) break; 
        for(int i{0}; i < sz; ++i){
            int x{Q.front().first};
            int cnt{Q.front().second};
            Q.pop();
            if(cnt == 1){
                sum -= x;
            }
            else{
                Q.push({x, cnt - 1});
            }
        }

        if(k < n && Q.size() < l && sum + vec[k] <= w){
            Q.push({vec[k], l});
            sum += vec[k];
            k++;
        }
        ans++;
    }
    cout << ans;
}

