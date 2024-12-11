#include <iostream> //import the input output operations for C++
#include <vector>   //for dynamic array size
#include <algorithm>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;

int checkDay(int day)
{
    while (day < 1 || day > 31)
    {
        cout << "Invalid input, enter day: ";
        cin >> day;
    }
    return day;
}

int checkYear(int year)
{
    time_t currentTime = time(nullptr);

    // Convert to local time structure
    tm *localTime = localtime(&currentTime);

    // Extract the year
    int year_now = 1900 + localTime->tm_year;

    while (year < year_now)
    {
        cout << "Invalid year, cannot create task in the past, enter year: ";
        cin >> year;
    }
    return year;
}

int checkMonth(int month)
{
    while (month < 1 || month > 12)
    {
        cout << "Invalid input, enter month: ";
        cin >> month;
    }
    return month;
}

double checkTime(double time)
{
    while (time < 0)
    {
        cout << "Invalid input, enter time: ";
        cin >> time;
    }
    return time;
}

int findTask(vector<Task> &tasks, string &title)
{
    for (int i = 0; i < tasks.size(); i++)
    {
        if (tasks[i].getTitle() == title)
        {
            return i;
        }
    }
    return -1;
}

int findTask(vector<Task> &tasks, Time &time)
{
    for (int i = 0; i < tasks.size(); i++)
    {
        if (tasks[i].getStartTime().getYear() == time.getYear() && tasks[i].getStartTime().getMonth() == time.getMonth() && tasks[i].getStartTime().getDay() == time.getDay() && tasks[i].getStartTime().getTime() == time.getTime())
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<Task> tasks;
    vector<Task> history;

    int choice = -1;
    while (choice != 0)
    {
        cout << "\n========== Task Management Menu ==========" << endl;
        cout << "0 - Terminate program" << endl;
        cout << "1 - Create a task" << endl;
        cout << "2 - Edit a task" << endl;
        cout << "3 - Display a task" << endl;
        cout << "4 - Display Tasks by Start Time" <<endl;
        cout << "5 - Delete a task" << endl;
        cout << "==========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0)
        {
            cout << "\nProgram terminated. Goodbye!\n";
            exit(0);
        }
        else if (choice == 1) // Create a task
        {
            cout << "\n========== Create a Task ==========" << endl;
            cout << "1 - Event" << endl;
            cout << "2 - Meeting" << endl;
            cout << "===================================\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1) // Create an event
            {
                cout << "\n========== Create an Event ==========" << endl;
                cout << "1 - Club Event" << endl;
                cout << "2 - Workshop" << endl;
                cout << "=====================================\n";
                cout << "Enter your choice: ";
                cin >> choice;

                cout << "\nEnter the title of your Event: ";
                string title;
                cin >> title;

                cout << "\n========== Start Time Input ==========" << endl;
                cout << "Year: ";
                int year;
                cin >> year;
                checkYear(year);

                cout << "Month: ";
                int month;
                cin >> month;
                checkMonth(month);

                cout << "Day: ";
                int day;
                cin >> day;
                checkDay(day);

                cout << "Time (24-hour format): ";
                double time;
                cin >> time;
                checkTime(time);

                Time start_time = Time(year, month, day, time);

                cout << "\n========== End Time Input ==========" << endl;
                cout << "Year: ";
                cin >> year;
                checkYear(year);

                cout << "Month: ";
                cin >> month;
                checkMonth(month);

                cout << "Day: ";
                cin >> day;
                checkDay(day);

                cout << "Time (24-hour format): ";
                cin >> time;
                checkTime(time);

                Time end_time = Time(year, month, day, time);

                cout << "\n========== Location Input ==========" << endl;
                cout << "Country: ";
                string country;
                cin >> country;

                cout << "City: ";
                string city;
                cin >> city;

                cout << "Street: ";
                string street;
                cin >> street;

                cout << "Postal Code: ";
                int postal_code;
                cin >> postal_code;

                Location location = Location(country, city, street, postal_code);

                cout << "\nFunding Needed (in $): ";
                double funding;
                cin >> funding;

                cout << "Transportation Needed (yes/no): ";
                bool transport;
                string choice2;
                cin >> choice2;
                transport = (choice2 == "yes" || choice2 == "YES");

                cout << "Catering Needed (yes/no): ";
                bool catering;
                cin >> choice2;
                catering = (choice2 == "yes" || choice2 == "YES");

                cout << "Send Email Notification (yes/no): ";
                bool email;
                cin >> choice2;
                email = (choice2 == "yes" || choice2 == "YES");

                if (choice == 1) // Club Event
                {
                    ClubEvent club_event = ClubEvent(title, start_time, end_time, location, email, funding, transport, catering);

                    cout << "\nHow many participants do you have? ";
                    int participants;
                    cin >> participants;

                    string name;
                    for (int i = 0; i < participants; ++i)
                    {
                        cout << "Enter the participant name: ";
                        cin >> name;
                        club_event.addParticipant(name);
                    }

                    cout << "\nHow many representatives do you have? ";
                    int representatives;
                    cin >> representatives;

                    int number;
                    for (int i = 0; i < representatives; ++i)
                    {
                        cout << "Enter the representative name: ";
                        cin >> name;
                        club_event.addRep(name);
                        cout << "Enter the representative's number: ";
                        cin >> number;
                        club_event.addNumber(number);
                    }

                    tasks.push_back(club_event);
                    cout << "\nClub event created successfully!\n";
                }
                else if (choice == 2) // Workshop
                {
                    cout << "\nEnter the name of the instructor: ";
                    string instructor;
                    cin >> instructor;

                    cout << "Enter the phone number of the instructor: ";
                    int number;
                    cin >> number;

                    cout << "Equipment Needed (yes/no): ";
                    bool equipment;
                    cin >> choice2;
                    equipment = (choice2 == "yes" || choice2 == "YES");

                    Workshop workshop = Workshop(title, start_time, end_time, location, email, funding, transport, catering, instructor, number, equipment);

                    cout << "\nHow many participants do you have? ";
                    int participants;
                    cin >> participants;

                    string name;
                    for (int i = 0; i < participants; ++i)
                    {
                        cout << "Enter the participant name: ";
                        cin >> name;
                        workshop.addParticipant(name);
                    }

                    tasks.push_back(workshop);
                    cout << "\nWorkshop created successfully!\n";
                }
                else
                {
                    cout << "\nInvalid input. Returning to main menu.\n";
                }
            }
            else if (choice == 2) // Create a meeting
            {
                cout << "\n========== Create a Meeting ==========" << endl;
                cout << "1 - General Meeting" << endl;
                cout << "2 - One-on-One Meeting" << endl;
                cout << "======================================\n";
                cout << "Enter your choice: ";
                cin >> choice;

                cout << "\nEnter the title of your Meeting: ";
                string title;
                cin >> title;

                cout << "\n========== Start Time Input ==========" << endl;
                cout << "Year: ";
                int year;
                cin >> year;
                checkYear(year);

                cout << "Month: ";
                int month;
                cin >> month;
                checkMonth(month);

                cout << "Day: ";
                int day;
                cin >> day;
                checkDay(day);

                cout << "Time (24-hour format): ";
                double time;
                cin >> time;
                checkTime(time);

                Time start_time = Time(year, month, day, time);

                cout << "\n========== End Time Input ==========" << endl;
                cout << "Year: ";
                cin >> year;
                checkYear(year);

                cout << "Month: ";
                cin >> month;
                checkMonth(month);

                cout << "Day: ";
                cin >> day;
                checkDay(day);

                cout << "Time (24-hour format): ";
                cin >> time;
                checkTime(time);

                Time end_time = Time(year, month, day, time);

                cout << "\n========== Location Input ==========" << endl;
                cout << "Country: ";
                string country;
                cin >> country;

                cout << "City: ";
                string city;
                cin >> city;

                cout << "Street: ";
                string street;
                cin >> street;

                cout << "Postal Code: ";
                int postal_code;
                cin >> postal_code;

                Location location = Location(country, city, street, postal_code);

                if (choice == 1) // General Meeting
                {
                    cout << "\n========== General Meeting Options ==========" << endl;
                    cout << "Equipment Needed (yes/no): ";
                    bool equipment;
                    string choice2;
                    cin >> choice2;
                    equipment = (choice2 == "yes" || choice2 == "YES");

                    General general_meeting = General(title, start_time, end_time, location, false, "Building Name", 100, equipment);

                    cout << "\nHow many participants do you have? ";
                    int participants;
                    cin >> participants;

                    string name;
                    for (int i = 0; i < participants; ++i)
                    {
                        cout << "Enter the participant name: ";
                        cin >> name;
                        general_meeting.addParticipant(name);
                    }

                    tasks.push_back(general_meeting);
                    cout << "\nGeneral meeting created successfully!\n";
                }
                else if (choice == 2) // One-on-One Meeting
                {
                    cout << "\nDo you need a follow-up meeting (yes/no)? ";
                    bool followUp;
                    string choice2;
                    cin >> choice2;
                    followUp = (choice2 == "yes" || choice2 == "YES");

                    oneOnOne one_on_one = oneOnOne(title, start_time, end_time, location, false, "Building Name", 100, followUp);

                    cout << "\nHow many participants do you have? ";
                    int participants;
                    cin >> participants;

                    string name;
                    for (int i = 0; i < participants; ++i)
                    {
                        cout << "Enter the participant name: ";
                        cin >> name;
                        one_on_one.addParticipant(name);
                    }

                    tasks.push_back(one_on_one);
                    cout << "\nOne-on-One meeting created successfully!\n";
                }
                else
                {
                    cout << "\nInvalid input. Returning to main menu.\n";
                }
            }
            else
            {
                cout << "\nInvalid input. Returning to main menu.\n";
            }
        }
        else if (choice == 2) // Edit task
        {
            cout << "\n========== Edit Task ==========" << endl;
            cout << "Enter the title of the task you want to edit: ";
            string title;
            cin >> title;

            int index = findTask(tasks, title);

            cout << "\n========== Edit Options ==========" << endl;
            cout << "1 - Start Time" << endl;
            cout << "2 - End Time" << endl;
            cout << "3 - Location" << endl;
            cout << "4 - Participants" << endl;
            cout << "==================================\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1) // Edit start time
            {
                cout << "\n========== Update Start Time ==========" << endl;
                cout << "Year: ";
                int year;
                cin >> year;
                checkYear(year);

                cout << "Month: ";
                int month;
                cin >> month;
                checkMonth(month);

                cout << "Day: ";
                int day;
                cin >> day;
                checkDay(day);

                cout << "Time (24-hour format): ";
                double time;
                cin >> time;
                checkTime(time);

                Time newStartTime = Time(year, month, day, time);
                tasks[index].setStartTime(newStartTime);

                cout << "\nStart time updated successfully!\n";
            }
            else if (choice == 2) // Edit end time
            {
                cout << "\n========== Update End Time ==========" << endl;
                cout << "Year: ";
                int year;
                cin >> year;
                checkYear(year);

                cout << "Month: ";
                int month;
                cin >> month;
                checkMonth(month);

                cout << "Day: ";
                int day;
                cin >> day;
                checkDay(day);

                cout << "Time (24-hour format): ";
                double time;
                cin >> time;
                checkTime(time);

                Time newEndTime = Time(year, month, day, time);
                tasks[index].setEndTime(newEndTime);

                cout << "\nEnd time updated successfully!\n";
            }
            else if (choice == 3) // Edit location
            {
                cout << "\n========== Update Location ==========" << endl;
                cout << "Country: ";
                string country;
                cin >> country;

                cout << "City: ";
                string city;
                cin >> city;

                cout << "Street: ";
                string street;
                cin >> street;

                cout << "Postal Code: ";
                int postal_code;
                cin >> postal_code;

                Location newLocation = Location(country, city, street, postal_code);
                tasks[index].setLocation(newLocation);

                cout << "\nLocation updated successfully!\n";
            }
            else if (choice == 4) // Edit participants
            {
                cout << "\n========== Edit Participants ==========" << endl;
                cout << "1 - Add Participants" << endl;
                cout << "2 - Remove Participants" << endl;
                cout << "=======================================\n";
                cout << "Enter your choice: ";
                cin >> choice;

                if (choice == 1) // Add participants
                {
                    cout << "\nHow many participants do you want to add? ";
                    int count;
                    cin >> count;

                    string name;
                    for (int i = 0; i < count; ++i)
                    {
                        cout << "Enter participant name: ";
                        cin >> name;
                        tasks[index].addParticipant(name);
                    }

                    cout << "\nParticipants added successfully!\n";
                }
                else if (choice == 2) // Remove participants
                {
                    cout << "\nHow many participants do you want to remove? ";
                    int count;
                    cin >> count;

                    string name;
                    for (int i = 0; i < count; ++i)
                    {
                        cout << "Enter participant name: ";
                        cin >> name;
                        tasks[index].removeParticipant(name);
                    }

                    cout << "\nParticipants removed successfully!\n";
                }
                else
                {
                    cout << "\nInvalid input. Returning to main menu.\n";
                }
            }
            else
            {
                cout << "\nInvalid input. Returning to main menu.\n";
            }
        }
        else if (choice == 3) // Display task
        {
            cout << "\n========== Display Task ==========" << endl;
            cout << "Enter the title of the task you wish to display: ";
            string title;
            cin >> title;

            int index = findTask(tasks, title);

            cout << "\n========== Task Information ==========" << endl;
            tasks[index].displayInformation();
            cout << "======================================\n";
        }
        else if (choice == 4){
          cout << "\n========== Find Task by Start Time ==========" << endl;
          cout << "Enter the Year: ";
          int year;
          cin >> year;
          cout << "Enter the Month: ";
          int month;
          cin >> month;
          cout << "Enter the Day: ";
          int day;
          cin >> day;
          cout << "Enter the Time: ";
          double time;
          cin >> time;
          Time temp_time = Time(year,month,day,time);
          int index = findTask(tasks, temp_time);
          tasks[index].displayInformation();
        }
        else if (choice == 5) // Delete task
        {
            cout << "\n========== Delete Task ==========" << endl;
            cout << "Enter the title of the task you wish to delete: ";
            string title;
            cin >> title;

            int index = findTask(tasks, title);

            history.push_back(tasks[index]);
            tasks.erase(tasks.begin() + index);

            cout << "\nTask deleted successfully!\n";
        }
        else
        {
            cout << "\nInvalid input. Please try again.\n";
        }
    }
}
