#include "oblig2_mbb.h"

int main()
{
    // Kjører print på alle funksjoner i terminal://

    // SQUARE //
    square mySquare(5, square::Color::PINK);    // Lager et kvadrat med lengde 5 og fargen PINK
    mySquare.print();                           // printer ut info om dette kvadratet
    mySquare * 2;                               // skalerer kvadraten med en faktor på 2

    // TRIANGLE //
    triangle myTriangle(5, 4, triangle::Color::GREEN); // lager en grønn trekant med katet 5 og 2
    myTriangle.print();                         // printer ut info om trekanten
    myTriangle * 3;                             // skalerer verdier i trekant med faktor på 3

    // CIRCLE //
    circle myCircle(2, circle::Color::YELLOW);  // lager en gul sirkel med radius 2
    myCircle.print();                           // printer ut info om denne sirkelen
    myCircle * 4;                               // skalerer sirkel med faktor på 4, og når dette skjer vil den printe de nye verdiene

    return 0;
}
