#include <iostream>
#include <string>
#include <map> // Include map to store variables
#include "tokenscanner.h"

std::map<std::string, double> variables; // Dictionary to store variable assignments
void calculate(double& result, double& operand, std::string expression);
// ...

int main() {
    // ...
  TokenScanner tokenScanner;
  tokenScanner.ignoreWhitespace();
  std::string str_input;
    while (true) {
        // ...
      std::cout << "> ";
      std::getline(std::cin, str_input);

      if(str_input.length() ==0) break;

      tokenScanner.setInput(str_input);

    double result = 0, operand = 0;
    bool isOperandSet = false;
    char op = '+';
        while (tokenScanner.hasMoreTokens()) {
            std::string expression = tokenScanner.nextToken();
            
            if (std::isdigit(expression[0]) || expression[0] == '-') {
                if (!isOperandSet) {
                    operand = std::strtod(expression.c_str(), NULL);
                    result = operand;
                    isOperandSet = true;
                } else {
                    operand = std::strtod(expression.c_str(), NULL);
                    calculate(result, operand, std::string(1, op));
                }
            } else {
                op = expression[0];
                if (variables.find(expression) != variables.end()) {
                    operand = variables[expression];
                    calculate(result, operand, std::string(1, op));
                    isOperandSet = true;
                }
            }
        }
        
        std::cout << result << std::endl;
    }

    return 0;
}


void calculate(double& result, double& operand, std::string expression) {
  switch(expression.c_str()[0]){
      case '+': result += operand; break;
      case '-': result -= operand; break;
      case '*': result *= operand; break;
      case '/': result /= operand; break;
      default: break;
  }
   
}
