#include <string>
#include "logicEngine.h"


using namespace std;


bool isWhite;

bool whichOne(char pieceType, char pieceTo, int moveToX, int moveToY, int moveFromX, int moveFromY) {
	if (isupper(pieceType)) {
		isWhite = false;
		pieceType = tolower(pieceType);
	}
	else {
		isWhite = true;
	}


	if (pieceType != 'p') {
		return true;
	}

	if (pieceType == 'p') {
		if (isWhite == false) {
			if (moveFromY-moveToY > 0 && moveFromY - moveToY < 3) {
				if (moveFromY - moveToY == 2 && moveFromY == 6) {
					if (moveFromX != moveToX) {
						return false;
					}
					else {
						return true;
					}
				}
				else {
					if (moveFromX != moveToX) {
						return false;
					}
					else {
						return true;
					}
				}
			}
		}
		else {
			if (moveToY - moveFromY > 0 && moveToY - moveFromY < 3) {
				if (moveToY - moveFromY == 2 && moveFromY == 1) {
					if (moveFromX != moveToX) {
						//if (pieceTo != ' ') {
						//	if()
						//}
						return false;
					}
					else {
						return true;
					}
				}
				else {
					if (moveFromX != moveToX) {
						return false;
					}
					else {
						return true;
					}
				}
			}
		}
	}
	




	return false;
}