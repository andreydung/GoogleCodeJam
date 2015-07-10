#include <iostream>
#include <fstream>

using namespace std;
int main(int argc, char *argv[]) {
	ifstream infile(argv[1]);
	ofstream outfile(argv[2]);

	int N;
	infile >> N;

	cout << N << endl;

	for (int k = 0; k < N; k++) {
		int M;
		infile >> M;

		char c;
		int count;
		
		int addition = 0;
		int sum = 0;
		for (int i = 1; i <= M + 1; i++) {
			infile >> c;
			count = c - '0';

			cout << count << " ";

			sum += count;

			if (sum < i) {
				addition += i - sum;
				sum = i;
			}
		}
		cout << "\n";
		outfile << "Case #" << k + 1 << ": " << addition << endl;
	}

	return 0;
}