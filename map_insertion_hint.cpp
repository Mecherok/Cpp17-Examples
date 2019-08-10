#include "stdafx.h"

using namespace std;

using map_type = map<string, size_t>;

int main() {
	map_type m{ {"b", 1}, {"c", 2}, {"d", 3} };

	auto insert_it { end(m) };
	for (const auto &s : { "z", "y", "x", "w", "v" }) {
		insert_it = m.insert(insert_it, { s, 1 });
	}

	// Wrong!
	m.insert(end(m), { "a", 1 });

	for (const auto &[key, value] : m) {
		cout << "\"" << key << "\": " << value << ", ";
	}
	cout << '\n';

	return 0;
}