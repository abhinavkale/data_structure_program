/*Problem Statemen-Write C++ program to store first year percentage of students in array. Write function for sorting array of floating point numbers in ascending order using a) Selection Sort b) Bubble sort and display top five scores.

Rollno-21326
Batch-F3
*/
#include<iostream>
using namespace std;
class sort
{
      int m[30];
      int i,j,n;
public:
       void insert(){

        cout<<"\nEnter no of students: "<<endl;
         cin>>n;
         cout<<"\nEnter marks: "<<endl;
                      for(i=0;i<n;i++)
                       cin>>m[i];                 
       }
         
         void display(){

          cout<<"\nEntered marks: "<<endl;
                  for(i=0;i<n;i++)
                     cout<<m[i]<<endl;
         }

          void bubble(){

            int temp;
                   for(i=0;i<n-1 ;i++)
                   {
                     for(j=0;j<(n-1)-i;j++)
                      {
                        if(m[j]>m[j+1])
                         {
                           temp=m[j];
                           m[j]=m[j+1];
                           m[j+1]=temp;
                         }
                      }
                   }
                   
                   cout<<"\nTop five:"<<endl;
                    for(i=n-1;i>=(n-5);i--)
                    {
                     cout<<m[i]<<endl;

                     }
           }
           
           void selection(){

           int min;
            float temp;
                   for(i=0;i<(n-1);i++)
                    {
                      min=i;
                       for(j=i+1;j<n;j++)
                        {
                          if(m[j]<m[min])
                            {
                              min=j;
                            }
                         }
                           temp=m[i];
                           m[i]=m[min];
                           m[min]=temp;

                      }
                       cout<<"\nTop five"<<endl;
                       for(i=n-1;i>= (n-5);i--)
                       {
                         cout<<m[i]<<endl;
                       }
                    }
                            
};
int main()
{
 sort s;
 int ch,x;
 	cout<<"\nList of top five students:"<<endl;
	 do
	 {
 		cout<<"1.Create \n2.Display\n3.Bubble sort\n4.Insertion sort"<<endl;
 		cout<<"\nEnter choice ";
 		cin>>ch;
 			 switch(ch)
 			 {
  				case 1:
   					s.insert();
  					 break;
 			 	case 2:
  					 s.display();
					  break;
  				case 3:
   					s.bubble();
   					break;
  				case 4:
  					 s.selection();
  					 break;
 				 default:
  					 cout<<"Invalid choice"<<endl;
  			}
  				cout<<"Do you want to continue(1/0)"<<endl;
 				 cin>>x;
	 }while(x==1);
 
    return 0;
}

