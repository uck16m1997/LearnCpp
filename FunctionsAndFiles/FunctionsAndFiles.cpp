
#include <iostream>

int scopeFunction(); // function declaration includes return type, name, parameters, and semicolon.  No function body!
int add(int a, int b); // This functions definition is in another cpp file that Linker knows

int main()
{
    std::cout << "Hello World!\n";
    // Return value from scopeFunction is contained in a temporary object
    // In modern C++ (especially since C++17), the compiler has many tricks to avoid generating temporaries
    // Since the return value of scopeFunction() is immediately output the compiler can use the return value to directly initialize the parameter of operator<<
    std::cout << scopeFunction() << "\n";
    std::cout << add(5, 6) << "\n";

}

// LifeTime is a runTime property where objects will be instantiated and destroyed
// LifeTimes guarantee that objects must be created and initialized no later than the point of definition, and destroyed no earlier than the end 
// Altough for optimization purposes compiler can created earlier, or destroyed later 
// Scope is a compileTime property and trying to use an identifier when it is not in scope will result in a compile error.
int scopeFunction() {
    return 5;
}

// When a function is called, all of the parameters of the function are created as variables
// Value of each of the arguments is copied into the matching parameter (using COPY INITIALIZATION)
// This process is called PASS BY VALUE and parameters that can utilize this are called VALUE PARAMETERS
void printValues(int x, int y)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
}

void doSomething(int) // ok: unnamed parameter will not generate warning
{
}