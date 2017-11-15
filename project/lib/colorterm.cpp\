#include <stdio.h>
#include <iostream>
#include "../include/ColorTerm.hpp"
using namespace std;

int main(int argc, char **argv) {

	using namespace ColorTerm;
	AttrSet aset(Attr::Bold, Attr::Underline, Attr::Blink, Attr::Inverse);
	TermStyleManipulator tsm;

	tsm.set(aset, Color::Black, Color::Default);
	cout << tsm << "hello!" << CT_END << '\n';

	tsm.setColor(Color::Default, Color::Default);
	tsm.setBrightness(false, false);
	cout << tsm << "hello!" << CT_END << '\n';


	return 0;
}
