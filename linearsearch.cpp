#include<iostream>
using namespace std;
int linearsearch(int element, int arr[], int size)
{
	int loc=-1;
	for(int i=0;i<size;i++)
	{
		if(element==arr[i])
		{
			loc=i;
			break;
		}
	}
	if(loc==-1)
		cout<<"search unsuccessful\nitem not found"<<endl;
	else
		cout<<"search successful\nitem found at location "<<loc<<endl;
}
void insert(int size,int array[])
{
	cout<<"enter the elements of array"<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>array[i];
	}
	cout<<"\n";
}
int main()
{
	int array[10],size,item;
	cout<<"enter the size of array"<<endl;
	cin>>size;
	insert(size,array);
	cout<<"enter the element you want to search within the array"<<endl;
	cin>>item;
	linearsearch(item,array,size);
	return 0;
}
