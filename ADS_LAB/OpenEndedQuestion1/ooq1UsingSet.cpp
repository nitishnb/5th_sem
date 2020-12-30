#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
        int n,x;
        cin>>n;
        set<int>v;
        for(int i=0;i<n;i++){
            cin>>x;
            v.insert(x);
        }
        set<int>::iterator it=v.begin();
        for(int i=0;i<v.size()-2;i++)
            cout<<*(it++)<<" ";
        cout<<endl;
    }
}
