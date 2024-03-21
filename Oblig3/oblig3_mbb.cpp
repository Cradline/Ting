#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
#include "oblig3_mbb.h"


std::map<std::string, Building> HouseMap; // map bestående av alle bygninger

Room::Room(std::pair<int, int> roomDims, std::string name) : lengde(roomDims.first), bredde(roomDims.second), name(name) {}

double Room::area() const {
    return lengde*bredde;
}

int Room::getLengde() const {
    return lengde;
}

int Room::getBredde() const {
    return bredde;
}

std::string Room::getName() const {
    return name;
}

Building::Building(std::string name) : name(name), totArea(0) {} // gjør at total Areal til en bygning er 0 når ny bygning opprettes

void Building::addRoom(Room room) {
    rooms.push_back(room);
    totArea += room.area();
}

const std::vector<Room>& Building::getRooms() const {
    return rooms;
}

double Building::area() const {
    double totArea = 0;
    for(const auto& room : rooms) {
        totArea += room.area();
    }
    return totArea;
}

std::string Building::getName() const {
     return name;
}

int Building::calcCleaners() const {
    int CleanersByArea = ceil(Building::area() / 15); // ceil runder opp til nærmeste heltall,
    int CleanersByRooms = ceil(rooms.size() / 2);
    return std::max(CleanersByArea, CleanersByRooms);
}

void ReadInput(std::string file_path) {
    std::ifstream inputFile(file_path); // åpner inputfilen med info om rommene i forskjellige bygninger

    if(inputFile.fail()){
        std::cout << "Error, unable to read input file." << std::endl;
        exit(1); // går ut av funksjonen, kan ikke lese input
    }

    int x, y;
    std::string z;

    while(inputFile >> x >> y >> z){ // inputfil har en x, y og z verdi

        std::pair<int, int> roomDims = std::make_pair(x, y);
        Room room(roomDims, z);

        if(HouseMap.find(z) == HouseMap.end()) {                    // sjekker om bygning allerede eksisterer i HouseMap
            Building building(z);                                   // eksisterer ikke fra før --> lager ny bygning med navn z
            building.addRoom(room);                                 // adder rommet til bygningen
            building.calcCleaners();                                // regner ut hvor mange renholdere dette bygget trenger
            HouseMap.emplace(z, building);                          // plasserer bygningen i HouseMap

        } else {                                                    // vi har en allerede eksisterende bygning
            Building& existingBuilding = HouseMap.find(z)->second;  // Henter referansen til den eksisterende bygningen i HouseMap
            existingBuilding.addRoom(room);                         // Legger til rommet i den eksisterende bygningen
        }

    }
    inputFile.close(); // lukker inputfilen

}

void WriteFile(std::string file_path) {


    for (const auto& pair : HouseMap) { // variabel pair er referanse til hvert element i HouseMap

        const Building& building = pair.second; // i HouseMap er Building "second" i pair

        std::ofstream outFile(building.getName() + "_" + file_path);    // lager en fil for hver bygning,
                                                                        // henter navnet på bygningen og dette blir første del av filnavnet

        outFile << "Name: " << building.getName() << std::endl;         // Skriver første linje i filen, henter navnet på aktuell bygning
        outFile << "Total areal: " << building.area() << std::endl;     // printer info om bygning
        outFile << "Antall rom: " << building.getRooms().size() << std::endl;
        outFile << "Renholdere som trengs: " << building.calcCleaners() << std::endl;
        outFile << std::endl;                                           // blank linje for litt mellomrom
        outFile << "Rom: " << std::endl;                                // printer info om alle rommene i aktuell bygning
        int j = 0;
        for (const Room& room : building.getRooms()) {
            j++;
            outFile << j << ". " << "Lengde: " << room.getLengde() << ", Bredde: " << room.getBredde() << std::endl;
        }
        outFile.close(); // lukker filen
    }
}




