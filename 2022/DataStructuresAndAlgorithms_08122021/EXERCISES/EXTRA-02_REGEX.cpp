#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <thread>
#include <ctime>
 
#include <regex>
 
void PrintMatches(std::string str,
        std::regex reg){
    
    // Used when your searching a string
    std::smatch matches;
       
    // Determines if there is a match and match 
    // results are returned in matches
    while(std::regex_search(str, matches, reg)){
        // Number of matches
        std::cout<<"Number of matches: "<<matches.size()<<std::endl;

        // Get the first match
        std::cout << matches.str(1) << "\n";
        
        // Eliminate the previous match and create
        // a new string to search
        str = matches.suffix().str();
    }
    // std::cout << "\n";
}

void printMatchesIt(std::string str, std::regex reg) {
    std::sregex_iterator currentMatch (str.begin(), str.end(), reg);
    std::sregex_iterator last_match;
    while (currentMatch != last_match) {
        std::smatch match = *currentMatch;
        std::cout<<"match: "<<match.str()<<std::endl;
        currentMatch++;
    }
    // std::cout<<std::endl;

}

int main() {
    // Thumb rules
    // [ ]   : Match what is in the brackets
    // [^ ]  : Match anything not in the brackets
    // ( )   : Return surrounded submatch
    // .     : Match any 1 character or space
    // +     : Match 1 or more of what proceeds
    // ?     : Match 0 or 1
    // *     : Match 0 or More
    // *?    : Lazy match the smallest match
    // \b    : Word boundary
    // ^     : Beginning of String
    // $     : End of String
    // \n    : Newline
    // \d    : Any 1 number
    // \D    : Anything but a number
    // \w    : Same as [a-zA-Z0-9_]
    // \W    : Same as [^a-zA-Z0-9_]
    // \s    : Same as [\f\n\r\t\v]
    // \S    : Same as [^\f\n\r\t\v]
    // {5}   : Match 5 of what proceeds the curly brackets
    // {5,7} : Match values that are between 5 and 7 in length

    /* MATCH ZERO OR ONE ITEM */
    // std::string str1 {"cat cats"};
    // std::regex reg1 ("([cat]+s?)"); // [cat]    Matches 'cat' 
    //                                 // +s       Matches 'cats'
    //                                 // ?        Says it can be one or another
    // printMatchesIt(str1, reg1);

    /* MATCH ZERO OR MORE ITEMS */
    // std::string str2 {"doctor doctors doctor's"};
    // std::regex reg2("([doctor]+['s]*)"); // [doctor]    Matches 'doctor'
    //                                      // +['s]       Matches ''s' (separately or both)
    //                                      // *           Says it can be any of those matches (doctor doctors doctor's)
    // printMatchesIt(str2, reg2);

    /* REPLACE */
    // std::string str3 {"Just some words\nand some more\r\nand more"};
    // std::cout<<str3<<std::endl; 
    // std::regex reg3 ("[\r]?\n"); //   
    //                              //
    // std::string line = std::regex_replace(str3, reg3, " "); // Will replace '\n' for a white space
    // std::cout<<line<<std::endl;

    /* LAZY AND GREEDY */
    // std::string str4 = "<name> Life On Mars </name>"
    //                    "<name> Freaks and Geeks </name>";
    // std::regex reg4 ("<name>(.*?)</name>"); // Will grab what is in between <name></name>
    // PrintMatches(str4, reg4);

    /* WORD BOUNDARIES */
    // std::string str5 {"Parcela par Parcial paraíso"};
    // std::regex reg5 ("(\\bpar\\b)"); // Match 'par'
    // printMatchesIt(str5, reg5);
    //---------------------
    // std::string str6 {"parei parque topar"};
    // std::regex reg6 ("(\\bpar[a-z]+)"); // Match 'parei' and 'parque'
    // printMatchesIt(str6, reg6);
    //---------------------
    // std::string str6 {"parodiado escapar equipar parasitar"};
    // std::regex reg6 ("([a-z]+par\\b)"); // Match 'escapar' and 'equipar'
    // printMatchesIt(str6, reg6);
    //---------------------
    // std::string str6 {"limpar aparto aparta"};
    // std::regex reg6 ("(\\b[a-z]+par[a-z.]+\\b)"); // Match 'aparto' and 'aparta'
    // printMatchesIt(str6, reg6);

    /* STRING BOUNDARIES */
    // std::string str7 {"Match everything up to @"};
    // std::regex reg7("(^.*[^@])"); // ^  -> Refer to line begin
    //                               // .  -> Any character
    //                               // *  -> Up to the end of the line
    //                               // [^@]   -> Except for @ 
    // printMatchesIt(str7, reg7);
    //---------------------
    // std::string str8 {"@ Get this string"};
    // std::regex reg8 ("[^@\\s].*$");  // [^@\\s]  -> Ignore '@' and space ' '(\\s)
    //                                  // .*$  -> get any character (.) until (*) end of line ($)
    // printMatchesIt(str8, reg8);

    /* EXCLUDE SPECIFIC PART */
    // std::string str10 = "206-709-3100 202-456-1111 212-832-2000";
    // std::regex reg10 (".{3}-(.{8})");  // .         -> get something
    //                                    // {3}       -> which is 3 in length
    //                                    // -         -> has a dash
    //                                    // (.{8})    -> and, in parenthesis, what I specifically want to grab, which is 8 in length
    // PrintMatches(str10, reg10);


    /* USING OR (|) OPERATOR IN REGEX */
    std::string str11 {"[ 4.5000] event foo.qux START"};
    // Use parenthesis '()' to print calling function PrintMatches
    std::regex reg11 ("(\\d{1,7}.\\d{1,7}|foo.[a-z]+|[A-Z]+)");  // \\d{1,7}.\\d{1,7}  -> Get digit [1-9] with size 1 to 7 followed by a dot (.)
    //                                                            //                       and by another by another digit [1-9] with size 1 to 7
    //                                                            // foo.[a-z]+    -> Get 'foo.', followed by a string [a-z]
    //                                                            // [A-Z]+    -> Get string [A-Z]
    /* Same output, but different implementation */
    // std::regex reg11 ("\\d{1,7}.\\d{1,7}|[a-z.]{4}[a-z]{3}|[A-Z]+");  // \\d{1,7}.\\d{1,7}  -> Get digit [1-9] with size 1 to 7 followed by a dot (.)
                                                                      //                       and by another by another digit [1-9] with size 1 to 7
                                                                      //[a-z.]{4}[a-z]{3}   -> Get string ranging from a to z (including if has dot) of size 4,
                                                                      //                       followed by a string of size 3 
    PrintMatches(str11, reg11);
    // printMatchesIt(str11, reg11);

    return 0;
}