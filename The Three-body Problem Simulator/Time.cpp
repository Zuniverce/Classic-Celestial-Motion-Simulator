#include "Time.h"
double Time::minute(double M) {
    return M * MINUTETOSECOND;
}
double Time::hour(double H) {
    return H * minute(HOURTOMINUTE);
}
double Time::day(double D) {
    return D * hour(DAYTOHOUR);
}
void Time::setShowInterval() {
    cout << "输出时间间隔(s)" << endl;
    cin >> showInterval;
}
