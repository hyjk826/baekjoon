// 2022-05-22
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

vi graph[300001];

int main(){
    fastio;
    int n;
    cin >> n;
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    ll d{0}, g{0};
    for(int i{1}; i <= n; ++i){
        for(auto& u : graph[i]){
            ll a = i;
            ll b = u;
            d += ((ll)graph[a].size() - 1) * ((ll)graph[b].size() - 1);
        }
        if(graph[i].size() >= 3){
            int k = graph[i].size();
            g += 1LL * k * (k - 1) * (k - 2) / 6;
        }
    }
    d /= 2;
    if(d == 3 * g) cout << "DUDUDUNGA";
    else if(d < 3 * g) cout << "G";
    else cout << "D";
}