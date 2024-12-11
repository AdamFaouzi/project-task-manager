#include <iostream> //import the input output operations for C++
#include <vector>   //for dynamic array size
#include <algorithm>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;

class Time
{        // initialise the Time class
private: // outline the private attributes of the Time class
    int year;
    int month;
    int day;
    double time;

public: // outline the public functions of the Time class
    Time()
    {
    }
    Time(int y, int m, int d, double t)
    { // all arguments constructor function
        year = y;
        month = m;
        day = d;
        time = t;
    }
    // getters functions
    int getYear() { return year; }
    int getMonth() { return month; }
    int getDay() { return day; }
    int getTime() { return time; }
    // setters functions
    void setYear(int y) { year = y; }
    void setMonth(int m) { month = m; }
    void setDay(int d) { day = d; }
    void setTime(double t) { time = t; }

    friend ostream &operator<<(ostream &os, const Time &t)
    {
        os << t.month << "/" << t.day << "/" << t.year << " at: " << t.time << endl;
        return os;
    }
};

class Location
{        // initialise the Location class
private: // outline the private attributes of the Location class
    string country;
    string city;
    string street;
    int postal_code;

public: // outline the public functions of the Location class
    Location(string co, string c, string s, int pc)
    { // all arguments constructor function
        country = co;
        city = c;
        street = s;
        postal_code = pc;
    }
    // getters functions
    string getCountry() { return country; }
    string getCity() { return city; }
    string getStreet() { return street; }
    int getPostalCode() { return postal_code; }
    // setters functions
    void setCountry(string c) { country = c; }
    void setCity(string c) { city = c; }
    void setStreet(string s) { street = s; }
    void setPostalCode(int p) { postal_code = p; }

    friend ostream &operator<<(ostream &os, const Location &l)
    {
        os << l.country << " " << l.city << " " << l.street << " " << l.postal_code << endl;
        return os;
    }
};

class Task
{        // initialise Tasks class
private: // outline the private attributes of the Tasks class
    string title;
    vector<string> participants;
    Time start_time;
    Time end_time;
    Location location;
    bool send_emails;

public:
    Task(string t, Time st, Time et, Location l, bool se) : title(t), start_time(st), end_time(et), location(l), send_emails(se) {}

    void addParticipant(const string &participant)
    {
        // Add the participant to the 'participants' vector using push_back
        participants.push_back(participant);
        // 'push_back' adds an element to the end of the vector
        cout << participant << " has been added to the participants list.\n";
    }

    void removeParticipant(const string &participant)
    {
        // Use std::find from <algorithm> library to search for the participant in the vector
        auto it = find(participants.begin(), participants.end(), participant);
        /*
        // 'auto it' is a variable declaration where the type of 'it' is automatically deduced by the compiler.
        // 'auto' allows the compiler to determine the correct type based on the initialization expression.
        // In this case, 'it' will be of the type of iterator used by the 'find' function, which is an iterator for the vector<string>.
        // The 'find' function returns an iterator that points to the element found, or to the end of the vector if the element is not found.
        // This simplifies the code by not requiring you to manually specify the iterator type (i.e., 'std::vector<string>::iterator').
        */
        // Check if the participant was found
        if (it != participants.end())
        {
            // If found, erase the participant from the vector
            participants.erase(it);
            cout << participant << " has been removed from the participants list.\n";
        }
        else
        {
            // If the participant is not found, display a message
            cout << "Participant not found.\n";
        }
    }

    void displayParticipants()
    {
        cout << "Participants:\n";
        for (const string &participant : participants)
        {
            cout << "-" << participant << '\n';
        }
    }

    virtual void displayInformation()
    {
        cout << std::boolalpha;
        cout << title << " information: " << endl;
        cout << "Start time: " << start_time << "End time: " << end_time;
        cout << "Location: " << location;
        cout << "Send email: " << send_emails;
        displayParticipants();
    }

    string getTitle() { return title; }
    Time getStartTime() { return start_time; }
    Time getEndTime() { return end_time; }
    Location getLocation() { return location; }
    bool getSendEmail() { return send_emails; }

    void setTitle(string t) { title = t; }
    void setStartTime(const Time &st) { start_time = st; }
    void setEndTime(const Time &et) { end_time = et; }
    void setLocation(const Location &loc) { location = loc; }
    void setSendEmail(bool se) { send_emails = se; }
};

