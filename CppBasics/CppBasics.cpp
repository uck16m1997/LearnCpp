#include <iostream>


// Naming conventions
int my_variable_name;   // conventional (separated by underscores/snake_case)
void my_function_name() {}; // conventional (separated by underscores/snake_case)

int myVariableName;   // conventional (intercapped/CamelCase)
void myFunctionName() {}; // conventional (intercapped/CamelCase)

int main()
{
	// Strings seperated by whitespace (space, tab, newline) will be concatenated
	std::cout << "Hello "
		"CppBasics!\n";

	int width{ 5 };    // direct list initialization of value 5 into variable width
	int height = { 6 }; // copy list initialization of value 6 into variable height
	int depth{};       // value initialization / zero initialization to value 0

	int x{};
	int y{};
	std::cout << "Enter two numbers: ";
	std::cin >> x >> y;
	std::cout << "You have entered " << x << " and " << y << '\n';

	return 0;
}

