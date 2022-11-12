// 2022-11-13
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
    vi prime(111);
    prime[1] = 1;
    for(int i{2}; i < 111; ++i){
        if(prime[i] == 0){
            for(int j{i * 2}; j <= 111; j += i){
                prime[j] = 1;
            }
        }
    }
    vi A;
    for(int i{1}; i < 111; ++i){
        if(prime[i] == 0) A.push_back(i);
    }
    vi B;
    for(int i{0}; i < (int)A.size() - 1; ++i){
        B.push_back(A[i] * A[i + 1]);
    }
    int n;
    cin >> n;
    cout << *upper_bound(B.begin(), B.end(), n);
}
	

