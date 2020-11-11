#include<bits/stdc++.h>
using namespace std;

bool Func(int* arr,int n,int sum){
	bool dp[n+1][sum+1];
	for(int j=0; j<=sum; j++){
		dp[0][j] = false;
	}
	for(int i=0; i<=n; i++){
		dp[i][0] = true;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=sum; j++){
			if(j-arr[i-1]>=0)
				dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	for(int i=0; i<=n; i++){
		for(int j=0; j<=sum; j++){
			cout << dp[i][j]<< " " ;
		}
		cout << endl;
	}
	return dp[n][sum];
	/*if(n==0 && sum != 0) return false;
	if (sum==0) return true;
	else{
		return Func(arr,n-1,sum-arr[n-1]) || Func(arr,n-1,sum);
	}*/
}

int main()
{
	int n,sum;
	sum=0;
	cin >> n;
	int* arr = new int[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
		sum = sum + arr[i];
	}
	if(abs(sum)%2 != 0){
		cout << "NO";
	}
	else{
		if( Func(arr,n,sum/2) ) cout << "YES";
		else cout << "NO";
	}
return 0;
}
