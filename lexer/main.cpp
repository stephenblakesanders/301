#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <sstream>

using namespace std;
int main(){
    fstream newfile;
    newfile.open("program.gcupl",ios::in); // open a file to perform read operation using file object
    if (newfile.is_open()){   // checking whether the file is open
        string tp;
        string tp2;
        bool operat; // boolean to check if an operator is found
        bool keyword; // boolean to check if an keyword is found
        bool identi; // boolean to check if an identifier is found
        bool endsy; // boolean to check if an end symbol is found
        bool consts; // boolean to check if an constant is found

        while(getline(newfile, tp)){ // read data from file object and put it into string.

            // defines the regular expressions for identifiers as well as constants
            regex r("[a-z][0-9a-z]*");
            regex c("[0-9]*");
            char operators[] = "+-=/*%()<>"; // creates an array of chars containing all operators

            stringstream lineStream(tp);
            string token;

            while (lineStream >> token)
            {
                keyword = false; // sets all the boolean values to false as every new token is read
                identi = false;
                operat = false;
                endsy = false;
                consts = false;

                // checks to see if there's a space at the front of a token and removes it if there is
                // also checks to see if the last char in the token is a semicolon
                // and if it is it removes the semicolon so the token can be identified
                // as well as sets the boolean for an end symbol to true so that the
                // end symbol is processed as a token as well
                token.erase(remove_if(token.begin(), token.end(), ::isspace), token.end());
                if (token[token.size() - 1] == ';' && token.size() != 1)
                {
                    token.pop_back();
                    endsy = true;
                }

                // if statements for all keywords
                if(token == "if")
                {
                    // if the token is the given keywords, prints out the token as a keyword
                    // also sets the keyword boolean to true
                    cout << token << " is a keyword\n";
                    keyword = true;
                }

                if(token == "else")
                {
                    // if the token is the given keywords, prints out the token as a keyword
                    // also sets the keyword boolean to true
                    cout << token << " is a keyword\n";
                    keyword = true;
                }

                if(token == "for")
                {
                    // if the token is the given keywords, prints out the token as a keyword
                    // also sets the keyword boolean to true
                    cout << token << " is a keyword\n";
                    keyword = true;
                }

                if(token == "int")
                {
                    // if the token is the given keywords, prints out the token as a keyword
                    // also sets the keyword boolean to true
                    cout << token << " is a keyword\n";
                    keyword = true;
                }

                if(token == "break")
                {
                    // if the token is the given keywords, prints out the token as a keyword
                    // also sets the keyword boolean to true
                    cout << token << " is a keyword\n";
                    keyword = true;
                }

                // if the boolean for keyword is false, checks to see if the token is an identifier
                // it is important that the keywords are checked first, otherwise all the keywords
                // would return as identifiers as well, so this boolean check removes that possibility
                if(!keyword){
                    if(regex_match(token, r))
                    {
                        cout << token << " is a identifier\n";
                        identi = true;
                    }
                }

                // checks to see if the token matches the regular expression given for constants
                if(regex_match(token, c))
                {
                    cout << token << " is a constant\n";
                    consts = true;
                }

                // iterates through the token to see if it contains an operator
                // if there is, the operator boolean is set to true
                // this works because we assume spaces between every token
                // with the exception to end symbols, so any operator token
                // would only be one char in length
                for(int i = 0; i < token.size(); i++)
                {
                    for(int j = 0; j < 10; j++)
                    {
                        if (token[i] == operators[j])
                        {
                            operat = true;
                        }
                    }
                }

                // prints the token as an operator if the operator boolean is true
                if (operat)
                {
                    cout << token << " is an operator\n";
                }

                // checks to see if the token is an end symbol or if the end symbol
                // boolean is true, in which case it prints out the token as an end symbol
                // and sets the end symbol boolean to true if it wasn't alread
                if (token == ";" || endsy == true)
                {
                    if(endsy)
                    {
                        cout << "; is an end symbol\n";
                    }
                    else
                    {
                        cout << token << " is an end symbol\n";
                        endsy = true;
                    }


                }

                // checks for the case that all of the booleans are false
                // this results in the token being recognized as an
                // unidentified token, printing the token as such so the user is aware
                if(!operat && !keyword && !identi && !endsy && !consts)
                {
                    cout << token << " is an unidentified token\n";
                }


            }
        }

        }

    newfile.close(); //close the file object.
   }

