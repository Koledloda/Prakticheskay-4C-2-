#include <iostream>
#include <cmath>
#include <Windows.h>
#include <string>
#include <algorithm>
#include <random>


std::string reverse(std::string word) {
    setlocale(LC_ALL, "Rus");
    std::reverse(word.begin(), word.end());
    return word;
}

std::string removeVowels(std::string word) {
    setlocale(LC_ALL, "Rus");
    std::string vowels = "уеыаоэяиюУЕЫАОЭЯИЮaeiouAEIOU";
    word.erase(std::remove_if(word.begin(), word.end(), [&](char c) { return vowels.find(c) != std::string::npos; }), word.end());
    return word;
}

std::string removeConsonants(std::string word) {
    setlocale(LC_ALL, "Rus");
    std::string consonants = "йцкнгшщзхфвпрлджчсмтбЙЦКНГШЩЗХФВПРЛДЖЧСМТБbcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    word.erase(std::remove_if(word.begin(), word.end(), [&](char c) { return consonants.find(c) != std::string::npos; }), word.end());
    return word;
}

std::string shuffle(std::string word) {
    setlocale(LC_ALL, "Rus");
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(word.begin(), word.end(), g);
    return word;
}

int main() 
{
    setlocale(LC_ALL, "Rus");
    std::string word;
    int choice;

    std::cout << "Введите слово: ";
    std::cin >> word;

    std::cout << "\nМеню:\n";
    std::cout << "1. Слово выводится задом наперед.\n";
    std::cout << "2. Вывести слово без гласных.\n";
    std::cout << "3. Вывести слово без согласных.\n";
    std::cout << "4. Рандомно раскидывать буквы заданного слова.\n";
    std::cout << "Выберите действие (1-4): ";
    std::cin >> choice;

    switch (choice) {
    setlocale(LC_ALL, "Rus");
    case 1:
        std::cout << "Результат: " << reverse(word) << std::endl;
        break;
    case 2:
        std::cout << "Результат: " << removeVowels(word) << std::endl;
        break;
    case 3:
        std::cout << "Результат: " << removeConsonants(word) << std::endl;
        break;
    case 4:
        std::cout << "Результат: " << shuffle(word) << std::endl;
        break;
    default:
        std::cout << "Некорректный выбор." << std::endl;
        break;
    }

    return 0;
}