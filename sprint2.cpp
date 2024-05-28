#include <iostream>
#include <vector>
using namespace std;
int main(void) {
    int NI = 7, NO = 15, ni, no;
    vector <int> q;
    ni = 10;
    for (int i = 0; i < ni; i++) {
        q.push_back(rand() % 20);
        cout << q[q.size() - 1] << " in " << q.size() << endl;
    }
    no = 10;
    for (int i = 0; i < no; i++) {
        int ii = q[0];
        if (q.size() != 0) {
            cout << ii << " out " << q.size() << endl;
            q.erase(q.begin());
        }
    }
    return 0;
}