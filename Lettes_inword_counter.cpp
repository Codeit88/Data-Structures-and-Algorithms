#include<iostream>
using namespace std;
int main(){
char ar[50] = { 's','a','m','i',' ','i','s',' ','a',' ','g','o','o','d','b','o','y',' ','l','i','b'};
	int i = 0, charcount = 0, wordcount = 1;
	while (ar[i] != '\0') {
		charcount++;
		if (ar[i] == ' ')
			wordcount++;
		i++;
	}
	int j=0,l=0;
	int *count=new int[wordcount];
	for(int i=0;(i<charcount+1);i++){
		if(ar[i]!=' '&&ar[i]!='\0')
		j++;
		else if(ar[i]==' '||ar[i]=='\0'){
			count[l]=j;
			j=0;
			l++;
		}
	}
	for(int i=0;i<wordcount;i++){
		cout<<count[i]<<endl;
	}
return 0;
}

