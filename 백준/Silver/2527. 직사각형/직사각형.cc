// 2022-11-28
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


int main() {
	fastio;
	for(int i{0}; i < 4; ++i){
        vi A(4), B(4);
        for(int j{0}; j < 4; ++j){
            cin >> A[j];
        }
        for(int j{0}; j < 4; ++j){
            cin >> B[j];
        }
        int a = max(A[0], B[0]);
        int b = min(A[2], B[2]);
        int c = max(A[1], B[1]);
        int d = min(A[3], B[3]);
        if(a > b || c > d) cout << "d" << "\n";
        else if(b - a == 0 && d - c == 0) cout << "c" << "\n";
        else if(b - a == 0 || d - c == 0) cout << "b" << "\n";
        else cout << "a" << "\n";
    }
}
	
