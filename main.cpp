/* PA5 - CSCE 221 - Dr. Leyk
Program will:
1. Read lines from input.csv
2. Parse line using regex and store in HashTable
3. Read lines from roster.csv
4. Parse line with regex
5. Look up grade in HastTable
6. Write result in output string
7. Create and save output csv
 
4/5/2017
*/

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <sstream>
#include "Node.h"
using namespace std;

int main() {
    ifstream fileIn("input.csv");
    string line;
    
    while (getline(fileIn, line)) {
        // get uin for key of hashtable
        regex uinPat{R"(8\d{8})"};  // pattern = 9 digit uin starting with 8
        smatch uinMatch;
        regex_search(line, uinMatch, uinPat);
        int uin = stoi(uinMatch[0]);

        // get grade for value in hashtable
        regex gradePat{R"((?:\d+,)(\d{3}|\d{2}))"};  // pattern = 2 or 3 digits after "*********," <- UIN
        smatch gradeMatch;
        regex_search(line, gradeMatch, gradePat);
        int grade = stoi(gradeMatch[1]);
        
        //cout << uin << " - " << grade << endl;
        Node node(uin, grade);
        cout << node.getUin()%100 << endl;
    }
    return 0;
}
