#include <iostream>
#include <List>
#include <functional>
#include <iterator>
#include <algorithm>
#include <string>

// task: find word in matrix

using namespace std;

static const string myString = "slvqhelqsltphelp";
static const string anotherString = "qrsycrolfssdtroa";
char** convertStringToMatrix(string s);
pair<int, int> findChordsOfLetter(char letter, char** matrix, int orderOfLetter);
void resetMatrixToNulls(bool** matrix, int len);
int findDirectionToGo(bool** boolMatrix, char** matrix, pair<int, int> currentLetterIndex, string word, int indexOfLetterInWord,
	list<pair<int, int>> goingBackLettersChords, int lenghtOfRow);
bool isInList(int x, int y, list<pair<int, int>> restrictedList);
void solvePuzzle(string startString, string wordToFind);



int main() {
	//solvePuzzle(myString, "help");
	solvePuzzle(anotherString, "crossroad");
}

char** convertStringToMatrix(string s) {
	//This function converts string to square matrix

	const int n = int(sqrt(s.length()));
	char** matrix = new char*[n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new char[n];
	}
	unsigned int indexOfLetter = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = s[indexOfLetter];
			indexOfLetter++;
		}
	}
	return matrix;
	
}

pair<int, int> findChordsOfLetter(char letter, char** matrix, int orderOfLetter) {

	//Function to find chords of letter in matrix, orderOfLetters - how many time should we skip our letter
	//Use it to find first letter of the word

	pair<int, int> chords;
	chords.first = -1;
	chords.second = -1;
	for (int i = 0; i < sqrt(myString.length()); i++) {
		for (int j = 0; j < sqrt(myString.length()); j++) {
			if (matrix[i][j] == letter) {
				if (orderOfLetter != 0) {
					orderOfLetter--;
					continue;
				}
				
				chords.second = i;
				chords.first = j;
				return chords;
			}
		}
	}
	return chords;
}

void resetMatrixToNulls(bool** matrix, int lenghtOfRow) {
	/*
	reset matrix to 0
	*/
	for (int i = 0; i < lenghtOfRow; i++) {
		for (int j = 0; j < lenghtOfRow; j++) {
			matrix[i][j] = false;
		}
	}
}



