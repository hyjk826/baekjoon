// 2022-09-14
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
    int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    int l{0}, r{n - 1};
    int a{0}, b{MAX};
    while(l < r){
        int sum = vec[l] + vec[r];
        if(abs(sum) < abs(b + a)){
            a = vec[l];
            b = vec[r];
        }
        if(sum >= 0){
            r--;
        }
        else{
            l++;
        }
    }
    cout << a << " " << b;
}
	

