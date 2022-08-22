// 2022-08-22
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
    int k{10};
    while(n >= k){
        int a = n % k;
        if(a / (k / 10) >= 5){
            n -= a / (k / 10) * (k / 10);
            n += k;
        }
        else{
            n -= a / (k / 10) * (k / 10);
        }
        k *= 10;
    }
    cout << n;
}

