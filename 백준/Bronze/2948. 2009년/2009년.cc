// 2022-09-05
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
    vi arr = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vs v = {"Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"};
    int d, m;
    cin >> d >> m;
    int sum{-1};
    for(int i{0}; i < m - 1; ++i){
        sum += arr[i];
    }
    sum += d;
    cout << v[sum % 7];
}
	

