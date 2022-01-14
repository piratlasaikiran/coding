#include <bits/stdc++.h>
using namespace std;

struct roomDetails{
    int startTime=0;
    int endTime=24;
    string Bookedby="";
};
map<string, map<string, set<string>>> conferenceRoomMapper;
map<string, map<string, map<string, vector<pair<int, int>>>>> bookingData;

string convertToLowerString(string s){
    for(int i=0; i<s.size(); i++){
        if((s[i] >= 'A') && (s[i] <= 'Z')){
            s[i] = s[i] - 'A' + 'a';
        }
    }
    return s;
}

void addBuilding(string building){
    building = convertToLowerString(building);
    if(conferenceRoomMapper.find(building) != conferenceRoomMapper.end()){
        cout << "Building already added.! Try adding another building." << endl;
        return;
    }

    else{
        conferenceRoomMapper[building];
        cout << "Building added" << endl;
    }
}

void addFloor(string building, string floor){
    building = convertToLowerString(building);
    floor = convertToLowerString(floor);
    if(conferenceRoomMapper.find(building) == conferenceRoomMapper.end()){
        cout << "Building not there. First add building: " << building << endl;
    }
    else if(conferenceRoomMapper[building].find(floor) != conferenceRoomMapper[building].end()){
        cout << "Floor already added.! Try adding another floor." << endl;
    }
    else{
        conferenceRoomMapper[building][floor];
        cout << "Floor added" << endl;
    }
}

void addConferenceRoom(string building, string floor, string room){
    building = convertToLowerString(building);
    floor = convertToLowerString(floor);
    room = convertToLowerString(room);
    if(conferenceRoomMapper.find(building) == conferenceRoomMapper.end()){
        cout << "Building not there. First add building: " << building << endl;
    }
    else if(conferenceRoomMapper[building].find(floor) == conferenceRoomMapper[building].end()){
        cout << "Floor not there. First add floor." << endl;
    }
    else if(conferenceRoomMapper[building][floor].find(floor) != conferenceRoomMapper[building][floor].end()){
        cout << "Room already added.! Try adding another room." << endl;
    }
    else{
        conferenceRoomMapper[building][floor].insert(room);
        cout << "Room added" << endl;
    }
}

bool checkIfSlotsOverlap(pair<int, int> bookedSlot, pair<int, int> desiredSlot){
    if(bookedSlot.second < desiredSlot.first || bookedSlot.first > desiredSlot.second)
        return false;
    return true;
}

bool checkRoomAvaialbleAtSlot(string building, string floor, string room, pair<int, int> slot){
    building = convertToLowerString(building);
    floor = convertToLowerString(floor);
    room = convertToLowerString(room);
    auto bookedSlots = bookingData[building][floor][room];
    for(int i=0; i<bookedSlots.size(); i++){
        int bookingStart = bookedSlots[i].first;
        int bookingEnd = bookedSlots[i].second;
        if(checkIfSlotsOverlap(bookedSlots[i], slot))
            return false;
    }

    return true;
}

void bookConferenceRoom(string building, string floor, string room, pair<int, int> slot){
    building = convertToLowerString(building);
    floor = convertToLowerString(floor);
    room = convertToLowerString(room);
    if(conferenceRoomMapper.find(building) == conferenceRoomMapper.end()){
        cout << "Building not there. First add building: " << building << endl;
    }
    else if(conferenceRoomMapper[building].find(floor) == conferenceRoomMapper[building].end()){
        cout << "Floor not there. First add floor." << endl;
    }
    else if(conferenceRoomMapper[building][floor].find(floor) == conferenceRoomMapper[building][floor].end()){
        cout << "Room already added.! Try adding another room." << endl;
    }
    else if(checkRoomAvaialbleAtSlot(building, floor, room, slot)){
            bookingData[building][floor][room].push_back(slot);
            cout << "Room booked.!" << endl;
    }
    else{
        cout << "Sorry. Room Not available." << endl;
    }
}

