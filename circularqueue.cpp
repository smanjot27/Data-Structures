#include<iostream>
using namespace std;
class CircularQueue
{
	int queue[5],front=-1,rear=-1,max=5;
	public:
	void insert();
	void dlt();
	void display();
};
void CircularQueue::insert()
{
	int item;
	if((front==0 && rear==max-1)||front==rear+1)
	{
		cout<<"overflow condition"<<endl;
	}
	else
	{
		cout<<"enter the element to be inserted in queue"<<endl;
		cin>>item;
		if(front==-1 && rear==-1)
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
}
void CircularQueue::dlt()
{
	if(front==-1)
	{
		cout<<"underflow condition"<<endl;
	}
	else
	{
		cout<<"deleting "<<queue[front]<<endl;
		if(front==rear)
			front=rear=-1;
		else if(front==max-1)
			front=0;
		else
			front++;
	}
}
void CircularQueue::display()
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
	CircularQueue que;
	int choice;
	option: cout<<"enter the number against operation to be performed on circular queue\n1. insert an element\t2. delete an element\t3. display queue\t4. exit"<<endl;
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


