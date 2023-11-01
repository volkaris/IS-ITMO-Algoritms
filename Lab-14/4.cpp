#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<std::string, null_type,std::less_equal<std::string>, rb_tree_tag,tree_order_statistics_node_update>

int main(){
    ordered_set X;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    size_t n;
    std::cin >> n;

    for (size_t i = 0; i < n; ++i) {
        std::string input;
        std::cin >> input;

        if (isdigit(input[0])) {

            std::cout<<*X.find_by_order(stoi(input)-1)<< "\n";

        }
        else {
            X.insert(input);
        }
    }

}