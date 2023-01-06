// 2023-01-06
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

vi uni(1001);

int find(int a){
    if(a == uni[a]) return a;
    return uni[a] = find(uni[a]);
}

bool Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        uni[a] = b;
        return true;
    }
    return false;
}

int main(){
	fastio;
    int n, m, k;
    cin >> n >> m >> k;
    struct st{
        int a, b, w;
    };
    vp edge(m);
    for(int i{0}; i < m; ++i){
        cin >> edge[i].first >> edge[i].second;
    }
    vi ans(k);
    for(int i{0}; i < k; ++i){
        for(int j{1}; j <= n; ++j){
            uni[j] = j;
        }
        int sum{0};
        int cnt{0};
        for(int j{i}; j < m; ++j){
            if(Union(edge[j].first, edge[j].second)){
                sum += j + 1;
                cnt++;
            }
        }
        if(cnt == n - 1){
            ans[i] = sum;
        }
        else break;
    }
    for(auto& i : ans) cout << i << " ";
}