int findDirectionToGo(bool** boolMatrix, char** matrix, pair<int, int> currentLetterIndex, string word, int indexOfLetterInWord, 
	list<pair<int, int>> goingBackLettersChords, int lenghtOfRow) {
	/* 
	This function finds direction to go will finding letter with index in the word, returns direction
	4 lambdas which return bool values calculate if charater of the word is equal to character in matrix,
	checks if it's already been used with help of boolMatrix, and checks if program already visited letter in this iteration.

	*/

	// right 1, bottom 2, left 3, up 4, can't find 0

	int x = currentLetterIndex.first;

	int y = currentLetterIndex.second;
	bool isRight;
	auto checkRight = [](int x, int y, bool** boolMatrix, char** matrix, string word, int indexOfLetterInWord, 
		list<pair<int,int>> goingBackLettersChords) {
		return (matrix[y][x + 1] == word[indexOfLetterInWord] && boolMatrix[y][x + 1] != true &&
			isInList(y, x + 1, goingBackLettersChords) != true) ? true : false;
	};

	bool isLeft;
	auto checkLeft = [](int x, int y, bool** boolMatrix, char** matrix, string word, int indexOfLetterInWord, 
		list<pair<int, int>> goingBackLettersChords) {
		return (matrix[y][x - 1] == word[indexOfLetterInWord] && boolMatrix[y][x - 1] != true &&
			isInList(y, x - 1, goingBackLettersChords) != true) ? true : false;
	};
	
	bool isTop;
	auto checkTop = [](int x, int y, bool** boolMatrix, char** matrix, string word, int indexOfLetterInWord,
		list<pair<int, int>> goingBackLettersChords) {
		return (matrix[y - 1][x] == word[indexOfLetterInWord] && boolMatrix[y - 1][x] != true &&
			isInList(y - 1, x, goingBackLettersChords) != true) ? true : false;
	};

	bool isBottom;
	auto checkBottom = [](int x, int y, bool** boolMatrix, char** matrix, string word, int indexOfLetterInWord, 
		list<pair<int, int>> goingBackLettersChords) {
		return (matrix[y + 1][x] == word[indexOfLetterInWord] && boolMatrix[y + 1][x] != true &&
			isInList(y + 1, x, goingBackLettersChords) != true) ? true : false;
	};
	//left top
	if (x == 0 && y == 0) {
		isBottom = checkBottom(x, y, boolMatrix, matrix, word, indexOfLetterInWord, goingBackLettersChords);
		isRight = checkRight(x, y, boolMatrix, matrix, word, indexOfLetterInWord, goingBackLettersChords);
		return isRight ? 1 : isBottom ? 2 : 0;
	} 
	//left bottom
	else if (x == 0 && y == lenghtOfRow - 1) {
		isTop = checkTop(x, y, boolMatrix, matrix, word, indexOfLetterInWord, goingBackLettersChords);
		isRight = checkRight(x, y, boolMatrix, matrix, word, indexOfLetterInWord, goingBackLettersChords);
		return isRight ? 1 : isTop ? 4 : 0;
	}
	//right bottom
	else if (x == lenghtOfRow - 1 && x == y) {
		isTop = checkTop(x, y, boolMatrix, matrix, word, indexOfLetterInWord, goingBackLettersChords);
		isLeft = checkLeft(x, y, boolMatrix, matrix, word, indexOfLetterInWord, goingBackLettersChords);
		return isLeft ? 3 : isTop ? 4 : 0;

	}
	//right top
	else if (x == lenghtOfRow - 1 && y == 0) {
		isBottom = checkBottom(x, y, boolMatrix, matrix, word, indexOfLetterInWord, goingBackLettersChords);
		isLeft = checkLeft(x, y, boolMatrix, matrix, word, indexOfLetterInWord, goingBackLettersChords);
		return isBottom ? 2 : isLeft ? 3 : 0;
	}
	//just top
	else if (y == 0) {
		isBottom = checkBottom(x, y, boolMatrix, matrix, word, indexOfLetterInWord, goingBackLettersChords);
		isLeft = checkLeft(x, y, boolMatrix, matrix, word, indexOfLetterInWord, goingBackLettersChords);
		isRight = checkRight(x, y, boolMatrix, matrix, word, indexOfLetterInWord, goingBackLettersChords);
		return isRight ? 1 : isBottom ? 2 : isLeft ? 3 : 0;
	}
	//just left
	else if (x == 0) {
		isBottom = checkBottom(x, y, boolMatrix, matrix, word, indexOfLetterInWord, goingBackLettersChords);
		isRight = checkRight(x, y, boolMatrix, matrix, word, indexOfLetterInWord, goingBackLettersChords);
		isTop = checkTop(x, y, boolMatrix, matrix, word, indexOfLetterInWord, goingBackLettersChords);
		return isRight ? 1 : isBottom ? 2 : isTop ? 4 : 0;
	}
	//just bottom
	else if (y == lenghtOfRow - 1) {
		isLeft = checkLeft(x, y, boolMatrix, matrix, word, indexOfLetterInWord, goingBackLettersChords);
		isRight = checkRight(x, y, boolMatrix, matrix, word, indexOfLetterInWord, goingBackLettersChords);
		isTop = checkTop(x, y, boolMatrix, matrix, word, indexOfLetterInWord, goingBackLettersChords);
		return isRight ? 1 : isLeft ? 3 : isTop ? 4 : 0;
	}
	//just right
	else if (x == lenghtOfRow - 1) {
		isBottom = checkBottom(x, y, boolMatrix, matrix, word, indexOfLetterInWord, goingBackLettersChords);
		isTop = checkTop(x, y, boolMatrix, matrix, word, indexOfLetterInWord, goingBackLettersChords);
		isLeft = checkLeft(x, y, boolMatrix, matrix, word, indexOfLetterInWord, goingBackLettersChords);
		return isBottom ? 2 : isLeft ? 3 : isTop ? 4 : 0;
	}
	//centre
	else {
		isBottom = checkBottom(x, y, boolMatrix, matrix, word, indexOfLetterInWord, goingBackLettersChords);
		isRight = checkRight(x, y, boolMatrix, matrix, word, indexOfLetterInWord, goingBackLettersChords);
		isTop = checkTop(x, y, boolMatrix, matrix, word, indexOfLetterInWord, goingBackLettersChords);
		isLeft = checkLeft(x, y, boolMatrix, matrix, word, indexOfLetterInWord, goingBackLettersChords);
		return isRight ? 1 : isBottom ? 2 : isLeft ? 3 : isRight ? 4 : 0;
	}
}

bool isInList(int y, int x, list<pair<int, int>> restrictedList) {
	/*
	returns if list has element with first == x and second == y
	*/
	for (auto i = restrictedList.begin(); i != restrictedList.end(); i++) {
		if (i->first == x && i->second == y) {
			return true;
		}
	}
	return false;
}

