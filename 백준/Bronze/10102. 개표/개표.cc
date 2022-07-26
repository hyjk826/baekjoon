// 2022-07-26
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
    string str;
    cin >> str;
    int a = count(str.begin(), str.end(), 'A');
    int b = n - a;
    if(a == b) cout << "Tie";
    else if(a > b) cout << "A";
    else cout << "B";
}

