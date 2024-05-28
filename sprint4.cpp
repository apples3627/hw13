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
    Queue(int x, int y, int z) : NI(x), NO(y), capacity(z), lostPackets(0) {}
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
    //위쪽 값 수정해서 excel 그래프
    ofstream dataf("data4.txt");
    for (int NO = 50; NO <= 150; NO += 50) { //NO값 변화 50 100 150
        Queue q(tempNI, NO, tempCap);
        dataf << "NO: " << NO << endl;
        q.xx(elapsedTime, T, dataf);
        dataf << endl;
    }
    dataf.close();
    cout << "----" << endl;
    return 0;
}