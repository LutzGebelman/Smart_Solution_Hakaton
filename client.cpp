#include "main.cpp"

void Yes() {
    Data Vladimir;
    srand(time(NULL));
    system("color 70");
    int i = rand();
    Vladimir.name = "Vladimir";
    Vladimir.last_name = "Vladimirovich";
    Vladimir.number = "#002342";
    Vladimir.position = "Explorer";
    while (true) {
        system("cls");
        Vladimir.Update_Data();
        Vladimir.Output();
        if (Vladimir.Temperature >= 37.5 || Vladimir.Pulse > 120 || Vladimir.blood_Saturation < 95) {
            Vladimir.Emergency();
        }
        this_thread::sleep_for(chrono::seconds(3));
    }
}

int main() {
    thread thread1(Yes);
    thread1.join();
    return 0;
}