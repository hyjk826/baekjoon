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
	int n;
    cin >> n;
    for(int i{0}; i < 9; ++i){
        cout << n << " * " << i + 1 << " = " << n * (i + 1) << "\n";
    }
}