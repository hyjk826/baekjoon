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
    ll x, n;
    cin >> x >> n;
    vl A;
    A.push_back(x);
    set<ll> st;
    st.insert(x);
    int cycle{0};
    int idx{-1};
    for(int i{1}; i <= 1000; ++i){
        if(x & 1) x = (x << 1) ^ 6;
        else x = (x >> 1) ^ 6;
        if(st.count(x)){
            for(int j{0}; j < (int)A.size(); ++j){
                if(A[j] == x){
                    cycle = i - j; 
                    idx = j; break;
                }
            }
            break;
        }
        st.insert(x);
        A.push_back(x);
    }
    if(n < idx) cout << A[n];
    else{
        cout << A[idx + (n - idx) % cycle];
    }   
}
