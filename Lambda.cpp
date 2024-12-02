#include<bits/stdc++.h>
using namespace std;

// struct Lambda {
//     int operator()(int x) const {
//         return x + 1;
//     }
// };

int  main(){
    // Lambda lambda;
    // cout << lambda(2) << '\n';


    // auto lambda_outer =
    // [](int x) {
    //     return [x](int y) {
    //         return x + y;
    //     };
    // };
    // cout << lambda_outer(1)(2) << '\n';



    int y = 1, x = 0;
    auto lambda = [y, &x](auto a, int b) constexpr mutable -> int {
        return sizeof(a) * y + b * x;
    };
    cout<<x;
}
