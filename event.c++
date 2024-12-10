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
