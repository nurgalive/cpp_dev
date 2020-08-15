#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void Print(const vector<int>& input, const string& title){
    cout << title << ": ";
    cout << "[";
    for (auto v : input) {
        cout << v << ",";
    }
    cout << "]";
    cout << endl;
}



int main() {
    vector<int> v;

    int N;
    cin >> N;

    int number;

    for(int i = 0; i < N; i++) {
        cin >> number;
        v.push_back(number);
    }

    //Print(v, "Before");
    sort(begin(v), end(v), [](int x, int y) {
        if (x < 0) {
            x = x * -1;
        }

        if (y < x) {
            y = y * -1;
        }

        return (x < y);
    });

    //Print(v, "After");

    for (const int& val : v) {
        cout << val << " ";
    }

    return 0;
}
