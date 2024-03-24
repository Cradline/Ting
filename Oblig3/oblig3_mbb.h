#ifndef OBLIG3_MBB_H
#define OBLIG3_MBB_H

#include <string>
#include <vector>

class Room {

public:
    Room(std::pair<int, int> roomDims, std::string name);
    double area() const;
    int getLengde() const;
    int getBredde() const;
    std::string getName() const;

private:
    std::pair<int, int> roomDims;
    int lengde, bredde;
    std::string name;
};

class Building {

public:
    Building(std::string name);
    double area() const;
    void addRoom(Room room);
    const std::vector<Room>& getRooms() const; // skal ikke endre på noen av medlemsvariablene, kun hente info
    int calcCleaners() const;
    std::string getName() const;

private:
    std::vector<Room> rooms;
    std::string name;
    int totArea;


};

void ReadInput(std::string file_path); // funksjon for å lese input fil og sortere info

void WriteFile(std::string file_path); // funksjon for å lage dokumenter av info




#endif // OBLIG3_MBB_H
