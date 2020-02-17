#include<iostream>
using namespace std;

class str
{
  char str1[20],str2[20];
  int i,l1,l2;
   public:
    void input();
    void output();
    void len();
    void copys();
    void con();
    void reverses();
    void sub();
    void palin();
    void freq();
    void del();
};

 void str::input()
 { cout<<"Enter String1: "<<endl;
   cin>>str1;

   cout<<"\nEnter String2: "<<endl;
   cin>>str2;
  }

 void str::output()
 { cout<<"\nEntered String1: "<<endl;
   cout<<str1;


   cout<<"\nEntered String2: "<<endl;
   cout<<str2;


  }

 void str::len()
 { int i,j;

   for(i=0;str1[i]!='\0';i++);
   cout<<"\nString1 length= "<<i<<endl;


   for(j=0;str2[j]!='\0';j++);
   cout<<"\nString2 length= "<<j<<endl;

 }

 void str::con()
 { int i,j,k=0;
   char conc[50];

      for(i=0;str1[i]!='\0';i++)
      {
          conc[k]=str1[i];
          k++;
      }
      for(j=0;str2[j]!='\0';j++)
      {
          conc[k]=str2[j];
          k++;
      }
      conc[k]='\0';
      cout<<conc;
 }

 void str::copys()
 {   int j;
     char co[50];
     for(i=0,j=0;str1[i]!='\0';i++,j++)
    { co[j]=str1[i];
    }
    co[j]='\0';
     cout<<"Copied string1= "<<co;
 }

 void str::reverses()
 { int i,j,k;
   char temp[10];
   for(i=0;str1[i]!='\0';i++);
   for(k=i-1,j=0;k>=0;j++,k--)
   {
       temp[j]=str1[k];
   }
   temp[j]='\0';
   cout<<temp;
 }

 void str::sub()
{ int j=0,flag;
  char s[10];
  cout<<"Enter string to check substring: ";
  cin>>s;
  for(i=0;str1[i]!='\0';i++)
   { while(str1[i]==s[j])
     { ++i;
       ++j;
       if(s[j]=='\0')
       { flag=0;
       }
     }
   }
   if(flag!=0)
    {cout<<"Substring is not present:";
    }
  else
  {cout<<"Substring is present";
  }
}

 void str::palin()
 {int i,j;
     for(i=0;str1[i]!='\0';i++);
     for(j=i-1,i=0;j>=0;j--,i++)
     {
         if(str1[i]!=str1[j])
         {
             cout<<"\nString1 is not palindrome";
             return;
         }
     }
     cout<<"\nSting1 is palindrome";
 }
 void str::del()
{	int ind,l,s;
	char temp3[100];
	cout<<"Enter the index from where you want to delete :";
	cin>>ind;
	cout<<"Length of string to be deleted:";
	cin>>l;
	s=ind+l-1;
	int j=0;
	for(i=0;str1[i]!='\0';i++)
	{  if(i<ind||i>s)
	  { temp3[j]=str1[i];
      	    j++;
          }
        }
        cout<<endl<<temp3<<endl;

}

void str::freq()
{	char c;
	int cnt=0;
	cout<<"Enter the character :";
	cin>>c;
	for(i=0;str1[i]!='\0';i++)
	{if(str1[i]==c)
	 cnt++;
	}
	cout<<"\nFrequency of occurence is :"<<cnt<<endl;


}

int main()
{ str s;
  s.input();
  s.output();
  int choice;
  char a;

   do
    { cout<<"\n1.String length\n2.String copy\n3.String concatenate\n4.String reverse\n5.Substring\n6.Frequency of occurrence\n7.Delete substring\n8.Palindrome";
      cout<<"Entered choice\n";
      cin>>choice;
        switch(choice)
        { case 1:s.len();
                 break;

          case 2:s.copys();
                 break;

          case 3:s.con();
                 break;

          case 4:s.reverses();
                 break;

          case 5:s.sub();
                 break;

          case 6:s.freq();
                 break;

          case 7:s.del();
                 break;
          case 8:s.palin();
                 break;

          default:cout<<"Thanks";
        }
  cout<<"\nDo another choice(y/n): \n";
  cin>>a;
    }while(a=='y');


 return 0;
}

/*
[secomp@localhost 21326]$ g++ string.cpp
[secomp@localhost 21326]$ ./a.out
Enter String1: 
Abhinav

Enter String2: 
Kale

Entered String1: 
Abhinav
Entered String2: 
Kale
1.String length
2.String copy
3.String concatenate
4.String reverse
5.Substring
6.Frequency of occurrence
7.Delete substring
8.PalindromeEntered choice
1

String1 length= 7

String2 length= 4

Do another choice(y/n): 
y

1.String length
2.String copy
3.String concatenate
4.String reverse
5.Substring
6.Frequency of occurrence
7.Delete substring
8.PalindromeEntered choice
2
Copied string1= Abhinav
Do another choice(y/n): 
y

1.String length
2.String copy
3.String concatenate
4.String reverse
5.Substring
6.Frequency of occurrence
7.Delete substring
8.PalindromeEntered choice
3
AbhinavKale
Do another choice(y/n): 
y

1.String length
2.String copy
3.String concatenate
4.String reverse
5.Substring
6.Frequency of occurrence
7.Delete substring
8.PalindromeEntered choice
4
vanihbA
Do another choice(y/n): 
y

1.String length
2.String copy
3.String concatenate
4.String reverse
5.Substring
6.Frequency of occurrence
7.Delete substring
8.PalindromeEntered choice
5
Enter string to check substring: y
Substring is present
Do another choice(y/n): n
*/

