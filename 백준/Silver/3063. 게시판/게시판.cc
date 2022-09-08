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
	int t;
    cin >> t;
    while(t--){
        vi A(4), B(4);
        for(int i{0}; i < 4; ++i) cin >> A[i];
        for(int i{0}; i < 4; ++i) cin >> B[i];
        int a = max(A[0], B[0]);
        int b = min(A[2], B[2]);
        int c = max(A[1], B[1]);
        int d = min(A[3], B[3]);
        int ans = (A[2] - A[0]) * (A[3] - A[1]);
        if(a <= b && c <= d){
            ans -= (b - a) * (d - c);
        }
        cout << ans << "\n";
    }
}