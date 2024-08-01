#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool ifCorrect(string sequence)
{
	stack<char> st;
	for (char c : sequence )
	{
		if (c == 'I') 
		{
			st.push(c);
		}
		else if (c=='O')
		{
			if (st.empty())
			{
				return false;
			}
			st.pop();			
		}
	}
	return st.empty();
}
int main() {
	string sequence1 = "IOIIOIOO";
	string sequence2 = "IOOIOIIO";
	string sequence3 = "IIIOIOIO";
	string sequence4 = "IIIOOIOO";
	cout << (ifCorrect(sequence1) ? "true" : "false") << endl;
	cout << (ifCorrect(sequence2) ? "true" : "false") << endl;
	cout << (ifCorrect(sequence3) ? "true" : "false") << endl;
	cout << (ifCorrect(sequence4) ? "true" : "false") << endl;
	return 0;
}