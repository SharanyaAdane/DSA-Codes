 #include<iostream>
using namespace std;
void swap(int *b,int *c)
{
    int temp=*b;
    *b=*c;
    *c=temp;
}
int partition(int *a,int p,int q)
{
    int x=a[p];
    int i=p;
    int j;
    for(j=p+1;j<=q;j++)
    {
        if(a[j]<=x)
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i],&a[p]);
    return i;
}
void print(int *a,int n)
{
    for(int i=0;i<n;i++)
        {
            cout << a[i]<< "--->";
        }
        cout << endl;
}
void Quicksort(int *a,int p,int q)
{
    if(p<q)
    {
        int t=partition(a,p,q);
        Quicksort(a,p,t-1);
        Quicksort(a,t+1,q);

    }
   // print(a,q-p+1);

}
int main()
{
    int n;
    cout << "ENTER THE  NUMBER OF ELEMENTS" << endl;
    cin >> n;
    int a[n];
    cout << "Enter the elements" << endl;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    };
    Quicksort(a,0,n-1);
    // Printing the array
    for(int i=0;i<n;i++)
    {
        cout << a[i];
    };
}
