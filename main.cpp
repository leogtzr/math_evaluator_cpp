#include <iostream>
#include <cstdlib>

#include "parser.h"

using std::endl;
using std::cout;

int main(void) {

    Parser p;
    p.get_arrays().create_array("a");
    
    for(int i = 1; i <= 10; i++) {
        p.get_arrays().add_element_to_array("a", (double)i);
    }

    try {
        char expression[] = "a[sin(pi) + 2]^3";
        p.parse(expression);
        double r = p.get_numeric_answer();
        cout << "Ok ... " << r << endl;
    } catch(ParsingException ex) {
        cout << "Error: " << ex.get_msg() << endl;
    }

    return EXIT_SUCCESS;
}