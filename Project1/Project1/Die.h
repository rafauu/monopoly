#pragma once
#include <initializer_list>
#include <vector>
#include <random>
#include <algorithm>

class Die
{
public:
	Die(std::vector<int> values) :
		values(values)
	{}
	~Die() = default;
	Die(const Die &) = default;

	int roll(std::random_device& rng)
	{
		std::mt19937 m_twister{ rng() };
		std::shuffle(values.begin(), values.end(), m_twister);
		return values.at(0);
	}

	std::vector<int> values;
};

