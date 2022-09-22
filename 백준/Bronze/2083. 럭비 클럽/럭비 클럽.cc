// 2022-09-22
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
        string str;
        int a, b;
        cin >> str >> a >> b;
        if(str == "#") break;
        if(a > 17 || b >= 80) cout << str << " " << "Senior\n";
        else cout << str << " " << "Junior\n";
    }
}
	

