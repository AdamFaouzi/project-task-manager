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
