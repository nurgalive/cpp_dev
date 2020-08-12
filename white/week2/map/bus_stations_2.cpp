// Автобусные остановки - 2

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

void PrintVector(vector<string> v) {
    for (auto val : v) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    //key stores bus stops
    //value stores bus number
    map<vector<string>, int> bus_number;
    int bus_count = 1;

    //input number of lines
    int Q;
    cin >> Q;

    string query, stop;
    int stop_count;



    for (int i = 0; i < Q; i++) {
        vector<string> input_stops;
        bool is_stops_unique = true;
        int already_exist_bus_number;
        cin >> stop_count;
        //PrintVector(input_stops);

        // form an input vector of stops
        for (int i = 0; i < stop_count; i++) {
            cin >> stop;
            input_stops.push_back(stop);
        }

        // if initial map with bus number empty - create first bus number
        if (bus_number.empty()) {
            bus_number[input_stops] = bus_count;
            cout << "New bus " << bus_count << endl;
            bus_count++;
        } else {
            for (auto [key, value] : bus_number) {
                if(key == input_stops) {
                    is_stops_unique = false;
                    already_exist_bus_number = value;
                }
            }

            if (is_stops_unique) {
                bus_number[input_stops] = bus_count;
                cout << "New bus " << bus_count << endl;
                bus_count++;
            } else  {
                cout << "Already exists for " << already_exist_bus_number << endl;
            }




        }



    }




   return 0;
}
