#include "oblig_1_mbb.h"
#include <cmath>
#include <iostream>

float sum;
std::vector<double> counter;                // vektor, denne kan senere brukes til mer enn hva jeg gjør i denne oppgaven

float CalcMe::add(float a, float b){        // utfører addisjon
    sum = a + b;
    counter.push_back(sum);                 // legger til sum i vektor, lager plass til den nye variabelen
    return sum;
}
float CalcMe::substract(float a, float b){  // utfører substraksjon
    sum = a - b;
    counter.push_back(sum);                 // legger til sum i vektor, lager plass til den nye variabelen
    return sum;
}
float CalcMe::multiply(float a, float b){   // utfører multiplikasjon
    sum = a * b;
    counter.push_back(sum);                 // legger til sum i vektor, lager plass til den nye variabelen
    return sum;
}
float CalcMe::divide(float a, float b){     // utfører divisjon
    sum = a / b;
    counter.push_back(sum);                 // legger til sum i vektor, lager plass til den nye variabelen
    return sum;
}
float CalcMe::root(float a){                // utfører rotfunksjon
    sum = sqrt(a);
    counter.push_back(sum);                 // legger til sum i vektor, lager plass til den nye variabelen
    return sum;
}

void input_sjekk(int& input){               // sjekker input, vi forventer int
    std::cin >> input;

    while(std::cin.fail()){                 // går inn i while løkken hvis input ikke er int
        std::cin.clear();                   // åpner for mulighet å sjekke på nytt
        std::cin.ignore();
        std::cout << "Ugyldig verdi, please try again" << std::endl;
        std::cin >> input;                  // spør om ny input fra bruker, vi vil ha int!
    }
    while(input > 6 || input < 1){          // sjekker om vi har fått en verdi utenfor meny-valg. Sjekker her for å få ny verdi med en gang, istedet for å hente inn a og b før det kommer feilmelding på menyvalg
        std::cout << "Ugyldig verdi, please try again" << std::endl;
        std::cin >> input;
    }
}
void input_sjekk(char& input){              // sjekker input fra bruker, vi forventer char
    std::cin >> input;                      // henter input fra bruker

    while(std::cin.fail()){                 // så lenge input ikke er char, spør vi igjen
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Ugyldig symbol, please try again" << std::endl;
        std::cin >> input;
    }
}

void input_sjekk(float& input){             // sjekker input fra bruker, vi forventer float
    std::cin >> input;

    while(std::cin.fail()){                 // så lenge input fra bruker ikke er float, spør vi på nytt
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Ugyldig symbol, please try again" << std::endl;
        std::cin >> input;
    }
}

void YesNo(char& input){                    // sjekke ja eller nei svar fra bruker, når vi skal ut av programmet eller mellom de to forskjellige kalkis-løkkene
    std::cin >> input;
    if(input == 'y' || input == 'Y'){           // hvis bruker svarer ja, starter vi kalkis på nytt
        std::cout << "You said yes <3\n" << std::endl;
        return;

    }else if(input == 'n' || input == 'N'){     // hvis bruker svarer nei, så avslutter vi her
        std::cout << "Neivel da!\n" << std::endl;
        return;                                 // kalkis out, vi avslutter programmet

    }else {
        while(input != 'n' && input != 'N' && input != 'y' && input != 'Y'){ // Hvis ikke vi får yey eller ney fra bruker, så spør vi på nytt
            std::cout << "Plis svar Yes eller No da\n" << std::endl;
            input_sjekk(input);                   // henter ny input fra bruker
        }
    }

}
