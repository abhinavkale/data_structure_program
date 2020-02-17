/*
In any language program mostly syntax error occurs due to unbalancing delimiter such as (),{},[]. Write C++ program using stack to check whether given expression is well parenthesized or not.
*/
#include<iostream>
using namespace std;
class Expression{
private:
	char str[40];
	char stack[20];
	int top;
public:
	Expression()
	{
		stack[0]='\0';
		top=-1;
		str[0]='\0';
	}
	void input();
	void check();
	void push(char);
	void pop();	
};
void Expression::input()
{
	cout<<"\nEnter mathematical equation to check if it is properly bracketted or not: \n";
	cin>>str;
}
void Expression::check()
{
	int i=0;
	char error;
	do{
		
		switch(str[i]){
			
			case '[':
				push('[');
				break;
			case '{':
				push('{');
				break;
			case '(':
				push('(');
				break;
			case ')':
				if(stack[top]=='(')
					pop();
				else
				{
					error = ')';
					goto out;
				}
				break;
			case '}':
				if(stack[top]=='{')
					pop();
				else
				{
					error = '}';
					goto out;
				}
				break;
			case ']':
				if(stack[top]=='[')
					pop();
				else
				{
					error = ']';
					goto out;
				}
				break;
			default:
				
				break;
			}
			i++;
		}while(str[i]!='\0');
		out:cout<<"";
		if(top==-1)
			cout<<"\nEquation is properly bracketted.";
		else
		{
			cout<<"\nEquation is not properly bracketted.";
		}
}
void Expression::push(char a)
{
	if(top>=20)
		cout<<"\nStack overflow.";
	else
	{
		++top;
		stack[top] = a;
	}
}
void Expression::pop()
{
	if(top<0)
		cout<<"\nStack underflow.";	
	else
	{
		stack[top] = '\0';
		top--;
	}
}
int main()
{
	Expression s;
	s.input();
	s.check();
	return 0;
}
	
