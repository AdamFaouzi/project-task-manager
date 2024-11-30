#include <iostream> //import the input output operations for C++
#include <vector>   //for dynamic array size
#include <algorithm>
#include <string>
using namespace std;

class Time
{        // initialise the Time class
private: // outline the private attributes of the Time class
  int year;
  int month;
  int day;
  double time;

public: // outline the public functions of the Time class
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
  void setMonth(int m) { year = m; }
  void setDay(int d) { year = d; }
  void setTime(double t) { year = t; }

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

int main()
{
  Time t1 = Time(2024, 12, 1, 10.45);
  Time t2 = Time(2024, 12, 1, 11.00);
  Location l = Location("Lebanon", "Beirut", "Ras el Nabeh", 00000);
  Event t = Event("Student Meeting", t1, t2, l, 5000, true, false);
  t.displayInformation();
}
