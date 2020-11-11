#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> mat){
    int n= mat.size();
    unordered_map<int,int> m, t, u;
    for(int j=0; j<n; j++){
        m[mat[0][j]]++;
    }
    for(int i=1; i<n; i++){
        u=m;
        for(int j=0; j<n; j++){
            t[mat[i][j]]++;
        }
        for(auto x:u){
            if(m.size()==0) break;
            if(!t[x.first]) m.erase(x.first);
            else if(t[x.first] != x.second) x.second=min(x.second,t[x.first]);
        }
        if(m.size()==0) break;
        t.clear();
    }
    // for(auto x:m) cout<<x.first<<" ";
    // cout<<endl;
    int ans=0;
    for(auto x:m) ans+=x.second;
    return ans;
    
}
int main() {
	int n;
	cin>>n;
	vector<vector<int>> mat(n,vector<int>(n));
	for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin>>mat[i][j];
	cout<< solve(mat);
	return 0;
}
