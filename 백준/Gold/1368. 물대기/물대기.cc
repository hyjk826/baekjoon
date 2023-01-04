// 2023-01-04
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
    int n;
    cin >> n;
    vi uni(n + 1);
    for(int i{0}; i <= n; ++i){
        uni[i] = i;
    }
    struct st{
        int a, b, w;
    };
    vector<st> edge;
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        edge.push_back({0, i + 1, a});
    }
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= n; ++j){
            int a;
            cin >> a;
            if(i < j) edge.push_back({i, j, a});
        }
    }
    sort(edge.begin(), edge.end(), [&](st x, st y){
        return x.w < y.w;
    });
    function<int(int)> find = [&](int a){
        if(a == uni[a]) return a;
        return uni[a] = find(uni[a]);
    };
    function<bool(int, int)> Union = [&](int a, int b){
        a = find(a);
        b = find(b);
        if(a != b){
            uni[a] = b;
            return true;
        }
        return false;
    };
    int ans{0};
    for(auto& i : edge){
        if(Union(i.a, i.b)){
            ans += i.w;
        }
    }
    cout << ans;
}
