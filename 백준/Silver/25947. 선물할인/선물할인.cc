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

int main(){
	fastio;
    int n, b, a;
    cin >> n >> b >> a;
    vl A(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> A[i];
    }
    sort(A.begin() + 1, A.end());
    vl B = A;
    for(int i{1}; i <= n; ++i){
        B[i] /= 2;
        A[i] += A[i - 1];
        B[i] += B[i - 1];
    }
    for(int i{n}; i >= 1; --i){
        ll sum{0};
        sum += B[i] - B[max(0, i - a)];
        sum += A[max(0, i - a)];
        if(sum <= b){
            cout << i; return 0;
        }
    }
    cout << 0;
}
