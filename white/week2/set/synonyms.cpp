// Синонимы

#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

void PrintSet(const set<set<string>>& vec) {
    for (auto v : vec) {
        cout << "Set: ";
        for (auto s : v) {
            cout << s << " ";
        }
        cout << endl;
    }
}

void Add(const string& word1, const string& word2, map<string, set<set<string>>>& input) {
    set<string> temp_set = {word1, word2};
    input[word1].insert(temp_set);
    input[word2].insert(temp_set);
}

void Count(const string& word, map<string, set<set<string>>>& input_map) {
    cout << input_map[word].size() << endl;
}

void Check(const string& word1, const string& word2, map<string, set<set<string>>>& input_map) {
    set<string> temp_set = {word1, word2};

    if (input_map[word1].count(temp_set) == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    // ключ: слово
    // значение: множество пар слов
    // word1 : <<word1, word2>, <word1, word3>>
    // word2 : <<word1, word2>>
    // word3 : <<word1, word3>>
    map<string, set<set<string>>> dic;

//    Add("program", "code", dic);
//    Count("cipher", dic);
//    Add("code", "cipher", dic);
//    Count("code", dic);
//    Count("program", dic);
//    Check("code", "program", dic);
//    Check("program", "cipher", dic);
//    Check("cpp", "java", dic);

    //PrintVector(dic);

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        string command;
        cin >> command;

        if(command == "ADD") {
            string word1, word2;
            cin >> word1 >> word2;

            Add(word1, word2, dic);
        }

        if (command == "COUNT") {
            string word;
            cin >> word;
            Count(word, dic);
        }

        if (command == "CHECK") {
            string word1, word2;
            cin >> word1 >> word2;

            Check(word1, word2, dic);
        }

    }



   return 0;
}
