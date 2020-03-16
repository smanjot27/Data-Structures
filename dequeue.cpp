#include<iostream>
using namespace std;
class Deque
{
	int queue[5],front=-1,rear=-1,max=5;
	public:
	void insert();
	void dlt();
	void display();
	void insfront(int);
	void insrear(int);
	void delfront();
	void delrear();
};
void Deque::insert()
{
	int flag,item;
	if((front==0 && rear==max-1)||front==rear+1)
	{
		cout<<"overflow condition"<<endl;
	}
	else
	{
		cout<<"enter 0 for insertion from front and 1 for insertion fron rear end"<<endl;
		cin>>flag;
		cout<<"enter the element to be inserted in queue"<<endl;
		cin>>item;
		if(flag==0)
			insfront(item);
		else
			insrear(item);
	}
}
void Deque::insfront(int item)
{
	if(front==-1)
	{
		front++;
		rear++;	
	}
	else if(front==0)
	{
		front=max-1;;
	}
	else
		front--;
	queue[front]=item;
}
void Deque::insrear(int item)
{
	if(rear==-1)
	{
		front=rear=0;
	}
	else if(rear==max-1)
	{
		rear=0;
	}
	else
		rear++;
	queue[rear]=item;
}
void Deque::dlt()
{
	int flag;
	if(front==-1)
	{
		cout<<"underflow condition"<<endl;
	}
	else
	{
		cout<<"enter 0 for deletion from front and 1 for deletion fron rear end"<<endl;
		cin>>flag;
		if(flag==0)
			delfront();
		else
			delrear();
	}
}
void Deque::delfront()
{
	cout<<"deleting "<<queue[front]<<endl;
	if(front==rear)
		front=rear=-1;
	else if(front==max-1)
		front=0;
	else
		front++;
}
void Deque::delrear()
{
	cout<<"deleting "<<queue[rear]<<endl;
	if(front==rear)
		rear=-1;
	else if(rear==0)
		rear=max-1;
	else
		rear--;
}
void Deque::display()
{
	if(front==-1 && rear==-1)
		cout<<"empty queue"<<endl;
	else
	{
		if(front<=rear)
		{
			for (int i=front;i<rear+1;i++)
			{
				cout<<"\t"<<queue[i];
			}
			cout<<"\n";
		}
		else
		{
			for (int i=0;i<rear+1;i++)
			{
				cout<<"\t"<<queue[i];
			}
			for(int i=front;i<max;i++)
			{
				cout<<"\t"<<queue[i];
			}
			cout<<"\n";
		}
	}
}
int main()
{
	Deque que;
	int choice;
	option: cout<<"enter the number against operation to be performed on deque\n1. insert an element\t2. delete an element\t3. display queue\t4. exit"<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1: que.insert();
			goto option;
		case 2: que.dlt();
			goto option;
		case 3: que.display();
			goto option;
		case 4: cout<<"exiting.."<<endl;
			break;
		default: cout<<"invalid option"<<endl;
			 break;
	}
	return 0;
}
