// 2022-07-05
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
    vl vec(n + 1);
    vec[1] = 1;
    vec[2] = 1;
    for(int i{3}; i <= n; ++i){
        vec[i] = vec[i -1] + vec[i - 2];
    }
    cout << vec[n] << " " << n - 2;
}