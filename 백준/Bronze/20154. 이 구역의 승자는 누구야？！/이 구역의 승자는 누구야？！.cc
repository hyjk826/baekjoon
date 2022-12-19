// 2022-12-20
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
	vi A = {3,2,1,2,3,3,3,3,1,1,3,1,3,3,1,2,2,2,1,2,1,1,2,2,2,1};
    string str;
    cin >> str;
    vi B;
    for(auto& c : str){
        B.push_back(A[c - 'A']);
    }
    while(B.size() >= 2){
        vi C;
        for(int i{0}; i < (int)B.size(); i += 2){
            if(i == (int)B.size() - 1) C.push_back(B[i]);
            else C.push_back((B[i] + B[i + 1]) % 10);
        }
        swap(B, C);
    }
    if(B.front() & 1) cout << "I'm a winner!";
    else cout << "You're the winner?";
}
	
