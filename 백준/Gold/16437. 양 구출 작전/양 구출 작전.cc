// 2022-12-08
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

int n;
vector<vi> g(123456);
vl A(123456);

void dfs(int cur){
    for(auto& i : g[cur]){
        dfs(i);
        A[cur] += A[i];
    }
    A[cur] = max(A[cur], 0LL);
}



int main() {
	fastio;
    cin >> n;
    for(int i{1}; i <= n - 1; ++i){
        char c; int a;
        cin >> c >> A[i] >> a;
        if(c == 'W') {
            A[i] *= -1;
        }
        a--;
        g[a].push_back(i);
    }
    dfs(0);
    cout << A[0];
}
	
