// 2022-11-26
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

vector<vi> ch((int)1e6 + 1);
vi uni((int)1e6 + 1);
vi cnt((int)1e6 + 1);

int find(int a){
    if(a == uni[a]) return a;
    return uni[a] = find(uni[a]);
}


bool Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        uni[a] = b;
        return true;
    }
    return false;
}


int main() {
	vi prime((int)1e6 + 1);
	prime[1] = 1;
	for(int i{2}; i * i <= (int)1e6; ++i){
		if(prime[i] == 0){
			for(int j{i * i}; j <= (int)1e6; j +=i){
				prime[j] = 1;
			}
		}
	}
	fastio;	
	int n;
	cin >> n;
	for(int i{1}; i <= n; ++i){
		int a;
		cin >> a;
		ch[a].push_back(i);
	}
    for(int i{1}; i <= n; ++i){
        uni[i] = i;
    }
	for(int i{2}; i <= (int)1e6; ++i){
		if(prime[i]) continue;
		vi A;
		for(int j{i}; j <= (int)1e6; j += i){
			for(int k{0}; k < (int)ch[j].size(); ++k){
				A.push_back(ch[j][k]);
			}
		}
		for(int j{0}; j < (int)A.size() - 1; ++j){
            Union(A[j], A[j + 1]);
		}
	}
	for(int i{1}; i <= n; ++i){
        cnt[find(i)]++;
    }
    cout << *max_element(cnt.begin(), cnt.end());
}
	
