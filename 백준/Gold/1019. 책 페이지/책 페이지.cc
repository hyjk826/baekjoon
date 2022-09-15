// 2022-09-06
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

vi ans(10);

void f(int n, int cnt){
    while(n){
        ans[n % 10] += cnt;
        n /= 10;
    }
}

int main() {
	fastio;
    int n;
    cin >> n;
    int l{1};
    int k{1};
    while(l <= n){
        while(n % 10 != 9 && l <= n){
            f(n, k);
            n--;
        }
        if(l > n) break;
        while(l % 10 != 0 && l <= n){
            f(l, k);
            l++;
        }
        l /= 10;
        n /= 10;
        for(int i{0}; i < 10; ++i){
            ans[i] += (n - l + 1) * k;
        }
        k *= 10;
    }
    for(auto& i : ans){
        cout << i << " ";
    }
}
	

