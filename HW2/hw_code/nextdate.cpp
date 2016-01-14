#include "nextdate.h"

string int2str(int &i) {
    string s;
    stringstream ss(s);
    ss << i;

    return ss.str();
}

string nextdate(int year, int month, int day) {
    if(year < 1812 || year > 2012 || month < 1 || month > 12 || day < 1 || day > 31) {
        return "INVALID_INPUT";
    }
    else if(year == 2012 && month == 12 && day == 31) {
        return "OVER_MAX_YEAR";
    }
    else if(month == 2) {
        if(year % 4 == 0 && day > 29) {
            return "INVALID_INPUT";
        }
        else if(year % 4 != 0 && day > 28){
            return "INVALID_INPUT";
        }
        else if((year % 4 == 0 && day == 29) || (year % 4 != 0 && day == 28)) {
            month += 1;
            day = 1;
        }
        else {
            day += 1;
        }
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11) {
        if(day > 30) {
            return "INVALID_INPUT";
        }
        else if(day == 30) {
            month += 1;
            day = 1;
        }
        else {
            day += 1;
        }
    }
    else {
        if(day == 31) {
            if(month == 12) {
                month = 1;
                year += 1;
            }
            else {
                month += 1;
            }
            day = 1;
        }
        else {
            day += 1;
        }
    }
    return int2str(year) + "/" + int2str(month) + "/" + int2str(day);
}   
