#include <iostream>

using namespace std;

void f_prefix(string s, int *prefix){

	int length=s.length();
	prefix[0]=0;
	int a=0;
	for(int b=1; b<length; b++){
		while(a>0 && s[a]!=s[b]){
			a=prefix[a-1];
		}
		if(s[a]==s[b]) a++;
		prefix[b]=a;
	}
}

void kmp(string s, string t, int *prefix){

	int i=0; int j=0; int k=0; int n=t.length(); int m=s.length();

	while(n-k>=m){

		while(j<m && t[i]==s[j]){
			i++;
			j++;
		}
		if(j==m) cout<<k<<endl;
		if(prefix[j-1]>0) k=i-prefix[j-1];
		else{
			if(i==k) i++;
			k=i;
		}
		if(j>0) j=prefix[j-1];
	}
}

int main(){
	
	string s,t;
	cin>>s;
	cin>>t;
	int prefix[s.length()];
	f_prefix(s,prefix);
	//for(int i=0; i<s.length(); i++) cout<<prefix[i]<<",";
	kmp(s,t,prefix);

	return 0;

}
