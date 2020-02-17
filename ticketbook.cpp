/*The ticket booking system of Cinemax theater has to be implemented using C++ program. There are 10 rows and 7 seats in each row. Doubly circular linked list has to be maintained to keep track of free seats at rows. Assume some random booking to start with. Use array to store pointers (Head pointer) to each row. On demand 
i)The list of available seats is to be displayed 
ii)The seats are to be booked 
iii)The booking can be cancelled.
Name-Neeraj Jain

Roll no.-21324
*/
#include<iostream>
using namespace std;
struct node
{
	int c,r,status;
	node* next;
	node* prev;
}*head[10],*last[10];
class ticket
{
public:
ticket()
{
	int i,j;
	for(j=0;j<10;j++)
	{
	head[j]=NULL;
	last[j]=NULL;
	node *temp;
	for(i=0;i<7;i++)
	{
	temp=createnode(i-1,j);
		if(head[j]==last[j] && head[j]==NULL)
		{
		head[j]=temp;
		last[j]=temp;
		head[j]->next=NULL;
		last[j]->next=NULL;
		head[j]->prev=NULL;
		last[j]->prev=NULL;
		}
		else
		{
		temp->next=head[j];
		head[j]->prev=temp;
		head[j]=temp;
		head[j]->prev=last[j];
		last[j]->next=head[j];
		}
	}
}
}
 node* createnode(int x,int y)
{
node* temp;
temp=new node;
temp->c=x;
temp->r=y;
temp->status=0;
temp->next=NULL;
temp->prev=NULL;
return(temp);
}
void display()
{
int i,j;
node* temp;
	for(j=0;j<10;j++)
	{
	temp=head[j];
		for(i=0;i<7;i++)
		{
		cout<<temp->status<<" ";
		temp=temp->next;
		}
	cout<<"\n";
	}
}
void book()
{
int x,y,i,a;
cout<<"\nEnter no of tickets to book";
cin>>a;
cout<<"\nEnter row and column to book tickets";
cin>>x>>y;
node* temp;
x=x-1;
temp=head[x];
for(i=0;i<7;i++)
{
if(temp->c==y)
 {
  if(temp->status==0)
	{
	temp->status=1;
	}
	else
	{
	cout<<"\nSeats are already reserved";
	}
  }
    temp=temp->next;
}
    display();
}

void cancel1()
{ 
int x,y,i;
cout<<"\nEnter row and column to cancel";
cin>>x>>y;
node* temp;
x=x-1;
temp=head[x];
for(i=0;i<7;i++)
{
if(temp->c==y)
 { 
  if(temp->status==1)
	{
	temp->status=0;
	}
	else
	{
	cout<<"\nInvalid option";
	}
  }
    temp=temp->next;
}
    display();
}
};
int main()
{
 ticket t;
	t.display();
	t.book();
	t.cancel1();

return 0;
}









   

