#include <iostream> //import the input output operations for C++
#include <vector> //for dynamic array size
#include <algorithm>
#include <string>
using namespace std; 

class Time{ //initialise the Time class
  private: //outline the private attributes of the Time class
    int year;
    int month;
    int day;
    double time;
  public: //outline the public functions of the Time class
    Time(int y, int m, int d, double t){ //all arguments constructor function
        year = y;
        month = m;
        day = d;
        time = t;
    }
    //getters functions
    int getYear(){return year;}
    int getMonth(){return month;}
    int getDay(){return day;}
    int getTime(){return time;}
    //setters functions
    void setYear(int y){year = y;}
    void setMonth(int m){year = m;}
    void setDay(int d){year = d;}
    void setTime(double t){year = t;}
};

class Location{ //initialise the Location class
  private: //outline the private attributes of the Location class
    string country;
    string city;
    string street;
    int postal_code;
  public: //outline the public functions of the Location class
    Location(string co, string c, string s, int pc){ //all arguments constructor function
        country = co;
        city = c;
        street = s;
        postal_code = pc;
    }
    //getters functions
    string getCountry(){return country;}
    string getCity(){return city;}
    string getStreet(){return street;}
    int getPostalCode(){return postal_code;}
    //setters functions
    void setCountry(string c){country = c;}
    void setCity(string c){city = c;}
    void setStreet(string s){street = s;}
    void setPostalCode(int p){postal_code = p;}
};

class Tasks{ //initialise Tasks class
  private: //outline the private attributes of the Tasks class
    vector<string> participants;
    Time start_time;
    Time end_time;
    Location location;
  public:
    Tasks(Time st, Time et, Location l) : start_time(st), end_time(et), location(l){}

    void addParticipant(const string& participant){
        // Add the participant to the 'participants' vector using push_back
        participants.push_back(participant);
        // 'push_back' adds an element to the end of the vector
        cout<<participant<<" has been added to the participants list.\n";
    }

    void removeParticipant(const string& participant){
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
        if(it != participants.end()){
            // If found, erase the participant from the vector
            participants.erase(it);
            cout<<participant<<" has been removed from the participants list.\n";
        } else{
            // If the participant is not found, display a message
            cout<<"Participant not found.\n";
        }
    }

    void displayParticipants(){
        cout<<"Participants:\n";
        for(const string& participant : participants){
            cout<<"-"<<participant<<'\n';
        }
    }

    Time getStartTime() { return start_time; }
    Time getEndTime() { return end_time; }
    Location getLocation() { return location; }

    void setStartTime(const Time& st) { start_time = st; }
    void setEndTime(const Time& et) { end_time = et; }
    void setLocation(const Location& loc) { location = loc; }
};

class Events: public Tasks{
  //Code for Events Class
};

int main(){
  
}
