#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string>  radixsort(vector<string>& arr, int len, int phase) {
  for (int i = len - 1; i >= len - phase; i--) {
    vector<int> alphabet(26);
    for (int j = 0; j < arr.size(); j++) {
      alphabet[arr[j][i] - 'a']++;          //arr[j][i]-с первого слова с последней буквы смотрим  
      //arr[j][i]-"a"-получаем какую то букву и чтобы поставить ее в нужное место в массиве нужен ее индекс вычитаем из нее 'a" и получаем аски код(число) и по нему засовываем в массив и переходим к следующему слову
    }

  int temp,count=0;
    
    for (int j = 0; j < alphabet.size(); j++) {
       temp = alphabet[j];
      alphabet[j] = count;
      count += temp;
    }

    vector<string> answer(arr.size(), "");
	
    for (int j = 0; j < arr.size(); j++) {
      answer[alphabet[arr[j][i] - 'a']] = arr[j];
      alphabet[arr[j][i] - 'a']++;
    }
  
    arr = answer;
  }
  return arr;
}

int main() {
  
  int amount_of_strings, len, phase;
  cin >> amount_of_strings >> len >> phase;
  vector<string> arr(amount_of_strings);
  for (int i = 0; i < amount_of_strings; i++) {
    cin>> arr[i];
  }


  radixsort(arr, len, phase);

  for (int i = 0; i < amount_of_strings; i++) {
    cout << arr[i] << endl;
  }

}