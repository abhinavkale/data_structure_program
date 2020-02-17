

/*Department of Computer Engineering has student's club named 'Pinnacle Club'.
Students of Second, third and final year of department can be granted membership on request.
Similarly one may cancel the membership of club.
First node is reserved for president of club and last node is reserved for secretary of club.
Write C++ program to maintain club member‘s information using singly linked list.
Store student PRN and Name.
Write functions to
 Add and delete the members as well as president or even secretary.
 Compute total number of members of club
 Display members
 Display list in reverse order using recursion
 Two linked lists exists for two divisions. Concatenate two lists.
 Sort the singly linked list/Merge two sorted singly linked lists.

Name-Abhinav Kale
Batch-F3
Roll no-21326
 */

#include<iostream>
using namespace std;

struct node
{
	char name[20];
	long int PRN;
	node* next;
};

class Pinnacle
{
public:
	node *head;
	Pinnacle()
	{
		head=NULL;
	}
	void insertNode();
	void insertPresident();
	void insertSecretary();
	void display();
	void deletePresident();
	void deleteSecretary();
	void deleteNode();
	void reverseDisplay(node* head);
	Pinnacle concatenate(Pinnacle L2);
};

Pinnacle Pinnacle::concatenate(Pinnacle L2)
{
	Pinnacle L3;
	if(head==NULL)
	{
		L3=L2;
		return L3;
	}
	else
	{
		node *t,*p;
		t=head;
		L3.head=head;
		while(t->next)
		{

			p=t;
			t=t->next;
		}
		t->next=L2.head;
	}
	return L3;
}

void Pinnacle::reverseDisplay(node* head)
{
	if(!head)
		return;
	else
	{
		reverseDisplay(head->next);
		cout<<head->name<<"\t"<<head->PRN<<endl;
	}

}

void Pinnacle::deletePresident()
{
	if(head==NULL)
		return;
	else
	{
		node *t=head;
		head=head->next;
		t->next=NULL;
		delete t;
	}
}

void Pinnacle::deleteSecretary()
{
	if(head==NULL)
		return;
	else
	{
		node *t=head;
		node *p=NULL;
		while(t->next)
		{
			p=t;
			t=t->next;
		}
		p->next=NULL;
		delete t;
		t=NULL;
	}
}

void Pinnacle::deleteNode()
{
	if(head==NULL)
		return;
	else
	{
		int pos,count=1;
		cout<<"Enter position to delete node from\t";
		cin>>pos;
		node *p,*t;
		t=head;
		while(count<pos && t)
		{
			p=t;
			t=t->next;
			count++;
		}
		p->next=t->next;
		delete t;
		t=NULL;
	}
}

void Pinnacle::insertNode()
{
	node *ptr;
	ptr=new node;
	cout<<"Enter student's name and PRN number\n";
	cin>>ptr->name>>ptr->PRN;
	cout<<"Enter the position to add\t";
	int p,count=0;
	cin>>p;
	ptr->next=NULL;
	if(head==NULL)
		head=ptr;
	else
	{
		node *t=head;
		//count++;
		while(count<(p-1) && t)
		{
			t=t->next;
			count++;
		}
		ptr->next=t->next;
		t->next=ptr;
	}
}

void Pinnacle::insertPresident()
{
	node *ptr;
	ptr=new node;
	cout<<"Enter President's name and PRN number\n";
	cin>>ptr->name>>ptr->PRN;
	if(head==NULL)
		head=ptr;
	else
	{
		ptr->next=head;
		head=ptr;
	}
}

void Pinnacle::insertSecretary()
{
	node *ptr;
	ptr=new node;
	cout<<"Enter Secretary's name and PRN number\n";
	cin>>ptr->name>>ptr->PRN;
	ptr->next=NULL;
	if(head==NULL)
		head=ptr;
	else
	{
		node *temp=head;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=ptr;
	}
}

void Pinnacle::display()
{
	cout<<endl;
	if(!head)
	{
		cout<<"Empty list\n";
		return;
	}
	else
	{
		int count=0;
		node *p=head;
		while(p!=NULL)
		{
			cout<<p->PRN<<"\t"<<p->name<<endl;
			p=p->next;
			count++;
		}
		cout<<endl<<"Total members : "<<count;
	}
	cout<<endl;
}

int main()
{
	Pinnacle p1,p2,p3;
//	p1.insertNode();
//	p1.display();

	int choice;
	do{
 		cout<<"\tChoice of Operations:\n1.Display all data\n2.Insert President\n3.Insert Secretary\n4.Insert node\n5.Display in Reverse\n";
 		cout<<"6.Delete President\n7.Delete Secretary\n8.Delete Node\n9.Concatenate\n10.Exit\t";

		cin>>choice;
		switch (choice)
		{
		case 1:
			p1.display();
			break;
		case 2:
			p1.insertPresident();
			break;
		case 3:
			p1.insertSecretary();
			break;
		case 4:
			p1.insertNode();
			break;
		case 5:
			p1.reverseDisplay(p1.head);
			break;
		case 6:
			p1.deletePresident();
			break;
		case 7:
			p1.deleteSecretary();
			break;
		case 8:
			p1.deleteNode();
			break;
		case 9:
			cout<<"For 2nd list,";
			p2.insertPresident();
			p2.insertSecretary();
			p2.insertNode();
			p3=p1.concatenate(p2);
			p3.display();
			break;
		case 10:
			cout<<"Thank you.";
			break;
		default:
			cout<<"Invalid choice, Please try again.\n";
			break;
		}
	}while(choice!=10);

	return 0;
}
