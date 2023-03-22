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
    string str;
    cin >> str;
    int a = stoi(str);
    int mn{MAX};
    sort(str.begin(), str.end());
    do{
        if(a < stoi(str)) mn = min(mn, stoi(str));
    }while(next_permutation(str.begin(), str.end()));
    if(mn == MAX) cout << 0;
    else cout << mn;
}
