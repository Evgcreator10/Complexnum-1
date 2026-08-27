#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class SignEmulator {
private:
    float f_disc;
    int type[100];
    float amp[100];
    float freq[100];
    float phase[100];
    int count;


public:
    SignEmulator(float f) {
        f_disc = f;
        count = 0;
    }

    int AddSignal(float a, float f, float p) {
        if (count >= 100) return -1;
        type[count] = 1;
        amp[count] = a;
        freq[count] = f;
        phase[count] = p * 3.14159265f / 180.0f;
        int id = count;
        count++;
        return id;
    }
    int AddSignal(float a) {
        if (count >= 100) return -1;
        type[count] = 2;
        amp[count] = a;
        freq[count] = 0;
        phase[count] = 0;
        int id = count;
        count++;
        return id;
    }

    float GetSample(int Index, int k) {
        if (Index < 0 || Index >= count) return 0.0f;

        if (type[Index] == 2) {
            return amp[Index];
        }

        float omega = 2.0f * 3.14159265f * freq[Index];
        float t = (float)k / f_disc;
        return amp[Index] * sin(omega * t + phase[Index]);
    }
};