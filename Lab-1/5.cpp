#include <iostream>
#include "vector"
using namespace std;
int main()
{   int n,x;
    long long int distance1,distance,mindistance=999999999999999999;
    vector<int>arr;
    cin >> n;
    for(int i=0;i<n;i++){int g;
        cin >>g;
        arr.push_back(g);
    }
    cin >>x;
    for (int i=0;i<arr.size();i++){
        distance=abs(arr[i]-x);
        mindistance=min(distance,mindistance);
    }
    for (int i=0;i<arr.size();i++){
        distance1=abs(arr[i]-x);
        if (distance1==mindistance){cout << arr[i];
            break;
        }
    }
}