// 2022-09-06
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
    vi prime(1000001);
    for(int i{2}; i <= 1000000; ++i){
        if(prime[i] == 0){
            for(int j{i * 2}; j <= 1000000; j += i){
                prime[j] = 1;
            }
        }
    }
    set<int> st;
    for(int i{2}; i <= 1000000; ++i){
        if(prime[i]) continue;
        st.insert(i);
    }
    int n;
    cin >> n;
    if(n < 8) cout << -1;
    else{
        if(n & 1){
            cout << 2 << " " << 3 << " ";
            n -= 5;
        }
        else{
            cout << 2 << " " << 2 << " ";
            n -= 4;
        }
        for(auto& i : st){
            if(st.count(n - i)){
                cout << i << " " << n - i;
                return 0;
            }
        }
    }
}
	

