#include<iostream>
using namespace std;
class stack
{
	int st[20],top=-1,max=20;
	public:
		void push(int);
		int pop();
};
void stack::push(int x)
{
	top++;
	st[top]=x;
}
int stack::pop()
{
	int item;
	item=st[top];
	top--;
	return(item);
}
int main()
{
	int num,count=0,rem,item,flag=0;
	stack s;
	cout<<"enter a number string to check if its a palindrome or not\n";
	cin>>num;
	int m=num;
	while(m>0)
	{
		m=m/10;
		count++;
	}
	cout<<"length of string = "<<count<<endl;
	if(count%2==0)
	{
		cout<<"even string\n";
		for(int i=0;i<count/2;i++)
		{
			rem=num%10;
			num=num/10;
			s.push(rem);
		}
		for(int i=count/2;i<count;i++)
		{
		    rem=num%10;
			num=num/10;
			item=s.pop();
			if(item!=rem)
			{
				flag++;
			}
		}
		if(flag==0)
		{
			cout<<"number string is a palindrome\n";
		}
		else
		{
			cout<<"number string isn't a palindrome\n";
		}
	}
	else
	{
		cout<<"odd string\n";
		for(int i=0;i<count/2;i++)
		{
			rem=num%10;
			num=num/10;
			s.push(rem);
		}
		num=num/10;
		for(int i=0;i<count/2;i++)
		{
			rem=num%10;
			num=num/10;
			item=s.pop();
			if(item!=rem)
			{
				flag++;
			}
		}
		if(flag==0)
		{
			cout<<"number string is a palindrome\n";
		}
		else
		{
			cout<<"number string isn't a palindrome\n";
		}
	}
}
