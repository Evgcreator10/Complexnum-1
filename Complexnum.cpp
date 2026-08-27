#include <iostream>
#include "Cmpx.h"
#include "SignEmulator.h"

using namespace std;

int main() {
    SignEmulator emulator(1200.0f);

    int id1 = emulator.AddSignal(100.0f, 50.0f, 30.0f);
    int id2 = emulator.AddSignal(50.0f, 50.0f, 60.0f);
    int id3 = emulator.AddSignal(20.0f);
    cout << "Signals added: " << id1 << ", " << id2 << ", " << id3 << endl;

    for (int k = 0; k < 5; k++) {
        cout << "Sample " << k << " for signal 0: " << emulator.GetSample(id1, k) << endl;
    }
    return 0;
}