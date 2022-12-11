// 2022-12-12
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

int n, m;
vi A(6), B(10);
vi chk(10);
int ans{0};

bool f(int a, int b){
    int cnt{0};
    while(a){
        if(chk[a % 10] == 0) return 0;
        cnt++;
        a /= 10;
    }
    return (b == cnt);
}

void dfs(int L, int a, int b){
    if(L < A[0]){
        for(int i{0}; i < m; ++i){                
            dfs(L + 1, a * 10 + B[i], 0);
        }
    }
    else if(L < A[0] + A[1]){
        for(int i{0}; i < m; ++i){
            if(f(a * B[i], A[L - A[0] + 2])) dfs(L + 1, a, b * 10 + B[i]);
        }   
    }
    else if(L == A[0] + A[1]){
        if(f(a * b, A[n - 1])) ans++;
    }
}

int main() {
	fastio;
    cin >> n;
    for(int i{0}; i < n; ++i) cin >> A[i];
    cin >> m;
    for(int i{0}; i < m; ++i) {
        cin >> B[i];
        chk[B[i]] = 1;
    }
    dfs(0, 0, 0);
    cout << ans;
}
	
