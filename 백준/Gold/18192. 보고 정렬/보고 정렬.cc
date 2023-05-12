#include "bogoSort.h"
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

void sort_array(int n){
    vi vec = copy_array();
    while(1){
        int idx{-1};
        for(int i{0}; i < n; ++i){
            if(vec[i] != i){
                idx = i; break;
            }
        }
        if(idx == -1) break;        
        while(vec[idx] != idx){
            int idx2{-1};
            for(int i{idx + 1}; i < n; ++i){
                if(vec[i] == idx){
                    idx2 = i; break;
                }                
            }
            shuffle_array(idx, idx2);
            vec = copy_array();
        }
    }
}