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
    vi A(5), B(5);
    for(auto& i : A) cin >> i;
    for(auto& i : B) cin >> i;
    int arr[] = {6,3,2,1,2};
    int a{0}, b{0};
    for(int i{0}; i < 5; ++i){
        a += A[i] * arr[i];
        b += B[i] * arr[i];
    }
    cout << a << " " << b;
}
