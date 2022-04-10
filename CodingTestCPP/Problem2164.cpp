#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimiter) {
	vector<string> answer;
	stringstream ss(input);
	string temp;

	while( getline(ss, temp, delimiter) ) {
		answer.push_back(temp);
	}

	return answer;
}
namespace p2164 {
	class Problem {
	private:

	public:
		bool Solution();

	public:
		Problem();
		virtual ~Problem();
	};

	bool Problem::Solution() {
		int n = 0;
		cin >> n;
		cin.ignore();

		queue<int> myQueue;

		for( int i = 1; i <= n; ++i ) {
			myQueue.push(i);
		}

		while( myQueue.size() > 1 ) {
			myQueue.pop();
			myQueue.push(myQueue.front());
			myQueue.pop();
		}

		cout << myQueue.front() << endl;
		return true;
	}
	Problem::Problem() {
	}
	Problem::~Problem() {
	}
}

using namespace p2164;
int main() {

	Problem problem;
	problem.Solution();

	return 0;
}