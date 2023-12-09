#include <iostream>
#include<math.h>
using namespace std;
void swap(int & x, int & y) {
  int temp = x;
  x = y;
  y = temp;
}

class MaxHeap{
    public:
        int *harr;
        int heapsize;
        int capacity;
        MaxHeap(int c)
        {
            heapsize=0;
            capacity=c;
            harr=new int[c];
        }

void linearsearch(int val)
{
    for(int i=0;i<heapsize;i++)
    {
        if(harr[i]==val)
            {cout << "Value found" << endl;
                return;
            }


    }
    cout << "Value not found " << endl;
}
int getMax()
{
    return harr[0];
}
int height()
{
    return ceil(log2(heapsize)+1)-1;
}
int parent(int i)
{
    return (i-1)/2;
}
int left(int i)
{
    return (2*i+1);
}
int right(int i)
{
    return (2*i+2);
}
void InsertKey(int val)
{
    if(heapsize==capacity)
    {
        cout << "Heap full" << endl;
        return;
    }
    heapsize++;
    int i=heapsize-1;
    harr[i]=val;
    while(i!=0 && harr[parent(i)]<harr[i])
    {
        swap(harr[parent(i)],harr[i]);
        i=parent(i);
    }

}
void MaxHeapify(int i)
{
    int l=left(i);
    int r=right(i);
  //  int p=parent(i);
    int largest=i;
    if(l<heapsize && harr[i]<harr[l])
    {
        largest=l;
    }
    if(r<heapsize && harr[largest]<harr[l])
    {
        largest=r;
    }
    if(i!=largest)
    {
        swap(harr[i],harr[largest]);
        MaxHeapify(largest);
    }

}
int extractMax()
{
    if(heapsize==1)
    {   heapsize--;
        return harr[0];
    }
    else if(heapsize==0)
    {
        cout << "Heap empty" << endl;
        return INT_MAX;
    }
    else
    {
        int temp=harr[0];
        heapsize--;
        harr[0]=harr[heapsize];
        MaxHeapify(0);
        return temp;
    }
}
void IncreaseKey(int k,int v)
{   harr[k]=v;
    while((harr[parent(k)] <harr[k]) && k!=0)
    {
        swap(harr[parent(k)],harr[k]);
        k=parent(k);
    }

}
void deleteKey(int i)
   {
       IncreaseKey(i,INT_MAX);
       extractMax();
   }
void Printa(){
    for(int i=0;i<heapsize;i++)
    {
        cout << harr[i] << endl;
    }

}

};


int main()
{   int s;
    cout << "Enter size of heap"<< endl;
    cin >> s;

    MaxHeap obj(s);
    cout << "Min heap created" << endl;
    int option ,val;
    do{
         cout << "1. Insert node" << endl;
         cout << "2. Search node" << endl;
         cout << "3. Delete node" << endl;
         cout << "4. Get Min" << endl;
         cout << "5. Extract Min" << endl;
         cout << "6. Height of heap" << endl;
        cout << "7.Print Heap Values" << endl;
         cout << "0.Exit Program" << endl;
         cin >> option;
         switch(option){
         case 0:
             break;
    case 1:
      cout << "INSERT Operation -" << endl;
      cout << "Enter VALUE to INSERT in HEAP: ";
      cin >> val;
      obj.InsertKey(val);
      cout << endl;
      break;
    case 2:
      cout << "SEARCH Operation -" << endl;
      cout << "Enter VALUE to SEARCH in HEAP: ";
      cin >> val;
      obj.linearsearch(val);
      break;
    case 3:
      cout << "DELETE Operation -" << endl;
      cout << "Enter INDEX of Heap Array to DELETE: ";
      cin >> val;
      obj.deleteKey(val);
      break;
    case 4:
      cout << "GET MAX value : " << obj.getMax();
      cout << endl;
      break;
    case 5:
      cout << "EXTRACT MAX value : " << obj.extractMax();
      cout << endl;
      break;
    case 6:
      cout << "HEAP TREE HEIGHT : " << obj.height() << endl;
      break;

    case 7:
      cout << "PRINT Heap Array : " << endl;
      obj.Printa();

      cout << endl;
      break;

    

    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;


}

