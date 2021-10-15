#include<iostream> 
#include<stack>
#include<vector>
using namespace std;

class Cube{
    private:
    int length;

    Cube(int len){
        length = len;

    }

    int getLength(){
        return length;
    }
friend class Game;

};
class Game{

vector< stack<Cube> > stacks;
Cube cube1 = new Cube(10);
Cube cube2 = new Cube(9);
Cube cube3 = new Cube(8);
Cube cube4 = new Cube(7);
stacks[0].push(cube1);
stacks[0].push(cube2);
stacks[0].push(cube3);
stacks[0].push(cube4);
    void Solve(){
        while(_stack[2].size() != 4){
            legalMove(0,1);
            legalMove(0,2);
            legalMove(1,2);
        }
        cout<< *this <<"\n";

    }
    void legalMove(int index1 , int index2){
        if(stacks[index1].size()==0 && stacks[index2].size()>0)
        move(index2,index1);
        else if(stacks[index2].size()==0 && stacks[index1].size()>0)
        move(index1,index2);
        else {
        if(stacks[index1].top().getLength()<stacks[index2].top().getLength)
        move(index1,index2);
        else
        move(index2,index1);
        }

    }

    void move(int index1, int index2){
        Cube cube= stacks[index1].top();
        stacks[index1].pop();
        stacks[index2].push(cube);

    }

};