#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

class BigDecimal {
public:
    BigDecimal(double value) : value(value) {}

    double toDouble() const {
        return value;
    }

    // You need to implement the setScale function based on your needs.
    // I'll provide a simple implementation that rounds to the specified number of decimal places.
    BigDecimal setScale(int places) const {
        double multiplier = pow(10.0, places);
        double scaledValue = round(value * multiplier) / multiplier;
        return BigDecimal(scaledValue);
    }

private:
    double value;
};

static map<string, double> parm;
static vector<string> printBill;

double round(double value, int places) {
    if (places < 0) {
        throw invalid_argument("places must be non-negative");
    }

    BigDecimal bd(value);
    bd = bd.setScale(places);
    return bd.toDouble();
}

string getKeyFromValue(const map<string, double>& hm, double value) {
    for (const auto& pair : hm) {
        if (pair.second == value) {
            return pair.first;
        }
    }
    return "";
}

void findPath(map<string, double>& details) {
    printBill.clear();

    double maxValue = max_element(details.begin(), details.end(),
        [](const auto& pair1, const auto& pair2) {
            return pair1.second < pair2.second;
        })->second;

    double minValue = min_element(details.begin(), details.end(),
        [](const auto& pair1, const auto& pair2) {
            return pair1.second < pair2.second;
        })->second;

    if (maxValue != minValue) {
        string maxKey = getKeyFromValue(details, maxValue);
        string minKey = getKeyFromValue(details, minValue);
        double result = maxValue + minValue;
        result = round(result, 1);

        if (result >= 0.0) {
            cout << minKey << " needs to pay " << maxKey << ":" << round(abs(minValue), 2) << endl;
            details.erase(maxKey);
            details.erase(minKey);
            details[maxKey] = result;
            details[minKey] = 0.0;
        }
        else {
            cout << minKey << " needs to pay " << maxKey << ":" << round(abs(maxValue), 2) << endl;
            details.erase(maxKey);
            details.erase(minKey);
            details[maxKey] = 0.0;
            details[minKey] = result;
        }

        findPath(details);
    }
}

int main() {
    parm["A"] = -5.0;
    parm["B"] = 25.0;
    parm["C"] = -20.0;
    parm["D"] = 25.0;
    parm["E"] = -20.0;
    parm["F"] = -5.0;

    findPath(parm);

    return 0;
}
