// 2022-09-06
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    int R, W;
    cin >> R >> W;
    int A = (R + 4) / 2;
    int B = R + W;
    for(int i{1}; i < A; ++i){
        if(i * (A - i) == B){
            cout << max(i, A - i) << " " << min(i, A - i);
            return 0;
        }
    }
}
	