class Event : public Task
{
private:
    double funding;
    bool transportation;
    bool catering;

public:
    Event(string ti, Time st, Time et, Location l, bool se, double f, bool t, bool c) : Task(ti, st, et, l, se), funding(f), transportation(t), catering(c) {}

    double getFunding() { return funding; }
    bool getTransportation() { return transportation; }
    bool getCatering() { return catering; }

    void setFunding(double f) { funding = f; }
    void setTransportation(bool t) { transportation = t; }
    void setCatering(bool c) { catering = c; }

    void displayInformation() override
    {
        Task::displayInformation();
        cout << std::boolalpha;
        cout << "Funding: " << funding << endl;
        cout << "Transportation needed?: " << transportation << endl;
        cout << "Catering needed?: " << catering << endl;
    }
};

class ClubEvent : public Event
{
private:
    vector<string> representitives;
    vector<int> numbers;

public:
    ClubEvent(string ti, Time st, Time et, Location l, bool se, double f, bool t, bool c) : Event(ti, st, et, l, se, f, t, c) {}

    void addRep(const string &rep)
    {
        representitives.push_back(rep);
        cout << rep << " has been added to the representitives list.\n";
    }

    void removeRep(const string &rep)
    {
        auto it = find(representitives.begin(), representitives.end(), rep);
        if (it != representitives.end())
        {
            representitives.erase(it);
            cout << rep << " has been removed from the representitives list.\n";
        }
        else
        {
            cout << "Representitive not found.\n";
        }
    }

    void displayRepresentitives()
    {
        cout << "Representitives:\n";
        for (const string &rep : representitives)
        {
            cout << "-" << rep << '\n';
        }
    }

    void addNumber(const int &num)
    {
        numbers.push_back(num);
        cout << num << " has been added to the numbers list.\n";
    }

    void removeNumber(const int &num)
    {
        auto it = find(numbers.begin(), numbers.end(), num);
        if (it != numbers.end())
        {
            numbers.erase(it);
            cout << num << " has been removed from the numbers list.\n";
        }
        else
        {
            cout << "Number not found.\n";
        }
    }

    void displayNumbers()
    {
        cout << "Numbers:\n";
        for (const int &num : numbers)
        {
            cout << "-" << num << '\n';
        }
    }

    void displayInformation() override
    {
        Event::displayInformation();
        displayRepresentitives();
        displayNumbers();
    }
};

class Workshop : public Event
{
private:
    string instructor;
    int number;
    bool equipment;

public:
    Workshop(string ti, Time st, Time et, Location l, bool se, double f, bool t, bool c, string i, int n, bool e) : Event(ti, st, et, l, se, f, t, c), instructor(i), number(n), equipment(e) {}

    string getInstructor() const
    {
        return instructor;
    }

    void setInstructor(const string &instr)
    {
        instructor = instr;
    }

    int getNumber() const
    {
        return number;
    }

    void setNumber(int num)
    {
        number = num;
    }

    bool getEquipment() const
    {
        return equipment;
    }

    void setEquipment(bool equip)
    {
        equipment = equip;
    }

    void displayInformation() override
    {
        Event::displayInformation();
        cout << std::boolalpha;
        cout << "Instructor: " << instructor << endl;
        cout << "Instructor Number: " << number << endl;
        cout << "Equipment needed?: " << equipment << endl;
    }
};

class Meeting : public Task
{
private:
    string building;
    int room_number;

public:
    Meeting(string ti, Time st, Time et, Location l, bool se, string b, int rn) : Task(ti, st, et, l, se), building(b), room_number(rn) {}
    // getters
    string getBuilding() { return building; }
    int getRoomNumber() { return room_number; }

    // setters
    void setBuilding(string b) { building = b; }
    void setRoomNumber(int rn) { room_number = rn; }

    void displayInformation()
    { // general display
        Task::displayInformation();
        cout << "Building: " << building << endl;
        cout << "Room number: " << room_number << endl;
    }
};

class General : public Meeting
{
private:
    bool equip_needed;
    vector<string> equipment;

public:
    General(string ti, Time st, Time et, Location l, bool se, string b, int rn, bool en) : Meeting(ti, st, et, l, se, b, rn), equip_needed(en) {}

    // getter
    bool getEquipNeeded() { return equip_needed; }

    // setter
    void setEquipNeeded(bool en) { equip_needed = en; }

