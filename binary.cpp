#include<iostream>
#include"sorting.cpp"
using namespace std;
void binarysearch(int size, int item, int array[])
{
	int beg=0,end=size-1,mid=(beg+end)/2;
	while(item!=array[mid] && beg<=end)
	{
		if(item<array[mid])
			end=mid-1;
		else
			beg=mid+1;
		mid=(beg+end)/2;
	}
	if(item==array[mid])
		cout<<"\nsearch successful\nitem found at location "<<mid<<endl;
	else
		cout<<"\nsearch unsuccessful\nitem not found"<<endl;
}
void insert(int size,int array[])
{
	cout<<"enter the elements of array"<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>array[i];
	}
}
int main()
{
	int array[10],size,item;
	cout<<"enter the size of array"<<endl;
	cin>>size;
	insert(size,array);
	cout<<"enter the element you want to search within the array"<<endl;
	cin>>item;
	sorting(array,size);
	binarysearch(size,item,array);
	return 0;
}
