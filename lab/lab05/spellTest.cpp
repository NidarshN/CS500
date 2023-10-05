#include <iostream>
#include "spellCheck.h"

int main() {
    std::string recLetter = "Nidalamule is a fantastic Student. barthle once raised a clutch of baby hawks to adulthood. There was never a challenge that bartksafdjksdfNASmwik couldn't solve.";
    std::string studentName = "Nidarsh";

    std::string correctedLetter = spellCheck(recLetter, studentName);

    std::cout << "Original Recommendation Letter:\n" << recLetter << std::endl;
    std::cout << "\nCorrected Recommendation Letter:\n" << correctedLetter << std::endl;

    return 0;
}
