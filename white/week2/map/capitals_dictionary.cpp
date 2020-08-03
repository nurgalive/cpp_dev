// справочник столиц

#include <iostream>
#include <string>
#include <map>

using namespace std;


// method to add new country and its capital or change capital of the country
void ChangeCapital(map<string,string>& m, const string& country, const string& new_capital) {
    bool is_country_exist = false;
    bool is_capital_same = false;
    for (auto [key, value] : m) {
        // is the country already exists in map?
        if (key == country) {
            is_country_exist = true;
            // is the capital already same in the map?
            if (value == new_capital) {
                is_capital_same = true;
            }
        }
    }

    // if there is no country
    if (!is_country_exist) {
        m[country] = new_capital;
        cout << "Introduce new country " << country << " with capital " << new_capital << endl;
    }

    if (is_country_exist && is_capital_same) {
        cout << "Country " << country << " hasn't changed its capital" << endl;
    }

    if (is_country_exist && !is_capital_same) {
        string old_capital = m[country];
        m[country] = new_capital;

        cout << "Country " << country << " has changed its capital from " << old_capital
        << " to " << new_capital << endl;
    }
}

// method to rename countries
void RenameCountry(map<string, string>& m, const string& old_country_name, const string& new_country_name) {
    if (old_country_name == new_country_name) {
        cout << "Incorrect rename, skip" << endl;
    } else {
        bool is_country_exist = false;
        bool is_new_country_already_exist = false;

        if (m.count(new_country_name) == 1) {
            is_new_country_already_exist = true;
            cout << "Incorrect rename, skip" << endl;
        } else if (m.count(old_country_name) == 1 && is_new_country_already_exist == false) {
            is_country_exist = true;
            string temp_capital = m[old_country_name];
            //cout << "Size map: " << m.size() << endl;
            m.erase(old_country_name);
            //cout << "Size map: " << m.size() << endl;
            m[new_country_name] = temp_capital;
            //cout << "Size map: " << m.size() << endl;

            cout << "Country " << old_country_name << " with capital " << temp_capital
                 << " has been renamed to " << new_country_name << endl;
        } else {
            cout << "Incorrect rename, skip" << endl;
        }

    }
}

// prints countries capital name
void AboutCountry(const map<string, string>& m, const string& country_name) {
    bool is_country_exists = false;
    string capital_name;
    for (auto [key, value] : m){
        if (key == country_name) {
            capital_name = value;
            is_country_exists = true;
            break;
        }
    }

    if (is_country_exists) {
        cout << "Country " << country_name << " has capital " << capital_name << endl;
    } else {
        cout << "Country " << country_name << " doesn't exist" << endl;
    }
}

void Dump(const map<string, string>& m) {
    if (m.empty()) {
        cout << "There are no countries in the world" << endl;
    } else {
        for (auto [key, value] : m) {
            cout << key << "/" << value << endl;
        }
    }
}

int main() {
    // key: country
    // value: capital
    map<string, string> capitals;
    //input number of lines
    int Q;
    cin >> Q;

    string query, country, capital, old_capital, new_capital;

    for (int i = 0; i < Q; i++) {
        cin >> query;

        if (query == "CHANGE_CAPITAL") {
            cin >> country >> capital;
            ChangeCapital(capitals, country, capital);
        }

        if (query == "RENAME") {
            cin >> old_capital >> new_capital;
            RenameCountry(capitals, old_capital, new_capital);
        }

        if (query == "ABOUT") {
            cin >> country;
            AboutCountry(capitals, country);
        }

        if (query == "DUMP") {
            Dump(capitals);
        }
    }

//    string str;
//    getline(cin, str);


//    string ussr = "USSR";
//    string russia = "Russia";
//    string moscow = "Moscow";
//    string petersburg = "Petersburg";
//
//    AboutCountry(capitals, ussr);
//    cout << "add country" << endl;
//    Dump(capitals);
//    ChangeCapital(capitals, ussr, moscow);
//    Dump(capitals);
//    ChangeCapital(capitals, russia, petersburg);
//    Dump(capitals);
    //AboutCountry(capitals,ussr);

//    cout << "country does not exist" << endl;
//    RenameCountry(capitals, ussr, russia);
//
//

//
//    cout << "rename country" << endl;
//    RenameCountry(capitals, ussr, russia);
//
//    cout << "new country name already exists" << endl;
//    RenameCountry(capitals, ussr, russia);
//    cout << "New country name and old country name are same" << endl;
//    RenameCountry(capitals, russia, russia);

//    ChangeCapital(capitals, country1, capital1);
//    ChangeCapital(capitals, country1, capital1);
//    ChangeCapital(capitals, country1, capital2);





   return 0;
}
