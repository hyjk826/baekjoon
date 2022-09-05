// 2022-09-05
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
    int t;
    cin >> t;
    for(int T{0}; T < t; ++T){
        cout << "Battle " << T + 1 << ": ";
        vi A, B;
        A = {1,2,3,3,4,10};
        B = {1,2,2,2,3,5,10};
        int a{0}, b{0};
        for(int i{0}; i < 6; ++i){
            int x;
            cin >> x;
            a += A[i] * x;
        }
        for(int i{0}; i < 7; ++i){
            int x;
            cin >> x;
            b += B[i] * x;
        }
        if(a > b) cout <<  "Good triumphs over Evil\n";
        else if(a < b) cout << "Evil eradicates all trace of Good\n";
        else cout <<  "No victor on this battle field\n";
    }
}
	

