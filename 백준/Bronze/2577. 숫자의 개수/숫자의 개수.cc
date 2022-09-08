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
	int a, b, c;
    cin >> a >> b >> c;
    int k = a * b * c;
    vi cnt(10);
    while(k){
        cnt[k % 10]++;
        k /= 10;
    }
    for(auto& i : cnt) cout << i << "\n";
}