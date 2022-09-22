// 2022-09-21
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

struct st{
    int a, b, c;
};

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


int main() {
	fastio;
    int n, m;
    cin >> n >> m;
    for(int i{1}; i <= n; ++i) uni[i] = i;
    vi ch(n + 1);
    for(int i{1}; i <= n; ++i){
        char c;
        cin >> c;
        if(c == 'M') ch[i] = 1;
    }
    vector<st> vec;
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        if(ch[a] != ch[b]){
            vec.push_back({a, b, c});
        }
    }    
    sort(vec.begin(), vec.end(), [&](st x, st y){
        return x.c < y.c;
    });
    int cnt{0};
    int ans{0};
    for(int i{0}; i < (int)vec.size(); ++i){
        if(Union(vec[i].a, vec[i].b)){
            ans += vec[i].c;
            cnt++;
        }
    }
    if(cnt != n - 1) cout << -1;
    else cout << ans;
}
	

