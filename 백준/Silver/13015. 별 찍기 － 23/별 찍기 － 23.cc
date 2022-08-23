// 2022-08-23
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
    cout << string(n, '*') << string(2 * (n - 1) - 1, ' ') << string(n, '*') << "\n";
    for(int i{0}; i < n - 2; ++i){
        cout << string(i + 1, ' ') << '*' << string(n - 2, ' ') << '*' << string(2 * (n - 2 - i) - 1, ' ') << '*' << string(n - 2, ' ') << '*' << "\n";
    }
    cout << string(n - 1, ' ') << '*' << string(n - 2, ' ') << '*' << string(n - 2, ' ') << '*' << "\n";
    for(int i{0}; i < n - 2; ++i){
        cout << string(n - 2 - i, ' ') << '*' << string(n - 2, ' ') << '*' << string(i * 2 + 1, ' ') << '*' << string(n - 2, ' ') << '*' << "\n";
    }
    cout << string(n, '*') << string(2 * (n - 1) - 1, ' ') << string(n, '*') << "\n";
}

