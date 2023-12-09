#include<iostream>
using namespace std;
void Countsort(int *a,int n)
{
    int k=a[0];
    for(int i=0;i<n;i++)
    {
        k=max(k,a[i]);
    }
    int count[k+1]={0};
    for(int j=0;j<n;j++)
    {
        count[a[j]]++;
    }
    for(int i=1;i<=k;i++)
    {
        count[i]+=count[i-1];
    }
    int output[n];
    for(int j=n-1;j>=0;j--)
    {
        output[--count[a[j]]]=a[j];

    }
    for(int j=0;j<n;j++)
    {        a[j]=output[j];

    }
}
int main()
{   int n;
    cout << "ENTER THE NUMBER OF ELEMENTS"<< endl;;
    cin >> n;
    int a[n];
    cout << "Enter the elements" << endl;
    for(int i=0;i<n;i++)
    {

        cin >> a[i];
    }
    Countsort(a,n);
    for(int i=0;i<n;i++)
    {
        cout << a[i] << "-->";
    }

}
