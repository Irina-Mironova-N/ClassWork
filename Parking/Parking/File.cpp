#include "param.h"


string* readFile(string path) {
	ifstream in;
	in.open(path);
	int count = 0;
	if (in) {
		string str={""};

		
		while (getline(in, str)) {
			count++;
		}
		in.close();
	}
	in.open(path);
	string* buf = new string[count];
	if (in) {
		string str = { "" };
		count = 0;
		int count = 0;
		while (getline(in, str)) {
			buf[count++] = str;
		}
		in.close();
		return buf;
	}

}