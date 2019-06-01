#include <iostream>

#include "Array.hpp"

using namespace std;

int main() {
    try {
    } catch (exception & error) {
        cerr << error.what() << "\n";
    } catch (char const * error) {
        cerr << error << "\n";
    }

    return 0;
}
