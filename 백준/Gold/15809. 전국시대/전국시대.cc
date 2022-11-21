// 2022-11-21
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

vi uni(100001);
vi cnt(100001);

int find(int a){
    if(a == uni[a]) return a;
    return uni[a] = find(uni[a]);
}

int main() {
	fastio;	
	int n, m;
    cin >> n >> m;
    for(int i{1}; i <= n; ++i){
        uni[i] = i;
        cin >> cnt[i];
    }
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            b = find(b);
            c = find(c);
            uni[b] = c;
            cnt[c] += cnt[b];
            cnt[b] = 0;
        }
        else{
            b = find(b);
            c = find(c);            
            if(cnt[b] > cnt[c]){
                uni[c] = b;
                cnt[b] -= cnt[c];
                cnt[c] = 0;            
            }
            else if(cnt[b] < cnt[c]){
                uni[b] = c;
                cnt[c] -= cnt[b];
                cnt[b] = 0;
            }
            else{
                cnt[b] = cnt[c] = 0;
            }            
        }
    }
    vi ans;
    for(int i{1}; i <= n; ++i){
        if(cnt[i] > 0) ans.push_back(cnt[i]);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(auto& i : ans) cout << i << " ";
}
	

