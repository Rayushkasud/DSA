/* RAYUSHKA SUD CSE 3 2193191
Heap SORT
*/
#include<iostream>

using namespace std;
class Heap_ {
    public:
    int leftChild(int i){
        return (2*i+1);
    }
    int rightChild(int i){
        return (2*i+2);
    }
    int parent(int i){
        return ((i-1) /2);
    }
    void maxHeapify(int arr[], int Size , int index){
        int largest = index;
        int left = leftChild(index);
        int right = rightChild(index);
        if(left<Size && arr[left]>arr[largest]){
            largest = left;
        }
        if(right<Size && arr[right]>arr[largest]){
            largest = right;
        }
        if(largest != index){
            swap(arr[index],arr[largest]);
             maxHeapify(arr,Size,largest);
        }
    

    }
    void buildHeap(int A[], int n){
        int x = parent(n-1);
        for(int i = x; i>=0 ; i--){
            maxHeapify(A , n , i);
        }
            }
void HeapSort(int arrayToSort[],int capacity){
    buildHeap(arrayToSort , capacity);
    for(int i = capacity-1 ;i>=1;i--)
{
    swap(arrayToSort[0],arrayToSort[i]);
    maxHeapify(arrayToSort,i,0);
}
cout<<"Sorted Array"<<endl;
for(int i=0;i<capacity;i++){
    cout<<arrayToSort[i]<<" ";
}
}
};
int main(){
   
    // int num;
    // cout<<"Enter number of array elements to be sorted:"<<endl;
    // cin>>num;
    Heap_ h;
    int a[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(a) / sizeof(a[0]);
    h.HeapSort(a,n);
}

