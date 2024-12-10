class oneOnOne : public Meeting
{
private:
    bool follow_up;

public:
    oneOnOne(string ti, Time st, Time et, Location l, bool se, string b, int rn, bool fu) : Meeting(ti, st, et, l, se, b, rn), follow_up(fu) {}

    // getter
    bool getFollowUp() { return follow_up; }

    // setter
    void setFollowUp(bool fr) { follow_up = fr; }

    void displayInformation()
    {
        cout << "One on one meeting details: " << endl;
        Meeting::displayInformation();
        cout << "Follow up required? " << follow_up << endl;
    }
};
