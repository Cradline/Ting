#include <iostream>
#include <vector>
#include "oblig_1_mbb.h"

int main()
{
    int valg, nyttValg;                          // valg fra meny forventes å være en int
    float a, b;                                  // tall som brukes i kalkulator skal være float
    char fortsette, keep;                        // en char for valg ifm avslutte/restart
    bool kalkis1 = true;                         // kalkis 1.0 skal kjøre så lenge kalkis er true
    bool kalkis2 = true;                         // kalkis 2.0 er plattformen der vi bruker verdi fra tidligere regning, hadde tenkt at denne skulle ha flere morsomme funksjoner

    //-------------------------------------------------------------------------------------------------//

    while(kalkis1){
        std::cout << "-----------------------\nKALKIS 1.0: \n 1. Add \n 2. Substract \n 3. Multiply \n 4. Divide \n 5. Square \n 6. Exit\n-----------------------\nWhat to do?" <<std::endl; // viser meny for bruker
        input_sjekk(valg);                      // tar inn valg fra bruker

        if(valg == 6){                          // sjekker allerede her om valget er 5, for da vil vi avslutte før vi spør om a og b
            std::cout << "Ok, good bye then!" << std::endl;
            std::cout << "You did " << counter.size() << " kalkis-jobs today" << std::endl; // printer hvor mange ganger vi har kjørt kalkis loop i dag
            return 0;                           // avslutter program med en gang
        }

        std::cout << "First number:" << std::endl;
        input_sjekk(a);                         // henter input for a fra bruker

        if(valg !=5){                           // hvis valg fra bruker er 5 (ta rota av et tall) trenger vi bare én variabel fra bruker, derfor skipper vi denne
            std::cout << "Second number:" << std::endl;
            input_sjekk(b);                      // henter input for b fra bruker
        }

        switch(valg){                           // henter inn valg fra bruker, og styrer til riktig case
            case 1:                             // Valg 1 fra meny: addisjon
                std::cout << a << " + " << b << " = " << CalcMe::add(a, b) << std::endl;
                break;                          // med break hopper vi ut av switch

            case 2:                             // Valg 2 fra meny: substraksjon
                std::cout << a << " - " << b << " = " << CalcMe::substract(a, b) << std::endl;
                break;

            case 3:                             // Valg 3 fra meny: multiplikasjon
                std::cout << a << " x " << b << " = " << CalcMe::multiply(a, b) << std::endl;
                break;

            case 4:                             // Valg 4 fra meny: divisjon
                if (b != 0) {
                    std::cout << a << " / " << b << " = " << CalcMe::divide(a, b) << std::endl;         // dele på 0 blir bare tull
                } else {
                    std::cout << "Cannot divide by zero! Let's go back to the menu:\n" << std::endl;
                    continue;
                }
                break;

            case 5:                             // valg 5 fra meny: rota
                std::cout << "Rota av " << a << " er " << CalcMe::root(a) << std::endl;
                break;

            default:                            // andre verdier gir feilmelding
                std::cout << "Ugyldig verdi, please try again" << std::endl;
                break;
        }

        std::cout << "En gang til? (y/n)" << std::endl;     // spør om vi skal kjøre kalkulator en gang til
        YesNo(fortsette);                                   // henter input fra bruker

        if(fortsette == 'n' || fortsette == 'N'){           // hvis bruker svarer nei, så avslutter vi her
            std::cout << "Ok, good bye then!" << std::endl;
            std::cout << "You did " << counter.size() << " kalkis-jobs today" << std::endl;
            return 0;                                       // kalkis out, vi avslutter programmet
        }

        //---------------------------------------------------------------------------------------------//


        while(kalkis2){
            std::cout << "Vil du beholde svaret ditt som en variabel i neste utregning? (y/n)" << std::endl;
            YesNo(keep);                                            // henter input fra bruker

            if(keep == 'n' || keep == 'N'){
                break;                                              // hvis vi har fått nei fra bruker, skal vi gå ut av denne og tilbake til kalkis 1.0

            } else if(keep == 'y' || keep == 'Y'){
                std::cout << "-----------------------" << std::endl;    // viser meny header
                std::cout << "KALKIS 2.0: \n 1. Add \n 2. Substract \n 3. Multiply \n 4. Divide \n 5. Square\n 6. Exit" <<std::endl; // viser meny for bruker
                std::cout << "----------------------- \nWhat to do?" << std::endl;

                input_sjekk(nyttValg);                              // tar inn valg fra bruker

                if(nyttValg == 6){                                  // sjekker allerede her om valget er 5, for da vil vi avslutte før vi spør om a og b
                    std::cout << "Ok, good bye then!" << std::endl;
                    std::cout << "You did " << counter.size() << " kalkis-jobs today" << std::endl;
                    return 0;                                       // avslutter program med en gang

                }
                if(nyttValg != 5){                                  // hvis valg fra bruker er 5 (ta rota av et tall) trenger vi bare én variabel fra bruker, derfor skipper vi denne
                    std::cout << "New number:" << std::endl;
                    input_sjekk(b);                                 // henter input for b fra bruker
                }
                a = sum;

                switch(nyttValg){ // samme funksjoner i casene som i kalkis 1.0

                    case 1:
                        std::cout << a << " + " << b << " = " << CalcMe::add(a, b) << std::endl;
                        break;

                    case 2:
                        std::cout << a << " - " << b << " = " << CalcMe::substract(a, b) << std::endl;
                        break;

                    case 3:
                        std::cout << a << " x " << b << " = " << CalcMe::multiply(a, b) << std::endl;
                        break;

                    case 4:
                        if (b != 0) {
                            std::cout << a << " / " << b << " = " << CalcMe::divide(a, b) << std::endl;
                            break;
                        } else {
                            std::cout << "Cannot divide by zero! Let's go back to the menu:\n" << std::endl;
                            continue;
                        }

                    case 5:
                        std::cout << "Rota av " << a << " er " << CalcMe::root(a) << std::endl;
                        break;

                    default:
                        std::cout << "Ugyldig verdi, please try again" << std::endl;
                        break;

                }
                std::cout << "En gang til? (y/n)" << std::endl;     // spør bruker om vi skal gjøre en ny operasjon
                YesNo(fortsette);                                   // henter input fra bruker, ja eller nei

                if(fortsette == 'n' || fortsette == 'N'){           // hvis bruker svarer nei, så avslutter vi her
                    std::cout << "Ok, good bye then!" << std::endl; // hadeee
                    std::cout << "You did " << counter.size() << " kalkis-jobs today" << std::endl; // printer antall utregninger gjort siden oppstart av programmet
                    return 0;                                 // kalkis out, vi avslutter programmet
                }
            }
        }
    }
    return 0;
}
