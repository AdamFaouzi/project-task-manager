#include <iostream> //import the input output operations for C++
#include <vector>   //for dynamic array size
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

class Time
{        // initialise the Time class
private: // outline the private attributes of the Time class
  int year;
  int month;
  int day;
  double time;

public: // outline the public functions of the Time class
  Time(){

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

public:
  Task(string t, Time st, Time et, Location l) : title(t), start_time(st), end_time(et), location(l) {}

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
    cout << title << " information: " << endl;
    cout << "Start time: " << start_time << "End time: " << end_time;
    cout << "Location: " << location;
    displayParticipants();
  }

  string getTitle() { return title; }
  Time getStartTime() { return start_time; }
  Time getEndTime() { return end_time; }
  Location getLocation() { return location; }

  void setTitle(string t) { title = t; }
  void setStartTime(const Time &st) { start_time = st; }
  void setEndTime(const Time &et) { end_time = et; }
  void setLocation(const Location &loc) { location = loc; }
};

class Event : public Task
{
private:
  double funding;
  bool transportation;
  bool catering;

public:
  Event(string ti, Time st, Time et, Location l, double f, bool t, bool c) : Task(ti, st, et, l), funding(f), transportation(t), catering(c) {}

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
  ClubEvent(string ti, Time st, Time et, Location l, double f, bool t, bool c) : Event(ti, st, et, l, f, t, c) {}

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
  Workshop(string ti, Time st, Time et, Location l, double f, bool t, bool c, string i, int n, bool e) : Event(ti, st, et, l, f, t, c), instructor(i), number(n), equipment(e) {}

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

class Meeting : public Event{
    private:
        string agenda;
        string type;
        vector<string> attendees;
        double duration;
    
    public:
        Meeting(string ti, Time st, Time et, Location l, double f, bool t, bool c,string a, string ty, double d) : Event(ti, st, et, l, f, t, c), agenda(a), type(ty), duration(d){}
        //getters
        string getAgenda(){ return agenda;}
        string getType(){return type;}
        double getDuration(){return duration;}

        //setters
        void setAgenda(string a){agenda = a;}
        void setType(string t){type = t;}
        void setDuration(double d){
            if (d <= 0){
                cout << "The duration can't be negative" << endl;
            }
            else{
                duration = d;
            }
        }

        //add attendees 
        void add_attendee(const string &add_name){
            attendees.push_back(add_name);
            cout << add_name << " has been added to the list" << endl;
            cout << "Updated list of attendees: ";
            for (auto i : attendees){
                cout << "- " << i << endl;
            }
        }

        //remove attendees 
        void remove_attendee(const string &remove_name){
            auto remove_attend = find(attendees.begin(), attendees.end(), remove_name);
            if (remove_attend != attendees.end()){
                attendees.erase(remove_attend);
                cout << remove_name << " has been removed from the list of attendees" << endl;
                cout << "The updated list is of attendees is: ";
                for (auto j : attendees){
                    cout << "- " << j << endl;
                }
            }
            else{
                cout << remove_name << "doesn't exist in the list of equipments" << endl;
            }
        }

        void display(){ // general display
            cout << "Agenda: " << agenda << endl << "Type of meeting: " << type << endl << "Duration: " << duration << endl << "Attendees: ";
            for (auto i : attendees){
                cout << "- " << i << endl;
            }
        }
        
};

class General : public Meeting{
    private:
        string room_number;
        bool equip_needed;
        vector <string> equipment;

    public:
        General(string ti, Time st, Time et, Location l, double f, bool t, bool c,string a, string ty, double d, string rn, bool en) : Meeting(ti,st,et,l,f,t,c,a,ty,d), room_number(rn),equip_needed(en){}
        

        //getter
        string getRoomNumber(){return room_number;}
        bool getEquipNeeded(){return equip_needed;}

        //setter
        void setRoomNumber(string rn){room_number = rn;}
        void setEquipNeeded(bool en){equip_needed = en;}

        void add_equip(const string &equipment_added){
            if (equip_needed != false){
                equipment.push_back(equipment_added);
                cout << equipment_added << "has been added to the list of equipments" << endl;
                for (auto i : equipment){
                    cout << "- " << i << endl;
                }
            }
            else{
                cout << "No equipment needed" << endl;
            }
        }

