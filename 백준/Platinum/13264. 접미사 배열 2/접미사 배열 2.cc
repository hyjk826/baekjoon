// 2022-12-01
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

vi suffixArray(string& str){
    int n = (int)str.size();
    vi sfx(n), g(n + 1), ng(n + 1);
    int t = 1;
    for(int i{0}; i < n; ++i){
        sfx[i] = i; g[i] = str[i] - 'a';
    }
    auto cmp = [&](int a, int b){
        if(g[a] == g[b]) return g[a + t] < g[b + t];
        else return g[a] < g[b];
    };
    g[n] = -1;
    for(; t < n; t <<= 1){
        sort(sfx.begin(), sfx.end(), cmp);
        ng[sfx[0]] = 0;
        ng[n] = -1;
        for(int i{1}; i < n; ++i){
            if(cmp(sfx[i - 1], sfx[i])){
                ng[sfx[i]] = ng[sfx[i - 1]] + 1;
            }
            else ng[sfx[i]] = ng[sfx[i - 1]];
        }
        swap(g, ng);
    }
    return sfx;
}


int main() {
	fastio;
    string str;
    cin >> str;
    vi ans = suffixArray(str);
    for(auto& i : ans) cout << i << "\n";
}
	
