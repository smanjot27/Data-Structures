#include<iostream>
using namespace std;
class priorityqueue
{
	int queue[5],i=0,rear=-1,front=-1,max=5;
	public:
	void insert();
	void dlt();
	void display();
	void ins(int);
};
void priorityqueue::insert()
{
	int item;
	if(rear==max-1)
		cout<<"overflow condition"<<endl;
	else
	{
		cout<<"enter the element"<<endl;
		cin>>item;
		if(rear==-1 && front==-1)
		{
			rear=front=0;
			queue[rear]=item;
		}
		else
		{
			rear++;
			ins(item);
		}
	}
}
void priorityqueue::ins(int item)
{
	int loc=rear;
	for(int j=front;j<rear;j++)
	{
		if(item<queue[j])
		{
			loc=j;
			break;
		}
	}	
	if(loc==rear)
		queue[rear]=item;
	else
	{
		for(int j=rear;j>=loc;j--)
		{
			queue[j+1]=queue[j];
		}
		queue[loc]=item;
	}
}
	
void priorityqueue::dlt()
{
	int j;
	if(front==-1)
		cout<<"underflow condition"<<endl;
	else
		cout<<"enter priority of the element to be deleted"<<endl;
		cin>>j;
		for (int k=j;k<rear;k++)
		{
			queue[k]=queue[k+1];
		}
	rear--;
}
void priorityqueue::display()
{
	if(front==-1)
		cout<<"empty queue"<<endl;
	else
		for (int k=front;k<rear+1;k++)
		{
			cout<<queue[k]<<"\t";
		}
	cout<<"\n";
}

int main()
{
        priorityqueue que;
	int choice;
	option: cout<<"enter the number against operation to be performed on priority queue\n1. insert an element\t2. delete an element\t3. display queue\t4. exit"<<endl;
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
