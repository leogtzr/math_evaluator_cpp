#include <iostream>
#include <cstdlib>

#include "parser.h"

using std::endl;
using std::cout;

int main(void) {

    Parser p;

    try {
        char expression[] = "pi^2.0 - sin(cos(tan(3.2e0)))";
        p.evaluate_expression_with_exception(expression);
        p.parse(expression);
        double r = p.get_numeric_answer();
        cout << "Ok ... " << r << endl;
    } catch(ParsingException ex) {
        cout << "Error: " << ex.get_msg() << endl;
    }

    return EXIT_SUCCESS;
}