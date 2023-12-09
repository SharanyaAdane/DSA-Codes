#include <iostream>
#include<stdio.h>


using namespace std;

int main()
{   int seq[10];
    int nos;
    int j,i;
    int key;
    cout << "Enter the numbers to be sorted :" << endl;
    cin >> nos;


    for(i=0;i<nos;i++)

     {  //cout << "Enter "<< i+1 << "number"<< endl;
        //cin >> seq[i];
        seq[i]=rand()%10;
     }

     for(j=1;j<nos;j++)
     {
       key=seq[j];
       for(i=j-1;i>=0 && seq[i]>key;i--)
       {
          seq[i+1]=seq[i];

       }
       seq[i+1]=key;
     }
     for(i=0;i<nos;i++)
     {
         cout << seq[i] << endl;
     }


    return 0;

}
