#include <iostream>

using namespace std;
void swap(int & x, int & y) {
  int temp = x;
  x = y;
  y = temp;
}
class MinHeap{
public:
    int *harr;
    int heapsize;
    int capacity;
    MinHeap(int cap){
        heapsize=cap;
        capacity=cap;
        harr=new int[cap];


    }
    void Printa()
    {
        for(int i=0;i< heapsize;i++)
        {
            cout << harr[i] << " ";


        }
        cout << endl;

    }
    void UnsortedA()
    {   cout << "ENTER THE ELEMENTS" << endl;
        for(int i=0;i<heapsize;i++)
        {
            cin >> harr[i];
        }
    }
     int parent(int i)
   {
       return ((i-1)/2);
   }
    int left(int i)
   {
       return (2*i+1);
   }
    int right(int i)
   {
       return (2*i+2);
   }
    void MinHeapify(int i)
    {   int l=left(i);
        int r=right(i);
        int smallest=i;
        if(harr[l]<harr[i] && l<heapsize)
            smallest=l;
        if(harr[r]<harr[smallest] && r<heapsize)
            smallest=r;
        if(i!=smallest)
        {
            swap(harr[smallest],harr[i]);
             MinHeapify(smallest);
        }

    }
    int extractMin()
    {
        if (heapsize==0)
        {   cout << "Heap empty"<<endl;
            return INT_MIN;

        }
        if(heapsize==1)
        {
            heapsize--;
            return harr[heapsize];
        }
       int root=harr[0];
        harr[0]=harr[heapsize-1];
        heapsize--;
        MinHeapify(0);
        return root;
    }
    void HeapSort()
    {
        int temp[capacity];
        for(int j=0;j<capacity;j++)
        {
            temp[j]=extractMin();
            cout << temp[j] << " ";
        }
    }


};

int main()
{
    int cap;
    cout << "Enter the capacity" << endl;
    cin >> cap;
    MinHeap obj(cap);
    obj.UnsortedA();
    cout << "Unsorted array :"<<endl;
    obj.Printa();
    for(int i=cap/2-1;i>=0;i--)
    {
        obj.MinHeapify(i);
    }
    cout << "sorted array"<<endl;
    obj.HeapSort();
}
