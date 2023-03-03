# include "passenger.h"

Passenger::Passenger(string name, string tel, char sex, string address): name(name), tel(tel), sex(sex), address(address) {};

void Passenger::book_ticket(Bus &bus) {

    int bus_interval_index = bus.get_interval();
    int bus_number = bus.get_bus_number();

    if (ordered_tickets[bus_interval_index].count(bus_number)) {
        cout << "You have ordered a ticket of bus number " << bus_number << endl;
    }
    else {

        if (bus.search_capacity()) {
            ordered_tickets[bus_interval_index].insert(bus_number);
            bus.add_passenger(name);
            cout << "Book the ticket successfully!" << endl;

        }else {
            cout << "The service is sold out." << endl;
        }

    }

}

void Passenger::cancel_ticket(Bus &bus) {

    int bus_interval_index = bus.get_interval();
    int bus_number = bus.get_bus_number();

    if (ordered_tickets[bus_interval_index].count(bus_number)) {
        ordered_tickets[bus_interval_index].erase(bus_number);
        bus.remove_passenger(name);
        cout << "Cancel the ticket successfully!" << endl;

    }else {
        cout << "You don't have ordered a ticket of bus number " << bus_number << endl;
    }

}

void Passenger::search_ordered_ticker()const {

    int ticket_count = 0;
    cout << name << " ordered ticket: " << endl;
    cout << "morning bus: ";
    for (auto ticket: ordered_tickets.at(0)) {
        cout << ticket << " ";
        ticket_count ++;
    }

    cout << endl;

    cout << "afternoon bus: ";
    for (auto ticket: ordered_tickets.at(1)) {
        cout << ticket << " ";
        ticket_count ++;

    }

    cout << endl;
    cout << "Total number of ordered tickets: " << ticket_count << endl;
}

bool Passenger::book_morning_and_afternoon()const {
    return  (ordered_tickets.at(0).size() > 0 && ordered_tickets.at(1).size() > 0);
}

void Passenger::set_name(string new_name) {
    name = new_name;
}
void Passenger::set_tel(string new_tel) {
    tel = new_tel;
}
void Passenger::set_address(string new_address){
    address = new_address;
}

string Passenger::get_name()const{
    return name;
}

string Passenger::get_tel()const{
    return tel;
}

char Passenger::get_sex()const{
    return sex;
}

string Passenger::get_address()const{
    return address;
}

bool Passenger::operator<(const Passenger& other) const {
    return name < other.name;
}

Passenger::~Passenger() {

}


