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
    
    Cmpx(float r) {
        real = r;
        mnim = 0;
    }    
    Cmpx(const Cmpx& obj) {
        real = obj.real;
        mnim = obj.mnim;
    }
    void SetPolar(float rasst, float ugol) {
        real = rasst * cos(ugol);
        mnim = rasst * sin(ugol);
    }


    float Real() {
        return real;
    }
    float Imag() {
        return mnim;
    }
    float Abs() {
        return sqrt(real * real + mnim * mnim);
    }
    float Angle() {
        return atan2(mnim, real);
    }

    float AngleDeg() {
        return atan2(mnim, real) * 180.0f / 3.14159265f;
    }

 
    void OrtPart(int n) {
        cout << fixed << setprecision(n) << real;
        if (mnim >= 0) cout << "+" << mnim << "i";
        else cout << mnim << "i";
    }
        void PolPartDeg(int n) {
        cout << fixed << setprecision(n) << Abs() << " / " << AngleDeg() << "°";
    }

    // 5 пункт 1-ого задания
    Cmpx operator+(Cmpx other) {
        return Cmpx(real + other.real, mnim + other.mnim);
    }
    Cmpx operator-(Cmpx other) {
        return Cmpx(real - other.real, mnim - other.mnim);
    }
    Cmpx operator*(Cmpx other) {
        float r = real * other.real - mnim * other.mnim;
        float m = real * other.mnim + mnim * other.real;
        return Cmpx(r, m);
    }
    Cmpx operator/(Cmpx other) {
        float denom = other.real * other.real + other.mnim * other.mnim;
        float r = (real * other.real + mnim * other.mnim) / denom;
        float m = (mnim * other.real - real * other.mnim) / denom;
        return Cmpx(r, m);
    }
    void Turn(float ugol) {
        float rasst = Abs();
        float currentUgol = Angle();
        real = rasst * cos(currentUgol + ugol);
        mnim = rasst * sin(currentUgol + ugol);
    }
};