//============================================================================
// Name        : matrix21326.cpp
// Author      : Abhinav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class matrix
{ int a[10][10],b[10][10],c[10][10],d[10][10],e[10][10],f[10][10],g[10][10],i,j,x,y,x1,y1,k,add,rm,cm,p;
public:
 void input();
 void output();
 void sum();
 void sub();
 void mul();
 void transpose();
 void dia();
 void saddle();
 void upper();
 
};

void matrix::input()
 { cout<<"Enter no of rows for matrix1"<<endl;
   cin>>x;
   cout<<"Enter no of columns for matrix1"<<endl;
   cin>>y;

   cout<<"Enter matrix1"<<endl;
    for(i=0;i<x;i++)
    { for(j=0;j<y;j++)
      {cin>>a[i][j];
      }
      cout<<endl;
    }

   cout<<"Enter no of rows for matrix2"<<endl;
   cin>>x1;
   cout<<"Enter no of columns for matrix2"<<endl;
   cin>>y1;


    cout<<"Enter matrix2"<<endl;
    for(i=0;i<x1;i++)
        { for(j=0;j<y1;j++)
          {cin>>b[i][j];
          }
          cout<<endl;
        }
 }

void matrix::output()
{ cout<<"Matrix 1"<<endl;
      for(i=0;i<x;i++)
        { for(j=0;j<y;j++)
           {cout<<a[i][j]<<" ";
           }
          cout<<endl;
        }

    cout<<"Matrix 2"<<endl;
            for(i=0;i<x1;i++)
              { for(j=0;j<y1;j++)
                 {cout<<b[i][j]<<" ";
                 }
                cout<<endl;
              }
}

 void matrix::sum()
 { if(x==x1 && y==y1)
   { for(i=0;i<x;i++)
      { for(j=0;j<y;j++)
         { c[i][j]=a[i][j]+b[i][j];
         }
          cout<<endl;
       }
   
    for(i=0;i<x;i++)
      { for(j=0;j<y;j++)
         { cout<<c[i][j]<<" ";
         }
          cout<<endl;
       }
    }
    else
      { cout<<"Matrix should have same row and column"<<endl;
      }
 }


 void matrix::sub()
 {  if(x==x1 && y==y1)
    { for(i=0;i<x;i++)
      { for(j=0;j<y;j++)
         { d[i][j]=a[i][j]-b[i][j];
         } 
        cout<<endl;
       }

     for(i=0;i<x;i++)
      { for(j=0;j<y;j++)
         { cout<<d[i][j]<<" ";
         }
          cout<<endl;
       }
    }
      else
         { cout<<"Matrix should have same row and column"<<endl;
         } 
 }

void matrix::mul()
{ int sum=0;
   if(y==x1)
  { for(i=0;i<y;i++)
    { for(j=0;j<x1;j++)
       { g[i][j]=0;
          for(k=0;k<y;k++)
           {  sum=sum+(a[i][k]*b[k][j]);
           }
	g[i][j]=sum;
	sum=0;
       }
     cout<<"\n";
    }
  }
   else
     { cout<<"Matrix should have same column of 1matrix and row of 2matrix"<<endl;
     }

  if(y==x1)
   { for(i=0;i<x;i++)
      { for(j=0;j<y1;j++)
          { cout<<g[i][j]<<" ";
          }
         cout<<"\n";
      }
   }
}

 
void matrix::transpose()
{ for(i=0;i<x;i++)
    { for(j=0;j<y;j++)
       { e[j][i]=a[i][j];
       }
       cout<<endl;
    }
 cout<<"Transpose of matrix1"<<endl;
    for(i=0;i<x;i++)
        { for(j=0;j<y;j++)
           { cout<<e[i][j];
           }
         cout<<"\n";
        }

  for(i=0;i<x1;i++)
    { for(j=0;j<y1;j++)
       { f[j][i]=b[i][j];
       }
       cout<<endl;
    }

 cout<<"Transpose of matrix2"<<endl;
    for(i=0;i<x1;i++)
        { for(j=0;j<y1;j++)
           { cout<<f[i][j];
           }
           cout<<"\n";
        }
}

void matrix::dia()
{ int add=0,add1=0;
  for(i=0;i<x;i++)
   { for(j=0;j<y;j++)
       {  if(i==j)
            { add=add+a[i][j];
            }
       }
    }
 cout<<"Sum of diagonal element of matrix1 "<<add<<endl;


 for(i=0;i<x1;i++)
   { for(j=0;j<y1;j++)
       {  if(i==j)
            { add1=add1+b[i][j];
            }
       }
    }
 cout<<"Sum of diagonal element of matrix2 "<<add1<<endl;
}

