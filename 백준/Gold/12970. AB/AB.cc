// 2022-09-20
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
    int n, k;
    cin >> n >> k;
    int a = n / 2;
    if(k > a * (n - a)) cout << -1;
    else{
        string ans;
        for(int i{0}; i < a; ++i){
            ans += 'A';
        }
        for(int i{0}; i < n - a; ++i){
            ans += 'B';
        }
        int cnt = a * (n - a);
        for(int i{a - 1}; i >= 0; --i){
            if(cnt == k) break;
            for(int j{i + 1}; j < n; ++j){
                if(ans[j] == 'B') {
                    swap(ans[j - 1], ans[j]);
                    cnt--;
                }
                if(cnt == k) break;
            }
        }
        cout << ans;
    }
}
	

