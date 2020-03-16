//towerofhanoi
#include<iostream>
using namespace std;
void tower(int num,char beg, char aux,char end)
{
	if(num==1)
	{
		cout<<"moving disk "<<num<<" from "<<beg<<" to "<<end<<endl;
		return;
	}
	else
	{
		tower(num-1,beg,end,aux);
		cout<<"moving disk "<<num<<" from "<<beg<<" to "<<end<<endl;
		tower(num-1,aux,beg,end);
	}
}
int main()
{
	int num;
	cout<<"enter the number of disk"<<endl;
	cin>>num;
	tower(num,'a','b','c');
	return 0;
}
