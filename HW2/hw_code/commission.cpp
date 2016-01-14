#include "commission.h"

string float2str(float &i) {
    string s;
    stringstream ss(s);
    ss << i;

    string result = ss.str();
    if(result.find(".") == std::string::npos) {
        result += ".0";
    }
    return result;
}

string commission(int locks, int stocks, int barrels) {
    if(locks == -1) {
        return "STOP_PROGRAM";
    }
    else if(locks < 1 || locks > 70 || stocks < 1 || stocks > 80 || barrels < 1 || barrels > 90) {
        return "INVALID_INPUT";
    }
    else {
        float totalsales = locks*45 + stocks*30 + barrels*25;
        float commission = 0.0;
        if(totalsales >= 1800.0) {
            commission = 0.1 * 1000.0 + 0.15 * 800.0;
            commission += 0.2 * (totalsales - 1800.0);
        }
        else if(totalsales >= 1000.0) {
            commission = 0.1 * 1000.0;
            commission += 0.15 * (totalsales - 1000.0);
        }
        else {
            commission = 0.1 * totalsales;
        }
        return float2str(commission);
    }
}
