// 2022-09-09
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
	vi prime(1000001);
    prime[1] = 1;
    for(int i{2}; i <= 1000000; ++i){
        if(prime[i] == 0){
            for(int j{i * 2}; j <= 1000000; j += i){
                prime[j] = 1;
            }
        }
    }
    int l, r;
    cin >> l >> r;
    for(int i{l}; i <= r; ++i){
        if(prime[i] == 0) cout << i << "\n";
    }
}