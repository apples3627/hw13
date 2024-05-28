#include <iostream>
//#include <Windows.h> for Win (Sleep)
#include <unistd.h> //for Mac (sleep 소문자로)
#include <vector>
#include <fstream>
using namespace std;
class Queue {
public:
    int NI, NO, capacity;
    vector<int> queue;
    int lostPackets;
    string quename;
    Queue(int x, int y, int z, const string &n) : NI(x), NO(y), capacity(z), lostPackets(0), quename(n){}
    void xx(int elapsedTime, int T, ofstream &dataFile) {
        for (int elapsedSeconds = 0; elapsedSeconds < elapsedTime; elapsedSeconds += T) {
            usleep(T * 1000);
            int ni = rand() % NI;
            int no = rand() % NO;
            if (capacity < queue.size() + ni) {
                lostPackets += queue.size() + ni - capacity;
                ni = capacity - queue.size();
            }
            for (int i = 0; i < ni; i++) {
                queue.push_back(rand() % 20);
            }
            for (int i = 0; i < no; i++) {
                if (!queue.empty()) {
                    queue.erase(queue.begin());
                }
            }
            dataFile << elapsedSeconds+1 << " " << queue.size() << " " << lostPackets << endl;
        }
    }
};
int main() {
    int elapsedTime = 120;
    int T =1;
    int tempNI = 200,tempCap = 100;
    int NO =100;
    ofstream dataf("datae.txt");
    int que = 6; 
    vector<string> quename1(que); 
    for (int i = 0; i < que; ++i) {
        string name = "Queue" + to_string(i + 1); 
        Queue q(tempNI, NO, tempCap, quename1[i]); 
        dataf << name << " NO: " << NO << endl;
        q.xx(elapsedTime, T, dataf);
        dataf << endl;
    }   
    dataf.close();
    cout << "----" << endl;
    return 0;
}