    void add_equip(const string &equipment_added)
    {
        if (equip_needed != false)
        {
            equipment.push_back(equipment_added);
            cout << equipment_added << "has been added to the list of equipments" << endl;
            for (auto i : equipment)
            {
                cout << "- " << i << endl;
            }
        }
        else
        {
            cout << "No equipment needed" << endl;
        }
    }

    void remove_equip(const string &equipment_removed)
    {
        auto equip_rem = find(equipment.begin(), equipment.end(), equipment_removed);
        if (equip_rem != equipment.end())
        {
            equipment.erase(equip_rem);
            cout << equipment_removed << "has been removed from the list of equipments" << endl;
            cout << "The updated list is of equipments is: ";
            for (auto j : equipment)
            {
                cout << "- " << j << endl;
            }
        }
        else
        {
            cout << equipment_removed << "doesn't exist in the list of equipments" << endl;
        }
    }

    void displayInformation()
    {
        cout << "General meeting information: " << endl;
        Meeting::displayInformation();
        cout << std::boolalpha;
        cout << "Equipment needed : " << equip_needed << endl;
        if (equip_needed != false)
        {
            cout << "Equipment needed: " << endl;
            for (auto i : equipment)
            {
                cout << "- " << i << endl;
            }
        }
    }
};
class oneOnOne : public Meeting
{
private:
    bool follow_up;

public:
    oneOnOne(string ti, Time st, Time et, Location l, bool se, string b, int rn, bool fu) : Meeting(ti, st, et, l, se, b, rn), follow_up(fu) {}

    // getter
    bool getFollowUp() { return follow_up; }

    // setter
    void setFollowUp(bool fr) { follow_up = fr; }

    void displayInformation()
    {
        cout << "One on one meeting details: " << endl;
        Meeting::displayInformation();
        cout << "Follow up required? " << follow_up << endl;
    }
};

int checkDay(int day)
{
    while (day < 1 || day > 31)
    {
        cout << "Invalid input, enter day: ";
        cin >> day;
    }
    return day;
}

int checkYear(int year)
{
    time_t currentTime = time(nullptr);

    // Convert to local time structure
    tm *localTime = localtime(&currentTime);

    // Extract the year
    int year_now = 1900 + localTime->tm_year;

    while (year < year_now)
    {
        cout << "Invalid year, cannot create task in the past, enter year: ";
        cin >> year;
    }
    return year;
}

int checkMonth(int month)
{
    while (month < 1 || month > 12)
    {
        cout << "Invalid input, enter month: ";
        cin >> month;
    }
    return month;
}

double checkTime(double time)
{
    while (time < 0)
    {
        cout << "Invalid input, enter time: ";
        cin >> time;
    }
    return time;
}

int findTask(vector<Task> &tasks, string &title)
{
    for (int i = 0; i < tasks.size(); i++)
    {
        if (tasks[i].getTitle() == title)
        {
            return i;
        }
    }
    return -1;
}

void findTask(vector<Task> &tasks, Time &time)
{
    for (int i = 0; i < tasks.size(); i++)
    {
        if (tasks[i].getStartTime().getYear() == time.getYear() && tasks[i].getStartTime().getMonth() == time.getMonth() && tasks[i].getStartTime().getDay() == time.getDay() && tasks[i].getStartTime().getTime() == time.getTime())
        {
            tasks[i].displayInformation();
            cout << endl;
        }
    }
}

void findTask(vector<Task> &tasks, Location &location)
{
    for (int i = 0; i < tasks.size(); i++)
    {
        if (tasks[i].getLocation().getCountry() == location.getCountry() && tasks[i].getLocation().getCity() == location.getCity() && tasks[i].getLocation().getStreet() == location.getStreet() && tasks[i].getLocation().getPostalCode() == location.getPostalCode())
        {
            tasks[i].displayInformation();
            cout << endl;
        }
    }
}

