#ifndef OBLIG2_MBB_H
#define OBLIG2_MBB_H
#include <string>



class BaseShape2D {
public:
    virtual double area() = 0;              // alle barneklasser skal ha utregning av areal
    virtual double circumference() = 0;     // alle barneklasser skal ha funksjon for omkrets
    virtual void operator*(double rhs) = 0; // ved bruk av operasjon "*" skal vi ha en skaleringsfunksjon

    enum class Color {                      // enum class for farger
        PINK, YELLOW, BLUE, GREEN
    };
    BaseShape2D(Color color) : color(color) {}

protected:
    Color color;
    std::string getColor(Color color) const { // omgjør tallverdi fra enum til fargenavn string
        switch (color) {
        case Color::PINK:   return "PINK";
        case Color::YELLOW: return "YELLOW";
        case Color::BLUE:   return "BLUE";
        case Color::GREEN:  return "GREEN";

        default:            return "UKJENT";
        }
    }
};

class square : public BaseShape2D { // barneklasse til BaseShape2D
public:
    square(double lengde, BaseShape2D::Color color);
    double area() override;
    double circumference() override;
    void operator*(double rhs) override;
    void print();

private:
    double lengde = 0;

};

class circle : public BaseShape2D { // barneklasse til BaseShape2D
public:
    circle(double radius, BaseShape2D::Color color);
    double area() override;
    double circumference() override;
    void operator*(double rhs) override;
    void print();

private:
    double r = 0;
};

class triangle : public BaseShape2D { // barneklasse til BaseShape2D
public:
    triangle(double katet1, double katet2, BaseShape2D::Color color);
    double area() override;
    double circumference() override;
    void operator*(double rhs) override;
    void print();
    double h; // hypotenus

private:
    double k1 = 0, k2 = 0;

};

#endif // OBLIG2_MBB_H
