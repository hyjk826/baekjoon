// 2022-07-31
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
    vi A(10), B(10);
    int a{0}, b{0};
    int ai{-1}, bi{-1};
    for(int i{0}; i < 10; ++i) cin >> A[i];
    for(int i{0}; i < 10; ++i) cin >> B[i];
    for(int i{0}; i < 10; ++i){
        if(A[i] > B[i]){
            a += 3;
            ai = i;
        }
        else if(B[i] > A[i]){
            b += 3;
            bi = i;
        }
        else{
            a++;
            b++;
        }
    }
    cout << a << " " << b << "\n";
    if(a > b) cout << "A";
    else if(a < b) cout << "B";
    else{
        if(ai == bi) cout << "D\n";
        else if(ai > bi) cout << "A\n";
        else cout << "B\n";
    }
}

