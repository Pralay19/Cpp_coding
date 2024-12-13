#include<bits/stdc++.h>
using namespace std;

int count_k_digit(string str,int x){
	if(str=="") return 0;
	int n=str.size();
	sort(str.begin(),str.end());
	int l=0,r=n-1;
	int start=0;
	while(l<=r && r<n){
		int mid=(l+r)/2;
		if((str[mid]-'0')==x){
			if((str[mid+1]-'0')==x && (str[mid-1]-'0')!=x){
				start=mid;
				break;
			}
			else if((str[mid-1]-'0')==x && (str[mid+1]-'0')!=x){
				while((str[mid]-'0')==x){
					mid--;
				}
				start=mid+1;
				break;
			}
			else if((str[mid+1]-'0')==x && (str[mid-1]-'0')==x){
				while((str[mid]-'0')==x){
					mid--;
				}
				start=mid+1;
				break;
			}
			else{
				start=mid;
				break;
			}
		}
		else if((str[mid]-'0')>x){
			r--;
		}
		else{
			l++;
		}
	}

	int count=0;
	while(start<n){
		if((str[start]-'0')!=x) break;
		count++;
		start++;
	}
	return count;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		int x;
		cin>>x;

		cout << count_k_digit(str,x)<<endl;
	}
}