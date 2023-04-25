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

vi divisor(int n){
    vi ret;
    for(int i{1}; i * i <= n; ++i){
        if(n % i == 0){
            if(i * i == n) ret.push_back(i);
            else{
                ret.push_back(i);
                ret.push_back(n / i);
            }
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int main(){
	fastio;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi vec(n);
        int sum{0};
        for(int i{0}; i < n; ++i){
            cin >> vec[i];
            sum += vec[i];
        }
        vi div = divisor(sum);
        for(auto& i : div){
            sum = 0;
            for(int j{0}; j < n; ++j){
                sum += vec[j];
                if(sum == i){
                    sum = 0;
                }
                else if(sum > i){
                    sum = MAX; break;
                }                
            }
            if(sum != MAX){
                cout << i << "\n"; break;
            }
        }
    }
}
