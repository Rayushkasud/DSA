/* RAYUSHKA SUD CSE 3 2193191
Telephone directory
*/
#include<iostream>
#include<vector>
#include <utility>
#include<string>


using namespace std;
//#define m 1000000007
typedef long long ll;
using namespace std;
using namespace std;
 

struct pai
{
    string name;
    ll ph_no;
};

class hashmap
{
    pai dir[10];

public:
    
    hashmap()
    {
        for(int i=0;i<10;i++)
        {
            dir[i].ph_no=0;
        }
    }

    void insert_num()
    {
        ll n,sum;
        string in_name;
        ll num;
        int hashvalue,end_point;
        cin >> n;
        for(int i=0;i<n;i++)
        {
            cin >> in_name;
            cin >> num;

            sum = 0;
            for(int i=0;i<in_name.length();i++)
            {
                sum += in_name[i];
            }
            
            hashvalue=(sum/in_name.length())%10;
            end_point=hashvalue;

            while(true)
            {
                if(dir[hashvalue].ph_no==0)
                {
                    dir[hashvalue].name=in_name;
                    dir[hashvalue].ph_no=num;
                    break;
                }
                hashvalue=(hashvalue+1)%10;
                if(hashvalue==end_point)
                {
                    break;
                }
            }
        }
    }

    void search_dir()
    {
        ll sum;
        string s_name;
        ll s_num;
        int hashvalue,end_point;

        cin>> s_name;
        sum=0;
        for(int i=0;i<s_name.length();i++)
        {
            sum +=s_name[i];
        }
        
        hashvalue=(sum/s_name.length())%10;
        end_point=hashvalue;

        while(true)
        {
            if(dir[hashvalue].name==s_name)
            {
                cout<<"found : "<<dir[hashvalue].ph_no<<endl;
                break;
            }
            hashvalue=(hashvalue+1)%10;
            if(hashvalue==end_point)
            {
                cout<<"not found"<<endl;
                break;
            }
        }
    }

};



int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    hashmap m;
    m.insert_num();
    m.search_dir();
    

	return 0;
}