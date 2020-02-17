/*Problem Statement-Queues are frequently used in computer programming, and a typical example is the creation of a job queue by an operating system. If the operating system does not use priorities, then the jobs are processed in the order they enter the system. Write C++ program for simulating job queue. Write functions to add job and delete job from queue. 
*/
#include<iostream>
using namespace std;
class queue
{
	int a[10];
	int rear;
	int front;
public:
	queue()
	{
		front=rear=-1;
	}
	void enqueue(int);
	void dequeue();
	void display();
};
void queue::enqueue(int x)
{
	if(rear==9)
		cout<<"Overflow"<<endl;
	else
	{
		if(front==-1)
		{
			front++;
			rear++;
			a[rear]=x;
		}
		else
		{	rear++;
			a[rear]=x;
		}
	}
}
void queue::dequeue()
{
	int y;
	if(front==-1 || front>rear)
		cout<<"\nUnderflow"<<endl;

	else
	{
		y=a[front];
		front++;
		cout<<"\nThe element removed from queue is "<<y;
	}
}
void queue::display()
{
	int i;	
		for(i=front;i<=rear;i++)
		{
			cout << a[i] << " ";
		}
	cout << endl;
	
}

int main()
{
	queue q;
	int d,n;
	char ch;
	cout<<"\nEnter:\n"<<"1.Insert Job\n"<<"2.Delete Job\n"<<"3.Display\n";
	do
	{
		cout<<"\nEnter choice no."<< endl;
		cin>>n;
		switch(n)
		{
		case 1:
			cout<<"\nEnter the JOB ID :"<<endl;
			cin>>d;
			q.enqueue(d);
			break;
		case 2:
			q.dequeue();
			break;
		case 3:
			q.display();
			break;
		default:
			cout<<"\nEntered wrong choice";
			break;
		}
	cout<<"\nDo you want to continue(y/n) ";
	cin>>ch;

	}while(ch=='y');
	return 0;

}

