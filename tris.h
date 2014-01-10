#ifndef FILETTO_H
#define FILETTO_H

class Filetto{
public:
	Filetto();
	void start();
private:
	void rules();
	void print();
	void insert();
	void gamep1();
	void gamep2();
	void control();
	void newgame();
	char p1[10+1];
	char p2[10+1];
	bool trisp1;
	bool trisp2;
	bool stallo;
	char tabella[3][3];
	
};
#endif
