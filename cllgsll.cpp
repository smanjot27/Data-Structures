#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
struct node
{	
	int urn,semester,phone;
	string branch;
	string name;
	struct node *next;
};
class linked_list
{
	node *first,*last;
	int count=0;
	public:
	linked_list()
	{
		first=NULL;
		last=NULL;
	}
	void create();
	void insert();
	void dlt();
	void display();
	int inscheck(int);
	int delcheck(int);
};
void linked_list::create()
{
	node *temp=new node;
	if(first==NULL)
	{
		cout<<"Enter University Roll Number of student"<<endl;
		cin>>temp->urn;
		cin.ignore();
		cout<<"Enter student's name"<<endl;
		getline(cin,temp->name);
		cout<<"Enter student's branch"<<endl;
		getline(cin,temp->branch);
		cout<<"Enter semester"<<endl;
		cin>>temp->semester;
		cout<<"Enter student's phone number"<<endl;
		cin>>temp->phone;
		temp->next=NULL;
		count++;
		first=temp;
		last=temp;
	}
	else
		insert();
}
void linked_list::insert()
{
	count++;
	node *temp=new node;
	node *trav=first;
	node *save=first;
	cout<<"Enter University Roll Number of student"<<endl;
	cin>>temp->urn;
	cin.ignore();
	cout<<"Enter student's name"<<endl;
	getline(cin,temp->name);
	cout<<"Enter student's branch"<<endl;
	getline(cin,temp->branch);
	cout<<"Enter semester"<<endl;
	cin>>temp->semester;
	cout<<"Enter student's phone number"<<endl;
	cin>>temp->phone;
	int number=inscheck(temp->urn);
	if(number==count-1)
	{
		last->next=temp;
		temp->next=NULL;
		last=temp;
	}
	else
	{
		for(int i=0;i<number;i++)
		{
			save=trav;
			trav=save->next;
		}
		temp->next=save->next;
		save->next=temp;
	}
}
int linked_list::inscheck(int item)
{
	node *temp=first;
	int num=0;
	if(item<=temp->urn)
		num++;
	else
	{
		while(temp!=NULL)
		{
			if(item<=temp->urn)
				break;
			else
				num++;
				temp=temp->next;
		}
	}
	return(num);
}	
void linked_list::dlt()
{
	node *temp=first;
	node *save=first;
	int item;
	cout<<"enter roll number of student whose data is to be deleted"<<endl;
	cin>>item;
	int number=delcheck(item);
	if(number==-1)
		cout<<"item not present in list"<<endl;
	else
	{
		if(number==0)
			first=first->next;
		else
		{
			for(int i=0;i<number;i++)
			{
				save=temp;
				temp=temp->next;
			}
                	save->next=temp->next;
		}
		count--;
	}	
}	
int linked_list::delcheck(int item)
{	
	node*temp=first;
	int num=-1;
	int count=0;
	if(item<first->urn)
		num=-1;	
	else if(item==first->urn)
		num=0;
	else
	{
		while(temp!=NULL)
		{
			if(item==temp->urn)
			{
				num=count;
				break;
			}
			else
				count++;
				temp=temp->next;
		}
	}
	return(num);
}
void linked_list::display()
{
	if(first==NULL)
		cout<<"empty linked list"<<endl;
	else
	{
		cout<<setw(15)<<"ROLL NO."<<setw(15)<<"NAME"<<setw(15)<<"BRANCH"<<setw(15)<<"SEMESTER"<<setw(15)<<"PHONE NO"<<endl;
		node *temp=first;
		while(temp!=NULL)
		{
			cout<<setw(15)<<temp->urn<<setw(15)<<temp->name<<setw(15)<<temp->branch<<setw(15)<<temp->semester<<setw(15)<<temp->phone<<endl;
			temp=temp->next;
		}
		cout<<"number of nodes = "<<count<<endl;
	}
}
int main()
{
	linked_list list;
	int choice;
	option: cout<<"enter the number against operation to be performed on singly linked list\n1. create a node\t2. insert a node\t3. delete a node\t4. display list\t5. exit"<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1: list.create();
			goto option;
		case 2: list.insert();
			goto option;
		case 3: list.dlt();
			goto option;
		case 4: list.display();
			goto option;
		case 5: cout<<"exiting.."<<endl;
			break;
		default: cout<<"invalid option"<<endl;
			 goto option;
	}
	return 0;
}
