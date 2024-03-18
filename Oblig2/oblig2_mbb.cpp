#include "oblig2_mbb.h"
#include <iostream>
#include <cmath>



square::square(double lengde, BaseShape2D::Color color) : BaseShape2D(color), lengde(lengde) {}

double square::area() { // funksjon for utregning av areal til firkant
    return lengde*lengde;
}

double square::circumference() { // funksjon for utregning av omkrets til firkant
    return lengde*4;
}

void square::operator*(double rhs) { // skaleringsfunksjon til firkant, printer ved skalering
    std::cout << "------------------------------\n"
                 "Skaleringsoperasjon med faktor: " << rhs <<
                 "\n------------------------------\n" << std::endl;
    lengde *= rhs;
    std::cout << "Ny lengde: " << lengde << std::endl;
    std::cout << "Nytt areal: " << area() << std::endl;
    std::cout << "Ny omkrets: " << circumference() << std::endl;
}

void square::print() { // print funksjon til square
    std::cout << "------------------------------\n " << std::endl;
    std::cout << "Du har en " << BaseShape2D::getColor(color) << " square!" << std::endl;
    std::cout << "Lengde: " << lengde << std::endl;
    std::cout << "Areal: " << area() << std::endl;
    std::cout << "Omkrets: " << circumference() << std::endl;
    std::cout << "------------------------------\n " << std::endl;
}


circle::circle(double radius, BaseShape2D::Color color) : BaseShape2D(color), r(radius) {}

double circle::area() { // funksjon for utregning av areal til sirkel
    return r*r*3.14;
}

double circle::circumference()  { // funksjon for utregning av omkrets til sirkel
    return 2*r*3.14;
}

void circle::operator*(double rhs) { // skaleringsfunksjon til circle, printer ny info
    std::cout << "------------------------------\n"
                 "Skaleringsoperasjon med faktor: " << rhs <<
                 "\n------------------------------\n" << std::endl;
    r *= rhs;
    std::cout << "Ny radius: " << r << std::endl;
    std::cout << "Nytt areal: " << area() << std::endl;
    std::cout << "Ny omkrets: " << circumference() << std::endl;

}

void circle::print() { // print funksjon til circle
    std::cout << "------------------------------\n" << std::endl;
    std::cout << "Du har en " << BaseShape2D::getColor(color) << " sirkel!" << std::endl;
    std::cout << "Radius: " << r << std::endl;
    std::cout << "Areal: " << area() << std::endl;
    std::cout << "Omkrets: " << circumference() << std::endl;
    std::cout << "------------------------------\n " << std::endl;
}

triangle::triangle(double katet1, double katet2, BaseShape2D::Color color) :
    BaseShape2D(color), k1(katet1), k2(katet2){

    h = std::sqrt(k1*k1 + k2*k2); // utregning for hypotenus
}

double triangle::area() { // funksjon for utregning av areal til trekant
    return 0.5*k1*k2;
}

double triangle::circumference() { // funksjon for utregning av areal til trekant
    return h+k1+k2;
}

void triangle::operator*(double rhs) {// skalerer verdiene i triangle, og printer ny info
    std::cout << "------------------------------\n"
                 "Skaleringsoperasjon med faktor: " << rhs <<
                 "\n------------------------------\n" << std::endl;
    k1 *= rhs;
    k2 *= rhs;
    h *= rhs;
    std::cout << "Nye kateter:\nKatet1: " << k1 << " og katet2: " << k2 << std::endl;
    std::cout << "Ny hypotenus: " << h << std::endl;
    std::cout << "Nytt areal: " << area() << std::endl;
    std::cout << "Ny omkrets: " << circumference() << std::endl;
}

void triangle::print() { // print funksjon til triangle
    std::cout << "------------------------------\n" << std::endl;
    std::cout << "Du har en " << BaseShape2D::getColor(color) << " trekant!\nLengde katet1: " << k1 << ", og katet2: " << k2 << std::endl;
    std::cout << "Hypotenus: " << h << std::endl;
    std::cout << "Areal: " << area() << std::endl;
    std::cout << "Omkrets: " << circumference() << std::endl;
    std::cout << "------------------------------\n" << std::endl;

}

