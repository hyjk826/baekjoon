// 2023-01-13
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
    int n;
    cin >> n;
    string str;
    n++;
    while(n){
        if(n % 2 == 0) str += '4';
        else str += '7';
        n /= 2;
    }
    reverse(str.begin(), str.end());
    cout << str.substr(1);
}
