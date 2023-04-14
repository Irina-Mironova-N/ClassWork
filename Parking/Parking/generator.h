#pragma once



#define random(a,b) a+rand()%(b+1-a)

string createAerodrom(int count);
void generateAerodromeFile(string path, int count);
void generateAeroplane(string path, int count);
string createArplane(string , string , float, int );
