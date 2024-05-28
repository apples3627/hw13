#include <iostream>
//#include <Windows.h> for Win (Sleep)
#include <uNIstd.h> //for Mac (sleep 소문자로)
#include <vector>
#include <fstream>
using namespace std;
int main() {
    int elapsedSeconds =0;
    int T = 1;
    int NI, NO;
    int NofPackets[120];
    vector <int> queue;
    while (elapsedSeconds < 120) {
        usleep(T * 1000);
        int capacity = 100;
        int lost = 0;
        NI = rand() % 100;
        NO = rand() % 100;
        if (capacity < queue.size() + NI) {
            lost += queue.size() + NI - capacity;
            NI = capacity - queue.size();
        }
        for (int i = 0; i < NI; i++) {
            queue.push_back(rand() % 20);
        }
        for (int i = 0; i < NO; i++) {
            if (queue.size() != 0) {
                queue.erase(queue.begin());
            }
        }
        NofPackets[elapsedSeconds] = queue.size();
        elapsedSeconds += T;
    }
    int max = NofPackets[0];
    int avg = 0;
    ofstream aa("data.txt");
    for (int i = 0; i < 120; i++) {
        aa << i << " " << NofPackets[i] << endl;
        avg += NofPackets[i];
        if (NofPackets[i] > max) {
            max = NofPackets[i];
        }
    }
    avg /= 120;
    aa.close();
    cout << "avg: " << avg << endl;
    cout << "max: " << max << endl;
    return 0;
}
