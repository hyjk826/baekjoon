// 2022-12-04
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


int main() {
	fastio;
	vs vec(3);
    set<char> st;
    vi ch2(26);
    int idx{1};
    for(int i{0}; i < 3; ++i){
        cin >> vec[i];
        for(auto& j : vec[i]){
            if(ch2[j - 'A'] == 0) ch2[j - 'A'] = idx++;
        }
    }
    vi A;
    for(int i{0}; i < 10; ++i){
        A.push_back(i);
    }
    do{
        vi ch(26);
        vi B(3);
        for(int i{0}; i < 3; ++i){
            for(auto& j : vec[i]){
                B[i] = B[i] * 10 + A[ch2[j - 'A'] - 1];
            }
        }
        if(B[0] + B[1] == B[2]){
            cout << "YES";
            return 0;
        }
    }while(next_permutation(A.begin(), A.end()));
    cout << "NO";
}
	
