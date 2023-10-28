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
    int a, b;
    bool operator< (const st& x) const{
        return a * x.b < b * x.a;
    }
};

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

bool ch[5001][5001];

void solve(){
	int n, k;
    cin >> n >> k;
    vi prime(n + 1);
    for(int i{2}; i <= n; ++i){
        if(prime[i] == 0){
            for(int j{i * i}; j <= n; j += i){
                prime[j] = 1;
            }
        }
    }
    vector<vi> g(n + 1);
    g[1].push_back(0);
    g[1].push_back(1);
    for(int i{2}; i <= n; ++i){
        if(prime[i]) continue;
        for(int j{1}; j * i <= n; ++j){
            for(int k{j}; k * i <= n; ++k){
                ch[j * i][k * i] = 1;
            }
        }
    }
    for(int i{2}; i <= n; ++i){
        for(int j{i + 1}; j <= n; ++j){
            if(ch[i][j] == 0) g[j].push_back(i);
        }
        g[i].push_back(1);
    }
    // for(int i{1}; i <= n; ++i){
    //     cout << i << " : ";
    //     for(auto& j : g[i]) cout << j << " ";
    //     cout << "\n";
    // }
    // return;
    vector<st> vec;
    for(int i{1}; i <= n; ++i){
        for(auto& j : g[i]) vec.push_back({j, i});
    }
    nth_element(vec.begin(), vec.begin() + k - 1, vec.end()); 
    auto ans = vec[k - 1];
    cout << ans.a << " " << ans.b << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
