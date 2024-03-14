#ifndef OBLIG_1_MBB_H
#define OBLIG_1_MBB_H

#include <vector>
extern float sum;
extern std::vector<double> counter;

struct CalcMe {
    static float add(float a, float b);
    static float substract(float a, float b);
    static float multiply(float a, float b);
    static float divide(float a, float b);
    static float root(float a);
};

void input_sjekk(int& input);
void input_sjekk(char& input);
void input_sjekk(float& input);

void YesNo(char& input);


#endif // OBLIG_1_MBB_H
