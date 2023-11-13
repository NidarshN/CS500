#include <iostream>
#include <vector>
#include <map>
#include <regex>
#include <algorithm>
#include "pokerHand.h"

int getCardValue(char value)
{
    if (value >= '2' && value <= '9')
    {
        return value - '0';
    }
    else
    {
        switch (value)
        {
        case 'T':
            return 10;
            break;
        case 'J':
            return 11;
            break;
        case 'Q':
            return 12;
            break;
        case 'K':
            return 13;
            break;
        case 'A':
            return 14;
            break;
        default:
            return 0;
            break;
        }
    }
}

std::vector<Card> parseHand(const std::string &hand)
{
    std::vector<Card> parsedHand;
    std::regex cardReg("([2-9TJQKA])([CDHS])");
    std::smatch match;

    std::string::const_iterator stringSearchStart(hand.begin());
    std::string::const_iterator stringSearchEnd(hand.end());

    while (std::regex_search(stringSearchStart, stringSearchEnd, match, cardReg)) {
        parsedHand.push_back({ getCardValue(match[1].str()[0]), match[2].str()[0] });
        stringSearchStart = match.suffix().first;
    }
    return parsedHand;
}

bool isPair(const std::vector<Card> &hand)
{
    std::map<int, int> count;
    for (const Card &card : hand)
        count[card.value]++;

    for (const auto &countPair : count)
    {
        if (countPair.second == 2)
            return true;
    }
    return false;
}

bool isTwoPair(const std::vector<Card> &hand)
{
    std::map<int, int> count;
    for (const Card &card : hand)
        count[card.value]++;
    
    int twoPairCount = 0;
    for (const auto &countPair : count)
    {
        if (countPair.second == 2)
            twoPairCount++;
    }
    return twoPairCount == 2;
}

bool isThreeOfAKind(const std::vector<Card> &hand)
{
    std::map<int, int> count;
    for (const Card &card : hand)
        count[card.value]++;

    for (const auto &countPair : count)
    {
        if (countPair.second == 3)
            return true;
    }
    return false;
}

bool isStraight(const std::vector<Card> &hand)
{
    std::vector<int> values;
    for (const Card &card : hand)
        values.push_back(card.value);

    std::sort(values.begin(), values.end());
    for (int i = 1; i < values.size(); i++)
    {
        if (values[i] != values[i - 1] + 1)
            return false;
    }
    return true;
}

bool isFlush(const std::vector<Card> &hand)
{
    char suit = hand[0].suit;
    for (const Card &card : hand)
    {
        if (card.suit != suit)
            return false;
    }
    return true;
}

bool isFullHouse(const std::vector<Card> &hand)
{
    std::map<int, int> count;
    for (const Card &card : hand)
    {
        count[card.value]++;
    }
    bool hasTwoPair = false, hasThreePair = false;
    for (const auto &pairCount : count)
    {
        if (pairCount.second == 2)
            hasTwoPair = true;
        if (pairCount.second == 3)
            hasThreePair = true;
    }
    return hasTwoPair && hasThreePair;
}

bool isFourOfAKind(const std::vector<Card> &hand)
{
    std::map<int, int> count;
    for (const Card &card : hand)
    {
        count[card.value]++;
    }
    for (const auto &pairCount : count)
    {
        if (pairCount.second == 4)
            return true;
    }
    return false;
}

bool isStraightFlush(const std::vector<Card> &hand)
{
    return isStraight(hand) && isFlush(hand);
}

int getCardRank(const std::vector<Card> &hand)
{
    if (isStraightFlush(hand))
        return 8; 
    if (isFourOfAKind(hand))
        return 7; 
    if (isFullHouse(hand))
        return 6; 
    if (isFlush(hand))
        return 5; 
    if (isStraight(hand))
        return 4;
    if (isThreeOfAKind(hand))
        return 3;
    if (isTwoPair(hand))
        return 2;
    if (isPair(hand))
        return 1;
    return 0;
}

int compareHands(const std::vector<Card> &hand1, const std::vector<Card> &hand2)
{
    std::vector<int> hand1Values, hand2Values;
    for (const auto &card : hand1)
        hand1Values.push_back(card.value);
    for (const auto &card : hand2)
        hand2Values.push_back(card.value);

    std::sort(hand1Values.begin(), hand1Values.end(), std::greater<int>());
    std::sort(hand2Values.begin(), hand2Values.end(), std::greater<int>());

    for (int i = 0; i < hand1Values.size(); ++i)
    {
        if (hand1Values[i] > hand2Values[i])
            return 1;
        if (hand2Values[i] > hand1Values[i])
            return -1;
    }
    return 0;
}

std::string bestPokerHand(const std::string &hand1, const std::string &hand2)
{
    std::vector<Card> parsedHand1 = parseHand(hand1);
    std::vector<Card> parsedHand2 = parseHand(hand2);

    int handRank1 = getCardRank(parsedHand1);
    int handRank2 = getCardRank(parsedHand2);

    if (handRank1 > handRank2)
        return "Player One Wins";
    if (handRank2 > handRank1)
        return "Player Two Wins";

    int result = compareHands(parsedHand1, parsedHand2);
    if (result == 1)
        return "Player One Wins";
    if (result == -1)
        return "Player Two Wins";

    return "Tie";
}
