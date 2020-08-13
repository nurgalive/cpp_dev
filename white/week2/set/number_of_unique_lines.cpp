// Количество уникальных строк

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {

    set<string> set_lines;

    //input number of lines
    int N;
    cin >> N;


    string line;

    for (int i = 0; i < N; i++) {
        cin >> line;

        set_lines.insert(line);

    }

    cout << set_lines.size();

   return 0;
}
