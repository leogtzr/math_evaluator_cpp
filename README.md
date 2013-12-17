A tiny c++ math library for evaluate and recognize expressions.
===============

**Features:**
--------------

**Operators:**

    && ||
    == != < > <= >=
    + -
    * / %
    ^
    !

**Functions:**

    - factorial
    - log
    - acot
    - acosh
    - sign
    - acos
    - asech
    - atan
    - asinh
    - atanh
    - acoth
    - asin
    - acsc
    - acsch
    - asec
    - cot
    - coth
    - csc
    - csch
    - log10
    - log2
    - sec
    - sech
    - sqrt
    - tan
    - rand_0_to_1
    - sin
    - cos

**Numeric constants:**

    pi
    e
    g (gravity)

**User defined variables:**

    char expression[] = "sin(pi + x)";        
    p.get_vars().add("x", 1.0);
    p.parse(expression);
    double result = p.get_numeric_answer();

**Recognition:**

    try {
        char expression[] = "pi^2.0 - sin(cos(tan(3.2e0)";
        p.evaluate_expression_with_exception(expression);
        cout << "Ok ... " << endl;
    } catch(ParsingException ex) {
        cout << "Error: " << ex.get_msg() << endl;
    }

**Evaluation:**

    try {
        char expression[] = "pi^2.0 - sin(cos(tan(3.2e0)))";
        p.evaluate_expression_with_exception(expression);
        p.parse(expression);
        double r = p.get_numeric_answer();
        cout << "Ok ... " << r << endl;
    } catch(ParsingException ex) {
        cout << "Error: " << ex.get_msg() << endl;
    }

