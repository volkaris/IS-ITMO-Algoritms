#include <iostream>
#include <iso646.h>
using namespace  std;
int main() { int q,n,arr[100];
    cin >> n;
    for (int i=0;i<n;i++){
        cin >>q;
        arr[i]=q;
    }

int tmp=arr[n-1];
    for (int i=(n-1);i>0;i--){
        arr[i]=arr[i-1];
    }
arr[0]=tmp;
    for (int i=0;i<n;i++){
        cout <<arr[i]<<" ";
    }
}