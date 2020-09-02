// имена и фамилии

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        // добавить факт изменения имени на first_name в год year
        name[year] = first_name;
    }

    void ChangeLastName(int year, const string& last_name) {
        // добавить факт изменения фамилии на last_name в год year
        surname[year] = last_name;
    }

    string GetFullName(int year) {
        // получить имя и фамилию по состоянию на конец года year
        string result;
        string res_name;
        string res_surname;
        bool is_name_presented = false;
        bool is_surname_presented = false;
        cout << "names size: " << name.size() << endl;
        if (!name.size() == 0) {
            if (!name[year].empty()) {
                is_name_presented = true;
                res_name = name[year];
            } else {
                bool is_value_found = false;
                for (auto [key, value] : name) {
                    if (key == year) {
                        break;
                    }

                    if (!value.empty()) {
                        res_name = value;
                        is_value_found = true;
                    }

                    if (is_value_found) {
                        is_name_presented = true;
                    }

                }
                cout << "names size: " << name.size() << endl;
            }

        }

        if (!surname.size() == 0) {
            if (!surname[year].empty()) {
                is_surname_presented = true;
                res_surname = surname[year];
            } else {
                bool is_value_found = false;
                for (auto [key, value] : surname) {
                    if (key == year) {
                        break;
                    }

                    if (!value.empty()) {
                        res_surname = value;
                        is_value_found = true;
                    }

                    if (is_value_found) {
                        is_surname_presented = true;
                    }
                }
            }

        }

        if (is_name_presented == true) {
            if (is_surname_presented == true) {
                return res_name + " " + res_surname;
            } else {
                return res_name + " with unknown last name";
            }
        } else {
            if (is_surname_presented == true) {
                return res_surname + " with unknown first name";
            } else {
                return "Incognito";
            }
        }
    }

private:
    map <int, string> name;
    map <int, string> surname;

};



int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout  << year << " " << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout  << year << " " << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout  << year << " " << person.GetFullName(year) << endl;
    }

    cout << "=============================================\n\n";
    person.ChangeLastName(1890, "Sidorov");
    person.ChangeFirstName(1900, "Solnishko");
    for (int year : {1889, 1890, 1941, 1965, 1967, 1969, 1970, 1991}) {
        cout  << year << " " << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1990, "Vasya");
    cout << "=============================================\n\n";
    person.ChangeLastName(1900, "Lesnoe");
    for (int year : {1941, 1965, 1967, 1969, 1970, 1990}) {
        cout  << year << " " << person.GetFullName(year) << endl;
    }

//    //case 1
//    person.ChangeLastName(3, "3_2nd");
//    person.ChangeLastName(6, "6_2nd");
//
//    for (int year : {3, 4, 5, 6}) {
//        cout  << year << " " << person.GetFullName(year) << endl;
//    }
//
//    cout << "Error here" << endl;
//
//    person.ChangeFirstName(-1, "-1_1st");
//    person.ChangeFirstName(2, "2_1st");
//
//    for (int year : {-1, 0, 1, 2, 3, 6}) {
//        cout  << year << " " << person.GetFullName(year) << endl;
//    }
//
//    //case 2
//    person.ChangeLastName (1, "1_second");
//    person.ChangeFirstName(0, "0_first");
//    person.ChangeFirstName(1, "1_first");
//    person.ChangeFirstName(0, "3_first");
//
//    cout << person.GetFullName(0) << endl;
//    cout << person.GetFullName(1)<< endl;
//    cout << person.GetFullName(2)<< endl;
//    cout << person.GetFullName(0) << endl;
//
//    //3 case
//    cout << person.GetFullName(2000) << endl;
//
//    person.ChangeLastName(1968, "1968_2nd");
//    person.ChangeLastName(1967, "1967_2nd");
//    person.ChangeLastName(1965, "1965_2nd");
//    person.ChangeLastName(1966, "1966_2nd");
//
//    for (int year : {1900, 1920, 1950, 1965, 1966, 1967, 1968}) {
//        cout  << year << " " << person.GetFullName(year) << endl;
//    }
//
//    person.ChangeFirstName(1920, "1920_1st");
//    person.ChangeFirstName(1900, "1900_1st");
//    person.ChangeFirstName(1965, "1965_1st");
//    person.ChangeFirstName(1950, "1950_1st");
//
//    for (int year : {1900, 1920, 1950, 1965, 1966, 1967, 1968}) {
//        cout  << year << " " << person.GetFullName(year) << endl;
//    }

    return 0;
}
