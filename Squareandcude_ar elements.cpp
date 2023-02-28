#include<iostream>
using namespace std;
int main()
{
 int ar[50];
 cout<<"Elements of array would be: \n";
 for(int i=0;i<25;i++)
 {
 	ar[i]=i*i;
 }
 for(int i=25;i<50;i++)
 {
 	ar[i]=i*i*i;
	  }
for(int i=0;i<50;i++)
	  {
	  	if(i%10==0)
	  	{
	  		cout<<endl;
		  }
		  
	  	cout<<" "<<ar[i];
	  }
 return 0;
}


