#include "stdafx.h"

struct C {
	static const inline std::string N{ "abc" };
};

int main() {
	printf("%s\n", C::N.c_str());
}