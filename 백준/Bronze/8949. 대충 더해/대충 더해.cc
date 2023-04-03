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
    string a, b;
    cin >> a >> b;
    int dif = abs((int)a.size() - (int)b.size());
    if(a.size() > b.size()) swap(a, b);
    a = string(dif, '0') + a;
    for(int i{0}; i < (int)a.size(); ++i){
        cout << a[i] + b[i] - '0' - '0';
    }
}
