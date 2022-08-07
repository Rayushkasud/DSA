#include <iostream>
#include <vector>
using namespace std;

void moveZerosConstantSpace(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[count]);
            count++;
        }
    }
    for (int i = 0; i < n; i++)
    {

        cout << arr[i] << " ";
    }
}
void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

vector<int> moveZeros(int arr[], int size)
{
    vector<int> newArr;
    for (int i = 0; i < newArr.size(); i++)
    {

        cout << newArr[i] << " ";
    }
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != 0)
        {
            newArr.push_back(arr[i]);
        }
        else
        {
            count++;
        }
    }
    while (count > 0)
    {
        newArr.push_back(0);
        count--;
    }
    return newArr;
}

int main()
{
    int arr[5] = {0, 0, 0, 0, 5};
    int n = 5;
    vector<int> v = moveZeros(arr, n);
    cout << v.size() << endl;
    // moveZerosConstantSpace(arr, n);
    for (int i = 0; i < v.size(); i++)
    {

        cout << v[i] << " ";
    }
}