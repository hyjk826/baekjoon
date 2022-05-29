// 2022-05-28
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

int main(){
    fastio;
	int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    int x = a * 60 + b;
    int y = c * 60 + d;
    int ans{0};
    for(int i{x}; i <= y; ++i){
        int h = i / 60;
        int m = i % 60;
        if(h / 10 == e || h % 10 == e || m / 10 == e || m % 10 == e) ans++;
    }
    cout << ans;
}