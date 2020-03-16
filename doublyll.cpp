#include<iostream>
#include<iomanip>
using namespace std;
struct node
{
	int ssn,salary,phone;
	string name,dept,dsgn;
	struct node *prev,*next;
};
class doublyll
{
	node *first,*last;
	int count=0;
	public:
	doublyll()
	{
		first=NULL;
		last=NULL;
	}
	void insert();
	void dlt();
	void display();
	int inscheck(int);
	int delcheck(int);
};
void doublyll::insert()
{
	node *temp=new node;
	node *save=first;
	node *trav=first;
	cout<<"Enter employee's security number"<<endl;
	cin>>temp->ssn;
	cin.ignore();
	cout<<"Enter employee's name"<<endl;
	getline(cin,temp->name);
	cout<<"Enter employee's department"<<endl;
	getline(cin,temp->dept);
	cout<<"Enter designation"<<endl;
	getline(cin,temp->dsgn);
	cout<<"Enter salary"<<endl;
	cin>>temp->salary;
	cout<<"Enter employee's phone number"<<endl;
	cin>>temp->phone;
	temp->next=NULL;
	int number=inscheck(temp->ssn);
	count++;
	if(first==NULL)
	{
		first=temp;
		last=temp;
		temp->prev=NULL;
		temp->next=NULL;
	}
	else if(number==count-1)
	{
		temp->prev=last;
		temp->next=NULL;
		last->next=temp;
		last=temp;
	}
	else
	{
		for(int i=0;i<number;i++)
		{
			save=save->next;
		}
		trav=save->prev;
		trav->next=temp;
		temp->next=save;
		temp->prev=trav;
		save->prev=temp;
	}
}
int doublyll::inscheck(int item)
{
	node *temp=first;
	int num=0;
	if(first==NULL)
		num=0;
	else if(item<=first->ssn)
	{	
		num++;
	}
	else
	{
		while(temp!=NULL)
		{
			if(item<=temp->ssn)
				break;
			else
				num++;
				temp=temp->next;
		}
	}
	return(num);
}
void doublyll::dlt()
{
	node *temp=first;
	node *trav=first;
	int number,item;
	cout<<"enter the serial security number of employee whose data needs to be deleted"<<endl;
	cin>>item;
	number=delcheck(item);
	if(number==-1)
		cout<<"item not present"<<endl;
	else
	{
		if(number==0 && number==count-1)
		{
			first=NULL;
			last=NULL;
		}
		else if(number==0)
		{
			trav=first->next;
			trav->prev=NULL;
			first=first->next;
		}
		else if(number==count-1)
		{
			(last->prev)->next=NULL;
			last=last->prev;
		}
		else
		{
			for(int i=0;i<number;i++)
			{
				temp=temp->next;
			}
			trav=temp->prev;
			trav->next=temp->next;
			temp->next->prev=trav;
		}
		count--;
	}
}
int doublyll::delcheck(int item)
{
	node*temp=first;
	int num=-1;
	int count=0;
	if(item<first->ssn)
		num=-1;	
	else if(item==first->ssn)
		num=0;
	else
	{
		while(temp!=NULL)
		{
			if(item==temp->ssn)
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
void doublyll::display()
{
	node *temp=first;
	if(first==NULL)
		cout<<"empty list"<<endl;
	else
	{
	cout<<setw(20)<<"SERIAL SECURITY NO."<<setw(15)<<"NAME"<<setw(15)<<"DEPARTMENT"<<setw(15)<<"DESIGNATION"<<setw(15)<<"SALARY"<<setw(15)<<"PHONE NO"<<endl;
		while(temp!=NULL)
		{
			cout<<setw(20)<<temp->ssn<<setw(15)<<temp->name<<setw(15)<<temp->dept<<setw(15)<<temp->dsgn<<setw(15)<<temp->salary<<setw(15)<<temp->phone<<endl;
			temp=temp->next;
		}
		cout<<"number of nodes = "<<count<<endl;
	}
}
int main()
{
	doublyll list;
	int choice;
	option: cout<<"enter the number against operation to be performed on doubly linked list\n1. insert a node\t2. delete a node\t3. display list\t4. exit"<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1: list.insert();
			goto option;
		case 2: list.dlt();
			goto option;
		case 3: list.display();
			goto option;
		case 4: cout<<"exiting.."<<endl;
			break;
		default: cout<<"invalid option"<<endl;
			 goto option;
			 break;
	}
	return 0;
}
