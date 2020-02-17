/*Problem Statement-
Write C++ program to store first year percentage of students in array. Write function for sorting array of floating point numbers in ascending order using quick sort and display top five scores.

Name-Abhinav Kale
Batch-F3
Roll no-21326
*/
#include <iostream>
using namespace std;
int partition(float x[100],int lb,int ub)
{
	float a,temp;
	int down,up;
	a=x[lb];	
	down=lb;	
	up=ub;	
	while(down<up)
	{
		while (x[down]<=a && down<up)
			down++;
		while(x[up]>a)
			up--;

		if(down<up)
		{
			temp=x[down];
			x[down]=x[up];
			x[up]=temp;
		}
	}
	x[lb]=x[up];
	x[up]=a;
	return up;
}
void quicksort(float x[100],int lb,int ub){
	int j;
	if(lb<ub)
	{
		j=partition(x,lb,ub);
		quicksort(x,lb,j-1);
		quicksort(x,j+1,ub);
	}
}
int main()
{
	float arr[100];
	int i,n;
	cout<<"\n enter no of student:";
	cin>>n;
	cout<<"\n enter "<<n<<" student are:";
	for(i=0;i<n;i++)
		cin>>arr[i];
	quicksort(arr,0,n-1);
	cout<<"\n after sort, students are:";
	for(i=0;i<n;i++)
		cout<<arr[i]<<"\t";
	return 0;
}
