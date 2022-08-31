// 2022-08-31
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
    for(int i{0};;++i){
        int n;
        cin >> n;
        if(n == 0) break;
        cout << i + 1 << ". ";
        int n1 = 3 * n;
        if(n1 & 1) cout << "odd ";
        else cout << "even ";
        int n2 = (n1 + 1) / 2;
        int n3 = 3 * n2;
        int n4 = n3 / 9;
        cout << n4 << "\n";
    }
}

