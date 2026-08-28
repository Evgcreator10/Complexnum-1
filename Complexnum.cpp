#include <iostream>
#include "Cmpx.h"
#include "SignEmulator.h"
#include "Filtration.h"

using namespace std;

int main() {
    float f_disc = 1200.0f;
    SignEmulator emulator(f_disc);

    int id1 = emulator.AddSignal(100.0f, 50.0f, 30.0f);
    int id2 = emulator.AddSignal(50.0f, 50.0f, 60.0f);
    int id3 = emulator.AddSignal(20.0f);

    float T_h = 0.02f;
    int k = 24;

    cout << "RMS values:" << endl;
    cout << "Signal 1 RMS: " << Filtration::CalculateRMS(emulator, id1, k, T_h, f_disc) << endl;
    cout << "Signal 2 RMS: " << Filtration::CalculateRMS(emulator, id2, k, T_h, f_disc) << endl;
    cout << "Signal 3 RMS: " << Filtration::CalculateRMS(emulator, id3, k, T_h, f_disc) << endl;

    cout << "\nFourier harmonics for Signal 1:" << endl;
    Cmpx h1 = Filtration::CalculateFourier(emulator, id1, k, 1, T_h, f_disc);
    Cmpx h2 = Filtration::CalculateFourier(emulator, id1, k, 2, T_h, f_disc);

    cout << "1st Harmonic -> Real: " << h1.Real() << ", Imag: " << h1.Imag() << endl;
    cout << "2nd Harmonic -> Real: " << h2.Real() << ", Imag: " << h2.Imag() << endl;

    return 0;
}
