// 2022-11-20
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
    
vi prime((int)1e7 + 1);

int main() {
	fastio;	
    int t;
    cin >> t;    
    prime[1] = 1;
    int sz = (int)1e7;
    for(ll i{2}; i <= sz; ++i){
        if(prime[i] == 0){
            for(ll j{i * i}; j <= sz; j += i){
                prime[j] = 1;
            }
        }
    }
    while(t--){
        int ans{0};
        string str;
        cin >> str;
        sort(str.begin(), str.end());
        set<int> st;
        do{            
            string s;
            for(int i{0}; i < (int)str.size(); ++i){
                if(s.empty() && str[i] == 0) continue;
                s += str[i];
                st.insert(stoi(s));
            }            
        }while(next_permutation(str.begin(), str.end()));
        for(auto& i : st){
            if(i == 0) continue;
            if(prime[i] == 0){
                ans++;
            }
        }
        cout << ans << "\n";
    }
		
}
	

