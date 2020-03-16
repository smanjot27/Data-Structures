#include<iostream>
#include<cstring>
using namespace std;
class stack
{
	public:
		char st[20],source[20]="\0",top=-1,max=20;
	   	void push(char);
		int pop();
		int priority(char);
		int isoperator(char);
		int isoperand(char);
		void insertion(char);
};
void stack::push(char x)
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
int stack::pop()
{
	int item;
	if(top==-1)
	{
		cout<<"underflow condition\n";	
	}	
	else
	{
		item=st[top];
		top--;
		return(item);
	}
}
int stack::isoperand(char x)
{
	if((int(x)>=65 && int(x)<=90)||(int(x)>=97 && int(x)<=122))
	{
		return 1;
	}
	else 
	{
		return 0;
    }
}
int stack::isoperator(char x)
{
	if(x=='+'||x=='-'||x=='%'||x=='/'||x=='*'||x=='^')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int stack::priority(char x)
{
	if(x=='^')
	{
		return 3;
	}
	else if(x=='*'||x=='/')
	{
		return 2;
	}
	else if(x=='+'||x=='-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}	
void stack::insertion(char x)
{
	int length=strlen(source);
	if(!length)
	{
		source[0]=x;
	}
	else
	{
		
		for(int i=0;i<=length+1;i++)
		{
			if(i==length)
			{	
				source[i]=x;
			}
		}
	}
	length++;	
}
int main()
{
	stack s;
	string arr;
	int i=0;
	cout<<"enter string\n";
	getline(cin,arr);
	while(arr[i]!='\0')
	{
		if(s.isoperand(arr[i])!=0)
		{
			s.insertion(arr[i]);
		}
		else if(arr[i]==40)
		{
			s.push(arr[i]);
		}
		else if(s.isoperator(arr[i])!=0)
		{
			while(s.priority(arr[i])<=s.priority(s.st[s.top]))
			{
				cout<<"high priority element in stack\n";
				char z=char(s.pop());
				s.insertion(z);
				cout<<"element popped "<<z<<endl;
			}
			s.push(arr[i]);
		}
		else if(arr[i]==41)
		{
			char z=char(s.pop());
			while(s.isoperator(z)!=0)
			{
				s.insertion(z);
				cout<<"element popped "<<z<<endl;
				z=s.pop();
			}
		}
		i++;
	}
	while(s.top!=-1)
			{
				s.insertion(s.pop());
			}	
	cout<<s.source<<endl;
	return 0;
}

