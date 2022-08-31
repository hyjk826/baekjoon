// 2022-09-01
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
    while(1){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0) break;
        if(b - a == c - b) cout << "AP " << c + c - b << "\n";
        else cout << "GP " << c * (c / b) << "\n";
    }
}

