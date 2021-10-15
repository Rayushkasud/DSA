/* RAYUSHKA SUD CSE 3 2193191
LINEAR PROBING
*/
#include<iostream>

using namespace std;
class MyHash{
    public:
    int capacity, size;
    int *arr;
    public:
    MyHash(int c){
        capacity = c;
        size =0;
    
        arr = new int[capacity];
        //Initalising all values of hash table to -1(empty)
        for(int i=0; i<capacity ;i++){
            arr[i]=-1;
        }
    }
    int Hash(int key){
        return key%capacity;
    }

    bool Search(int Key){
        int h = Hash(Key);
        int i = h;
        while(arr[i] != -1){
            if(arr[i]==Key)
               return true;
            i = (i + 1)% capacity; 
            if(i==h)
               return false;
        }
        return false;
    }

    bool nextFreeSlot(int k, int pos){
      
        while(arr[pos] != -1 && arr[pos] != -2 && arr[pos] != k){

             pos = (pos + 1) % capacity;

        }
        if(arr[pos]== -1 || arr[pos] == -2){
            size++;
            arr[pos] = k;
            return true;
        }
        else{
            return false; // key already present in hash table
        }
         
    }
    
       
    
    bool insertWithReplacement(int Key){
        if(size == capacity ) return false;
        int h = Hash(Key);
        int i = h;
        int temp;
        bool res;
        if(arr[i] == -1 || arr[i] == -2){
            arr[i] = Key;
        }
        else if(Hash(arr[i]) == h){
            res = nextFreeSlot(Key , i);
            if(res){
                size++;
                return true;
            }
            else return false;
           
        }
        else{
            temp = arr[i]; 
            arr[i] = Key;
            res = nextFreeSlot(temp , i);
           if(res){
                size++;
                return true;
            }
            else return false;
            

        }
    }
        
        
        

      
 

    bool insertWithoutReplacement(int val){
        if(size == capacity) return false;
        else{
        int h = Hash(val);
        while(arr[h] != -1 && arr[h] != -2 && arr[h] != val){
            h = (h+1) % capacity;
        }
        if(arr[h]== -1 || arr[h] == -2){
            size++;
            arr[h] = val;
            return true;
        }
        else{
            return false; // key already present in hash table
        }
    }
    }
    bool del(int val){
        int i = Hash(val);
        int h =i;
        while(arr[h] != -1){
            if(arr[h] == val){
                arr[h] = -2;
                size--;
                return true;
            }
            h = (h + 1) % capacity;
            if(h==i){
                return false;
            }
        }
        return false;
    }
    void printTable(){
        for(int i = 0; i<capacity ; i++){
            cout<< arr[i]<<" ";
        }
    }


};
int main(){
    MyHash H(5);
    bool insertSuccessful ,search;
    insertSuccessful = H.insertWithoutReplacement(10);
    cout<<"Inserted successfully ? "<<insertSuccessful<<endl;
    insertSuccessful = H.insertWithoutReplacement(2);
    cout<<"Inserted successfully ? "<<insertSuccessful<<endl;
    insertSuccessful = H.insertWithoutReplacement(7);
    cout<<"Inserted successfully ? "<<insertSuccessful<<endl;
    insertSuccessful = H.insertWithoutReplacement(14);
    cout<<"Inserted successfully ? "<<insertSuccessful<<endl;
    insertSuccessful = H.insertWithoutReplacement(22);
    cout<<"Inserted successfully ? "<<insertSuccessful<<endl;
    H.printTable();
    cout<<endl;
    search = H.Search(22);
    cout<<search<<" ";
    cout<<endl;
    H.del(7);
    H.del(10);
    H.printTable();
    insertSuccessful =H.insertWithoutReplacement(9);
    cout<<"Inserted successfully ? "<<insertSuccessful<<endl;
    insertSuccessful =H.insertWithoutReplacement(14);
    cout<<"Inserted successfully ? "<<insertSuccessful<<endl;
    cout<<endl;
    insertSuccessful =H.insertWithoutReplacement(19);
    cout<<"Inserted successfully ? "<<insertSuccessful<<endl;
    H.printTable();
    H.del(19);
    H.del(9);
     H.insertWithReplacement(19);
     cout<<endl;
     H.printTable();
   insertSuccessful= H.insertWithReplacement(10);
   cout<<"Inserted successfully ? "<<insertSuccessful<<endl;
    cout<<endl;
    H.printTable();
    


}