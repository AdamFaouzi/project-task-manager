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
