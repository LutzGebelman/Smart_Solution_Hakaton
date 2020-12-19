#include <iostream>
#include <map>
#include <random>
#include <thread>
#include <chrono>
#include <ctime>

using namespace std;

int random_number(const int& seed){
    srand(seed);
    return rand();
}


struct Data {
        string name;
        int Pulse;
        double Alcohol;
        float Temperature;
        int Upper_Blood_Pressure;
        int Lower_Blood_Pressure;
        float blood_Saturation;
    };

ostream& operator << (ostream& stream, Data& data){
    return stream;
}


void Emergency (const Data& patient){
    cout << "Emergency caught on " << patient.name << endl;
    if (patient.Temperature > 37) { cout << "Temperature is: " <<  patient.Temperature << endl; }
    if (patient.Pulse > 120) { cout << "Pulse is: " <<  patient.Pulse << endl; }
    if (patient.blood_Saturation < 95) { cout << "Blood Saturation is: " <<  patient.blood_Saturation << endl; }
    cout << " _______________________________________________________ " << endl;
}

int main() {
    Data Vladimir;
    vector<int>v {50, 40, 30, 20, 10, 9, 8, 5, 4, 3, 2, 1, 0};
    for (int i : v){
        Vladimir.name = "Vladimir";
        Vladimir.Pulse = random_number(i) % 90 + 60;
        Vladimir.Alcohol = random_number(i) / 100000.0;
        Vladimir.Temperature = (random_number(i) % 30 + 350) / 10.0;
        Vladimir.Upper_Blood_Pressure = random_number(i) % 50 + 100;
        Vladimir.Lower_Blood_Pressure = Vladimir.Upper_Blood_Pressure - (random_number(i) % 9) - 40;
        Vladimir.blood_Saturation = random_number(i) % 8 + 92;


        if (Vladimir.Temperature >= 37 || Vladimir.Pulse > 120 || Vladimir.blood_Saturation < 95){
            Emergency(Vladimir);
        }

        /*cout << Vladimir.name << endl
            << "Pulse is: " << Vladimir.Pulse << endl
             << "Alcohol in milliliters is: " << Vladimir.Alcohol << endl
             << "Temperature is: " << Vladimir.Temperature << endl
             << "Upper blood pressure is: " << Vladimir.Upper_Blood_Pressure << endl
             << "Lower blood pressure is: " << Vladimir.Lower_Blood_Pressure << endl
             << "Blood saturation is: " << Vladimir.blood_Saturation << endl
             << "_______________________________________" << endl;*/
        this_thread::sleep_for(chrono::seconds(1));
    }

    return 0;
}