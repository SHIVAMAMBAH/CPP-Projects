
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

int main()
{
	std::ifstream file("words_alpha.txt");
	if (!file)
	{
		std::cerr << "Error Opening File";
		return 1;
	}

	std::vector<std::string> words;
	std::string word;

	while (file >> word)
	{
		words.push_back(word);
	}

	file.close();

	std::sort(words.begin(), words.end()); // Ensure sorted order

	std::string targetWord;
	std::cout << "Enter a word: ";
	std::cin >> targetWord;

	if (std::binary_search(words.begin(), words.end(), targetWord))
	{
		std::cout << targetWord << " found";
	}
	else
	{
		std::cout << targetWord << " not found";
	}

	return 0;
}
