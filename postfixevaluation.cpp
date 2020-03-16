#include<iostream>
using namespace std;
class stack
{
	public:
	int s[10],top=-1,max=10,val;
	void push(int);
	int pop();
	int isoperator(char);
};
void stack::push(int value)
{
	if(top==max)
		cout<<"overflow condition\n";
	else
		top++;
		s[top]=value;
		val=s[top];
}
int stack::isoperator(char element)
{
	if(element=='+'||element=='-'||element=='*'||element=='/'||element=='^'||element=='%')
		return 1;
	else
		return 0;
}
int stack::pop()
{
	int item;
	if(top==-1)
		cout<<"underflow condition\n";
	else
		item=s[top];
		top--;
		return(item);
}
int solve(int a, int b, char operator1)
{
	int c;
	switch(operator1)
	{
		case '+': c=b+a;
			break;
	 	case '-': c=b-a;
			 break;
		case '*': c=b*a;
			  break;
		case '/': c=b/a;
			break;
		case '^': c=b^a;
			break;
		case '%': c=b%a;
			  break;
		default: cout<<"invalid operator present\n";
			break;
	}
	return(c);
}
int main()
{
	stack st;
	string expression;
	cout<<"enter arithmetic expression\n";
	getline(cin,expression);
	int x,y,i=0;
	while(expression[i]!='\0')
	{
	        if(st.isoperator(expression[i])!=0)	
		{
			x=st.pop();
			y=st.pop();
		    	st.push(solve(x,y,expression[i]));
                 }
		else
	   	    st.push(int(expression[i])-48);
		i++;
	
	}
	cout<<"answer= "<<st.val<<"\n";
	return 0;
}

