// 2022-09-09
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

vector<vi> com(11, vi(11, -1));

int f(int a, int b){
    if(com[a][b] != -1) return com[a][b];
    if(b == 0 || a == b) return com[a][b] = 1;
    return com[a][b] = f(a - 1, b - 1) + f(a - 1, b);
}

int main(){
    fastio;
    int n, m;
    cin >> n >> m;
    cout << f(n, m);
}