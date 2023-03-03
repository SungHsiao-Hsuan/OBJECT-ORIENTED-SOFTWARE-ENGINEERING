
# include "passenger.h"

void menu();

int main() {

    map<int,set<Bus>>all_bus;
    set<Passenger>all_passenger;

    // add bus schedule
    Bus number1(1,0,30);
    Bus number2(2,1,30);

    // add passengers
    Passenger Maomao("Maomao","0932",'F',"abc street");
    Passenger Cassia("Cassia","0927",'F',"cde street");
    Passenger Roy("Roy","0776",'M',"fgh street");
    Passenger Ike("Ike","0922",'M',"ijk street");
    Passenger Kamui("Kamui","0996",'F',"if street");

    // Book ticket
    Maomao.book_ticket(number1);
    Cassia.book_ticket(number1);
    Kamui.book_ticket(number1);
    Roy.book_ticket(number2);
    Ike.book_ticket(number2);
    Maomao.book_ticket(number2);

    all_bus[number1.get_interval()].insert(number1);
    all_bus[number2.get_interval()].insert(number2);

    all_passenger.insert(Maomao);
    all_passenger.insert(Cassia);
    all_passenger.insert(Roy);
    all_passenger.insert(Ike);
    all_passenger.insert(Kamui);


    menu();

    char choice;
    while (cin >> choice) {
        choice = tolower(choice);
        if (choice == 'q') break;
        else if (choice == 'm') {
            cout << "Morning bus: " << endl;
            for (auto morning_bus: all_bus.at(0)) {
                morning_bus.search_passengers();
                cout << "==================================================================================" << endl;
            }

        }else if (choice == 'a') {
            cout << "Afternoon bus: " << endl;
            for (auto afternoon_bus: all_bus.at(1)) {
                afternoon_bus.search_passengers();
                cout << "==================================================================================" << endl;
            }

        }else if (choice == 's') {
            string passenger_name;
            cout << "Please enter the name of a passenger." << endl;
            int find = 0;
            cin >> passenger_name;
            for (auto passenger:all_passenger) {
                if (passenger.get_name() == passenger_name) {
                    passenger.search_ordered_ticker();
                    find = 1;
                    break;
                }
            }

            if (!find) {
                cout << "This passenger has not booked a ticket." << endl;
            }

        }else if (choice == 'c') {
            cout << "The passenger who booked the morning and afternoon bus tickets: ";
            for (auto passenger:all_passenger) {
                bool book_morning_and_afternoon_tickets = passenger.book_morning_and_afternoon();
                if (book_morning_and_afternoon_tickets) {
                    cout << passenger.get_name() << " ";
                }
            }

            cout << endl;
        }

        menu();
    }

}

void menu() {

    cout << "==================================================================================" << endl;
    cout << "M: Search the passenger who book the morning bus ticket?" << endl;
    cout << "A: Search the passenger who book the afternoon bus ticker?" << endl;
    cout << "S: Enter the passenger name to check which tickets have been booked by the passenger." << endl;
    cout << "C: Search for the passenger who booked the morning and afternoon bus tickets." << endl;
    cout << "Q: Quit the system." << endl;
    cout << "==================================================================================" << endl;

}