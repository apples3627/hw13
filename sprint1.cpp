#include <iostream>
//#include <Windows.h> for Win (Sleep)
#include <unistd.h> //for Mac (sleep 소문자로)
using namespace std;
int main() {
    int elapsedSeconds = 0,x, T = 1;
    cout << " RANDMAX " << RAND_MAX << endl;
    while (elapsedSeconds < 18) {
        sleep(T * 1000);
        x = rand() % 100;
        elapsedSeconds += T;
        cout << " Elapsed time[sec] = " << elapsedSeconds << " " << x << endl;
    }
    return 0;
}
