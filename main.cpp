#include <iostream>
#include <random>
#include <thread>
#include <chrono>
#include <ctime>

using namespace std;

class Data {
public:
    string name;
    string last_name;
    string position;
    string number;
    int Pulse;
    double Alcohol;
    float Temperature;
    int Upper_Blood_Pressure;
    int Lower_Blood_Pressure;
    float blood_Saturation;

    void Update_Data() {
        srand(time(NULL));
        Pulse = rand() % 90 + 60;
        Alcohol = rand() / 100000.0;
        Temperature = (rand() % 30 + 350) / 10.0;
        Upper_Blood_Pressure = rand() % 50 + 100;
        Lower_Blood_Pressure = Upper_Blood_Pressure - (rand() % 9) - 40;
        blood_Saturation = rand() % 8 + 92;
    }

    void Emergency (){
        system("color 70");
        cout << "!!!Emergency caught!!!" << endl;
        if (Temperature > 37.5) { cout << "Temperature is: " <<  Temperature << endl; }
        if (Pulse > 120) { cout << "Pulse is: " <<  Pulse << endl; }
        if (blood_Saturation < 95) { cout << "Blood Saturation is: " <<  blood_Saturation << endl; }
        cout << "_______________________________________" << endl;
    }

    void Output (){
        cout << name << endl
            << last_name << endl
            << position << endl
            << number << endl << endl
             << "Pulse is: " << Pulse << endl
             //<< "Alcohol in milliliters is: " << Alcohol << endl
             << "Temperature is: " << Temperature << endl
             << "blood pressure is: " << Upper_Blood_Pressure
             << "/"
             << Lower_Blood_Pressure << endl
             << "Blood saturation is: " << blood_Saturation << endl
             << "_______________________________________" << endl;
    }

};