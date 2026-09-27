#include <iostream>

using namespace std;

template <typename T, typename U>
auto max(T x, U y){

return (x > y) ? x : y;

}

int main() {
    cout << "max number is " << max(1.1, 4) << endl;
    cout << "max number is " << max(2.3, 4.4) << endl;
    return 0;
}
