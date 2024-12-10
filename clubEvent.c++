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
