#include <iostream>
#include "vector"
using namespace std;

int main() {
    int n, m;
    vector <int> gruzopodemnost;
    vector <int> mass_of_mesk;
    cin >> n >> m;
    for (int i = 0; i < n * m; i++) {
        int g;
        cin >> g;
        gruzopodemnost.push_back(g);
    }
    for (int i = 1; i < n * m; i++) {
        int qw = i;
        while (qw != 0 and gruzopodemnost[qw - 1] > gruzopodemnost[qw]) {
            swap(gruzopodemnost[qw - 1], gruzopodemnost[qw]);
            qw -= 1;
        }
    }
    int kolvo_mesk;
    cin >> kolvo_mesk;
    for (int i = 0; i < kolvo_mesk; i++) {
        int k;
        cin >> k;
        mass_of_mesk.push_back(k);
    }
    for (int i = 1; i < kolvo_mesk; i++) {
        int qw = i;
        while (qw != 0 and mass_of_mesk[qw - 1] > mass_of_mesk[qw]) {
            swap(mass_of_mesk[qw - 1], mass_of_mesk[qw]);
            qw -= 1;
        }
    }
    int count = 0;
    reverse(mass_of_mesk.begin(), mass_of_mesk.end());
    reverse(gruzopodemnost.begin(), gruzopodemnost.end());
    int i =n*m-1, j = kolvo_mesk-1;
    while ((i + 1) * (j + 1) > 0){
        if (mass_of_mesk[j] <= (gruzopodemnost[i])) {
            count++;
            i--;
            j--;

        }
        else {
            i--;
        }
    }
    
    cout << count;
}