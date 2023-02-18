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

Time::Time()
{
    showInterval = -ONE;
    totalTime = -ONE;
    while (showInterval <= 0) {
        cout << "输出时间间隔 (s):" << endl;
        cin >> showInterval;
    }
    while (totalTime <= 0) {
        cout << "模拟时长 (s):" << endl;
        cin >> totalTime;
    }
}
