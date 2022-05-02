#include <iostream>
#include <string>
#include <regex>

void PrintMatches(std::string str, std::regex reg) {
    std::smatch matches; // create the match object
    std::cout << std::boolalpha; // to print true/false instead of 1/0

    while(std::regex_search(str, matches, reg)) {
        std::cout<<"Is there a match: "<<matches.ready()<<std::endl;
        std::cout<<"Is not there a match: "<<matches.empty()<<std::endl;
        std::cout<<"Number of matches: "<<matches.size()<<std::endl;
        std::cout<<"Matched word: "<<matches.str(1)<<std::endl;
        str = matches.suffix().str();
        
        std::cout<<std::endl;
    }
}

void printMatchesIt(std::string str, std::regex reg) {
    std::sregex_iterator currentMatch (str.begin(), str.end(), reg);
    std::sregex_iterator last_match;
    while (currentMatch != last_match) {
        std::smatch match = *currentMatch;
        std::cout<<match.str()<<std::endl;
        currentMatch++;
    }
    std::cout<<std::endl;

}

int main() {
    // std::string str = "[    0.000000]  event  foo.bar  START";
    // std::regex reg("([0-9.]+)");
    // std::smatch matches;
    // std::regex_search(str, matches, reg);
    // std::cout<<matches.str(1)<<"\n";
    
    //
    // std::string str = "The ape was at the apex apetrecho";
    // std::regex reg("(ape[^ ]?)");
    // PrintMatches(str, reg);

    //
    // std::string str2 = "I picked the pickle";
    // std::regex reg2 ("(pick([^ ]+)?)");
    // printMatchesIt(str2, reg2);

    // Will get 'Cat' and 'fat'
    // std::string str3 = "Cat rat mat fat";
    // std::regex reg3 ("([c-fC-F]at)");
    // printMatchesIt(str3, reg3);

    // Will replace 'Cat' and 'fat' for 'Owl'
    // std::string str4 = "Cat rat mat fat";
    // std::regex reg4 ("([c-fC-F]at)");
    // std::string owlFood = std::regex_replace(str4, reg4, "Owl");
    // std::cout<<owlFood<<std::endl;

    /* MATCH POINTS AND ANY CHARACTER */
    // get F.B.I. and I.R.S.
    // std::string str5 = "F.B.I. I.R.S. CIA";
    // std::regex reg5 ("([^ ]\..\..\.)"); // [^ ] DO NOT MATCH WHITE SPACE
    //                                     // \. MATCH . (POINT) CHARACTER
    //                                     // . MATCH ANY CHARACTER
    // printMatchesIt(str5, reg5);

    /* REGEX REPLACE*/
    // std::string str6 = "This is a\nmultiline string\n"
    //                    "that has many\nlines";
    // std::cout<<str6<<std::endl;
    // std::regex reg6 ("\n"); // Define rule to find only 'new line' character
    // std::string noLBStr = std::regex_replace(str6, reg6, " "); // Will replace '\n' for a white space
    // std::cout<<noLBStr<<std::endl;

    /* MATCH SINGLE NUMBERS */
    // \d = [0-9] -> Any number IN range
    // \D = [^0-9] -> Anything but numbers in range
    // std::string str7 = "12345";
    // std::regex reg7 ("\\d"); // Will match any number in range [0-9]
    // printMatchesIt(str7, reg7);

    // /* MATCH RANGE/SIZE OF NUMBERS */
    // std::string str8 {"1 12 123 1234 12345 123456 1234567"}; 
    // std::regex reg8 ("\\d{5,7}"); // Matches numbers with size from 5 to 7 (if nb bigger than 7 only the digits up to 7 are excerpted)
    // printMatchesIt(str8, reg8);

    /* MATCH ANY SINGLE LETTER OR NUMBER */
    // \w = [a-zA-Z0-9]  -> Any number or letter in range
    // \W = [~a-zA-Z0-9]  -> Anything but letter or number in range
    // std::string str9 {"11-95135-0014"};
    // std::regex reg9("\\w{2}-\\w{5}-\\w{4}");
    // printMatchesIt(str9, reg9);

    /* MATCH SPECIAL CHARACTERS */
    // \s = [\f\n\r\t\v]  -> Any special character in the list
    // \S = [^\f\n\r\t\v]  -> Anything but the special characters in the list
        // \n : New Line
        // \b : Backspace
        // \f : Form Feed
        // \r : Carriage Return
        // \t : Tab
        // \v : Vertical Tab
    // std::string str10  {"Toshio Muramatsu"};
    // std::regex reg10 ("\\w{2,20}\\s\\w{2,20}"); // Matches a word length from 2 to 20
    //                                             // followed by any of the special characters (\f\n\r\t\v)
    //                                             // and another 2 to 20 length word
    // printMatchesIt(str10, reg10);

    /* MATCH 1 OR MORE CHARACTERS */
    // std::string str11 = "a as apes apart bug";  // Matches word beggining with 'a'
    //                                             // followed by letters in range [a-z]
    // std::regex reg11 ("a[a-z]+");
    // printMatchesIt(str11, reg11);

    return 0;
}