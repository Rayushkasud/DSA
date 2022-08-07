// Naive
vector<int> leaders(int a[], int n)
{
    // Code here
    vector<int> v;
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        flag = true;
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                flag = false;
                break;
            }
            else
            {
                flag = true;
                continue;
            }
        }
        if (flag == true)
        {
            v.push_back(a[i]);
        }
    }

    return v;
//theta n solution
 vector<int> leaders(int a[], int n){
        // Code here
        vector<int> v;
        int curr = a[n-1];
        v.push_back(curr);
     for(int i=n-2;i>=0;i--){
         if(a[i]>=curr){
             curr = a[i];
             v.push_back(curr);
         }
     }
     int left =0, right = v.size()-1;
         while(left<right){
             swap(v[left],v[right]);
             left++;
             right--;
         }
     
    
        return v;
    }