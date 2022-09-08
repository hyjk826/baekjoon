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

int main(){
    fastio;
	int h, m;
    cin >> h >> m;
    int k = h * 60 + m + 1440;
    k -= 45;
    int a = k / 60;
    if(a >= 24) a -= 24;
    cout << a << " " << k % 60;
}