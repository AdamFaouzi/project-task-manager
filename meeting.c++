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
