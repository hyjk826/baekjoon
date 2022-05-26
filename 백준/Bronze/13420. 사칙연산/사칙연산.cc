// 2022-05-27
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

ll f(ll a, char c, ll b){
    if(c == '*') return a * b;
    else if(c == '+') return a + b;
    else if(c == '-') return a - b;
    else return a / b;
}

int main(){
    fastio;
    int t;
    cin >> t;
    while(t--){
        ll a, b, k;
        char c1, c2;
        cin >> a >> c1 >> b >> c2 >> k;
        if(f(a, c1, b) == k) cout << "correct\n";
        else cout << "wrong answer\n";
    }
}