#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "cmdline.h"
using namespace std;


int main(int argc, char *argv[]) {
    cmdline::parser arg;
//    arg.add<string>("file", '\0', "", false, "");
    arg.footer("file");
    arg.parse_check(argc, argv);
    auto parg = arg.rest();

    vector<vector<string>> data;
    int nrow = 0, ncol = 0;
    string line, field;
    bool isfile = false;
    ifstream input;
    if(parg.size() >= 1 && parg[0] != "-") {
        input.open(parg[0]);
        isfile = true;
    }

    while(isfile?getline(input, line):getline(cin, line)) {
      ++nrow;
      istringstream sin(line);
      vector<string> fields;
      while(getline(sin, field, '\t')) {
        fields.push_back(field);
      }
      data.push_back(fields);
      if(nrow == 1) ncol = fields.size();
    }
    input.close();

    int i, j;
    for(i = 0; i < ncol; i++) {
        for(j = 0; j < nrow; j++) {
            cout << data[j][i];
           if(j < nrow - 1) cout << "\t";
        }
        cout << endl;
    }

    return 0;
}
