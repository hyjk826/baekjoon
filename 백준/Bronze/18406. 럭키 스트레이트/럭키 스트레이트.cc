// 2022-07-31
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
    vi vec;
    int sum{0};
    while(n){
        sum += n % 10;
        vec.push_back(n % 10);
        n /= 10;
    }
    int a{0};
    for(int i{0}; i < (int)vec.size() / 2; ++i) a += vec[i];
    if(a * 2 == sum) cout << "LUCKY";
    else cout << "READY";
}

