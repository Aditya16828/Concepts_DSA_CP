#include<iostream>
using namespace std;

int main(){
    int *ptr = new int(8);
    cout<<*ptr<<"\n";

    // array of integers in heap
    int *arr = new int[10];

    // initialize an array with all zeros
    int *zeros = new int[10]();

    for(int i=0;i<10;i++){
        cout<<zeros[i]<<" ";
    }
    std::cout<<"\n";

    int rows, cols;
    cin>>rows>>cols;
    int **grid = new int*[rows]; // inits the primary array only
    for(int i=0;i<rows;i++){
        grid[i] = new int[cols]();
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++)
            std::cout<<grid[i][j];
        std::cout<<"\n";
    }

    //int *r = new int(nothrow)(10);
    /*if(not r){
        cout<<"Memory not allocated\n";
    }*/
    return 0;
}