class Task
{        // initialise Tasks class
private: // outline the private attributes of the Tasks class
    string title;
    vector<string> participants;
    Time start_time;
    Time end_time;
    Location location;
    bool send_emails;

public:
    Task(string t, Time st, Time et, Location l, bool se) : title(t), start_time(st), end_time(et), location(l), send_emails(se) {}

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
        cout << std::boolalpha;
        cout << title << " information: " << endl;
        cout << "Start time: " << start_time << "End time: " << end_time;
        cout << "Location: " << location;
        cout << "Send email: " << send_emails;
        displayParticipants();
    }

    string getTitle() { return title; }
    Time getStartTime() { return start_time; }
    Time getEndTime() { return end_time; }
    Location getLocation() { return location; }
    bool getSendEmail() { return send_emails; }

    void setTitle(string t) { title = t; }
    void setStartTime(const Time &st) { start_time = st; }
    void setEndTime(const Time &et) { end_time = et; }
    void setLocation(const Location &loc) { location = loc; }
    void setSendEmail(bool se) { send_emails = se; }
};
