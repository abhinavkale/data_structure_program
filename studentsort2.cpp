/*Problem Statement-Write C++ program to store second year percentage of students in array. Write function for sorting array of floating point numbers in ascending order using a) Insertion sort b) Shell Sort and display top five scores.
Name-Abhinav Kale
Batch-F3
Rollno-21326
*/
#include <iostream>

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

          void insertionsort(){
            int x;
          for(i=1;i<n;i++){
            j=i-1;
            x=m[i];
                while(j>-1&&m[j]>x){
                    m[j+1]=m[j];
                    j--;
                }
                m[j+1]=x;
          }

            display();
          }

           void shellsort(){

           int gap,temp;
            for(gap=n/2;gap>=1;gap=gap/2){
                for(i=gap;i<n;i++){
                    temp=m[i];
                    j=i-gap;
                        while(j>=0 && m[j]>temp){
                            m[j+gap]=m[j];
                            j=j-gap;
                        }
                        m[j+gap]=temp;
                }
            }
            display();
           }

};
int main()
{
 sort s;
 int ch;
 char c;
 	cout<<"\nList of top five students:"<<endl;
	 do
	 {
 		cout<<"1.Create \n2.Display\n3.insertion sort\n4.shell sort"<<endl;
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
   					s.insertionsort();
   					break;
  				case 4:
  					 s.shellsort();
  					 break;
 				 default:
  					 cout<<"Invalid choice"<<endl;
  			}
  				cout<<"Do you want to continue(y/n)"<<endl;
 				 cin>>c;
	 }while(c=='y');

    return 0;
}

