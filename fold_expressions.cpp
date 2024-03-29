#include "stdafx.h"

template <typename ... Ts>
auto sum(Ts ... ts) {
	return (0 + ... + ts);
}

template <typename ... Ts>
auto sum_generic(Ts ... ts) {
	if constexpr ((std::is_same<Ts, const char*>::value && ...)) {
		return (std::string{} +... + std::string{ ts });
	}
	else if constexpr ((std::is_same<Ts, std::string>::value && ...)) { 
		return (std::string{} +... + ts);
	}
	else {
		return (0 + ... + ts);
	}
}

template <typename ... Ts>
auto logical_or(Ts ... ts) {
	return (... || ts);
}

template <typename ... Ts>
auto bitwise_or(Ts ... ts) {
	return (0 | ... | ts);
}

template <typename T, typename ... Ts>
bool within(T min, T max, Ts ...ts) {
	return ((min <= ts && ts <= max) && ...);
}

template <typename C, typename ... Ts>
auto matches(const C &a, Ts ... ts) {
	return (std::count(std::begin(a), std::end(a), ts) + ...);
}

template <typename C, typename ... Ts>
bool insert_all(C &s, Ts ... ts) {
	return (s.insert(ts).second && ...);
}

int main() {
	assert(sum(1, 2, 3, 4, 5) == 15);
	assert(sum(1, 2, 3, 4, 5, 6.5) == 21.5);

	std::string hello{ "Hello" };
	std::string world{ " world" };

	assert(sum_generic(hello, world) == "Hello world");
	assert(sum_generic(std::string("a"), std::string("b"), std::string("c")) == "abc");
	assert(sum_generic("a", "b", "c") == "abc");

	assert(logical_or() == false);
	assert(logical_or(false, true) == true);

	assert(bitwise_or(1, 2, 4) == 7);
	assert(bitwise_or() == 0);

	assert(within(0, 9, 1, 2, 3, 4, 5) == true);
	assert(within(0, 9, 1, 2, 3, 4, 20) == false);

	std::string aaa{ "aaa" };
	std::string bcd{ "bcd" };
	std::string def{ "def" };
	std::string zzz{ "zzz" };

	assert(within(aaa, zzz, bcd, def));
	assert(!within(aaa, def, bcd, zzz));

	std::set<int> s;
	assert(insert_all(s, 1, 2, 3) == true);
	assert(insert_all(s, 4, 5, 6, 6) == false);

	assert(1 == matches(std::vector<int>{1, 2, 3, 4}, 2, 5));
	assert(1 == matches(std::initializer_list<int>{1, 2, 3, 4}, 10, 2));
	assert(1 == matches("abcdefg", 'x', 'y', 'z', 'd'));
	assert(3 == matches("abcdefg", 'a', 'c', 'e', 'z'));
}