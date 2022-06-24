// 2022-06-24
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
    while(1){
        int n, m;
        double d;
        cin >> n >> m >> d;
        if(d == 0.0) break;
        vector<double> A(n), B(m);
        for(int i{0}; i < n; ++i){
            cin >> A[i];
        }
        for(int i{0}; i < m; ++i){
            cin >> B[i];
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        double a = 0.0;
        double b = 0.0;
        for(int i{0}; i < n; ++i){
            if(A[i] - a > d / 2) break;
            a = A[i] + d / 2;           
        }
        for(int i{0}; i < m; ++i){
            if(B[i] - b > d / 2) break;
            b = B[i] + d / 2;
        }
        if(a >= 75.0 && b >= 100.0) cout << "YES\n";
        else cout << "NO\n";
    }
}
