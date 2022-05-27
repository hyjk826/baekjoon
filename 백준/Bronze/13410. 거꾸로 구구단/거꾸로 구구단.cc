// 2022-05-27
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
	int n, m;
    cin >> n >> m;
    int ans{0};
    for(int i{1}; i <= m; ++i){
        int k = n * i;
        int a{0};
        while(k){
            a = a * 10 + k % 10;
            k /= 10;
        }
        ans = max(ans, a);
    }
    cout << ans;
}