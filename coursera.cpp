#include <iostream>
int *allocate_an_integer() {
    int j;
    int *i = &j;
    *i = 0;
    //std::cout<<*i<<std::endl;
    return i;
}
void func(){
int *i = new int;
*i = 0;
int &j = *i;
j++;
std::cout<<j;
}
int main(){
    func();
//std::cout<<allocate_an_integer();
}