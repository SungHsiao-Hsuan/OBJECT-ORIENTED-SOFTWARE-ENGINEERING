# include "bus.h"

Bus::Bus (int bus_number, int interval, int capacity): bus_number(bus_number), interval(interval),capacity(capacity) {};

void Bus::search_passengers() {
    cout << "Bus number: " << bus_number << endl;

    for (auto passenger: passengers) {
        cout << passenger << endl;
    }
}

bool Bus::search_capacity() {
    return (capacity > 0);
}

void Bus::add_passenger(string name){
    passengers.insert(name);
}

void Bus::remove_passenger(string name) {
    passengers.erase (name);
}

int Bus::get_interval() {
    return interval;
}

int Bus::get_bus_number() {
    return bus_number;
}

void Bus::set_bus_number(int bus_number) {
    bus_number = bus_number;
}

void Bus::set_interval(int interval) {
    interval = interval;
}

void Bus::set_capacity(int capacity) {
    capacity = capacity;
}

bool Bus::operator<(const Bus& other) const {

        if (interval != other.interval) {
            return interval < other.interval;
        }

        return bus_number < other.bus_number;
    }

int Bus::get_passengers_number() {
    return passengers.size();
}

Bus::~Bus() {

}

