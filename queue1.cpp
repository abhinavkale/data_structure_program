/*
Queues are frequently used in computer programming, and a typical example is the creation of a job queue by an operating system. If the operating system does not use priorities, then the jobs are processed in the order they enter the system. Write C++ program for simulating job queue. Write functions to add job and delete job from queue. 
Roll No.-21326
*/
#include <iostream>
using namespace std;
struct job
{
	int a;
	int p;
};
class queue
{
	job j[10];
	int rear;
	int front;
public:
	queue()
	{
		front=rear=-1;
	}
	void enqueue(int,int);
	void place(int,int,int);
	void dequeue();
	void display();
};
void queue::enqueue(int x,int y)
{
	int i,flg=0;
	if(rear==9)
		cout<<"\nOverflow"<<endl;
	else
	{
		if(front==-1)
		{
			front++;
			rear++;
			j[rear].a=x;
			j[rear].p=y;
		}
		else
		{
			for(i=front;i!=rear+1;i++)
			{
				if(y>j[i].p)
				{
					place(i,x,y);
					flg=1;
				}	
				if(flg==1)
				break;
			}
			if(flg==0)
				place(i,x,y);
		
		}
	}
}
void queue::place(int p,int x,int y)
{
	int i=rear;
		while(i>p || i==p)
		{
			j[i+1].a=j[i].a;
			j[i+1].p=j[i].p;
			i--;
		}
		rear++;
		j[p].a=x;
		j[p].p=y;
}
void queue::dequeue()
{
	int y,b;
	if(front==-1 || front>rear)
		cout<<"\nUnderflow"<<endl;

	else
	{
		y=j[front].a;
		b=j[front].p;
		front++;
		cout<<"\nThe element removed from queue is "<<y<<" with priority "<<b;
	}
}
void queue::display()
{
	int i;	
		for(i=front;i<=rear;i++)
		{
			cout<<"Job id.-"<<j[i].a <<"\tPriority-"<<j[i].p<<endl;
		}
	cout << endl;
	
}
int main()
{
	queue q;
	int d,n,ch,p;
	cout<<"\nEnter:\n"<<"1.Insert Job\n"<<"2.Delete Job\n"<<"3.Display\n";
	do
	{
		cout<<"Enter choice no."<< endl;
		cin>>n;
		switch(n)
		{
		case 1:
			cout<<"Enter the JOB ID and priority :"<<endl;
			cin>>d>>p;
			q.enqueue(d,p);
			break;
		case 2:
			q.dequeue();
			break;
		case 3:
			q.display();
			break;
		default:
			cout<<"\nInvalid Option";
		}
	cout<<"\nDo you wish to continue if yes enter 1 if no enter 0 ";
	cin>>ch;
	}
	while(ch==1);
	return 0;

}
/*
[secomp@localhost 21326]$ g++ queue1.cpp
[secomp@localhost 21326]$ ./a.out

Enter:
1.Insert Job
2.Delete Job
3.Display
Enter choice no.
1
Enter the JOB ID and priority :
1 2

Do you wish to continue if yes enter 1 if no enter 0 1
Enter choice no.
1
Enter the JOB ID and priority :
2 1

Do you wish to continue if yes enter 1 if no enter 0 1
Enter choice no.
1
Enter the JOB ID and priority :
3 3

Do you wish to continue if yes enter 1 if no enter 0 1
Enter choice no.
3
Job id.-3	Priority-3
Job id.-1	Priority-2
Job id.-2	Priority-1


Do you wish to continue if yes enter 1 if no enter 0 1
Enter choice no.
2
The element removed from queue is 3 with priority 3
Do you wish to continue if yes enter 1 if no enter 0 1
Enter choice no.
3
Job id.-1	Priority-2
Job id.-2	Priority-1


Do you wish to continue if yes enter 1 if no enter 0*/

