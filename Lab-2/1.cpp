#include <iostream>
using namespace std;
int main(){
    int array[1001];
    int n,position,number,position_1;
    cin >> n;

    for(int i=0;i<n;i++){int g;
        cin >>g ;
        array[i]=g;
    }
    cin >>number >>position;
    for (int i=n-1;i>=position;i--){
        array[i+1]=array[i];
    }
    position_1=array[position-1];
    array[position]=position_1;
    array[position-1]=number;
    for(int i=0;i<n+1;i++){
        cout <<array[i]<<" ";
    }
}