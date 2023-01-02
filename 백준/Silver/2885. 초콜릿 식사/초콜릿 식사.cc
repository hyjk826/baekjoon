// 2023-01-03
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
    int k;
    cin >> k;
    int a{1};
    while(a < k) a *= 2;
    int b = a;
    int cnt{0};
    while(k % b != 0){
        b /= 2;
        cnt++;
    }
    cout << a << " " << cnt;
}
