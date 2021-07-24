#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "../cmdline.h"
using namespace std;


void rec(string &seqid, vector<string> &seq) {
    cout << seqid << endl;
    vector<string>::reverse_iterator it;
    string::reverse_iterator i;
    char x;
    for(it = seq.rbegin(); it != seq.rend(); it++) {
        for(i = (*it).rbegin(); i != (*it).rend(); i++) {
            switch(*i){
                case 'a':
                    x='t';
                    break;
                case 'A':
                    x = 'T';
                    break;
                case 't':
                    x = 'a';
                    break;
                case 'T':
                    x = 'A';
                    break;
                case 'c':
                    x = 'g';
                    break;
                case 'C':
                    x = 'G';
                    break;
                case 'g':
                    x = 'c';
                    break;
                case 'G':
                    x = 'C';
                    break;
                default:
                    x = *i;
            }
            cout << x;
        }
    }
    cout << endl;
}


int main(int argc, char *argv[]) {
    cmdline::parser arg;
    arg.footer("file");
    arg.parse_check(argc, argv);
    auto parg = arg.rest();

    bool isfile = false;
    ifstream input;
    if(parg.size() > 0 and parg[0] != "-") {
        input.open(parg[0]);
        isfile = true;
    }

    vector<string> seq;
    string seqid, line;
    while(isfile?getline(input, line):getline(cin, line)) {
        if(line[0] == '>') {
            if(seq.size() > 0)
                rec(seqid, seq);
            seqid = line;
            seq.clear();
        } else {
            seq.push_back(line);
        }
    }
    if(seq.size() > 0)
        rec(seqid, seq);

    return 0;
}

