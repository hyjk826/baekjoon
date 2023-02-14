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
    int n;
    cin >> n;
    if(n == 1){
        cout << 1; return 0;
    }
    if(n & 1) cout << -1;
    else{
        vi A;
        A.push_back(0);
        for(int i{0}; i < n / 2; ++i){
            A.push_back(i);
            A.push_back(n - 1 - i);
        }
        for(int i{1}; i <= n; ++i){
            int a = A[i] - A[i - 1];
            if(a <= 0) a += n; 
            cout << a << " ";
        }
    }
}
