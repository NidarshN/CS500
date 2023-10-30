#include <iostream>
#include <string>
#include <cctype>
#include <unordered_map>
// #define NDEBUG
#include <cassert>

class PirateTranslation {

    private:

    std::unordered_map<std::string, std::string> pirateDictionary;
    std::vector<std::string> pirateSentence;

    public:

    PirateTranslation(){
        pirateDictionary = {
            {"hello", "ahoy"},
            {"excuse me", "arrr"},
            {"sir", "matey"},
            {"boy", "matey"},
            {"man", "matey"},
            {"madame", "proud beauty"},
            {"officer", "foul blaggart"},
            {"the", "th'"},
            {"my", "me"},
            {"your", "yer"},
            {"is", "be"},
            {"are", "be"},
            {"restroom", "head"},
            {"restaurant", "galley"},
            {"hotel", "fleabag inn"},
            {"coins", "doubloons"},
            {"pirate", "buccaneer"},
            {"friend", "mate"},
            {"you", "ye"}
        };
    }

    /*
     * Method: generateSentenceVector
     * Usage: pt.generateSentenceVector(str)
     * -------------------------------------
     * Creates a vector of strings containing words in the sentence.
     * The punctuations and whitespace are stored as a different element in the vector
    */
    void generateSentenceVector(const std::string& sentence){
        pirateSentence.clear();
        std::string word = "";
        for(int i=0; i<sentence.length(); i++){
            if(ispunct(sentence[i]) || isspace(sentence[i])){ 
                std::string s (1, sentence[i]);
                if(!word.empty()){
                    pirateSentence.push_back(word);
                    pirateSentence.push_back(s);
                    word = "";
                }else{
                    pirateSentence.push_back(s);
                }
            }else {
                word += sentence[i];
            }
        }
    }

    /*
     * Method: translateToPirate
     * Usage: std::string res = pt.translateToPirate(str)
     * -------------------------------------
     * Translates a string sentence into a
     * The punctuations and whitespace are stored as a different element in the vector
    */
    std::string translateToPirate(const std::string& sentence){
        std::string translatedSentence = "";
        std::vector<std::string> res;
        generateSentenceVector(sentence);

        for(int i = 0; i < pirateSentence.size(); i++){
            bool isuppercase = false;
            if(isupper(pirateSentence[i][0])){
                isuppercase = true;
            }
            std::string word = pirateSentence[i];
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            if(pirateDictionary.find(word) != pirateDictionary.end()){
                std::string pirateWord = pirateDictionary[word];
                if(isuppercase){
                    pirateWord[0] = toupper(pirateWord[0]);
                    isuppercase = false;
                }
                translatedSentence += pirateWord;
                res.push_back(pirateWord);
            }else if(pirateSentence[i] == " " && i < pirateSentence.size() - 1){
                if(isupper(pirateSentence[i-1][0])){
                    isuppercase = true;
                }
                std::string temp = pirateSentence[i-1] + pirateSentence[i] + pirateSentence[i+1];
                std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
                if(pirateDictionary.find(temp) != pirateDictionary.end()){
                    std::string combWord = pirateDictionary[temp];
                    if(isuppercase){
                        combWord[0] = toupper(combWord[0]);
                        isuppercase = false;
                    }
                    translatedSentence += combWord;
                    res.pop_back();
                    res.push_back(combWord);
                    i += 1;
                }else{
                    translatedSentence += pirateSentence[i];
                    res.push_back(pirateSentence[i]);
                }
            }else{
                translatedSentence += pirateSentence[i];
                res.push_back(pirateSentence[i]);
            }
        }

        std::string resStr = "";

        for(int i = 0; i < res.size(); i++){
            resStr += res[i];
        }
        return resStr;
    }
};

int main() {
    int choice;


    PirateTranslation pt;
    std::string testcase1 = "Hello, madame, would you direct me to the nearest hotel?";
    std::string answer1 = "Ahoy, proud beauty, would ye direct me to th' nearest fleabag inn?";

    std::string testcase2 = "Sir, what is the name of your best restaurant?";
    std::string answer2 = "Matey, what be th' name of yer best galley?";
    
    std::string testcase3 = "Excuse me, officer, my friend is lost. He is a fellow pirate looking for coins to pay the restaurant.";
    std::string answer3 = "Arrr, foul blaggart, me mate be lost. He be a fellow buccaneer looking for doubloons to pay th' galley.";

    std::string testcase4 = "Hello boy, what are you upto today?";
    std::string answer4 = "Ahoy matey, what be ye upto today?";

    std::string testcase5 = "my fellow smart-looking pirate wants some coins.";
    std::string answer5 = "me fellow smart-looking buccaneer wants some doubloons.";

    assert(pt.translateToPirate(testcase1)==answer1);
    assert(pt.translateToPirate(testcase2)==answer2);
    assert(pt.translateToPirate(testcase3)==answer3);
    assert(pt.translateToPirate(testcase4)==answer4);
    assert(pt.translateToPirate(testcase5)==answer5);

    std::string input;
    std::cout << "Enter the test phrase: ";
    std::getline(std::cin, input);
    std::cout << "Translated Pirate phrase: " << pt.translateToPirate(input) << std::endl;

    return 0;
}