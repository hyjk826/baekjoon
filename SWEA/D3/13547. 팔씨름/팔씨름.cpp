// 2022-09-24
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
	int T;
	cin >> T;
	for(int t{1}; t <= T; ++t){
		cout << "#" << t << " ";
        string str;
        cin >> str;
        int n = (int)str.size();
        int a, b;
        a = b = 0;
        for(int i{0}; i < n; ++i){
            if(str[i] == 'o') a++;
            else b++;
        }
        a += 15 - n;
        if(a > b) cout << "YES\n";
        else cout << "NO\n";
	}
}
	