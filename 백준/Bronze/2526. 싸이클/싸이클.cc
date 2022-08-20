// 2022-08-21
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
	int n, p;
    cin >> n >> p;
    vi vec;
    vec.push_back(n);
    set<int> st;
    while(1){
        int k = vec.back() * n % p;
        if(st.count(k)){
            for(int i{0}; i < (int)vec.size(); ++i){
                if(vec[i] == k){
                    cout << (int)vec.size() - i;
                    return 0;
                }
            }
        }
        else{
            st.insert(k);
            vec.push_back(k);
        }
    }
}