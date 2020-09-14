// Имена и фамилии - 2

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string &first_name) {
        // добавить факт изменения имени на first_name в год year
        name[year] = first_name;
    }

    void ChangeLastName(int year, const string &last_name) {
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
        //cout << "names size: " << name.size() << endl;
        if (name.size() != 0) {
            if (!name[year].empty()) {
                is_name_presented = true;
                res_name = name[year];
            } else {
                bool is_value_found = false;
                for (auto[key, value] : name) {
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
                //cout << "names size: " << name.size() << endl;
            }

        }

        if (surname.size() != 0) {
            if (!surname[year].empty()) {
                is_surname_presented = true;
                res_surname = surname[year];
            } else {
                bool is_value_found = false;
                for (auto[key, value] : surname) {
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


// ==============================================================================================

    string GetFullNameWithHistory(int year) {
        // создание векторов с данными для вывода
        string previous_name;
        string previous_surname;
        vector<string> names_vec;
        vector<string> surnames_vec;

        for (auto [key, value] : name) {
            if (value == previous_name) {
                continue;
            }

            if (key > year) {
                break;
            }
            //cout << "Added name: " + value << endl;
            if (value.empty()) {
                continue;
            }
            names_vec.push_back(value);
            previous_name = value;
        }

        for (auto [key, value] : surname) {
            if (value == previous_surname) {
                continue;
            }

            if (key > year) {
                break;
            }

            if (value.empty()) {
                continue;
            }
            //cout << "Added surname: " + value << endl;
            surnames_vec.push_back(value);
            previous_surname = value;
        }

// ==========================================================
        // printing
        if (names_vec.empty()) {
            if (surnames_vec.empty()) {
                // both vectors empty
                return "Incognito";
            } else {
                // names empty and surnames not empty
                if (surnames_vec.size() == 1) {
                    return surnames_vec[0] + " with unknown first name";
                }
                if (surnames_vec.size() == 2) {
                    return surnames_vec[1] + " (" + surnames_vec[0] + ") with unknown first name";
                } else {
                    string res = surnames_vec[surnames_vec.size()-1] + " (" + surnames_vec[surnames_vec.size()-2] + ", ";
                    for (int i = surnames_vec.size()-3; i >= 0; i--) {
                        res += surnames_vec[i];
                        if (i != 0) {
                            res = res + ", ";
                        } else {
                            res = res + ") with unknown first name";
                        }
                    }
                    return res;
                }
            }
        } else {
            if (surnames_vec.empty()) {
                if (names_vec.size() == 1) {
                    return names_vec[0] + " with unknown last name";
                }
                if (names_vec.size() == 2) {
                    return names_vec[1] + " (" + names_vec[0] + ") with unknown last name";
                } else {
                    string res = names_vec[names_vec.size() - 1] + " (" + names_vec[names_vec.size() - 2] + ", ";
                    for (int i = names_vec.size() - 3; i >= 0; i--) {
                        res += names_vec[i];
                        if (i != 0) {
                            res = res + ", ";
                        } else {
                            res = res + ") with unknown last name";
                        }
                    }
                    return res;
                }
            } else {
                // most hardest point
                string res;

                // names
                if (names_vec.size() == 1) {
                    res += names_vec[0] + " ";
                } else if (names_vec.size() == 2) {
                    res += names_vec[1] + " (" + names_vec[0] + ") ";
                } else {
                    res += names_vec[names_vec.size() - 1] + " (" + names_vec[names_vec.size() - 2] + ", ";
                    for (int i = names_vec.size() - 3; i >= 0; i--) {
                        res += names_vec[i];
                        if (i != 0) {
                            res += ", ";
                        }

                        if (i == 0) {
                            res += ") ";
                        }
                    }
                }


                // surnames
                if (surnames_vec.size() == 1) {
                    res += surnames_vec[0];
                } else if (surnames_vec.size() == 2) {
                    res += surnames_vec[1] + " (" + surnames_vec[0] + ")";
                } else {
                    res += surnames_vec[surnames_vec.size() - 1] + " (" + surnames_vec[surnames_vec.size() - 2] + ", ";
                    for (int i = surnames_vec.size() - 3; i >= 0; i--) {
                        res += surnames_vec[i];
                        if (i != 0) {
                            res += ", ";
                        }

                        if (i == 0) {
                            res += ")";
                        }
                    }
                }

                return res;

            }
        }
    }



private:
    map <int, string> name;
    map <int, string> surname;

};




int main() {
    Person person;

    // стандартные тесты

    cout << "Standard test" << endl;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;

    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;

    cout << endl;
    cout << endl;

    // дополнительные тесты

    // тест 1

    cout << "Test 1" << endl;

    int year = -1;
    person.ChangeFirstName(year, std::to_string(year)+"_first");
    person.ChangeLastName(year, std::to_string(year)+"_last");
    std::cout << "year: " << year << '\n';
    std::cout << person.GetFullNameWithHistory(year) << '\n';

    year = 0;
    person.ChangeFirstName(year, std::to_string(year)+"_first");
    person.ChangeLastName(year, std::to_string(year)+"_last");
    std::cout << "year: " << year << '\n';
    std::cout << person.GetFullNameWithHistory(year) << '\n';

    year = 1;
    person.ChangeFirstName(year, std::to_string(2)+"_first");
    person.ChangeLastName(year, std::to_string(2)+"_last");
    std::cout << "year: " << year << '\n';
    std::cout << person.GetFullNameWithHistory(year) << '\n';

    year = 0;
    std::cout << "year: " << year << '\n';
    std::cout << person.GetFullNameWithHistory(year) << '\n';

    cout << endl;
    cout << endl;

    // Test 2

    cout << "Test 2" << endl;
    person.ChangeFirstName(1, "1_first");
    person.ChangeLastName(1, "1_last");
    person.ChangeFirstName(3, "3_first");
    person.ChangeLastName(5, "5_last");
    person.ChangeFirstName(4, "3_first");
    person.ChangeLastName(6, "5_last");

    cout << person.GetFullName(7) << endl;
    cout << person.GetFullNameWithHistory(7) << endl;

    cout << endl;
    cout << endl;


    // Test 3
    cout << "Test 3" << endl;
    year = -1;
    person.ChangeFirstName(year, "");
    person.ChangeLastName(year, "");
    std::cout << "year: " << year << '\n';
    std::cout << person.GetFullNameWithHistory(year) << '\n';

    year = 0;
    person.ChangeFirstName(year, std::to_string(year)+"_first");
    person.ChangeLastName(year, std::to_string(year)+"_last");
    std::cout << "year: " << year << '\n';
    std::cout << person.GetFullNameWithHistory(year) << '\n';

    year = 1;
    person.ChangeFirstName(year, std::to_string(2)+"_first");
    person.ChangeLastName(year, std::to_string(2)+"_last");
    std::cout << "year: " << year << '\n';
    std::cout << person.GetFullNameWithHistory(year) << '\n';

    year = 0;
    std::cout << "year: " << year << '\n';
    std::cout << person.GetFullNameWithHistory(year) << '\n';

    year = 1;
    person.ChangeFirstName(year, std::to_string(year)+"_first");
    person.ChangeLastName(year, std::to_string(year)+"_last");
    std::cout << "year: " << year << '\n';
    std::cout << person.GetFullNameWithHistory(year) << '\n';

    year = 2;
    person.ChangeFirstName(year, std::to_string(year)+"_first");
    person.ChangeLastName(year, std::to_string(year)+"_last");
    std::cout << "year: " << year << '\n';
    std::cout << person.GetFullNameWithHistory(year) << '\n';

    year = 3;
    person.ChangeFirstName(year, std::to_string(2)+"_first");
    person.ChangeLastName(year, std::to_string(2)+"_last");
    std::cout << "year: " << year << '\n';
    std::cout << person.GetFullNameWithHistory(year) << '\n';

    year = 2;
    std::cout << "year: " << year << '\n';
    std::cout << person.GetFullNameWithHistory(year) << '\n';

    cout << endl;
    cout << endl;


    //Test 4

    cout << "Test 5" << endl;
    person.ChangeLastName (1, "1_second");
    person.ChangeFirstName(0, "0_first");
    person.ChangeFirstName(1, "1_first");
    person.ChangeFirstName(0, "3_first");

    cout << person.GetFullNameWithHistory(0) << endl;
    cout << person.GetFullNameWithHistory(1)<< endl;
    cout << person.GetFullNameWithHistory(2)<< endl;
    cout << person.GetFullNameWithHistory(0) << endl;

    cout << endl;
    cout << endl;

//    //Test 6
//
//    cout << "Test 6" << endl;
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