void solvePuzzle(string startString, string wordToFind) {

	/*
	function to solve the puzzle
	*/

	//transform strings to lower case
	std::transform(startString.begin(), startString.end(), startString.begin(),
		[](unsigned char c) { return std::tolower(c); });
	std::transform(wordToFind.begin(), wordToFind.end(), wordToFind.begin(),
		[](unsigned char c) { return std::tolower(c); });

	
	int lenghtOfRow = int(sqrt(startString.length()));


	char** matrix = convertStringToMatrix(startString);


	//information about puzzle
	/*
	cout << "searching word: " << wordToFind << endl;
	cout << "in matrix:" << endl;
	for (int i = 0; i < lenghtOfRow; i++) {
		for (int j = 0; j < lenghtOfRow; j++) {
			cout << matrix[i][j];
			if (j < lenghtOfRow - 1) {
				cout << ", ";
			}
		}
		cout << endl;
	}
	*/

	//matrix to check if letter has been already used in iteration

	bool** boolMatrix = new bool*[lenghtOfRow];
	for (int i = 0; i < lenghtOfRow; i++) {
		boolMatrix[i] = new bool[lenghtOfRow];
		for (int j = 0; j < lenghtOfRow; j++) {
			boolMatrix[i][j] = false;
		}
	}

	//current index of letter
	int index = 0;

	//variable to define which first letter of the word in matrix we'll use
	int timesToSkip = 0;
	

	char currentLetter = wordToFind[index];

	pair<int, int> currentLetterChords = findChordsOfLetter(currentLetter, matrix, timesToSkip);
	

	//chords of letters of word which were found
	list<pair<int, int>> chordsOfLetters;
	//chords of letter which we have to ignore
	list<pair<int, int>> goingBackLetterChords;

	//variables to check if we should clear list with chords we have to ignore
	int goingUp = 1;
	int goingBack = 0;
	int deb = 0;
	//set to matrix that letter is taken, push lettter to word list, pop letter from begining word
	boolMatrix[currentLetterChords.first][currentLetterChords.second] = true;

	chordsOfLetters.push_back(currentLetterChords);

	//if it's empty we found word
	list<char> lettersOfWord;

	for (int i = 0; i < wordToFind.length(); i++) {
		lettersOfWord.push_back(wordToFind[i]);
	}
	lettersOfWord.pop_front();

	index++;

	currentLetter = wordToFind[index];
	int direction = 0;
	while (currentLetterChords.first != -1 && currentLetterChords.second != -1 && !lettersOfWord.empty()) { 

		if (goingUp > 1 || (goingBack > 1 && direction != 0)) {
			goingBackLetterChords.clear();
		}
	
		direction = findDirectionToGo(boolMatrix, matrix, currentLetterChords, wordToFind, index, goingBackLetterChords, lenghtOfRow);
		
		switch (direction) {
			case 1:
				goingUp++;
				goingBack = 0;
				index++;

				currentLetter = wordToFind[index];
				boolMatrix[currentLetterChords.second][currentLetterChords.first] = true;
				currentLetterChords.first = currentLetterChords.first + 1;
				
				chordsOfLetters.push_back(currentLetterChords);
				lettersOfWord.pop_front();
				break;
			case 2:
				goingUp++;
				goingBack = 0;
				index++;
				currentLetter = wordToFind[index];
				
				boolMatrix[currentLetterChords.second][currentLetterChords.first] = true;
				currentLetterChords.second = currentLetterChords.second + 1;
				chordsOfLetters.push_back(currentLetterChords);
				lettersOfWord.pop_front();

				break;
			case 3:
				goingUp++;
				goingBack = 0;
				index++;
				
				currentLetter = wordToFind[index];
				boolMatrix[currentLetterChords.second][currentLetterChords.first] = true;
				currentLetterChords.first = currentLetterChords.first - 1;
				chordsOfLetters.push_back(currentLetterChords);
				lettersOfWord.pop_front();
				break;

			case 4:
				goingUp++;
				goingBack = 0;
				index++;
				
				currentLetter = wordToFind[index];
				boolMatrix[currentLetterChords.second][currentLetterChords.first] = true;
				currentLetterChords.second = currentLetterChords.second - 1;
				chordsOfLetters.push_back(currentLetterChords);
				lettersOfWord.pop_front();
				break;

			case 0:
			
				index--;
				if (index < 0) {
					index = 0;
				}
				goingBack++;		
				goingUp = 0;
				
				goingBackLetterChords.push_front(currentLetterChords);
				currentLetter = wordToFind[index];
				boolMatrix[currentLetterChords.second][currentLetterChords.first] = false;
				if (!chordsOfLetters.empty()) {
					chordsOfLetters.pop_back();
				}
				lettersOfWord.push_front(currentLetter);
				if (!chordsOfLetters.empty()) {
					currentLetterChords = chordsOfLetters.back();
				}
				if (index - 1 == 0) {
					timesToSkip++;
					resetMatrixToNulls(boolMatrix, lenghtOfRow);
					currentLetterChords = findChordsOfLetter(wordToFind[0], matrix, timesToSkip);
					chordsOfLetters.pop_back();
					chordsOfLetters.push_back(currentLetterChords);
				}
				break;
		}
	}
	if (!lettersOfWord.empty() ) {
		std::cout << "Can't find the word";
	}
	else {
		int counter = 0;
		for (auto i = chordsOfLetters.begin(); i != chordsOfLetters.end(); i++) {
			std::cout << "[" << i->second << "," << i->first << "]";
			counter++;
			if (counter < chordsOfLetters.size()) {
				std::cout << " -> ";
			}
		}
	}
	for (int i = 0; i < lenghtOfRow; i++) {
		delete[] boolMatrix[i];
		delete[] matrix[i];
	}
	delete[] boolMatrix;
	delete[] matrix;


}