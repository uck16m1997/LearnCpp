#include <iostream>


// Naming conventions
int my_variable_name;   // conventional (separated by underscores/snake_case)
void my_function_name() {}; // conventional (separated by underscores/snake_case)

int myVariableName;   // conventional (intercapped/CamelCase)
void myFunctionName() {}; // conventional (intercapped/CamelCase)

int main()
{
	// std::cout is buffered and periodically, the buffer is flushed meaning all of the data collected in the buffer is transferred to its destination
	// std::endl moves the cursor to the next line of the console, and it flushes the buffer
	// \n is preffered since it’s more efficient to let the system flush itself periodically as it was designed
	// Strings seperated by whitespace (space, tab, newline) will be concatenated
	std::cout << "Hello "
		"CppBasics!\n";

	// Expressions are a sequence of literals, variables, operators, and function calls that calculates a single value
	// Statements are a type of instruction that causes the program to perform some action
	// An expression statement is a statement that consists of an expression followed by a semicolon examples below

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

