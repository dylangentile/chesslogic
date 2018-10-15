#include <iostream>
#include <string>;
#include "Source.h"
#include "nextTurn.h"
#include "logicEngine.h"

using namespace std;

char board[8][8];

bool iswhite = true;

//move x, move y
int xm, ym;
char piecem;

int xbe = -1, ybe = -1;





int chartoNum(char z) {

	if (z == 'a') {
		return 0;
	}
	else if (z == 'b') {
		return 1;
	}
	else if (z == 'c') {
		return 2;
	}
	else if (z == 'd') {
		return 3;
	}
	else if (z == 'e') {
		return 4;
	}
	else if (z == 'f') {
		return 5;
	}
	else if (z == 'g') {
		return 6;
	}
	else if (z == 'h') {
		return 7;
	}
	else {
		return 256;
	}

}



int algtocode(string alg) {
	
	if (alg.length() == 2) {

		int posx = chartoNum(alg[0]);


		//ASCII int for some reason so minus 48 to get to the value, and  minus one more for counting from 0
		int posy = alg[1] - 49;

		xm = posx;
		ym = posy;

		if (iswhite == true) {
			piecem = 'p';
		}
		if (iswhite == false) {
			piecem = 'P';
		}


	}
	else if (alg.length() == 3) {
		
		
		
		int posx = chartoNum(alg[1]);

		if (iswhite == true) {
			piecem = alg[0];
		}
		if (iswhite == false) {
			piecem = toupper(alg[0]);
		}

		//ASCII int for some reason so minus 48 to get to the value, and  minus one more for counting from 0
		int posy = alg[2] - 49;
		xm = posx;
		ym = posy;

	}
	else {
		cout << "\n\ninvalid\n\n";
	}


	return 0;
}




int printBoard() {
	int row = 7;
	
	int g=0;


	for (int x = 0; x < 64; x++) {
		cout << board[g][row] << ", ";

		if (g == 7) {
			row--;
			cout << '\n';
			g = g - 8;
		}
		g++;
	}

	return 0;
}


int setup() {

	//pawn loop

	for (int i = 0; i < 8; i++) {

		board[i][1] = 'p';
		board[i][6] = 'P';
	}

	//white rooks
	board[0][0] = 'r';
	board[7][0] = 'r';

	//black rooks
	board[0][7] = 'R';
	board[7][7] = 'R';

	//white knights
	board[1][0] = 'n';
	board[6][0] = 'n';

	//black knights
	board[1][7] = 'N';
	board[6][7] = 'N';

	//white bishops
	board[2][0] = 'b';
	board[5][0] = 'b';

	//black bishops
	board[2][7] = 'B';
	board[5][7] = 'B';

	//white&black kings
	board[4][0] = 'k';
	board[4][7] = 'K';

	//white&black queens
	board[3][0] = 'q';
	board[3][7] = 'Q';
	return 0;
}


int turnend() {


	iswhite = !iswhite;

	xbe = -1;
	ybe = -1;

	nextTurn();

	return 0;
}

int movePiece(string move) {

	algtocode(move);

	int z = 0;

	int yplane = 0;
	int k = 0;
	for (int i = 0; i < 64; i++) {
		if (board[k][yplane] == piecem) {
			if (whichOne(piecem, board[xm][ym], xm, ym, k, yplane) != false) {
				xbe = k;
				ybe = yplane;
				break;
			}
		}
		else {
			z++;
		}
		if (k == 7) {
			yplane++;
			k = k - 8;
		}
		k++;
	}

	if (ybe == -1 || xbe == -1) {
		failTurn();
	}


	

	



	board[xbe][ybe] = ' ';
	board[xm][ym] = piecem;
	turnend();
	return 0;
}

int makeMove() {
	printBoard();

	string in;

	cin >> in;

	movePiece(in);
	return 0;
}
int main() {
	setup();

	makeMove();

	cout << "\n\n";
	system("PAUSE");
	return 0;

}