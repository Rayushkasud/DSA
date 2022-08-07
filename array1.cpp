#include <iostream>
using namespace std;
int Delete(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
            break;
    }
    if (i==n){
        return n;
    }
    for (int j = i ; j < n ; j++)
    {
        arr[j] = arr[j + 1];
    }
    return (n - 1);
}
int main()
{
    int a[] = {2, 4, 1, 5, 7};
    int k = Delete(a, 5, 1);
    
    for (int i = 0; i < k; i++)
    {
        cout << a[i] << " ";
    }
}
