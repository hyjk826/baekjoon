// 2022-05-29
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

bool isPrime(int n){
    for(int i{2}; i * i <= n; ++i){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    fastio;
	int n, k;
    cin >> n >> k;
    vi vec;
    for(int i{2000};;++i){
        if(vec.size() == n) break;
        if(isPrime(i)) vec.push_back(i);
    }
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < k; ++j){
            cout << vec[i] * (j + 1)<< " ";
        }
        cout << "\n";
    }
}