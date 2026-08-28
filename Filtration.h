#pragma once
#include <cmath>
#include "SignEmulator.h"
#include "Cmpx.h"


class Filtration final {
private:
    Filtration() = delete;


public:
    static float CalculateRMS(SignEmulator& emulator, int index, int k, float T_h, float f_disc) {
        int N = (int)(T_h * f_disc);
        if (N <= 0) return 0.0f;

        float sumSquares = 0.0f;
        for (int n = 0; n < N; n++) {
            float x = emulator.GetSample(index, k - n);
            sumSquares += x * x;
        }

        return sqrt(sumSquares / (float)N);
    }

    static Cmpx CalculateFourier(SignEmulator& emulator, int index, int k, int harmonic_k, float T_h, float f_disc) {
        int N = (int)(T_h * f_disc);
        if (N <= 0) return Cmpx(0, 0);

        float realSum = 0.0f;
        float imagSum = 0.0f;
        float pi = 3.14159265f;
        float tau = 1.0f / f_disc;
        float omega = 2.0f * pi * 50.0f;


        for (int n = 0; n < N; n++) {
            int current_k = k - n;
            float x = emulator.GetSample(index, current_k);

            float angle = omega * (float)harmonic_k * tau * (float)current_k;

            realSum += x * cos(angle);
            imagSum += x * (-sin(angle));
        }

        float coef = 2.0f / (float)N;
        return Cmpx(realSum * coef, imagSum * coef);
    }
};