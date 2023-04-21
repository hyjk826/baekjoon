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

int mex[(int)3e6 + 1];

int main(){
	fastio;
	vi fibo;
	fibo.push_back(1);fibo.push_back(2);
	while(1){
		int sz = (int)fibo.size();
		int a = fibo[sz - 1]; 
		int b = fibo[sz - 2];
		if(a + b <= (int)3e6) fibo.push_back(a + b);
		else break;
	}
	set<int> st;
	for(int i{1}; i <= 3e6; ++i){
		vi ch(20);
		for(int j{0}; j < (int)fibo.size() && i - fibo[j] >= 0; ++j){
			if(mex[i - fibo[j]] < 20) ch[mex[i - fibo[j]]] = 1;
			
		}
		for(int j{0}; j < 20; ++j){
			if(ch[j] == 0){
				mex[i] = j; break;
			}
		}
	}
    int n;
	cin >> n;
	int ans{0};
	for(int i{0}; i < n; ++i){
		int a;
		cin >> a;
		ans ^= mex[a];
	}
	if(ans) cout << "koosaga";
	else cout << "cubelover";
}
