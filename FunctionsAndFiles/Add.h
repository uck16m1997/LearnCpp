#pragma once

// Do not put function and variable definitions in your header files
// It will likely result in a violation of the one-definition rule (ODR)  if that header is then #included into more than one source (.cpp) file
int add(int a, int b); // This functions definition is in another cpp file that Linker knows
