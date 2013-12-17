#include <iostream>
#include <cstdlib>
#include <vector>

#include "parser.h"

using std::endl;
using std::cout;

using std::vector;

int main(void) {

    try {
        
        Parser p;
        char expression[] = "1 + asin(1.2)";
        p.evaluate_expression_with_exception(expression);
        p.parse(expression);
    } catch(ParsingException ex) {
        cout << "Error: " << ex.get_msg() << endl;
    }

    return EXIT_SUCCESS;
}