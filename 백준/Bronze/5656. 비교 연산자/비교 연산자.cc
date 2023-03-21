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
    int a, b; string op;
    int cnt{1};
    while(cin >> a >> op >> b){
        if(op == "E") break;
        bool ok = true;
        if(op == "!=") ok &= (a != b);
        else if(op == ">=") ok &= (a >= b);
        else if(op == "<") ok &= (a < b);
        else if(op == "<=") ok &= (a <= b);
        else if(op == "==") ok &= (a == b);
        else if(op == ">") ok &= (a > b);
        cout << "Case " << cnt << ": ";
        if(ok) cout << "true\n";
        else cout << "false\n";
        cnt++;
    }
}
