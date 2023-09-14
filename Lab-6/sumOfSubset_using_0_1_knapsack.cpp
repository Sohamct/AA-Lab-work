// 0/1 knapsack problem
#include <bits/stdc++.h>


using namespace std;


int main(){

	cout << "solving sum of subset using 0/1 knapsack" << endl;
	cout << "Enter the size of the subset: ";
	int sz;
	cin >> sz;
	cout << "Enter the target sum: ";
	int sum;
	cin >> sum;

	vector<int> v(sz);
	cout << "Enter elemets of sos: " ;
	for(int i = 0; i < sz; i++){
    	cin >> v[i];
	}
    
	int n = sz, m = sum;

	int T[n+1][m+1];

	int p[n+1];
	int w[n+1];

	for(int i = 1; i <= n; i++) p[i] = v[i-1];

	for(int i = 1; i <= n; i++) w[i] = v[i-1];
    
	for(int i = 0; i <= n; i++){
    	T[i][0] = 0;
	}
    
	for(int i = 0; i <= m; i++){
    	T[0][i] = 0;
	}

	for(int i =1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
        	if(j < w[i]){
            	T[i][j] = T[i-1][j];
        	}
        	else{
            	T[i][j] = max(T[i-1][j], p[i] + T[i-1][j - w[i]]);
        	}
    	}
	}
	cout << T[n][m] << endl;
	if(T[n][m] >= sum){
    	cout << "True" << endl;
	}
	else
	{
    	cout << "False" << endl;
	}
    
	int i = n;
	int j = m;
    
	int x[n+1];
    
	while(i > 0 && j > 0){
		if(T[i][j] != T[i-1][j]){
	    	x[i] = 1;
	    	j = j - w[i];
	    	i = i - 1;
		}
		else{
	    	x[i] = 0;
	    	i--;
		}
	}
    
	for(int i = 1; i <= n; i++){
		cout << x[i] << " ";
	}
    
	return 0;
}
