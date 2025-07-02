#include <iostream>
#include <random>

const char vowels[] = {'a', 'e', 'i', 'o', 'u'};
const std::string consonants[] = {"b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z", "ch", "sh", "th"};
const unsigned int WORD_COUNT = 6;
const float DOUBLE_CHANCE = 0.2f;

std::random_device randDev;
std::mt19937 rng(randDev());

std::uniform_int_distribution<std::mt19937::result_type> distVowels(0,4);
std::uniform_int_distribution<std::mt19937::result_type> distConsonants(0,23);
std::uniform_int_distribution<std::mt19937::result_type> distWorldLength(3,6);
std::uniform_real_distribution<float> distDoubleChance(0.0f, 1.0f);

const char getRandomVowel()
{
	return vowels[distVowels(rng)];
}

const std::string& getRandomConsonant()
{
	return consonants[distConsonants(rng)];
}

std::string getRandomWord()
{
	unsigned int wordLength = distWorldLength(rng);

	std::string word;

	bool startWithConsonant = rand() % 2 == 0;

	for(unsigned int i = 0; i < wordLength; i++)
	{
		if(startWithConsonant)
		{
			word += getRandomConsonant();
			if (distDoubleChance(rng) < DOUBLE_CHANCE && i < wordLength - 1) {
				word += getRandomConsonant();
				++i; // Skip the next iteration to account for the extra character added
			}

		} else {
			word += getRandomVowel();
			if (distDoubleChance(rng) < DOUBLE_CHANCE && i < wordLength - 1) {
				word += getRandomVowel();
				++i; // Skip the next iteration to account for the extra character added
			}
		}
		startWithConsonant = !startWithConsonant;
	}

	return word;
}

int main(int argc, char** argv)
{
	for(unsigned int count = 0; count < WORD_COUNT; count++)
	{
		std::cout << getRandomWord() << std::endl;
	}

	return 0;
}
