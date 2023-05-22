// WordCount.cpp

#include "WordCount.h"

#include <cctype>

using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const
{
	int result = 0;
	for (size_t i = 0; i < CAPACITY; i++)
	{
		for (size_t j = 0; j < table[i].size(); j++)
		{
			result += table[i].at(j).second;
		}
	}

	return result;
}

int WordCount::getNumUniqueWords() const
{
	int result = 0;
	for (size_t i = 0; i < CAPACITY; i++)
	{
		for (size_t j = 0; j < table[i].size(); j++)
		{
			result++;
		}
	}

	return result;
}

int WordCount::getWordCount(std::string word) const
{
	word = makeValidWord(word);
	size_t h = hash(word);
	for (size_t i = 0; i < table[h].size(); i++)
	{
		if (table[h].at(i).first == word)
		{
			return table[h].at(i).second;
		}
	}

	return 0;
}
	
int WordCount::incrWordCount(std::string word)
{
	word = makeValidWord(word);
	size_t h = hash(word);
	if (getWordCount(word))
	{
		for (size_t i = 0; i < table[h].size(); i++)
		{
			if (table[h].at(i).first == word)
			{
				return ++table[h].at(i).second;
			}
		}
	}

	table[h].push_back(make_pair(word, 1));

	return 1;
}

int WordCount::decrWordCount(std::string word)
{
	word = makeValidWord(word);
	size_t h = hash(word);
	if (getWordCount(word))
	{
		for (size_t i = 0; i < table[h].size(); i++)
		{
			if (table[h].at(i).first == word)
			{
				table[h].at(i).second--;
				if (table[h].at(i).second == 0)
				{
					table[h].erase(table[h].begin() + i);
					return 0;
				}
				return table[h].at(i).second;
			}
		}
	}

	return -1;
}

bool WordCount::isWordChar(char c)
{
	return isalpha(c) == 1024;
}

std::string WordCount::makeValidWord(std::string word)
{
	string result = "";
	for (size_t i = 0; i < word.length(); i++)
	{
		if (isWordChar(word[i]))
		{
			result += tolower(word[i]);
		}
		else if (word[i] == '-' || word[i] == '\'')
		{
			if (i != 0 && i != word.length() - 1)
			{
				result += word[i];
			}
		}
	}
	
	while (true)
	{
		if (result[0] == '-' || result[0] == '\'')
		{
			result.erase(0, 1);
		}
		else if (result[result.length() - 1] == '-' || result[result.length() - 1] == '\'')
		{
			result.pop_back();
		}
		else
		{
			return result;
		}
	}
}
