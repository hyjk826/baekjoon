// 2022-12-01
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
    int n;
    cin >> n;
    int a;
    cin >> a;
    vi A, B;
    bool zero = false;
    if(a < 0) a *= -1;
    if(a == 0) zero = true;
    A.push_back(a);
    for(int i{0}; i < n - 1; ++i){
        char c;
        cin >> c >> a;
        if(a == 0) zero = true;
        if(a == 1) continue;
        if(a < 0) a *= -1;
        if(c == '*') A.push_back(a);
        else B.push_back(a);
    }
    if(zero){
        cout << "mint chocolate";
        return 0;
    }
    vi cnt((int)1e5 + 1);
    for(int i{0}; i < (int)A.size(); ++i){
        for(int j{2}; j * j <= A[i]; ++j){
            while(A[i] % j == 0){
                cnt[j]++;
                A[i] /= j;
            }            
        }
        if(A[i] != 1) cnt[A[i]]++;
    }
    for(int i{0}; i < (int)B.size(); ++i){
        for(int j{2}; j * j <= B[i]; ++j){
            while(B[i] % j == 0){
                cnt[j]--;
                B[i] /= j;
            }
        }
        if(B[i] != 1) cnt[B[i]]--;
    }
    for(int i{2}; i <= (int)1e5; ++i){
        if(cnt[i] < 0){
            cout << "toothpaste";
            return 0;
        }
    }
    cout << "mint chocolate";
}
	
