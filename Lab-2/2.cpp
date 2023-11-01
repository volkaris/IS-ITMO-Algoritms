#include <iostream>
#include "vector"
using namespace std;
int main(){
    vector <int> array;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){int g;
        cin >>g ;
        array.push_back(g);
    }
    for (int i=1;i<n;i++){
        int k=i;
        while (k!=0 and array[k-1]>array[k]){
            swap(array[k],array[k-1]);
            k-=1;
        }
    }
    for(int i=0;i<n;i++){
        cout <<array[i]<<" ";
    }
}