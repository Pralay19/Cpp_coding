#include<bits/stdc++.h>
using namespace std;

int main(){
	string str1="abd";
	string str2="aabccad";
	sort(str1.begin(),str1.end());
	sort(str2.begin(),str2.end());

	int i=0,j=0;
	int ops=0;
	while(i<str1.size() && i<=j && j<str2.size()){
		if(str1[i]==str2[j]){
			
		}
		else{
			ops++;
			string a=str1.substr(0,i+1);
			string b=str1.substr(i+1,str1.size()-1-(i+1)+1);
			str1=a+str2[j]+b;
			cout<<str1<<endl;
		}
		i++;j++;
	}
	if(i==str1.size()){
		str1=str1+str2.substr(j,str2.size()-j+1);
	}
	cout <<ops<<endl;
}