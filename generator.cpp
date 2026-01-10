#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

void write_test(int id, int n, int k) {
    string filename = "test_cases/" + to_string(id) + ".in";
    ofstream out(filename);
    out << n << " " << k << endl;
    out.close();
    cout << "Generated " << filename << ": " << n << " " << k << endl;
}
int main() {
    write_test(1, 10, 2);
    write_test(2, 60, 8);
    write_test(3, 20, 0); 
    write_test(4, 5, 3);
    write_test(5, 50, 5);  
    return 0;
}
