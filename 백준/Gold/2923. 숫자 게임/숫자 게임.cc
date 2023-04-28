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

int A[101];
int B[101];
int X[101], Y[101];

int main(){
	fastio;
    int n;
    cin >> n;
    for(int i{0}; i < n; ++i){
        int a, b;
        cin >> a >> b;
        A[a]++; B[b]++;        
        for(int j{1}; j <= 100; ++j) {
            X[j]= A[j]; Y[j] = B[j];
        }
        int x{1}, y{100};
        int mx{0};
        while(x <= 100 && y >= 1){
            while(x <= 100 && X[x] == 0) x++;
            while(y >= 1 && Y[y] == 0) y--;
            if(x <= 100 && y >= 1) mx = max(mx, x + y);
            int k = min(X[x], Y[y]);
            X[x] -= k; Y[y] -= k;
        }
        cout << mx << "\n";
    }
}
