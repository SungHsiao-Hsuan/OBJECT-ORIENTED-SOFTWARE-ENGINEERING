# ifndef BUS_H
# define BUS_H

# include <iostream>
# include <string>
# include <set>
# include <map>

using namespace std;

class Bus {
private:
    int bus_number;
    int interval;
    int capacity;
    set<string> passengers;

public:

    Bus(int, int, int);
    void search_passengers();
    bool search_capacity();
    void add_passenger(string name);
    void remove_passenger(string name);
    int get_interval();
    int get_bus_number();
    void set_bus_number(int bus_number);
    void set_interval(int interval);
    void set_capacity(int capacity);
    bool operator<(const Bus &other) const;
    int get_passengers_number();
    ~Bus();

};


# endif