void matrix::upper()
{ int flag1,flag2;
 if(x==y) 
 { for(i=0;i<x;i++)
   { for(j=0;j<y;j++)
      { if(i>j)
         {  if(a[i][j]==0)
            { flag1=1;
             }
          else
            { flag1=0;              
            }
         }
       }
    }
  }
    if(flag1==1)
    { cout<<"Given matrix1 is  Upper Triangular"<<"\n";
    }
     if(flag1==0)
       { cout<<"Given matrix1 is not upper triangular"<<"\n";
       }

 if(x1==y1)
 { for(i=0;i<x1;i++)
    { for(j=0;j<y1;j++)
        { if(i>j)
           {  if(b[i][j]==0)
               { flag2=1;
               }
                else
                  { flag2=0;              
                  }
           }
        }
    }
 } 
    if(flag2==1)
    { cout<<"Given matrix2 is  Upper Triangular"<<"\n";
    }
     if(flag2==0)
       { cout<<"Given matrix2 is not upper triangular"<<"\n";
       }
}

void matrix::saddle()
{ int flag3=1;
    for(i=0;i<x;i++)
    {   p=0;
        rm=a[i][0];
           for(j=0;j<y;j++)
             { if(rm>=a[i][j]) 
                { rm=a[i][j];
                  p=j;
                }
             }
            cm=0;

    for(j=0;j<y;j++)
     { if(cm<a[j][p])
        { cm=a[j][p];
         }
     }
       
       if(rm==cm)
        { cout<<"Value of saddle point\n"<<rm<<endl;
          flag3=0;
        }
   }
  
    if(flag3>0)
     { cout<<"No saddle point\n"<<endl;  
     }
}


int main()
{  int z;
  matrix m;
  m.input();
  m.output();
  do
    { 
      
       cout<<"1.Sum of matrices\n2.Subtract of matrices\n3.Multiply\n4.Transpose\n5.Diagonal Sum\n6.Upper Triangular Matrix\n7.Saddle point\n"<<endl;
      cout<<"Enter Input"<<endl;
      cin>>z;
      switch(z)
       { case 1:{ m.sum();
                  break;
                }
         case 2:{ m.sub();
                  break;
                }
         case 3:{ m.mul();
                  break;
                 }
         case 4:{ m.transpose();
                  break;
                }
         case 5:{ m.dia();
                  break;
                }
         case 6:{ m.upper();
                  break;
                }
         case 7:{ m.saddle();
                  break;
                }
         default :{ cout<<"Thanks"<<endl;
                  }
        }

     }while(z<8);
 return 0;
}

/*[secomp@localhost 21326]$ g++ matrix21326.cpp
[secomp@localhost 21326]$ ./a.out
Enter no of rows for matrix1
3
Enter no of columns for matrix1
3
Enter matrix1
1 2 3 4 5 6 7 8 9 



Enter no of rows for matrix2
3
Enter no of columns for matrix2
3
Enter matrix2
2 4 5 7 4 6 3 8 1



Matrix 1
1 2 3 
4 5 6 
7 8 9 
Matrix 2
2 4 5 
7 4 6 
3 8 1 
1.Sum of matrices
2.Subtract of matrices
3.Multiply
4.Transpose
5.Diagonal Sum
6.Upper Triangular Matrix
7.Saddle point

Enter Input
1



3 6 8 
11 9 12 
10 16 10 
1.Sum of matrices
2.Subtract of matrices
3.Multiply
4.Transpose
5.Diagonal Sum
6.Upper Triangular Matrix
7.Saddle point

Enter Input
2



-1 -2 -2 
-3 1 0 
4 0 8 
1.Sum of matrices
2.Subtract of matrices
3.Multiply
4.Transpose
5.Diagonal Sum
6.Upper Triangular Matrix
7.Saddle point

Enter Input
3



25 36 20 
61 84 56 
97 132 92 
1.Sum of matrices
2.Subtract of matrices
3.Multiply
4.Transpose
5.Diagonal Sum
6.Upper Triangular Matrix
7.Saddle point

Enter Input
4



Transpose of matrix1
147
258
369



Transpose of matrix2
273
448
561
1.Sum of matrices
2.Subtract of matrices
3.Multiply
4.Transpose
5.Diagonal Sum
6.Upper Triangular Matrix
7.Saddle point

Enter Input
5
Sum of diagonal element of matrix1 15
Sum of diagonal element of matrix2 7
1.Sum of matrices
2.Subtract of matrices
3.Multiply
4.Transpose
5.Diagonal Sum
6.Upper Triangular Matrix
7.Saddle point

Enter Input
6
Given matrix1 is not upper triangular
Given matrix2 is not upper triangular
1.Sum of matrices
2.Subtract of matrices
3.Multiply
4.Transpose
5.Diagonal Sum
6.Upper Triangular Matrix
7.Saddle point

Enter Input
7
Value of saddle point
7
1.Sum of matrices
2.Subtract of matrices
3.Multiply
4.Transpose
5.Diagonal Sum
6.Upper Triangular Matrix
7.Saddle point

Enter Input
9
Thanks
[secomp@localhost 21326]$ 
*/


