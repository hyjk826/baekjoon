// 2022-11-21
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
	int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    vi A = vec;
    vi B = vec;
    for(int i{1}; i < n; ++i){
        A[i] = max(A[i], A[i - 1]);
    }
    for(int i{n - 2}; i >= 0; --i){
        B[i] = max(B[i], B[i + 1]);
    }
    int a, b;
    a = b = 0;
    for(int i{0}; i < n - 1; ++i){
        if(A[i] > B[i + 1]) a++;
        else if(A[i]< B[i + 1]) b++;
    }
    if(a > b) cout << "R";
    else if(a < b) cout << "B";
    else cout << "X";
}
	

