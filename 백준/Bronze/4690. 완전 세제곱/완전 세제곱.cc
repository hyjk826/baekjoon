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

int f(int a){
    return a * a * a;
}

int main(){
	fastio;
    for(int i{2}; i <= 100; ++i){
        for(int j{2}; j <= 100; ++j){
            for(int a{j}; a <= 100; ++a){
                for(int b{a}; b <= 100; ++b){
                    if(f(i) == f(j) + f(a) + f(b)){
                        cout << "Cube = " << i << ", Triple = (" << j << "," << a << "," << b << ")\n";
                    }
                }
            }
        }
    }
}
