#include<iostream>
using namespace std;
class array
{
	int arr[10],k;
	public:
		void create();
		void display();
		void insert();
		void remove();
};
void array::create()
{
	cout<<"enter the size of array\n";
	cin>>k;
	for(int i=0;i<k;i++)
	{
		cin>>arr[i];
	}	
}
void array::display()
{
	for(int i=0;i<k;i++)
		{
			cout<<"\t"<<arr[i];
		}
	cout<<"\n";	
}
void array::insert()
{
	int item1,loc1;
	cout<<"enter the element to be inserted with location\n";
	cin>>item1>>loc1;
	for(int i=k;i>loc1;i--)
	{
		arr[i]=arr[i-1];
	}
	for(int i=0;i<k+1;i++)
	{
		if(i==loc1)
		arr[i]=item1;
	}
	k=k+1;
}
void array::remove()
{
	int item2,loc2;
	cout<<"enter the element to be deleted with location\n";
	cin>>item2>>loc2;
	for(int i=loc2;i<k;i++)
	{
		arr[i]=arr[i+1];
	}
	k=k-1;
}
int main()
{
	array a;
	int n;
	option: cout<<"enter the number against the menu to avail that service\n1. creating an array\n2. displaying array elements\n3. inserting an element in a particular location\n4. deleting an element in particular location\n5. exit\n";
	cin>>n;
	switch(n)
	{
		case 1: a.create();
		goto option;
		case 2: a.display();
		goto option;
		case 3: a.insert();
		goto option;
		case 4: a.remove();
		goto option;
		case 5: cout<<"exit\n";
		break;
		default: cout<<"invalid option";
		break;
	}
	return 0;
}
