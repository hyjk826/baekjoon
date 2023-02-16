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

int n, sq;
int sz = (int)1e5 + 10;
vi vec(sz);
vector<vi> bucket(sz);

int query(int s, int e, int k){
    int ret{0};
    int a = s / sq;
    int b = e / sq;
    if(a == b){
        for(int i{s}; i <= e; ++i){
            ret += (vec[i] > k);
        }
    }
    else{
        for(int i{a + 1}; i <= b - 1; ++i){
            ret += bucket[i].end() - upper_bound(bucket[i].begin(), bucket[i].end(), k);
        }
        for(int i{s}; i < a * sq + sq; ++i){
            ret += (vec[i] > k);
        }
        for(int i{e}; i >= b * sq; --i){
            ret += (vec[i] > k);
        }
    }
    return ret;
}

void update(int idx, int x){
    int b = idx / sq;
    auto it = lower_bound(bucket[b].begin(), bucket[b].end(), vec[idx]);
    if(it != bucket[b].end()) bucket[b].erase(it);
    vec[idx] = x;
    it = lower_bound(bucket[b].begin(), bucket[b].end(), vec[idx]);
    bucket[b].insert(it, vec[idx]);
}

int main(){
	fastio;
    cin >> n;
    sq = sqrt(n);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
        bucket[i / sq].push_back(vec[i]);
    }
    for(int i{0}; i < n / sq; ++i){
        sort(bucket[i].begin(), bucket[i].end());
    }
    int q;
    cin >> q;
    while(q--){
        int op, a, b, c;
        cin >> op;
        if(op == 2){
             cin >> a >> b;
             update(a, b);
        }
        else{
            cin >> a >> b >> c;
            cout << query(a, b, c) << "\n";
        }
    }
}
