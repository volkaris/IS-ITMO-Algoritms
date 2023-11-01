#include <iostream>
#include <iso646.h>
using namespace  std;
int main() { int q,n,arr[100];
    cin >> n;
    for (int i=0;i<n;i++){
        cin >>q;
        arr[i]=q;
    }
int count=0;
    for (int i=1;i<n-1;i++){
        if (arr[i]>arr[i-1] and arr[i]>arr[i+1]) {count+=1
            ;
    }
}
    cout << count;
}