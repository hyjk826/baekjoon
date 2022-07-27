// 2022-07-27
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    int n;
    cin >> n;
    int ans{0};
    while(n){
        for(int i{1};;++i){
            if(i * (i + 1) / 2 > n){
                n -= (i - 1) * i / 2;
                ans += i - 1;
                break;
            }
        }
    }
    cout << ans;
}