        void remove_equip(const string &equipment_removed){
            auto equip_rem = find(equipment.begin(), equipment.end(), equipment_removed);
            if (equip_rem != equipment.end()){
                equipment.erase(equip_rem);
                cout << equipment_removed << "has been removed from the list of equipments" << endl;
                cout << "The updated list is of equipments is: ";
                for (auto j : equipment){
                    cout << "- " << j << endl;
                }
            }
            else{
                cout << equipment_removed << "doesn't exist in the list of equipments" << endl;
            }
        }

        void display(){
            cout << "General meeting information: " << endl;
            cout << "Room number: " << room_number << endl;
            if (equip_needed != false){
                cout << "Equipment needed: " << endl;
                for (auto i : equipment){
                    cout << "- " << i << endl;
                }
            }
        }

};
class oneOnOne : public Meeting{
    private:
        string name;
        bool follow_up;

    public:
        oneOnOne(string ti, Time st, Time et, Location l, double f, bool t, bool c,string a, string ty, double d,string n, bool fr) : Meeting(ti,st,et,l,f,t,c,a,ty,d), name(n), follow_up(fr){}

        //getters
        string getName(){return name;}
        bool getFollowUp(){return follow_up;}

        //setters
        void setName(string n){name = n;}
        void setFollowUp(bool fr){follow_up = fr;}

        void display(){
            cout << "One on one meeting details: " << endl;
            cout << "Name: " << name << endl;
            cout << "Follow up required? " << follow_up << endl;
        }

};

class Email{
    private:
        Time time_sent;
        vector <string> recipients;
        string content;
        string email_type;
        bool priority;
        vector <string> attachments;

    public:
        Email(Time ts, string c, string emt, bool p){
            time_sent = ts;
            content = c;
            email_type = emt;
            priority = true;
        }

        //getters
        Time getTimeSent(){return time_sent;}
        string getContent(){return content;}
        string getEmailType(){return email_type;}
        bool getPriority(){return priority;}

        //setters
        void setTimeSent(Time ts){time_sent = ts;}
        void setContent(string c){content = c;}
        void setEmailType(string emt){email_type = emt;}
        void setPriority(bool p){priority = p;}

        void add_recipient(const string &add_name){
            recipients.push_back(add_name);
            cout << add_name << "has been added to the list of recipients" << endl;
            cout << "Updated list of recipients: " << endl;
            for (auto i : recipients){
                cout << "- " << i << endl;
            }
        }

        void remove_recipient(const string &remove_name){
            auto name = find(recipients.begin(), recipients.end(), remove_name);
            if (name != recipients.end()){
                recipients.erase(name);
                cout << remove_name << "was removed from the list of recipients" << endl;
                cout << "The updated list of recipients is: " << endl;
                for (auto i : recipients){
                    cout << "- " << i << endl;
                }
            }
            else{
                cout << remove_name << "doesn't exist in the list of recipients" << endl;
            }
        }

        void add_attachment(const string &add_attach){
            attachments.push_back(add_attach);
            cout << add_attach << "has been added to the list of attachments" << endl;
            cout << "Updated list of attachments: " << endl;
            for (auto i : attachments){
                cout << "- " << i << endl;
            }
        }

        void remove_attachment(const string &remove_attach){
            auto attach = find(attachments.begin(), attachments.end(), remove_attach);
            if (attach != attachments.end()){
                attachments.erase(attach);
                cout << remove_attach << "was removed from the list of attachments" << endl;
                cout << "The updated list of attachments is: " << endl;
                for (auto i : attachments){
                    cout << "- " << i << endl;
                }
            }
            else{
                cout << remove_attach << "doesn't exist in the list of attachements" << endl;
            }
        }

        void display(){
            cout << "Email details: " << endl;
            cout << "Time: " << time_sent << endl;
            cout << "Recipients: " << endl;
            for (auto i : recipients){
                cout << "- " << i << endl;
            }
            cout << "Content: " << content << endl;
            cout << "Email type: " << email_type << endl;
            cout << "Priority: " << priority << endl;
            cout << "Attachments: " << endl;
            for (auto j : attachments){
                cout << "- " << j << endl;
            }
        }
};
