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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi A(n), B(n);
        for(int i{0}; i < n; ++i){
            cin >> A[i];
        }
        vi C(n + 1);
        for(int i{0}; i < n; ++i){
            cin >> B[i];
            C[B[i]] = i;
        }
        function<void(int,int,int,int)> f = [&](int l1, int r1, int l2, int r2){
            int idx = C[A[l1]];
            int a = idx - l2;
            int b = r2 - idx;
            if(a) f(l1 + 1, l1 + a, l2, idx - 1);
            if(b) f(l1 + a + 1, r1, idx + 1, r2);
            cout << A[l1] << " ";
        };  
        f(0, n - 1, 0, n - 1);
        cout << "\n";
    }
}
