#include<iostream>
using namespace std;
struct node
{
	int data;
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
	void insert(int);
	void dlt();
	void display();
	int inscheck(int);
	int delcheck(int);
};
void linked_list::create()
{
	node *temp=new node;
	cout<<"enter data for node"<<endl;
	cin>>temp->data;
	temp->next=NULL;
	if(first==NULL)
	{
		count++;
		first=temp;
		last=temp;
	}
	else
		insert(temp->data);
}
void linked_list::insert(int item)
{
	count++;
	node *temp=new node;
	node *trav=first;
	node *save=first;
	if(item==-1)
	{
		cout<<"enter data for node"<<endl;
		cin>>item;
	}
	temp->data=item;	
	int number=inscheck(temp->data);
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
	if(item<=temp->data)
		num++;
	else
	{
		while(temp!=NULL)
		{
			if(item<=temp->data)
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
	cout<<"enter the item to be deleted"<<endl;
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
	}	
	count--;
}	
int linked_list::delcheck(int item)
{	
	node*temp=first;
	int num=-1;
	int count=0;
	if(item<first->data)
		num=-1;	
	else if(item==first->data)
		num=0;
	else
	{
		while(temp!=NULL)
		{
			if(item==temp->data)
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
		node *temp=first;
		while(temp!=NULL)
		{
			cout<<temp->data<<"\t";
			temp=temp->next;
		}
		cout<<"\n";
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
		case 2: list.insert(-1);
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
