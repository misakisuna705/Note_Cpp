#include <iostream>

#include "Array.hpp"

using namespace std;

int main() {
    try {
        Misaki::Array<int> arr(5);

    } catch (exception & error) {
        cerr << error.what() << "\n";
    } catch (char const * error) {
        cerr << error << "\n";
    }

    return 0;
}
