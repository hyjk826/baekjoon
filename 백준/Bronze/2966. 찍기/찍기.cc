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
	int n;
    cin >> n;
    string str;
    cin >> str;
    string A, B, C;
    A = "ABC"; B = "BABC"; C = "CCAABB";
    vi vec(3);
    for(int i{0}; i < n; ++i){
        if(str[i] == A[i % (int)A.size()]) vec[0]++;
        if(str[i] == B[i % (int)B.size()]) vec[1]++;
        if(str[i] == C[i % (int)C.size()]) vec[2]++;
    }
    int k = *max_element(vec.begin(), vec.end());
    vs name = {"Adrian", "Bruno", "Goran"};
    cout << k << "\n";
    for(int i{0}; i < 3; ++i){
        if(k == vec[i]) cout << name[i] << "\n";
    }
}
