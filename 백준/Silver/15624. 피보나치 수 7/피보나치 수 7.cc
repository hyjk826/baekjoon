// 2022-08-19
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
	int n;
    cin >> n;
    vi vec(n + 1);
    vec[0] = 0;
    vec[1] = 1;
    for(int i{2}; i <= n; ++i){
        vec[i] = vec[i - 1] + vec[i - 2];
        vec[i] %= MOD;
    }
    cout << vec[n];
}