void cancelBooking(string building, string floor, string room, pair<int, int> slot){
    building = convertToLowerString(building);
    floor = convertToLowerString(floor);
    room = convertToLowerString(room);
    auto bookedSlots = bookingData[building][floor][room];
    bool bookingRemoved = false;
    for(vector<pair<int, int>>::iterator it = bookedSlots.begin(); it != bookedSlots.end(); ++it){
        if(it->first == slot.first && it->second == slot.second){
            bookedSlots.erase(it);
            bookingRemoved = true;
        }
    }

    if(bookingRemoved){
        cout << "Booking cancelled." << endl;
    }
    else{
        cout << "No such booking exists" << endl;
    }
}

bool validateBookingSlot(pair<int, int> slot){
    if(slot.first >= 0 && slot.first < 24 && slot.second >= 0 && slot.second < 24)
        return true;

    return false;

}

void listBookings(string building, string floor){
    building = convertToLowerString(building);
    floor = convertToLowerString(floor);
    auto listOfBookings = bookingData[building][floor];
    for(auto it = listOfBookings.begin(); it != listOfBookings.end(); ++it){
        auto roomMap = it->second;
        for(auto slots: roomMap){
            cout << slots.first << ":" << slots.second << " " << building << " " << floor << " " << it->first;
        }
    }
}

void searchConferenceRooms(string building, string floor, pair<int,int> wantedSlot){
    building = convertToLowerString(building);
    floor = convertToLowerString(floor);
    auto roomData = bookingData[building][floor];
    int availableRoomCount=0;
    for(auto it = roomData.begin(); it != roomData.end(); ++it){
        bool slotAvaiableinRoom = true;
        for(auto slot:it->second){
            if(checkIfSlotsOverlap(slot, wantedSlot))
                slotAvaiableinRoom = false;
        }
        if(slotAvaiableinRoom){
            cout << it->first << endl;
            availableRoomCount++;
        }
        if(availableRoomCount == 0){
            cout << "Sorry, no slots available" << endl;
        }
    }
}

int main(){
    cout<<"***Welcome to conference room booking system***"<<endl;
    string arg1, arg2, arg3, arg4, arg5;
    int slotStartTime, slotStopTime;
        while(true){
            cin >> arg1;
            if(arg1 == "ADD"){
                cin >> arg2;
                if(arg2 == "BUILDING"){
                    cin >> arg3;
                    addBuilding(arg3);
                }
                else if(arg2 == "FLOOR"){
                    cin >> arg3;
                    cin >> arg4; 
                    addFloor(arg3, arg4);
                }
                else if(arg2 == "CONFROOM"){
                    cin >> arg3;
                    cin >> arg4;
                    cin >> arg5;
                    addConferenceRoom(arg3, arg4, arg5);
                }

            }
            else if(arg1 == "BOOK"){
                cin >> slotStartTime >> slotStopTime;
                cin >> arg2 >> arg3 >> arg5;
                bookConferenceRoom(arg2, arg3, arg5, make_pair(slotStartTime, slotStopTime));
            }
            else if(arg1 == "CANCEL"){
                cin >> slotStartTime >> slotStopTime;
                cin >> arg2 >> arg3 >> arg4;
                cancelBooking(arg2, arg3, arg4, make_pair(slotStartTime, slotStopTime));
            }
            else if(arg1 == "LIST"){
                cin >> arg2;
                if(arg2 == "BOOKING"){
                cin >> arg2 >> arg3;    
                listBookings(arg2, arg3);
                }
            }
            else if(arg1 == "SEARCH"){
                cin >> slotStartTime >> slotStopTime;
                cin >> arg2 >> arg3;
                searchConferenceRooms(arg2, arg3, make_pair(slotStartTime, slotStopTime));
            }
            else if(arg1 == "EXIT" || arg1 == "QUIT"){
                cout << "Exiting as per request." << endl;
                return 0;
            }
            else{
                cout << "Invalid Action.!" << endl;
            }
        }
    return 0;
}