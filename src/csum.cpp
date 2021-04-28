#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "cmdline.h"
using namespace std;

bool str2double(const string &s, double &d) {
    try {
        d = stod(s);
        return true;
    }catch(invalid_argument) {
        return false;
    }
}

int main(int argc, char *argv[]) {
    cmdline::parser arg;
    arg.add<int>("skiprows", 'k', "skip rows num", false, 0);
    arg.add<int>("col", 'c', "columns index", false, 0);
    arg.footer("file");
    arg.parse_check(argc, argv);
    auto parg = arg.rest();

    bool isfile = false;
    ifstream input;
    if(parg.size() > 0 and parg[0] != "-") {
        input.open(parg[0]);
        isfile = true;
    }

    string line, field;
    int i, ln = 0;
    double v, sums = 0;
    while(isfile?getline(input, line):getline(cin, line)) {
        ++ln;
        if(ln <= arg.get<int>("skiprows")) continue;
        istringstream sin(line);
        i = 0;
        while(getline(sin, field, '\t')){
            if(++i == arg.get<int>("col")) {
                if(str2double(field, v)) sums += v;
                break;
            }
        }
    }

    cout << sums << endl;

    return 0;
}
