#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Cmpx {
private:
    float real;
    float mnim;

public:
    Cmpx() {
        real = 0;
        mnim = 0;
    }
    Cmpx(float r, float m) {
        real = r;
        mnim = m;
    }
  /* Cmpx(float rasst, float f) {
        real = rasst * cos(f);
        mnim = rasst * sin(f);
    }*/
    Cmpx(const Cmpx& obj) {
        real = obj.real;
        mnim = obj.mnim;
    }

    float Real() { return real; }
    float Imag() { return mnim; }
    float Abs() { return sqrt(real * real + mnim * mnim); }
    float Angle() { return atan2(mnim, real); }
    float BackUgol_Deg() { return atan2(mnim, real) * (float)180 / 3.14159265; }

    void OrtPart(int n) {
        cout << fixed << setprecision(n) << real << "+" << mnim << "i";
    }
    void PolPart_Rad(int n) {
        cout << fixed << setprecision(n) << Abs() << " * (cos(" << Angle() << ") + i*sin(" << Angle() << "))";
    }
    void PolPart_Deg(int n) {
        cout << fixed << setprecision(n) << Abs() << " * (cos(" << BackUgol_Deg() << ") + i*sin(" << BackUgol_Deg() << "))";
    }
};