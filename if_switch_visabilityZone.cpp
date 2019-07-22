#include <iostream>
#include <cstdio>
#include <map>
#include <string>

template <typename T>
void print(const T &map, char c) {
	if (const auto itr(map.find(c)); itr != map.end()) {
		std::cout << "There are " << itr->second << " " << c << " characters." << "\n";
	}
	else {
		std::cout << "There are " << 0 << " " << c << " characters." << "\n";
	}
}

int main() {
	{
		std::map<char, size_t> character_map{ {'a', 10}, {'b', 20} };

		print(character_map, 'a');
		print(character_map, 'c');
	}

	{
		std::cout << "Please enter a character: ";
		switch (char c(getchar()); c) {
		case 'a' ... 'z':
			std::cout << "You entered a lower case letter: " << c << "\n";
			break;
		case 'A' ... 'Z':
			std::cout << "You entered an upper case letter: " << c << "\n";
			break;
		default:
			std::cout << "You entered something else: " << c << "\n";
		}
	}
}
