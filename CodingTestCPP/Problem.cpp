#include <iostream>
#include <string>
#include <stack>
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
namespace p10828 {
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

		stack<int> myStack;
		cin.ignore();
		stringstream output;
		for( int i = 0; i < n; ++i ) {
			string line;
			getline(cin, line, '\n');

			vector<string> splitStr = split(line, ' ');

			if( splitStr.size() == 0 )
				continue;

			string key = splitStr[0];
			if( 0 == key.compare("push") ) {
				myStack.push(stoi(splitStr[1]));
			}
			else if( 0 == key.compare("pop") ) {
				if( !myStack.empty() ) {
					int item = myStack.top();
					myStack.pop();
					output << item;
				}
				else {
					output << -1;
				}
				output << "\n";
			}
			else if( 0 == key.compare("size") ) {
				output << myStack.size() << "\n";
			}
			else if( 0 == key.compare("empty") ) {
				output << (myStack.empty() ? 1 : 0) << "\n";
			}
			else if( 0 == key.compare("top") ) {
				if( !myStack.empty() ) {
					int item = myStack.top();
					output << item;
				}
				else {
					output << -1;
				}
				output << "\n";
			}
		}

		string outputStr;
		while( output >> outputStr ) {
			cout << outputStr << endl;
		}

		return true;
	}
	Problem::Problem() {
	}
	Problem::~Problem() {
	}
}

using namespace p10828;
int main() {

	Problem problem;
	problem.Solution();

	return 0;
}