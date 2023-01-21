#include "Time.h"

const int Time::DAYTOHOUR = 12;
const int Time::HOURTOMINUTE = 60;
const int Time::MINUTETOSECOND = 60;

int Time::minute(int M)
{
    int second = M;
    second *= MINUTETOSECOND;
    return second;
}

int Time::hour(int H)
{
    int second = H;
    second *= minute(HOURTOMINUTE);
    return second;
}

int Time::day(int D)
{
    int second = D;
    second *= hour(DAYTOHOUR);
    return second;
}
