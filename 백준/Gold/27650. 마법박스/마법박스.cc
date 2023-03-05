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
    vi prime(n + 1);
    vi A;
    for(ll i{2}; i <= n; ++i){
        if(prime[i]) continue;
        A.push_back(i);
        for(ll j{i * i}; j <= n; j += i){
            prime[j] = 1;
        }
    }
    int l{0}, r{(int)A.size() - 1};
    int ans{-1};
    while(l <= r){
        int mid{(l + r) / 2};
        cout << "? " << A[mid] << endl;
        int a;
        cin >> a;
        if(a == 1){
            l = mid + 1;
        }
        else{
            ans = mid;
            r = mid - 1;
        }
    }
    cout << "! " << A[ans] << endl;
}
