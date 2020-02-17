/*
Implement C++ program for expression conversion as infix to postfix and its evaluation using stack based on given conditions:  Operands and operator, both must be single character, Input Postfix expression must be in a desired format, Only '+', '-', '*' and '/ ' operators are expected.
Name-Abhinav Kale
Roll No.-21326
*/
#include<iostream>
using namespace std;
class Infix
{
private:
	char exp[40],post[40];
	int top,stack[20];
public:
	Infix()
	{
		exp[0]='\0';
		stack[0]='\0';
		top=-1;
	}
void input()
{
	cout<<"Enter the infix expression \n";
	cin>>exp;
}
void conversion()
{	
	int i,j=0;
	char a,b;
	for(i=0;exp[i]!='\0';i++)
	{
	a=exp[i];
		switch(a)
		{
			case'(':
				push('(');
				break;
			case')':
				while(stack[top]!='(')
				{
					b=pop();
					post[j]=b;
					j++;
				}
				pop();
				break;
			case '/':
				if(stack[top]=='*')
				{
					while(top!=-1)
					{
						b=pop();
						post[j]=b;
						j++;
					}
				push('/');
				}
				else
				{
					push('/');
				}
				break;
			
			case '*':
				if(stack[top]=='/')
				{
					while(top!=-1)
					{
						b=pop();
						post[j]=b;
						j++;
					}
				push('*');
				}
				else
				{
					push('*');
				}
				break;
			case '-':
				if(stack[top]=='/' || stack[top]=='*'|| stack[top]=='+')
				{
					while(top!=-1)
					{
						b=pop();
						post[j]=b;
						j++;
					}
				push('-');
				}
				else
				{
					push('-');
				}
				break;
			case '+':
				if(stack[top]=='/' || stack[top]=='*'|| stack[top]=='-')
				{
					while(top!=-1)
					{
						b=pop();
						post[j]=b;
						j++;
					}
				push('+');
				}
				else
				{
					push('+');
				}
				break;
			default :
				post[j]=exp[i];
				j++;
		}
	}
	if(top!=-1)
	{
		while(top!=-1)
		{
			b=pop();
			post[j]=b;
			j++;
		}
	}
post[j]='\0';
}
void result()
{
	int i,c,d,r,flg=0;
	char b;
	for(i=0;post[i]!='\0';i++)
	{
		b=post[i];
		if(b!='+' && b!='-' &&  b!='*' && b!='/')
		{
			push(b-48);
		}
		else
		{
			d=pop();
			c=pop();
			if(b=='+')
			{
				r=c+d;
				push(r);
			}
			else if(b=='-')
			{
				r=c-d;
				push(r);
			}
			else if(b=='*')
			{
				r=c*d;
				push(r);
			}
			else if(b=='/')
			{
				r=c/d;
				push(r);
			}
		}
	}
cout<<"\nResult is "<<stack[0];
}
void push(char c)
{
	if(top>=20)
	{
		cout<<"Overflow";
	}
	else
	{
	top++;
	stack[top]=c;
	}
}
char pop()
{
char c='0';
	if(top<0)
	{
		cout<<"Underflow";
	}
	else
	{
		c=stack[top];
		stack[top]='\0';
		top--;
	}
return c;
}
void display()
{
	cout<<"The postfix expression is "<<post;	
}
};
int main()
{
Infix i;
	i.input();
	i.conversion();	
	i.display();
	i.result();
return 0;

}

