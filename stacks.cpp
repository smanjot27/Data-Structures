#include<iostream>
using namespace std;
class stack
{
	int st[10];
	int max=10,top=-1;
	public:
		void push(int);
		void pop();
		void display();
};
void stack::push(int x)
{
	if(top==max)
	{
		cout<<"overflow condition\n";
	}
	else
	{
		top++;
		st[top]=x;
	}
}
void stack::pop()
{
	int item;
	if(top==-1)
	{
		cout<<"underflow condition\n";	
	}	
	else
	{
		item=st[top];
		cout<<item<<"\n";
		top--;
	}
}
void stack::display()
{
	if(top==-1)
	{
		cout<<"stack is empty\n";
	}
	else
	{
		for (int i=top;i>-1;i--)
		{
			cout<<"\t"<<st[i];
		}	
		cout<<"\n";
    }
}
int main()
{
	int n,x;
	stack s;
	option: cout<<"enter the number against the menu to avail that service\n1. pushing an element into the stack\n2. poping an element from the stack\n3. displaying stack\n4. exit\n";
	cin>>n;
	switch(n)
	{
		case 1:  cin>>x;
		s.push(x);
		goto option;
		break;
		case 2: s.pop();
		goto option;
		break;
		case 3: s.display();
		goto option;
		break;
		case 4: cout<<"exit\n";
		break;
		default: cout<<"invalid option\n";
		break;	
	}
	return 0;
}
