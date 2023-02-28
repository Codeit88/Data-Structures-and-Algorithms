#include<iostream>
using namespace std;
int main()
{
int n,i=0;
cout<<"Enter your number: ";
cin>>n;
while(n>0)
{
	n=n/10;
	i++;
}
cout<<"Total numbers are: "<<i;
 return 0;
}


