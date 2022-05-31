// 2022-05-31
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
	double d1, d2, d3;
    cin >> d1 >> d2 >> d3;
    cout << fixed << setprecision(1);
    double d = (d1 + d2 + d3) / 2;
    if(d > d1 && d > d2 && d > d3){
        cout << 1 << "\n";
        cout << (d1 + d2 - d3) / 2 << " " << (d1 - d2 + d3) / 2 << " " << (-d1 + d2 + d3) / 2;
    }
    else cout << -1 << "\n";
}