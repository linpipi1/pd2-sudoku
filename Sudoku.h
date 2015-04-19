#include<iostream>

class Sudoku{
public:
     	void GiveQuestion();
     	void ReadIn();
	void Guess(int k);
     	void Solve();
	static int count;
	 int antiquestion[12][12];
	 int copy[12][12];
private:

};
