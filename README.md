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
    acosh
    sign
    acos
    asech
    atan
    asinh
    atanh
    acoth
    asin
    acsc
    acsch
    asec
    cot
    coth
    csc
    csch
    log10
    log2
    sec
    sech
    sqrt
    tan
    rand_0_to_1
    sin
    cos

**Numeric constants:**

    pi
    e
    g (gravity)

**User defined variables:**

    char expression[] = "sin(pi + x)";        
    p.get_vars().add("x", 1.0);
    p.parse(expression);
    double result = p.get_numeric_answer();
