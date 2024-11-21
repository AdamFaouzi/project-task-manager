#include <iostream> //import the input output operations for C++
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
    Time start_time;
    Time end_time;
    Location location;
  public:
    Tasks(Time st, Time et, Location l){
        start_time = st;
        end_time = et;
        location = l;
    }
};

class Events: public Tasks{
  //Code for Events Class
};

int main(){
  
}
