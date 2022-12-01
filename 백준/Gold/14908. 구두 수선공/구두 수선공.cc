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

struct st{
    int a, b, idx;
};


int main() {
	fastio;
	int n;
    cin >> n;
    vector<st> vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].a >> vec[i].b;
        vec[i].idx = i + 1;
    }
    sort(vec.begin(), vec.end(), [&](st x, st y){
        int q = x.b * y.a;
        int w = y.b * x.a;
        if(q == w) return x.idx < y.idx;
        else return q > w;
    });
    for(auto& i :vec){
        cout << i.idx << " ";
    }
}
	
