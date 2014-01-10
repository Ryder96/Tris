#include "FIletto.h"
#include <iostream>
#include <string>

Filetto::Filetto()
{
	rules();
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			Filetto::tabella[i][j] = ' ';
	std::cout << "Inserire nome giocatore 1: ";
	std::cin.getline(p1,9);
	std::cout << "Inserire nome giocatore 2: ";
	std::cin.getline(p2,9);
	trisp1=false;
	trisp2=false;
	stallo=false;
	print();
}
void Filetto::newgame(){
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			Filetto::tabella[i][j] = ' ';
	std::cout << "Inserire nome giocatore 1: ";
	std::cin.getline(p1,9);
	std::cout << "Inserire nome giocatore 2: ";
	std::cin.getline(p2,9);
	trisp1=false;
	trisp2=false;
	stallo=false;
	print();
}
void Filetto::rules(){
	std::cout << "Regole filetto: \n" << "1)Si vince quando uno dei due giocatore ha i suoi tre simboli in fila \n" <<
		 "in verticale,orrizzontale o in diagonale.\n"<< 
		 "\n2)Per posizionare il simbolo nelle varie celle bisogna" <<
		 " selezionare tra le " <<
		 "nove \nopzioni:\n\n hdx=alto a destra;\n hc=alto centrale;\n hsx=alto a sinistra;\n" <<
		 " cdx=centrale destra;\n cc=centro;\n csx=centrale sinistra;\n ddx=destra in basso;\n dcc=basso centrale;\n"<<
		 " dsx=sinistra in basso;\n" << std::endl << std::endl;
}
void Filetto::print(){

	std::cout <<"  " <<" |   | "<< "  " << std::endl;
	std::cout <<" "<<tabella[0][0]<<" | "<<tabella[0][1]<<" | "<<tabella[0][2]<< std::endl;
	std::cout <<" __|___|__"<<std::endl;
	std::cout <<"   |   | "<<std::endl;
	std::cout <<" "<<tabella[1][0]<<" | "<<tabella[1][1]<<" | "<<tabella[1][2]<<std::endl;
	std::cout <<" __|___|__"<<std::endl;
	std::cout <<"   |   | "<<std::endl;
	std::cout <<" "<<tabella[2][0]<<" | "<<tabella[2][1]<<" | "<<tabella[2][2]<<std::endl;
	std::cout <<"   |   | "<<std::endl;

}
void Filetto::start(){
	int i=1;
	char answer[3];
	while(trisp1 == false && trisp2 == false && i < 6){
		std::cout << "Turno # " << i << std::endl;
		gamep1();
		control();
		print();
		if(trisp1 == true)
			break;
		++i;
		if(i == 6)
			break;
		gamep2();
		control();
		print();
		if(trisp2 == true)
			break;

	}
	if(trisp1 == true)
		std::cout << "Ha vinto: " << p1 << std::endl;

	if(trisp2 == true)
		std::cout << "Ha vinto: " << p2 << std::endl;
	
	if(trisp1 == false && trisp2 == false)
		std::cout << "Pareggio" << std::endl;
	print();
	std::cout << "Vuoi giocare ancora?" << std::endl;
	std::cin.getline(answer,3);
	if(std::strcmp(answer,"si") == 0){
		newgame();
		start();
	}
	else
		return;

}
void Filetto::gamep1(){
	char decision[4];
	std::cout <<"Turno di: " << p1 << "\ninserire cella: " << std::endl;
	std::cin.getline(decision,4);
	if(std::strcmp(decision,"hdx")==0 && tabella[0][2] == ' ')
		tabella[0][2]='x';

	if(std::strcmp(decision,"hc")==0 && tabella[0][1] == ' ')
		tabella[0][1]='x';
	
	if(std::strcmp(decision,"hsx")==0 && tabella[0][0] == ' ')
		tabella[0][0]='x';

	if(std::strcmp(decision,"cdx")==0 && tabella[1][2] == ' ')
		tabella[1][2]='x';

	if(std::strcmp(decision,"cc")==0 && tabella[1][1] == ' ')
		tabella[1][1]='x';

	if(std::strcmp(decision,"csx")==0 && tabella[1][0] == ' ')
		tabella[1][0]='x';

	if(std::strcmp(decision,"ddx")==0 && tabella[2][2] == ' ')
		tabella[2][2]='x';

	if(std::strcmp(decision,"dc")==0 && tabella[2][1] == ' ')
		tabella[2][1]='x';

	if(std::strcmp(decision,"dsx")==0 && tabella[2][0] == ' ')
		tabella[2][0]='x';
	
}
void Filetto::gamep2(){
	char decision[4];
	std::cout <<"Turno di: " << p2 << "\ninserire cella: " << std::endl;
	std::cin.getline(decision,4);
	if(std::strcmp(decision,"hdx")==0 && tabella[0][2] == ' ')
		tabella[0][2]='o';

	if(std::strcmp(decision,"hc")==0 && tabella[0][1] == ' ')
		tabella[0][1]='o';

	if(std::strcmp(decision,"hsx")==0 && tabella[0][0] == ' ')
		tabella[0][0]='o';

	if(std::strcmp(decision,"cdx")==0 && tabella[1][2] == ' ')
		tabella[1][2]='o';

	if(std::strcmp(decision,"cc")==0 && tabella[1][1] == ' ')
		tabella[1][1]='o';

	if(std::strcmp(decision,"csx")==0 && tabella[1][0] == ' ')
		tabella[1][0]='o';

	if(std::strcmp(decision,"ddx")==0 && tabella[2][2] == ' ')
		tabella[2][2]='o';

	if(std::strcmp(decision,"dc")==0 && tabella[2][1] == ' ')
		tabella[2][1]='o';

	if(std::strcmp(decision,"dsx")==0 && tabella[2][0] == ' ')
		tabella[2][0]='o';

}
void Filetto::control(){
	if(tabella[0][0] == tabella[0][1] && tabella[0][1] == tabella[0][2] && tabella[0][0] == 'x'){
		trisp1=true;
		return;
	}

	if(tabella[1][0] == tabella[1][1] && tabella[1][1] == tabella[1][2] && tabella[1][0] == 'x'){
		trisp1=true;
		return;
	}
	if(tabella[2][0] == tabella[2][1] && tabella[2][1] == tabella[2][2] && tabella[2][0] == 'x'){
		trisp1=true;
		return;
	}
	if(tabella[0][0] == tabella[1][0] && tabella[1][0] == tabella[2][0] && tabella[0][0] == 'x'){
		trisp1=true;
		return;
	}
	if(tabella[0][1] == tabella[1][1] && tabella[1][1] == tabella[2][1] && tabella[0][1] == 'x'){
		trisp1=true;
		return;
	}
	if(tabella[0][2] == tabella[1][2] && tabella[1][2] == tabella[2][2] && tabella[0][2] == 'x'){
		trisp1=true;
		return;
	}
	if(tabella[0][0] == tabella[1][1] && tabella[1][1] == tabella[2][2] && tabella[0][0] == 'x'){
		trisp1=true;
		return;
	}
	if(tabella[0][2] == tabella[1][1] && tabella[1][1] == tabella[2][0] && tabella[0][2] == 'x'){
		trisp1=true;
		return;
	}
	//
	if(tabella[0][0] == tabella[0][1] && tabella[0][1] == tabella[0][2] && tabella[0][0] == 'o'){
		trisp2=true;
		return;
	}
	if(tabella[1][0] == tabella[1][1] && tabella[1][1] == tabella[1][2] && tabella[1][0] == 'o'){
		trisp2=true;
		return;
	}
	if(tabella[2][0] == tabella[2][1] && tabella[2][1] == tabella[2][2] && tabella[2][0] == 'o'){
		trisp2=true;
		return;
	}
	if(tabella[0][0] == tabella[1][0] && tabella[1][0] == tabella[2][0] && tabella[0][0] == 'o'){
		trisp2=true;
		return;
	}
	if(tabella[0][1] == tabella[1][1] && tabella[1][1] == tabella[2][1] && tabella[0][1] == 'o'){
		trisp2=true;
		return;
	}
	if(tabella[0][2] == tabella[1][2] && tabella[1][2] == tabella[2][2] && tabella[0][2] == 'o'){
		trisp2=true;
		return;
	}
	if(tabella[0][0] == tabella[1][1] && tabella[1][1] == tabella[2][2] && tabella[0][0] == 'o'){
		trisp2=true;
		return;
	}
	if(tabella[0][2] == tabella[1][1] && tabella[1][1] == tabella[2][0] && tabella[0][2] == 'o'){
		trisp2=true;
		return;
	}
	else
		stallo = true;
}
