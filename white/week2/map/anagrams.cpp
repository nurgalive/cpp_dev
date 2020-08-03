#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

map<char, int> BuildCharCounters(const string& s) {
    //cout << "Size = " << m.size() << endl;
    map<char, int> result;

    for (auto c : s) {
        ++result[c];
    }

    // printing the map
//    for (auto [key, value] : result) {
//        cout << key << ": " << value;
//    }

    return result;
}

int main() {
    // input number of lines
    int N;
    cin >> N;

    // input word, word2
    string word1;
    string word2;


    for (int i = 0; i < N; i++) {
        cin >> word1 >> word2;
        //cout << word1 << endl;
        //cout << word2 << endl;

        if (BuildCharCounters(word1) == BuildCharCounters(word2)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

   return 0;
}
