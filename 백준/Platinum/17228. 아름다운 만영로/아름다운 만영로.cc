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

const ll p1 = 179, mod1 = 1e9 - 63;
const ll p2 = 917, mod2 = 1e9 + 7;

ll oneHashing(string& str){
    ll r1{0}, r2{0};
    int n = (int)str.size();
    for(int i{0}; i < n; ++i) r1 = (r1 * p1 + str[i]) % mod1;
    for(int i{0}; i < n; ++i) r2 = (r2 * p2 + str[i]) % mod2;
    return (r1 << 32 | r2);
}

ll k;

const int sz = 5e5 + 10;
vector<vector<pair<int, char>> > g(sz);
ll pw1[sz];
ll pw2[sz];
vl A, B;
int ans{0};
ll a = 1; 
ll b = 1;
string str;

void dfs(int cur){
    if(A.size() > (int)str.size()){
        ll x = A.back() - A[(int)A.size() - 1 - (int)str.size()] * a;
        x %= mod1;
        if(x < 0) x += mod1;
        ll y = B.back() - B[(int)B.size() - 1 - (int)str.size()] * b;
        y %= mod2;
        if(y < 0) y += mod2;
        if((x << 32 | y) == k) ans++;
    }
    for(auto& i : g[cur]){
        A.push_back((A.back() * p1 + i.second) % mod1);
        B.push_back((B.back() * p2 + i.second) % mod2);
        dfs(i.first);
    }
    A.pop_back();
    B.pop_back();
}

int main(){
	fastio;
    int n;
    cin >> n;    
    for(int i{0}; i < n - 1; ++i){
        int a, b; char c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    cin >> str;
    k = oneHashing(str);
    for(int i{1}; i <= (int)str.size(); ++i){
        a = a * p1 % mod1;
        b = b * p2 % mod2;
    }    
    A.push_back(0);
    B.push_back(0);
    dfs(1);
    cout << ans;
}
