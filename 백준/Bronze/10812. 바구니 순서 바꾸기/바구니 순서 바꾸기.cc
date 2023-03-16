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
    int n, m;
    cin >> n >> m;
    vi vec(n);
    iota(vec.begin(), vec.end(), 1);
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--; c--;
        vi A;
        for(int j{c}; j <= b; ++j) A.push_back(vec[j]);
        for(int j{a}; j < c; ++j) A.push_back(vec[j]);
        for(int j{a}; j <= b; ++j){
            vec[j] = A[j - a];
        }
    }
    for(auto& i : vec) cout << i << " ";
}
