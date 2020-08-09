// Автобусные остановки - 1

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

bool CheckBusStopIncluded(string& stop, const vector<string>& vec) {
    bool is_stop_exists = false;
    for (auto v : vec) {
        if (v == stop) {
            is_stop_exists = true;
        }
    }
    return is_stop_exists;
}

int main() {
    // key: bus
    // value: vector of stops
    map<string, vector<string>> buses;
    // вектор для хранения порядка добавления автобусов
    vector<string> bus_order;
    
    /*
     * Все данные хранятся в словаре, а итерация происходит через вектор, в котором хранится порядок добавления.
     * Когда берётся значение из вектора, потом берётся это значение из словаря и оттуда же берутся остановки
     */
    
    //input number of lines
    int Q;
    cin >> Q;

    string query, bus, stop;
    int stop_count;



    for (int i = 0; i < Q; i++) {

        cin >> query;

        if (query == "NEW_BUS") {
            cin >> bus >> stop_count;
            bus_order.push_back(bus);

            for (int i = 0; i < stop_count; i++) {
                cin >> stop;
                buses[bus].push_back(stop);
            }

        }

        if (query == "BUSES_FOR_STOP") {
            cin >> stop;
            bool is_stop_exist = false;

            for (auto [key, value] : buses) {
                for (auto v : value) {
                    if (v == stop) {
                        is_stop_exist = true;
                    }
                }
            }

            if (!is_stop_exist) {
                cout << "No stop" << endl;
            } else {
                for (auto b : bus_order) {
                    auto stops_from_bus = buses[b];
                    for (auto v : stops_from_bus) {
                        if (v == stop) {
                            cout << b << " ";
                        }
                    }
                }
                cout << endl;
            }

        }

        if (query == "STOPS_FOR_BUS") {
            cin >> bus;

            if (buses.count(bus) == 0) {
                cout << "No bus" << endl;
            } else {
                auto stops_of_bus = buses[bus];
                //cout << "Searching interchanges for bus: "  << bus << endl;
                // получили итератор по остановкам нужного автобуса
                for (auto v : stops_of_bus) {
                    string output = "Stop " + v + ": ";
                    bool is_there_interchange = false;
                    // итерируем по вектору автобусом, чтобы найти пересечение и сохранить порядок. А остановки
                    // добываются из словаря
                    for (auto b : bus_order) {
                        // пропускаем, если ключ такой как в автобусе, в котором мы ищем
                        if (b == bus) {
                            continue;
                        }
                        auto stops_from_bus = buses[b];
                        //cout <<"Check stops in bus: " << key2 << endl;
                        // Проверяем, есть ли такая остановка у автобуса
                        if (CheckBusStopIncluded(v, stops_from_bus)){
                            output = output + b + " ";
                            is_there_interchange = true;
                        }


                    }
                    if (is_there_interchange) {
                        cout << output << endl;
                    } else {
                        output = output +  "no interchange";
                        cout << output << endl;
                    }

                }
                //cout << "---------" << endl;



                }

            }

        if (query == "ALL_BUSES") {
            if (buses.empty()) {
                cout << "No buses" << endl;
            } else {
                for (auto [key, value] : buses) {
                    cout << "Bus " << key <<": ";
                    for (auto v : value) {
                        cout << v << " ";
                    }
                    cout << endl;
                }
            }

        }


    }




   return 0;
}
