#include <vector>
#include <ios>

using namespace std;

// Matrix
template <typename T>
std::vector<std::vector<T>> matrix(int rows, int columns) {
	std::vector<std::vector<T>> v(columns, std::vector<T> (rows));
	return v;
}

int main() {
	vector<vector<int>> candybars = matrix<int> (5, 6);
	candybars[0][4] = 7;
	return 0;
}
