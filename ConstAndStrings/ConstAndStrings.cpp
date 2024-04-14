// ConstAndStrings.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//
#include <iostream>

void constant_variables();
void literals();
void numeral_systems();
void constant_expressions();
void conditional_operator();
void consteval_funcs();
void consteval_funcs();
void greater();
void compileTime();
void strings();

int main()
{
    std::cout << "Constants and Strings!\n";

    //constant_variables();
    //literals();
    //numeral_systems();
    //constant_expressions();
    //conditional_operator();
    //consteval_funcs();
}


void constant_variables() {
    std::cout << "------------Constant Variables------------\n";

    int x{ 4 }; // x is a non-constant variable
    x = 5; // change value of x to 5 using assignment operator

    // Const variables have to be initialized when defined
    const double gravity{ 9.8 };  // preferred use of const before type


    // Const Variables can be initialized with non constant variables
    std::cout << "Enter your Birth Year: ";
    int birthYear{};
    std::cin >> birthYear;

    const int constAge{ birthYear }; // initialize const variable using non-const value
}

void literals() {
    std::cout << "------------ Literals ------------\n";

    std::cout << 5 << '\n';  // 5 (no suffix) is type int (by default)
    std::cout << 5L << '\n'; // 5L is type long
    std::cout << 5u << '\n'; // 5u is type unsigned int

    std::cout << 5.0 << '\n';  // 5.0 (no suffix) is type double (by default)
    std::cout << 5.0f << '\n'; // 5.0f is type float
}

void numeral_systems() {
    std::cout << "------------Numeral Systems------------\n";

    int octal{ 012 }; // 0 before the number means this is octal
    std::cout << octal << '\n';
    std::cout << std::oct << octal << '\n'; // octal
    std::cout << std::dec;
    
    int hexa{ 0xF }; // 0x before the number means this is hexadecimal
    std::cout <<  hexa << '\n';
    std::cout << std::hex << hexa << '\n'; // hexadecimal
    std::cout << std::dec;

    // We can use ' to seperate digits to help with readability
    int bin{ 0b1011'0010 };  // assign binary 1011 0010 to the variable
    std::cout << bin << '\n';
    std::cout << std::format("{:b}\n", bin) << '\n';
}

void constant_expressions() {
    std::cout << "------------Costant Expressions------------\n";
    
    /* AS IF RULE : compiler can modify a program however it likes in order to produce more optimized code,
    so long as those modifications do not affect a program’s “observable behavior”.*/ 

    /* Constant Expression: An expression that contains only compile-time constants and operators/functions that support compile-time evaluation */
    int a{ 5 };                 // 5 is a constant expression
    double b{ 1.2 + 3.4 };      // 1.2 + 3.4 is a constant expression

    /* Compile-Time Constant: is a constant whose value must be known at compile time 
    Includes Literals , Constexpr variables , Const integral(non floating) variables */
    
    const int c{ 5 };           // 5 is a constant expression
    const int d{ c };           // c is a constant expression
    const long e{ c + 2 };      // c + 2 is a constant expression 
    
    /* Runtime Constants: Const variables that are not compile-time constants 
    Includes non integral constants & non constant expressions */
    const int f{ a };           // a is not a constant expression
    const int g{ a + 1 };       // a + 1 is not a constant expression
    const long h{ a + c };      // a + c is not a constant expression
    const double k{ 1.2 };      // 1.2 is a constant expression


    /* We can use const expression for enlisting the compiler’s help
    to ensure we get a compile-time constant variable where we desire one*/

    constexpr double gravity{ 9.8 }; // ok: 9.8 is a constant expression
    constexpr int sum{ 4 + 5 };      // ok: 4 + 5 is a constant expression
    constexpr int something{ sum };  // ok: sum is a constant expression

    /* BEST PRACTICE 
    Any constant variable whose initializer is a constant expression should be declared as constexpr.
    Any constant variable whose initializer is not a constant expression should be declared as const. */


}

void conditional_operator() {
    std::cout << "------------Conditional Operator------------\n";
    constexpr bool inBigClassroom{ false };
    constexpr int classSize{ inBigClassroom ? 30 : 20 };

    std::cout << (true ? 1 : 2) << '\n';    // okay: both operands have matching type int

    std::cout << (false ? 1 : 2.2) << '\n'; // okay: int value 1 converted to double

    std::cout << (true ? -1 : 2u) << '\n';  // surprising result: -1 converted to unsigned int, result out of range

}

constexpr int greater(int x, int y) // now a constexpr function
{
    return (x > y ? x : y);
}

consteval auto compileTime(auto value)
{
    return value;
}

void consteval_funcs() {
    std::cout << "------------ConstEval Functions------------\n";

    constexpr int x{ 5 };
    constexpr int y{ 6 };

    // case 1: always evaluated at compile-time
    constexpr int g{ greater(x, y) }; // will be evaluated at compile-time
    std::cout << g << " is greater!\n";

    std::cout << greater(5, 6) << " is greater!\n"; // case 2: may be evaluated at either runtime or compile-time

    int z{ 5 }; // not constexpr but value is known at compile-time
    std::cout << greater(z, 6) << " is greater!\n"; // case 3: likely evaluated at runtime

    std::cin >> z;
    std::cout << greater(z, 6) << " is greater!\n"; // case 4: always evaluated at runtime

    // Consteval is used to indicate that a function must evaluate at compile-time, otherwise a compile error will result

    std::cout << compileTime(5) << " compile time !\n"; // ok: will evaluate at compile-time

    // Downside of consteval functions is that such functions can’t evaluate at runtime
    std::cout << compileTime(greater(5, 6)) << " is greater!\n"; // ok: will evaluate at compile-time

}

void strings() {
    std::cout << "------------ Strings ------------\n";

}

