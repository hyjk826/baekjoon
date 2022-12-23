// 2022-12-23
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

vector<vi> ch(1001, vi(1001, -1));

string str;

int f(int l, int r){
    if(l > r) return 0;
    if(ch[l][r] != -1) return ch[l][r];
    if(str[l] == str[r]){
        return ch[l][r] = (f(l + 1, r) + f(l, r - 1) + 1);
    }
    else return ch[l][r] = (f(l + 1, r) + f(l, r - 1) - f(l + 1, r - 1));
}

int main(){
    cin >> str;
    cout << f(0, (int)str.size() - 1);
}
