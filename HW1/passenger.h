# ifndef PASSENGER_H
# define PASSENGER_H

# include "bus.h"

class Passenger {
private:
    string name;
    string tel;
    char sex;
    string address;
    map<int,set<int>> ordered_tickets = {{0, {}}, {1, {}}};

public:

    Passenger(string,string,char,string);
    void book_ticket(Bus &bus);
    void cancel_ticket(Bus &bus);
    void search_ordered_ticker() const;
    void set_name(string new_name);
    void set_tel(string new_tel);
    void set_address(string new_address);
    string get_name()const;
    string get_tel()const;
    char get_sex()const;
    string get_address()const;
    bool operator<(const Passenger& other) const;
    bool book_morning_and_afternoon()const;
    ~Passenger();

};

# endif