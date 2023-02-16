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
    int l, r, c;
};

int main(){
	fastio;
    int n, q;
    cin >> n >> q;
    vector<st> vec(n);
    vi team(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].l >> vec[i].r;
        int y; cin >> y;
        vec[i].c = i;
    }
    sort(vec.begin(), vec.end(), [&](st& a, st& b){
        return tie(a.l, a.r) < tie(b.l, b.r);
    });
    int k{0};
    vector<st> A;
    team[vec[0].c] = k;
    A.push_back({vec[0].l, vec[0].r, k});
    for(int i{1}; i < n; ++i){
        if(vec[i].l <= A.back().r){
            team[vec[i].c] = A.back().c;
            A.back().r = max(A.back().r, vec[i].r);
        }
        else{
            k++;
            team[vec[i].c] = k;
            A.push_back({vec[i].l, vec[i].r, k});
        }
    }
    while(q--){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if(team[a] == team[b]) cout << 1;
        else cout << 0;
        cout << "\n";
    }
}
