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
    vl vec(n + 1);
    vl odd(n + 1), even(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
        if(i & 1) odd[i] = vec[i];
        else even[i] = vec[i];
        odd[i] += odd[i - 1];
        even[i] += even[i - 1];
    }

    vl b(n);
    for(int i{1}; i <= n; ++i){
        if(i & 1) b[0] += i * vec[i];
        else b[0] -= i * vec[i];
    }
    for(int i{1}; i < n; ++i){
        ll sum{0};
        if(n & 1){
            if(i & 1){
                sum -= even.back() - even[i];
                sum += odd.back() - odd[i];
                sum -= odd[i - 1];
                sum += even[i];
            }
            else{
                sum += even.back() - even[i];
                sum -= odd.back() - odd[i];
                sum += odd[i - 1];
                sum -= even[i - 1];
            }
            sum += (n + 1) * vec[i];
        }
        else{
            if(i & 1){
                sum += odd.back();
                sum -= even.back();
                sum -= odd[i] - odd[i - 1];
            }
            else{
                sum += even.back();
                sum -= odd.back();
                sum -= even[i] - even[i - 1];
            }
            sum -= (n - 1) * vec[i];
        }
        b[i] = sum - b[i - 1];
    }
    for(auto& i : b) cout << i << " ";
}
