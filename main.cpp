#include <iostream>
#include <cstdlib>

#include "parser.h"

using std::endl;
using std::cout;

int main(void) {

    Parser p;

    char expression[] = "sin(pi + 0.2)";
    try {
        p.evaluate_expression_with_exception(expression);
        p.parse(expression);
        double result = p.get_numeric_answer();
        cout << result << endl;
    } catch(ParsingException ex) {
        cout << ex.get_msg() << endl;
    }

    return EXIT_SUCCESS;
}