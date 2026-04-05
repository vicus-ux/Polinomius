#include "mainer.h"
#include <stdexcept>

Calculator::Calculator()
{
    sintaksis = std::make_unique<SintaksisAnalizer>();
    translator = std::make_unique<TranslatorPolski>();
}

Polinom Calculator::ArithmeticCalculator(const std::string& expression, std::unordered_map<std::string, Polinom>& perem)
{
    //Leksika
    leksich = std::make_unique<LeksichAnalizer>(expression);
    std::vector<std::unique_ptr<Token>> tokens = leksich->tokenize();
    //Sintaksis
    sintaksis->isCorrect(tokens, perem);
    //PolskayaZapis
    std::vector<std::unique_ptr<Token>> polishTokens = translator->toPolishNotation(tokens);
    //Calculation
    Polinom result = translator->calculate(polishTokens, perem);
    return result;
}

