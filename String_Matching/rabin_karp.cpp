#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector<int> Rabin_Karp(string text, string pattern, int primo){
	
	long long x,aux;
	int n,m;
	vector<int> match;
	x=0;
	aux=0;
	n=text.length();
	m=pattern.length();

	for(int i=0; i<m; ++i){

		x=x+pattern[i]*pow(primo,i);
		aux=aux+text[i]*pow(primo,i);
	}

	for(int i=m; i<=n; ++i){
	
		if(aux==x && text.substr(i-m,m)==pattern)
			match.push_back(i-m);
		if(i<n) aux=(aux-text[i-m])/primo+pow(primo,m-1)*text[i];
	}

	return match;
}


int main(){
	
	string text,pattern;
	vector<int> match;
	cin>>text>>pattern;
	match=Rabin_Karp(text,pattern,131);
	for(int i=0; i<match.size();++i) cout<<match[i]<<",";
	cout<<endl;

	return 0;

}
