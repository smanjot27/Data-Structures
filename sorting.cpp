#include<iostream>
using namespace std;
void display(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<"\n";
}
void sorting(int arr[],int n)
{
	int t;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(arr[i]>arr[j])
			{
				t=arr[i];
				arr[i]=arr[j];
				arr[j]=t;	
			}
		}
	}
	cout<<"\nin ascending order\n";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<"\t";
	}
}
//int main()
//{
//	int arr[10],n;
//	cout<<"enter size"<<endl;
//	cin>>n;
//	for(int i=0;i<n;i++)
//	{
//		cin>>arr[i];
//	}
//	display(arr,n);
//	sorting(arr,n);	
//}
