// FundamentalDataTypes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip> // for std::setw (which sets the width of the subsequent output)

void signedIntegers();
void fixedWidthVariables();
void floatingPointVariables();
void typeConversions();

int main()
{
    std::cout << "Fundamental Data Types\n";

    // Memory on modern machines is typically organized into "byte-sized (8 bits)" units with each byte of memory having a unique address
   
    // However most objects actually take up more than 1 byte of memory 
    // and the compiler knows how many bytes of data to retrieve when we access some variable x

    // In general an object with n bits  can hold 2^n unique values


    std::cout << std::left; // left justify output
    std::cout << std::setw(16) << "bool:"        << sizeof(bool) << " bytes\n";
    std::cout << std::setw(16) << "char:"        << sizeof(char) << " bytes\n";
    std::cout << std::setw(16) << "short:"       << sizeof(short) << " bytes\n";
    std::cout << std::setw(16) << "int:"         << sizeof(int) << " bytes\n";
    std::cout << std::setw(16) << "long:"        << sizeof(long) << " bytes\n";
    std::cout << std::setw(16) << "long long:"   << sizeof(long long) << " bytes\n";
    std::cout << std::setw(16) << "float:"       << sizeof(float) << " bytes\n";
    std::cout << std::setw(16) << "double:"      << sizeof(double) << " bytes\n";
    std::cout << std::setw(16) << "long double:" << sizeof(long double) << " bytes\n";
    std::cout << '\n';

    signedIntegers();

    std::cout << "8 / 5 Integer Divison " <<  8 / 5 << '\n';

    // signed values are connverted in to unsigned values and can cause overflow behaviour
    signed int s{ -1 };
    unsigned int u{ 1 };
    bool comp = (s < u); // -1 is implicitly converted to 4294967295, and 4294967295 < 1 is false
    std::cout << s << " is less than " << u << ": " << (comp ? "True" : "False") << "\n\n";


    fixedWidthVariables();
    floatingPointVariables();

    char ch1{ 'a' }; // (preferred)
    std::cout << "\nChar a: " << ch1 << '\n'; // cout prints character 'a'

    char ch2{ 98 }; // code point for 'b' (not preferred)
    std::cout  << "Char 98: " << ch2 << '\n'; // cout prints a character 'b'



    typeConversions();
    
}

void typeConversions() {
    double d{ 5 }; // okay: int to double is safe
    int x{ static_cast<int>(5.5) }; // error: double to int not safe

    std::int8_t myInt{ 65 };      // initialize myInt with value 65
    std::cout << "int8_t and other 8 byte variants will be treated as chars : " << myInt << '\n'; // you're probably expecting this to print 65
}

void floatingPointVariables() {
    std::cout << "Scientific Notation 1.2e4: " << 1.2e4 << "\n\n";

    int x{ 5 };      // 5 means integer
    double y{ 5.0 }; // 5.0 is a floating point literal (no suffix means double type by default)
    float z{ 5.0f }; // 5.0 is a floating point literal, f suffix means float type


    std::cout << std::setprecision(17); // show 17 digits of precision
    std::cout << "Float Values are precise to 7 digits: " << 3.33333333333333333333333333333333333333f << '\n'; // f suffix means float
    std::cout << "Double Values are precise to 16 digits: " << 3.33333333333333333333333333333333333333 << "\n\n"; // no suffix means double


    double d{ 0.1 };
    std::cout << "Double 0.1 with 2 degree of precision: " << std::setprecision(2);
    std::cout << d << '\n'; // use default cout precision of 6
    std::cout << std::setprecision(17);
    std::cout << "Double 0.1 with 17 degree of precision: " << d << '\n' << '\n';;

    double zero{ 0.0 };
    double posinf{ 5.0 / zero }; // positive infinity
    std::cout << "5.0/0: " << posinf << '\n';

    double neginf{ -5.0 / zero }; // negative infinity
    std::cout << "-5.0/0: " << neginf << '\n';

    double nan{ zero / zero }; // not a number (mathematically invalid)
    std::cout << "0/0: " << nan << '\n';
}


void fixedWidthVariables() {
    // Int size is only guaranteed up to 2 bytes but is 4 bytes on most modern computers
    // To guarantee the actual size we can use fixed width variables
    std::cout << '\n' << "Fixed Width Variables\n";

    std::cout << "int8_t:  " << sizeof(std::int8_t) * 8 << " bits\n";
    std::cout << "int16_t: " << sizeof(std::int16_t) * 8 << " bits\n";
    std::cout << "int32_t: " << sizeof(std::int32_t) * 8 << " bits\n";

    // Fixed width variables arent defined on all devices so we can use Least and Fast Guarantee
    std::cout << '\n' << "Least Width Variables provide smallest int type with atlesat # bits \n";
    std::cout << "least 8:  " << sizeof(std::int_least8_t) * 8 << " bits\n";
    std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
    std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
    std::cout << '\n' << "Fast Width Variables provide fastest int type with at least # bits \n";;
    std::cout << "fast 8:  " << sizeof(std::int_fast8_t) * 8 << " bits\n";
    std::cout << "fast 16: " << sizeof(std::int_fast16_t) * 8 << " bits\n";
    std::cout << "fast 32: " << sizeof(std::int_fast32_t) * 8 << " bits\n";
}


void signedIntegers() {
    short s;   
    int i;
    long l;     
    long long ll; 

    // 1 bit holds the size rest is the magnitude and range is (+-) 2^(n-1)

    // assume 4 byte integers
    int x{ 2'147'483'647 }; // the maximum value of a 4-byte signed integer
    std::cout << "Max Int variable X: " <<  x << '\n';

    x = x + 1; // integer overflow, undefined behavior
    std::cout << "Overflow X+1: " << x << '\n';


}