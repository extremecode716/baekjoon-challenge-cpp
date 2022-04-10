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
namespace p10773 {
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
		for( int i = 0; i < n; ++i ) {
			int num = 0;
			cin >> num;
			cin.ignore();
			if( num == 0 ) {
				if( !myStack.empty() ) {
					myStack.pop();
				}
			}
			else {
				myStack.push(num);
			}
		}

		int sum = 0;
		while( !myStack.empty() )
		{
			int topNum = myStack.top();
			sum += topNum;
			myStack.pop();
		}
		string outputStr;
		cout << sum << endl;

		return true;
	}
	Problem::Problem() {
	}
	Problem::~Problem() {
	}
}

using namespace p10773;
int main() {

	Problem problem;
	problem.Solution();

	return 0;
}