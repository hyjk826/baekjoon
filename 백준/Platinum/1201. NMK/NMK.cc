// 2023-01-12
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
    int n, m, k;
    cin >> n >> m >> k;
    vi A;
    if(m + k - 1 <= n && n <= m * k){
        n -= k;
        A.push_back(k);
        for(int i{2}; i <= m; ++i){
            int a = min(k, n - (m - i));
            n -= a;
            A.push_back(a);
        }
        int sum{0};
        for(int i{0}; i < (int)A.size(); ++i){
            sum += A[i];
            for(int j{sum}; j > sum - A[i]; --j){
                cout << j << " ";
            }
        }
    }
    else cout << -1;
}
