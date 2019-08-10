#include "stdafx.h"

using namespace std;

template <typename C>
void print_vector(const C& v) {
	cout << "Words: {";
	copy(begin(v), end(v), ostream_iterator<typename C::value_type>(cout, " "));
	cout << "}\n";
}

template <typename C, typename T>
void insert_sorted(C& v, const T& word) {
	const auto it(lower_bound(begin(v), end(v), word));
	v.insert(it, word);
}

int main() {
	list<string> v{ "some", "random", "words", "without", "order", "aaa", "yyy" };

	print_vector(v);
	print_vector(v);

	insert_sorted(v, "foobar");
	insert_sorted(v, "zzz");

	print_vector(v);

	return 0;
}