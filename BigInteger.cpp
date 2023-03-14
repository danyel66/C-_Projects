//
// Onyeka Daniel Nduka.
//
#include <iostream>
#include <vector>
using namespace std;

void displayDecimalDigit(vector<int> a);
vector<int> toDigit(string s);
int valueOf(char ch);
vector<int> trimLeadingZeros(vector<int> a);
vector<int> addLeadingZeros(vector<int> a, int zeroCount);
vector<int> normalize(vector<int> v, int base);
vector<int> add(vector<int> v1, vector<int> v2);

int main(int argc, char* argv []){
    cout << "Welcome to BigInteger Version 1." << endl;
    string bigInteger1;
    string bigInteger2;

    if (argc > 1)
        bigInteger1 = argv[1];
    if (argc > 2)
        bigInteger2 = argv[2];

    if (bigInteger1.empty()){
        cout << "Please enter a big integer: ";
        getline(cin, bigInteger1);
        cout << "Please enter another big integer: ";
        getline(cin, bigInteger2);
    } else if (bigInteger2.empty()){
        cout << "Please enter another big integer: ";
        getline(cin, bigInteger2);
    }
    cout << endl << "The sum is: ";
    displayDecimalDigit(add(toDigit(bigInteger1), toDigit(bigInteger2)));
    cout << endl << "Thank you for playing BigInteger!" << endl;
    return 0;
}

void displayDecimalDigit(vector<int> a){
    for (unsigned int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

vector<int> toDigit(string s){
    vector<int> res(s.length());
    for (unsigned int i = 0; i < s.length(); ++i) {
        res[i] = valueOf(s[i]);
    }

    return res;
}

int valueOf(char ch){
    if (ch >= '0' && ch <= '9') {
        return ch - '0';
    } else if (ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 10;
    } else if (ch >= 'a' && ch <= 'z') {
        return ch - 'a' + 10;
    } else {
        // Handle invalid input
        return -1;
    }
}

vector<int> trimLeadingZeros(vector<int> a){
    int count = 0;
    for (unsigned int i = 0; i < a.size(); i++) {
        if (a[i] == 0){
            count++;
        } else {
            break;
        }
    }
    if (count == 0)
        return a;
    vector<int> result;
    if (count == a.size()){
        result.push_back(0);
        return result;
    }

    for (int i = count; i < a.size(); i++) {
        result.push_back(a[i]);
    }
    return result;
}

vector<int> addLeadingZeros(vector<int> a, int zeroCount){
    vector<int> result(a.size() + zeroCount);
    for (unsigned int i = 0; i <= zeroCount; i++) {
        result[i] = 0;
    }

    for (unsigned int i = 0, j = zeroCount; i < a.size(); i++, j++) {
        result[j] = a[i];
    }
    return result;
}

vector<int> normalize(vector<int> v, int base = 10){
    vector<int> result = v;
    result = addLeadingZeros(result, 1);
    for (int i = result.size() - 1; i >= 0; --i) {
        while (result[i] >= base) {
            result[i] -= base;
            result[i - 1] += 1;
        }
    }
    return trimLeadingZeros(result);
}

vector<int> add(vector<int> v1, vector<int> v2){
    vector<int> result;
    vector<int> smallerV;
    if (v1.size() >= v2.size()) {
        result = v1;
        smallerV = addLeadingZeros(v2, v1.size() - v2.size());
    }
    else {
        result = v2;
        smallerV = addLeadingZeros(v1, v2.size() - v1.size());
    }
    for (unsigned int i = 0; i < result.size(); i++) {
        result[i] += smallerV[i];
    }
    return normalize(result);
}
