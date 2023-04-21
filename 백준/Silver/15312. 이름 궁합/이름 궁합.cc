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

int arr[] = {3,2,1,2,3,3,2,3,3,2,2,1,2,2,1,2,2,2,1,2,1,1,1,2,2,1};

int main(){
	fastio;
    string s, t;
    cin >> s >> t;
    string str;
    vi A;
    for(int i{0}; i < (int)s.size(); ++i){
        A.push_back(arr[s[i] - 'A']);
        A.push_back(arr[t[i] - 'A']);
    }
    while(A.size() != 2){
        vi temp;
        for(int i{0}; i < (int)A.size() - 1; ++i){
            temp.push_back((A[i] + A[i + 1]) % 10);
        }
        swap(A, temp);
    }
    cout << A[0] << A[1];
}
