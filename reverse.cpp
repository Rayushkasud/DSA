#include <iostream>

using namespace std;
int arr[5] = {1, 2, 3, 4, 5};
int *reverse()
{
    int n = 5;
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    return arr;
}
void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}
int main()
{
    int *p;

    p = reverse();
    for (int i = 0; i < 5; i++)
    {
        cout << *(p + i) << " ";
    }
}