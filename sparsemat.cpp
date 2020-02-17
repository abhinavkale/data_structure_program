/*problem statement-Write C++ program for sparse matrix realization and perform following operations on it:
Fast Transpose 
addition of two matrices
name-Abhinav Kale
batch-F3
roll no-21326
*/
#include <iostream>

using namespace std;

class sparse{
int n,m,n1,m1;
int terms,terms1;
int s[10][10],s1[10][10];

int row_no,col_no;
int value;

int row_no1,col_no1;
int value1;

public:

    void create(){
    cout<<"\nEnter matrix 1";
    cout<<"\nEnter row and column for matrix";
    cin>>n>>m;
    cout<<"\nEnter non zero terms";
    cin>>terms;

    s[0][0]=n;
    s[0][1]=m;
    s[0][2]=terms;

            for(int i=1;i<=terms;i++){
                cout<<"\nEnter row no ,col no and non zero elements";
                cin>>row_no>>col_no>>value;

                s[i][0]=row_no;
                s[i][1]=col_no;
                s[i][2]=value;
            }

    cout<<"\nEnter matrix 2";
    cout<<"\nEnter row and column for matrix";
    cin>>n1>>m1;
    cout<<"\nEnter non zero terms";
    cin>>terms1;

    s1[0][0]=n1;
    s1[0][1]=m1;
    s1[0][2]=terms1;

            for(int i=1;i<=terms1;i++){
                cout<<"\nEnter row no ,col no and non zero elements";
                cin>>row_no1>>col_no1>>value1;

                s1[i][0]=row_no1;
                s1[i][1]=col_no1;
                s1[i][2]=value1;
            }
    }

    void display(){
        cout<<"\nMatrix 1\nRow\tColumn\tElements\n";
        for(int i=0;i<=terms;i++){
            cout<<s[i][0]<<"\t"<<s[i][1]<<"\t"<<s[i][2]<<"\n";
        }
        cout<<"\n";

         cout<<"\nMatrix 2\nRow\tColumn\tElements\n";
        for(int i=0;i<=terms1;i++){
            cout<<s1[i][0]<<"\t"<<s1[i][1]<<"\t"<<s1[i][2]<<"\n";
        }
        cout<<"\n";

    }

    void transpose(){
    int temp[10][10];
    int next=1;
    temp[0][0]=m;
    temp[0][1]=n;
    temp[0][2]=terms;

        for(int c=0;c<=m;c++){

            for(int i=1;i<=terms;i++){
                if(s[i][1]==c){
                    temp[next][0]=s[i][1];
                    temp[next][1]=s[i][0];
                    temp[next][2]=s[i][2];
                    next++;
                }
            }
        }

    cout<<"\nRow\tColumn\tElements\n";
        for(int i=0;i<=terms;i++){
            cout<<temp[i][0]<<"\t"<<temp[i][1]<<"\t"<<temp[i][2]<<"\n";
        }

    }

    void fasttranspose(){
        int temp[10][10];
        int rterms[10];
        int rpos[10];
        int j;

        temp[0][0]=m;
        temp[0][1]=n;
        temp[0][2]=terms;

        for(int i=0;i<=n;i++){
            rterms[i]=0;
        }
        for(int i=1;i<=terms;i++){
            rterms[s[i][1]]++;
        }

        rpos[0]=1;
        for(int i=1;i<=n;i++){
            rpos[i]=rpos[i-1]+rterms[i-1];
        }

        for(int i=1;i<=terms;i++){
            j=rpos[s[i][1]];
            temp[j][0]=s[i][1];
            temp[j][1]=s[i][0];
            temp[j][2]=s[i][2];
            rpos[s[i][1]]=j+1;

        }

        cout<<"\nRow\tColumn\tElements\n";
        for(int i=0;i<=terms;i++){
            cout<<temp[i][0]<<"\t"<<temp[i][1]<<"\t"<<temp[i][2]<<"\n";
        }
    }

    void addition(){
        int add[10][10];
        if(s[0][0]==s1[0][0] && s[0][1]==s1[0][1]){//
            add[0][0]=s[0][0];
            add[0][1]=s[0][1];

            int i=1,j=1,k=1;
            while(i<=s[0][2] && j<=s1[0][2]){///
                if(s[i][0]==s1[j][0]){
                    if(s[i][1]==s1[j][1]){
                        add[k][2]=s[i][2]+s1[j][2];
                        add[k][1]=s[i][1];
                        add[k][0]=s[i][0];
                        k++;
                        i++;
                        j++;
                    }
                    else if(s[i][1]<s[j][1]){
                            add[k][2]=s[i][2];
                            add[k][1]=s[i][1];
                            add[k][0]=s[i][0];
                            k++;
                            i++;
                    }
                    else{
                            add[k][2]=s1[j][2];
                            add[k][1]=s1[j][1];
                            add[k][0]=s1[j][0];
                            k++;
                            j++;
                    }
                }
                else if(s[i][0]<s1[j][0]){
                    add[k][2]=s[i][2];
                    add[k][1]=s[i][1];
                    add[k][0]=s[i][0];
                    k++;
                    i++;
                }
                else{
                    add[k][2]=s1[j][2];
                    add[k][1]=s1[j][1];
                    add[k][0]=s1[j][0];
                    k++;
                    j++;
                }
            }///

            while(i<=s[0][2]){
                add[k][2]=s[i][2];
                    add[k][1]=s[i][1];
                    add[k][0]=s[i][0];
                    k++;
                    i++;
            }

             while(j<=s1[0][2]){
                add[k][2]=s1[j][2];
                    add[k][1]=s1[j][1];
                    add[k][0]=s1[j][0];
                    k++;
                    j++;
            }
            add[0][2]=k-1;

             cout<<"\nAddition\nRow\tColumn\tElements\n";
             for(int i=0;i<=add[0][2];i++){
                     cout<<add[i][0]<<"\t"<<add[i][1]<<"\t"<<add[i][2]<<"\n";
             }
             cout<<"\n";
        }//
        else{
            cout<<"\nAddition is not possible";
        }
    }
};


int main(){
sparse s;
int choice;
char a;
    do{
    cout<<"\nEnter\n1.create\n2.display\n3.transpose\n4.fast transpose\n5.addition";
    cout<<"\nEnter choice";
    cin>>choice;
        switch(choice){
        case 1:s.create();
                break;
        case 2:s.display();
                break;
        case 3:s.transpose();
                break;
        case 4:s.fasttranspose();
                break;
        case 5:s.addition();
                break;
        default:cout<<"\nInvalid option";

        }
        cout<<"Do you want to continue(y/n)";
        cin>>a;
    }while(a=='y');

return 0;
}
