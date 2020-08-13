// ежемесячные дела

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 *
пример ввода
12
ADD 5 Salary
ADD 31 Walk
ADD 30 WalkPreparations
NEXT
DUMP 5
DUMP 28
NEXT
DUMP 31
DUMP 30
DUMP 28
ADD 28 Payment
DUMP 28
 */

void Add(vector<string>& v, string delo, int day) {
    v[day] = delo;
}

void Dump(vector<string>& v, int day) {
    for (string s : v) {
        cout << s << " ";
    }
}

void Next(vector<string>& v, int i) {
    vector.
}



void WorryCount(const vector<string>& v) {
    int worry_count = 0;
    for (string s : v) {
        if (s == "WORRY") {
            worry_count++;
        }
    }
    cout << worry_count << endl;
}

int main() {
    // Сначала число операций Q, затем описания операций.
    int Q;
    cin >> Q;

    vector<string> line;

    string command;
    int que;

    for (int j = 0; j < Q; j++) {
        cin >> command;
        if (command == "COME") {
            cin >> que;
            Come(line, que);
        } else if (command == "WORRY") {
            cin >> que;
            Worry(line, que);
        } else if (command == "QUIET") {
            cin >> que;
            Quiet(line, que);
        } else {
            WorryCount(line);
        }
    }

}
