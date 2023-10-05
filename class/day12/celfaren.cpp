#include <iostream>

double celsiusToFarenheit(double celsius){
    return (double) (9 / 5 * celsius) + 32.0;
}
int main(){
    double celsius = 0.0f;
    std::cout << "Enter the celsius: " << std::endl;
    std::cin >>celsius;
    std::cout << "Farenheit: " << celsiusToFarenheit(celsius) << std::endl;
    return 0;

}