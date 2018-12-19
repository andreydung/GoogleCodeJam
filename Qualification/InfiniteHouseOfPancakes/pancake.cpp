#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int f(const vector<int>& P) {
  const int max_pancakes = *max_element(P.begin(), P.end());
  int ret = max_pancakes;
  for (int x = 1; x < max_pancakes; ++x) {
    int total_moves = 0;
    for (const int Pi : P) {
      // (Pi - 1) / x is equivalent to M(Pi), 
      // which is ceil(Pi / x) - 1
      total_moves += (Pi - 1) / x;
    }
    ret = min(ret, total_moves + x);
  }
  return ret;
}

int main(int argc, char* argv[]) {
	ifstream infile(argv[1]);
	ofstream outfile(argv[2]);

	int N = 0;
	infile >> N;

	for (int k = 0; k < N; k++) {
		int M;
		infile >> M;

		cout << M << endl;
		vector<int> pancakes;
		int a;

		for (int i = 0; i < M; i++) {
			infile >> a;
			pancakes.push_back(a);
		}

		outfile << "Case #" << k + 1 << ": " << f(pancakes) << endl;
	}
}