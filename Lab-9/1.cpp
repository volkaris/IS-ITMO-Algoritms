#include <iostream>
#include <bitset>
using namespace std;

void constructGrayCode(size_t amount)
{
    size_t degree = pow(2, amount);
    for (size_t i = 0; i < degree; ++i) {
		const size_t grayCode = i ^ (i >> 1);
        bitset<15> binaryGray(grayCode);
        cout << binaryGray.to_string().substr(15 - amount) << endl;
    }
}

int main()
{
    size_t amount;
    cin >> amount;
    constructGrayCode(amount);
}