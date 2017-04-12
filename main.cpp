/* PA5 - CSCE 221 - Dr. Leyk
Program will:
1. Read lines from input.csv
2. Parse line using regex and store in Hashtable
3. Read lines from roster.csv
4. Parse line with regex
5. Look up grade in Hashtable
6. Write result in output string
7. Create and save output.csv
 
4/5/2017
*/

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include "Hashtable.h"

using namespace std;


int main() {
    ifstream fileIn("input.csv");
    ofstream fileOut("output.csv");
    string line;
    Hashtable h1;
    
    while (getline(fileIn, line)) {  // parses input from input.csv and inputs all data to hashtable
        // get uin for key of hashtable
        regex uinPat{R"(8\d{8})"};  // pattern = 9 digit uin starting with 8
        smatch uinMatch;
        regex_search(line, uinMatch, uinPat);
        int uin = stoi(uinMatch[0]);

        // get grade for value in hashtable
        // pattern = 2 or 3 digits after "*********," <- UIN
        regex gradePat{R"((?:\d+,)(\d{3}|\d{2}))"};  
        smatch gradeMatch;
        regex_search(line, gradeMatch, gradePat);
        int grade = stoi(gradeMatch[1]);
        
        //  inserts all students to hashtable
        h1.insert(uin, grade);
    }
    
    h1.hashStats();  // output hash table stats
    
    ifstream fileIn2("roster.csv");
    string line2;
    
    while (getline(fileIn2, line2)) {  // parses data from roster.csv and writes to output.csv
        regex uinPat{R"(8\d{8})"};  // pattern = 9 digit uin starting with 8
        smatch uinMatch2;
        regex_search(line2, uinMatch2, uinPat);
        int uin = stoi(uinMatch2[0]);
        
        int grade = h1.search(uin);  // get the grade matching the uin on the current line
        //cout << uin << " - " << grade << endl;
        
        regex nameEmailUin{R"(.+,.+,8\d{8})"};  // pattern = name, email, uin
        smatch nameEmailUinMatch;
        regex_search(line2, nameEmailUinMatch, nameEmailUin);
        
        if (grade == 0) {  // when uin is not found in hashtable 0 is returned for the grade
            fileOut << nameEmailUinMatch[0] << "\n";  // output what was in roster
        } else {
            fileOut << nameEmailUinMatch[0] << "," << grade << "\n";  // output info with grade
        }
    }
    
    
    
    return 0;
}



