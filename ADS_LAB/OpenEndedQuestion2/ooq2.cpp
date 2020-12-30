#include<bits/stdc++.h> 
using namespace std; 


vector<int> printUnique(int l, int r){ 
    vector<int> a;
	for (int i=l ; i<=r ; i++){ 
		int x = i; 
		int digit[10] = {0}; 
		while(x){
			if (digit[x % 10]) 
				break; 
			digit[x%10] = 1; 
			x /= 10; 
		} 
		if (x == 0) 
			a.push_back(i); 
	}
    return a; 
} 


int main(){ 
	int L, R;
    cout<<"L = ";
    cin>>L;
    cout<<"R = ";
    cin>>R;
	vector<int> res = printUnique(L, R); 
    for(int i: res){
        cout<<i<<" ";
    }
	return 0; 
} 
