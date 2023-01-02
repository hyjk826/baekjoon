// 2023-01-03
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
    int a, b;
    cin >> a >> b;
    vi A, B;
    for(int i{1}; i * i <= a; ++i){
        if(a % i == 0){
            if(i * i == a) A.push_back(i);
            else{
                A.push_back(i);
                A.push_back(a / i);
            }
        }
    }
    for(int i{1}; i * i <= b; ++i){
        if(b % i == 0){
            if(i * i == b) B.push_back(i);
            else{
                B.push_back(i);
                B.push_back(b / i);
            }
        }
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for(auto& i : A){
        for(auto& j : B){
            cout << i << " " << j << "\n";
        }
    }
}
