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

void PrintMonth(int month){
    cout << "========== Month: " << month+1 << " ==========" << endl;
}

void PrintVector(const vector<vector<string>>& input_vector) {
    int iterator = 1;
    for (auto vec : input_vector) {
        cout << "Day " << iterator << ": ";

        for (auto v : vec) {
            cout << v << " ";
        }
        cout << endl;
        iterator++;
    }

}

void PrintSimpleVector(const vector<string> input) {
    for (auto v : input) {
        cout << v << " ";
    }
    cout << endl;
}

void Add(vector<vector<string>>& v, const string& delo, const int& day) {
    v[day].push_back(delo);
}

void Dump(vector<vector<string>>& input_vector, const int& day) {
     vector<string> day_tasks = input_vector[day];
     cout << day_tasks.size() << " ";
    for (string s : day_tasks) {
        cout << s << " ";
    }
    cout << endl;
}

void Next(vector<vector<string>>& todos, int& current_month) {
    vector<int> days_in_months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    current_month++;
    if (current_month == 12) {
        current_month = 0;
    }


    if (days_in_months[current_month] > todos.size()) {
        todos.resize(days_in_months[current_month]);
    } else if (days_in_months[current_month] < todos.size()) {
        int diff = todos.size() - days_in_months[current_month];
        int pointer = todos.size() - 1;
        vector<string> temp;

        for (int i = 0; i < diff; i++) {
            for (auto val : todos[pointer]) {
                temp.push_back(val);
            }
            pointer--;
        }

        todos.resize(days_in_months[current_month]);

        for (auto t : temp) {
            todos.back().push_back(t);
        }
        //PrintSimpleVector(todos.back());

    }

}


int main() {
    int current_month = 0;

    vector<vector<string>> todos(31);

//    PrintMonth(current_month);
//    Add(todos, "Salary", 4);
//    Add(todos, "Walk", 30);
//    Add(todos, "WalkPreparations", 29);
//
//    PrintVector(todos);
//    Next(todos,current_month);
//    PrintVector(todos);
//
//    PrintMonth(current_month);
//
//    Dump(todos, 4);
//    Dump(todos, 27);
//
//    Next(todos, current_month);
//    PrintMonth(current_month);
//    Dump(todos,30);
//    Dump(todos,29);
//    Dump(todos,27);
//    Add(todos, "Payment", 27);
//    Dump(todos, 27);
//    Next(todos, current_month);
//    PrintMonth(current_month);
//    PrintVector(todos);
//    Next(todos, current_month);
//    PrintMonth(current_month);
//    PrintVector(todos);
//    Next(todos, current_month);
//    PrintVector(todos);
//    Next(todos, current_month);
//    PrintMonth(current_month);
//    PrintVector(todos);
//    Next(todos, current_month);
//    PrintMonth(current_month);
//    PrintVector(todos);
//    Next(todos, current_month);
//    PrintVector(todos);
//    Next(todos, current_month);
//    PrintMonth(current_month);
//    PrintVector(todos);
//    Next(todos, current_month);
//    PrintMonth(current_month);
//    PrintVector(todos);
//    Next(todos, current_month);
//    PrintMonth(current_month);
//    PrintVector(todos);
//    Next(todos, current_month);
//    PrintMonth(current_month);
//    PrintVector(todos);
//    Next(todos, current_month);
//    PrintMonth(current_month);
//    PrintVector(todos);
//    Next(todos, current_month);
//    PrintMonth(current_month);
//    PrintVector(todos);
//    Next(todos, current_month);
//    PrintMonth(current_month);
//    PrintVector(todos);
//    Next(todos, current_month);
//    PrintMonth(current_month);
//    PrintVector(todos);
//    Next(todos, current_month);
//    PrintMonth(current_month);
//    PrintVector(todos);
//    Next(todos, current_month);
//    PrintMonth(current_month);
//    PrintVector(todos);
//    Next(todos, current_month);
//    PrintMonth(current_month);
//    PrintVector(todos);
//    Next(todos, current_month);
//    PrintMonth(current_month);
//    PrintVector(todos);
//    Next(todos, current_month);
//    PrintMonth(current_month);
//    PrintVector(todos);
//    Next(todos, current_month);
//    PrintMonth(current_month);
//    PrintVector(todos);
//    Next(todos, current_month);
//    PrintMonth(current_month);
//    PrintVector(todos);

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        string operation;
        cin >> operation;

        if (operation == "ADD") {
            int day;
            string todo;
            cin >> day;
            cin >> todo;

            Add(todos, todo, day-1);
        }

        if (operation == "NEXT") {
            Next(todos,current_month);
        }

        if (operation == "DUMP") {
            int day;
            cin >> day;

            Dump(todos, day-1);
        }

    }

}
