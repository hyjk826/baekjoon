// 2022-11-20
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

int check(int n){
    for(int i{2}; i * i <= n; ++i){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main() {
	fastio;	
    string s, t;
    cin >> s >> t;
    t += s;
    if(check(stoi(s)) && check(stoi(t))) cout << "Yes";
    else cout << "No";
}
	

