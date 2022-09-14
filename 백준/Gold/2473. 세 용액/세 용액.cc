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
#define MAX 1000000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    int n;
    cin >> n;
    vl vec(n);
    for(int i{0}; i < n; ++i) cin >> vec[i];
    sort(vec.begin(), vec.end());
    if(vec[0] >= 0){
        cout << vec[0] << " " << vec[1] << " " << vec[2];
    }
    else{
        ll a{0}, b{0}, c{(ll)1e16};
        for(int i{0}; i < n; ++i){
            int l = i + 1;
            int r = n - 1;
            ll x{0}, y{(ll)1e16};
            while(l < r){
                ll sum = vec[l] + vec[r];
                if(abs(sum + vec[i]) < abs(x + y + vec[i])){
                    x = vec[l];
                    y = vec[r];
                }
                if(sum >= -vec[i]){
                    r--;
                }
                else l++;
            }
            if(abs(vec[i] + x + y) < abs(a + b + c)){
                a = vec[i];
                b = x;
                c = y;
            }
        }
        cout << a << " " << b << " " << c;
    }
}
	

