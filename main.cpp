#include <iostream>
#include <cstdlib>
#include <vector>

#include "parser.h"

using std::endl;
using std::cout;

using std::vector;

int main(void) {

    try {
        char expression[] = "a[sin(pi) + 2]^3";
        Parser p;
        p.extract_tokens(expression);

        vector<Lexema> tokens = p.get_lexemas_positions();

        for(size_t i = 0; i < tokens.size(); i++) {
            cout << tokens[i] << endl;
        }


    } catch(ParsingException ex) {
        cout << "Error: " << ex.get_msg() << endl;
    }

    return EXIT_SUCCESS;
}