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
