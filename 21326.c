/*Name-Abhinav Shivaji Kale   Roll no-21326 Batch-F3
  Date of Execution-15/06/19   Date of Completion-18/06/19
   */

#include<stdio.h>
struct student
   { int rno;
     float marks;
   }s[5];
void main()
{ 
   int i,j,z,n,e=0; 
   float a=0,b=0;
   void input();
   void average();
   void high();
   void low();
   void absent();
   void max();

  do
  { printf("1.Input\n2.Average\n3.Highest marks\n4.Lowest marks\n5.Maximum frequency\n6.Absent Student\n");
            
    printf("Enter choice\n");
    scanf("%d",&z);
    
   switch(z)
    { case 1: {input();
                break;
              } 
      case 2: {average();
                break;
              }
      case 3: {high();
                break;
              }
      case 4: {low();
                break;
              }
      case 5: {max();
               break;
              } 
      case 6: {absent();
               break;
              }
      default: { printf("Thanks\n");
               }  
   }
 
 }while(z<7);
                
}

 void input()
 {  int i;
    printf("Enter any 5 Roll No\n");
    printf("For Absent Student Enter -1 as marks\n");
     for(i=1;i<=5;i++)
       { printf("Roll No = ",s[i].rno);
         scanf("%d",&s[i].rno);
         printf("Enter marks= \n",s[i].marks);
         scanf("%f",&s[i].marks);
       }
  
    for(i=1;i<=5;i++)
    { printf("%d  %f\n",s[i].rno,s[i].marks);
    }
 }

 void average()
  {  int i;
     float a=0,b=0;
    for(i=1;i<=5;i++)
      { a=a+s[i].marks;
        a++;
      }
   b=(a-5)/5;
   printf("Average Marks= %f\n",b);
  }

 void high()
  {  int i,c=0;
     for(i=1;i<=5;i++)
       { if(s[i].marks>c)
           { c=s[i].marks;
           }
        } 
    printf("Highest marks=%d\n",c);
  }

 void low()
 { int i,d=0;
   d=s[1].marks;
     for(i=1;i<=5;i++)
     { if(d>=s[i].marks)
         { d=s[i].marks;
         }  
     } 
  printf("Lowest marks=%d\n",d);
 }
 
 void absent()
 { int i,ab=0;
   for(i=1;i<=5;i++)
    { if(s[i].marks==-1)
        { ab=s[i].rno;
          break; 
        }
    }
printf("Absent Student Roll No=%d\n",ab);
 }

 void max()
 { int i,j,k=0;
  s[6].marks=0;
  for(i=1;i<=5;i++)
  {
     for(j=i+1;j<=5;j++)
    { 
        if(s[j].marks==s[i].marks)
         { k=1;
          
         }
     }
  }k=k+1;
  printf("Maximum Frequency=%d\n",k);

for(i=1;i<=5;i++)
    { for(j=1)
      if(k>1)
       {
         printf("Marks=%f",s[i].marks);
       }  

     }





 }

/*
[secomp@localhost 21326]$ gcc 21326.c
[secomp@localhost 21326]$ ./a.out
1.Input
2.Average
3.Highest marks
4.Lowest marks
5.Maximum frequency
6.Absent Student
Enter choice
1
Enter any 5 Roll No
For Absent Student Enter -1 as marks
Roll No = 1
Enter marks= 
12
Roll No = 2
Enter marks= 
14
Roll No = 3
Enter marks= 
15
Roll No = 4
Enter marks= 
17
Roll No = 5  
Enter marks= 
14
1  12.000000
2  14.000000
3  15.000000
4  17.000000
5  14.000000
1.Input
2.Average
3.Highest marks
4.Lowest marks
5.Maximum frequency
6.Absent Student
Enter choice
2
Average Marks= 14.400000
1.Input
2.Average
3.Highest marks
4.Lowest marks
5.Maximum frequency
6.Absent Student
Enter choice
3
Highest marks=17
1.Input
2.Average
3.Highest marks
4.Lowest marks
5.Maximum frequency
6.Absent Student
Enter choice
4
Lowest marks=12
1.Input
2.Average
3.Highest marks
4.Lowest marks
5.Maximum frequency
6.Absent Student
Enter choice
5
Maximum Frequency=2
1.Input
2.Average
3.Highest marks
4.Lowest marks
5.Maximum frequency
6.Absent Student
Enter choice
6
Absent Student Roll No=0
1.Input
2.Average
3.Highest marks
4.Lowest marks
5.Maximum frequency
6.Absent Student
Enter choice
7
Thanks
[secomp@localhost 21326]$ gedit 21326.c
*/


 



 


  

   
   
