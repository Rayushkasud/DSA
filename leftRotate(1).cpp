#include <iostream>
#include <vector>
using namespace std;
void leftRotate(vector<int> &v)
{
    int temp = v[0];
    int len = v.size();
    for (int i = 0; i < v.size() - 1; i++)
    {
        v[i] = v[i + 1];
    }
    v[len - 1] = temp;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
int main()
{
    vector<int> vect;
    for (int i = 0; i < 5; i++)
    {
        vect.push_back(i + 1);
    }
    leftRotate(vect);
}
//left rotate by d w theta d space
	public:
	void leftRotate(int arr[], int k, int n) 
	{ 
	   // Your code goes here
	  
	   vector<int> v;
	   for(int i=0;i<k;i++){
	       v.push_back(arr[i]);
	   }
	   for(int i=k;i<n;i++){
	       arr[i-k] = arr[i]; 
	   }
	   for(int i=0;i<k;i++ ){
	       arr[n-k+i] = v[i];
	   }
	}