int main()
{
    vector<Task> tasks;
    vector<Task> history;

    int choice = -1;
    while (choice != 0)
    {
        cout << "\n========== Task Management Menu ==========" << endl;
        cout << "0 - Terminate program" << endl;
        cout << "1 - Create a task" << endl;
        cout << "2 - Edit a task" << endl;
        cout << "3 - Display a task" << endl;
        cout << "4 - Display Tasks by Start Time" <<endl;
        cout << "5 - Display Taks by Location" << endl;
        cout << "6 - Delete a task" << endl;
        cout << "==========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0)
        {
            cout << "\nProgram terminated. Goodbye!\n";
            exit(0);
        }
        else if (choice == 1) // Create a task
        {
            cout << "\n========== Create a Task ==========" << endl;
            cout << "1 - Event" << endl;
            cout << "2 - Meeting" << endl;
            cout << "===================================\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1) // Create an event
            {
                cout << "\n========== Create an Event ==========" << endl;
                cout << "1 - Club Event" << endl;
                cout << "2 - Workshop" << endl;
                cout << "=====================================\n";
                cout << "Enter your choice: ";
                cin >> choice;

                cout << "\nEnter the title of your Event: ";
                string title;
                cin >> title;

                cout << "\n========== Start Time Input ==========" << endl;
                cout << "Year: ";
                int year;
                cin >> year;
                checkYear(year);

                cout << "Month: ";
                int month;
                cin >> month;
                checkMonth(month);

                cout << "Day: ";
                int day;
                cin >> day;
                checkDay(day);

                cout << "Time (24-hour format): ";
                double time;
                cin >> time;
                checkTime(time);

                Time start_time = Time(year, month, day, time);

                cout << "\n========== End Time Input ==========" << endl;
                cout << "Year: ";
                cin >> year;
                checkYear(year);

                cout << "Month: ";
                cin >> month;
                checkMonth(month);

                cout << "Day: ";
                cin >> day;
                checkDay(day);

                cout << "Time (24-hour format): ";
                cin >> time;
                checkTime(time);

                Time end_time = Time(year, month, day, time);

                cout << "\n========== Location Input ==========" << endl;
                cout << "Country: ";
                string country;
                cin >> country;

                cout << "City: ";
                string city;
                cin >> city;

                cout << "Street: ";
                string street;
                cin >> street;

                cout << "Postal Code: ";
                int postal_code;
                cin >> postal_code;

                Location location = Location(country, city, street, postal_code);

                cout << "\nFunding Needed (in $): ";
                double funding;
                cin >> funding;

                cout << "Transportation Needed (yes/no): ";
                bool transport;
                string choice2;
                cin >> choice2;
                transport = (choice2 == "yes" || choice2 == "YES");

                cout << "Catering Needed (yes/no): ";
                bool catering;
                cin >> choice2;
                catering = (choice2 == "yes" || choice2 == "YES");

                cout << "Send Email Notification (yes/no): ";
                bool email;
                cin >> choice2;
                email = (choice2 == "yes" || choice2 == "YES");

                if (choice == 1) // Club Event
                {
                    ClubEvent club_event = ClubEvent(title, start_time, end_time, location, email, funding, transport, catering);

                    cout << "\nHow many participants do you have? ";
                    int participants;
                    cin >> participants;

                    string name;
                    for (int i = 0; i < participants; ++i)
                    {
                        cout << "Enter the participant name: ";
                        cin >> name;
                        club_event.addParticipant(name);
                    }

                    cout << "\nHow many representatives do you have? ";
                    int representatives;
                    cin >> representatives;

                    int number;
                    for (int i = 0; i < representatives; ++i)
                    {
                        cout << "Enter the representative name: ";
                        cin >> name;
                        club_event.addRep(name);
                        cout << "Enter the representative's number: ";
                        cin >> number;
                        club_event.addNumber(number);
                    }

                    tasks.push_back(club_event);
                    cout << "\nClub event created successfully!\n";
                }
                else if (choice == 2) // Workshop
                {
                    cout << "\nEnter the name of the instructor: ";
                    string instructor;
                    cin >> instructor;

                    cout << "Enter the phone number of the instructor: ";
                    int number;
                    cin >> number;

                    cout << "Equipment Needed (yes/no): ";
                    bool equipment;
                    cin >> choice2;
                    equipment = (choice2 == "yes" || choice2 == "YES");

                    Workshop workshop = Workshop(title, start_time, end_time, location, email, funding, transport, catering, instructor, number, equipment);

                    cout << "\nHow many participants do you have? ";
                    int participants;
                    cin >> participants;

                    string name;
                    for (int i = 0; i < participants; ++i)
                    {
                        cout << "Enter the participant name: ";
                        cin >> name;
                        workshop.addParticipant(name);
                    }

                    tasks.push_back(workshop);
                    cout << "\nWorkshop created successfully!\n";
                }
                else
                {
                    cout << "\nInvalid input. Returning to main menu.\n";
                }
            }
            else if (choice == 2) // Create a meeting
            {
                cout << "\n========== Create a Meeting ==========" << endl;
                cout << "1 - General Meeting" << endl;
                cout << "2 - One-on-One Meeting" << endl;
                cout << "======================================\n";
                cout << "Enter your choice: ";
                cin >> choice;

                cout << "\nEnter the title of your Meeting: ";
                string title;
                cin >> title;

                cout << "\n========== Start Time Input ==========" << endl;
                cout << "Year: ";
                int year;
                cin >> year;
                checkYear(year);

                cout << "Month: ";
                int month;
                cin >> month;
                checkMonth(month);

                cout << "Day: ";
                int day;
                cin >> day;
                checkDay(day);

                cout << "Time (24-hour format): ";
                double time;
                cin >> time;
                checkTime(time);

                Time start_time = Time(year, month, day, time);

                cout << "\n========== End Time Input ==========" << endl;
                cout << "Year: ";
                cin >> year;
                checkYear(year);

                cout << "Month: ";
                cin >> month;
                checkMonth(month);

                cout << "Day: ";
                cin >> day;
                checkDay(day);

                cout << "Time (24-hour format): ";
                cin >> time;
                checkTime(time);

                Time end_time = Time(year, month, day, time);

                cout << "\n========== Location Input ==========" << endl;
                cout << "Country: ";
                string country;
                cin >> country;

                cout << "City: ";
                string city;
                cin >> city;

                cout << "Street: ";
                string street;
                cin >> street;

                cout << "Postal Code: ";
                int postal_code;
                cin >> postal_code;

                Location location = Location(country, city, street, postal_code);

                if (choice == 1) // General Meeting
                {
                    cout << "\n========== General Meeting Options ==========" << endl;
                    cout << "Equipment Needed (yes/no): ";
                    bool equipment;
                    string choice2;
                    cin >> choice2;
                    equipment = (choice2 == "yes" || choice2 == "YES");

                    General general_meeting = General(title, start_time, end_time, location, false, "Building Name", 100, equipment);

                    cout << "\nHow many participants do you have? ";
                    int participants;
                    cin >> participants;

                    string name;
                    for (int i = 0; i < participants; ++i)
                    {
                        cout << "Enter the participant name: ";
                        cin >> name;
                        general_meeting.addParticipant(name);
                    }

                    tasks.push_back(general_meeting);
                    cout << "\nGeneral meeting created successfully!\n";
                }
                else if (choice == 2) // One-on-One Meeting
                {
                    cout << "\nDo you need a follow-up meeting (yes/no)? ";
                    bool followUp;
                    string choice2;
                    cin >> choice2;
                    followUp = (choice2 == "yes" || choice2 == "YES");

                    oneOnOne one_on_one = oneOnOne(title, start_time, end_time, location, false, "Building Name", 100, followUp);

                    cout << "\nHow many participants do you have? ";
                    int participants;
                    cin >> participants;

                    string name;
                    for (int i = 0; i < participants; ++i)
                    {
                        cout << "Enter the participant name: ";
                        cin >> name;
                        one_on_one.addParticipant(name);
                    }

                    tasks.push_back(one_on_one);
                    cout << "\nOne-on-One meeting created successfully!\n";
                }
                else
                {
                    cout << "\nInvalid input. Returning to main menu.\n";
                }
            }
            else
            {
                cout << "\nInvalid input. Returning to main menu.\n";
            }
        }
        else if (choice == 2) // Edit task
        {
            cout << "\n========== Edit Task ==========" << endl;
            cout << "Enter the title of the task you want to edit: ";
            string title;
            cin >> title;

            int index = findTask(tasks, title);

            cout << "\n========== Edit Options ==========" << endl;
            cout << "1 - Start Time" << endl;
            cout << "2 - End Time" << endl;
            cout << "3 - Location" << endl;
            cout << "4 - Participants" << endl;
            cout << "==================================\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1) // Edit start time
            {
                cout << "\n========== Update Start Time ==========" << endl;
                cout << "Year: ";
                int year;
                cin >> year;
                checkYear(year);

                cout << "Month: ";
                int month;
                cin >> month;
                checkMonth(month);

                cout << "Day: ";
                int day;
                cin >> day;
                checkDay(day);

                cout << "Time (24-hour format): ";
                double time;
                cin >> time;
                checkTime(time);

                Time newStartTime = Time(year, month, day, time);
                tasks[index].setStartTime(newStartTime);

                cout << "\nStart time updated successfully!\n";
            }
            else if (choice == 2) // Edit end time
            {
                cout << "\n========== Update End Time ==========" << endl;
                cout << "Year: ";
                int year;
                cin >> year;
                checkYear(year);

                cout << "Month: ";
                int month;
                cin >> month;
                checkMonth(month);

                cout << "Day: ";
                int day;
                cin >> day;
                checkDay(day);

                cout << "Time (24-hour format): ";
                double time;
                cin >> time;
                checkTime(time);

                Time newEndTime = Time(year, month, day, time);
                tasks[index].setEndTime(newEndTime);

                cout << "\nEnd time updated successfully!\n";
            }
            else if (choice == 3) // Edit location
            {
                cout << "\n========== Update Location ==========" << endl;
                cout << "Country: ";
                string country;
                cin >> country;

                cout << "City: ";
                string city;
                cin >> city;

                cout << "Street: ";
                string street;
                cin >> street;

                cout << "Postal Code: ";
                int postal_code;
                cin >> postal_code;

                Location newLocation = Location(country, city, street, postal_code);
                tasks[index].setLocation(newLocation);

                cout << "\nLocation updated successfully!\n";
            }
            else if (choice == 4) // Edit participants
            {
                cout << "\n========== Edit Participants ==========" << endl;
                cout << "1 - Add Participants" << endl;
                cout << "2 - Remove Participants" << endl;
                cout << "=======================================\n";
                cout << "Enter your choice: ";
                cin >> choice;

                if (choice == 1) // Add participants
                {
                    cout << "\nHow many participants do you want to add? ";
                    int count;
                    cin >> count;

                    string name;
                    for (int i = 0; i < count; ++i)
                    {
                        cout << "Enter participant name: ";
                        cin >> name;
                        tasks[index].addParticipant(name);
                    }

                    cout << "\nParticipants added successfully!\n";
                }
                else if (choice == 2) // Remove participants
                {
                    cout << "\nHow many participants do you want to remove? ";
                    int count;
                    cin >> count;

                    string name;
                    for (int i = 0; i < count; ++i)
                    {
                        cout << "Enter participant name: ";
                        cin >> name;
                        tasks[index].removeParticipant(name);
                    }

                    cout << "\nParticipants removed successfully!\n";
                }
                else
                {
                    cout << "\nInvalid input. Returning to main menu.\n";
                }
            }
            else
            {
                cout << "\nInvalid input. Returning to main menu.\n";
            }
        }
        else if (choice == 3) // Display task
        {
            cout << "\n========== Display Task ==========" << endl;
            cout << "Enter the title of the task you wish to display: ";
            string title;
            cin >> title;

            int index = findTask(tasks, title);

            cout << "\n========== Task Information ==========" << endl;
            tasks[index].displayInformation();
            cout << "======================================\n";
        }
        else if (choice == 4){
          cout << "\n========== Find Task by Start Time ==========" << endl;
          cout << "Enter the Year: ";
          int year;
          cin >> year;
          cout << "Enter the Month: ";
          int month;
          cin >> month;
          cout << "Enter the Day: ";
          int day;
          cin >> day;
          cout << "Enter the Time: ";
          double time;
          cin >> time;
          Time temp_time = Time(year,month,day,time);
          findTask(tasks, temp_time);
        }
        else if (choice == 5){
            cout << "\n========== Find Task by Location ==========" << endl;
            cout << "Country: ";
            string country;
            cin >> country;

            cout << "City: ";
            string city;
            cin >> city;

            cout << "Street: ";
            string street;
            cin >> street;

            cout << "Postal Code: ";
            int postal_code;
            cin >> postal_code;

            Location newLocation = Location(country, city, street, postal_code);
            findTask(tasks,newLocation);
        }
        else if (choice == 6) // Delete task
        {
            cout << "\n========== Delete Task ==========" << endl;
            cout << "Enter the title of the task you wish to delete: ";
            string title;
            cin >> title;

            int index = findTask(tasks, title);

            history.push_back(tasks[index]);
            tasks.erase(tasks.begin() + index);

            cout << "\nTask deleted successfully!\n";
        }
        else
        {
            cout << "\nInvalid input. Please try again.\n";
        }
    }
}
