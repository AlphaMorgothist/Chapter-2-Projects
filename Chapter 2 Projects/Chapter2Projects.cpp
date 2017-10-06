// Chapter2Projects.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <random>
using namespace std;


int main()
{
	typedef unsigned short int uShort;
	uShort select;
	enum select { sGame = 1, GMN, pCode, GMNAI, Nim };
	int secNum = 0;
	do {
		random_device rd{};
		mt19937 engine{ rd() };
		uniform_int_distribution<int> dist{ 0,100 };
		int secNum = dist(engine);
		int tries = 5;
		int guess;
		int max = 0;
		int min = 0;
		int p1, p2;
		int sticks = 13;
		uShort sc1;
		uShort sc2;
		uShort sc3;
		cout << "\n\t\t\tChapter Two Project Menu" << endl;
		cout << "\nPlease select one of the following: \n" << endl;
		cout << "1: [Project 2.1] Score Game\n";
		cout << "2: [Project 2.2] Modified Guess My Number\n";
		cout << "3: [Project 2.3] Pseudocode GMN\n";
		cout << "4: [Project 2.4] Puter', Guess My Number!\n";
		cout << "5: [Project 2.5] Multi-Nim\n";
		cout << "6: Quit" << endl;
		cout << "\nSelection: ";
		cin >> select;
		system("CLS");
		switch (select) {
		case sGame:
			while (true) {
				while (true) {
					cout << "\n\t\tWelcome to The Score Game!" << endl;
					cout << "\nPlease provide a score from 1-100 for each of the following sports:\n" << endl;
					cout << "Soccor: ";
					cin >> sc1;
					if (sc1 <= 0 || sc1 > 100) {
						cout << "Please enter a valid number\n" << endl;
						system("pause");
						system("CLS");
					}
					else {
						break;
					}
				}
				while (true) {
					cout << "\nFootball: ";
					cin >> sc2;
					if (sc2 <= 0 || sc2 > 100) {
						cout << "Please enter a valid number\n" << endl;
						system("pause");
						system("CLS");
					}
					else {
						break;
					}
				}
				while (true) {
					cout << "\n Basketball: ";
					cin >> sc3;
					if (sc3 <= 0 || sc3 > 100) {
						cout << "Please enter a valid number\n" << endl;
						system("pause");
						system("CLS");
					}
					else {
						break;
					}
				}
				system("CLS");
				cout << "\nThank you for your input! We will now calculate your average scores..." << endl;
				system("pause");
				uShort scT = (sc1 + sc2 + sc3);
				cout << "\n\nYour Total Score: " << scT << endl;
				cout << "Your Average Score: " << (scT / 3) << endl;
				if (scT >= 200) {
					cout << "\nBased on your scores, you are quite talented!! Keep up the good work!" << endl;
				}
				else if (scT >= 100) {
					cout << "\nBased on your scores, you may be alright with a little more practice." << endl;
				}
				else if (scT >= 50) {
					cout << "\nBased on your scores, you might want to spend a little more time on the field." << endl;
				}
				else if (scT < 50) {
					cout << "\nBased on your scores, or lack thereof... you should probably \nstick to pencil-pushing." << endl;
				}
				cout << "\nThanks for Playing! " << endl;
				system("pause");
				break;
			}break;
		case GMN:
			while (true) {
				if (tries == 5) {
					cout << "\n\t\t\tWelcome to Guess My Number by Morgoth!" << endl;
				}
				cout << "\nYou have " << tries << " tries remaining to guess a randomly generated number between 1-100\n" << endl;
				if (tries == 5) {
					cout << "When you are ready to play please input a valid number for your first guess." << endl;
					cout << "Please avoid using anything in leiu of numbers, this breaks the game." << endl;
				}
				if (max != 0) {
					cout << "'Too High' Guess: " << max << endl;
				}
				if (min != 0) {
					cout << "'Too Low' Guess: " << min << endl;
				}
				cout << "\nGuess: ";
				cin >> guess;
				if (tries <= 0) {
					system("CLS");
					cout << "\nOh no! You ran out of tries!!" << endl;
					cout << "\nThanks for playing!\n" << endl;
					system("pause");
					break;
				}
				else if (guess > 100 || guess == 0 || guess == NAN) {
					system("CLS");
					cout << "\nPlease enter a valid number between 1-100" << endl;
					system("pause");
				}
				else if (guess > secNum) {
					system("CLS");
					cout << "\nThat number was too high!" << endl;
					max = guess;
					cout << "Your guess was: " << guess << endl;
					tries--;
				}
				else if (guess < secNum) {
					system("CLS");
					cout << "\nThat number was too low!" << endl;
					min = guess;
					cout << "Your guess was: " << guess << endl;
					tries--;
				}
				else if (guess == secNum) {
					system("CLS");
					cout << "\nYOU GUESSED THE SECRET NUMBER!" << endl;
					cout << "Your guess was: " << guess << endl;
					cout << "It took you " << 5 - tries << " tries to guess the number!" << endl;
					system("pause");
					system("CLS");
					break;
				}
			}
			break;

		case pCode:
			cout << "This is Select 3" << endl;
			system("pause");
			break;
		case GMNAI:
			cout << "This is Select 4" << endl;
			system("pause");
			break;
		case Nim:
			cout << "\n\t\t\tWelcome...TO NIM!!" << endl;
			cout << "\n\nHere are the Rules:\n\nPlayers take turns removing 1-4 sticks from a pile of 13\nThe player who picks up the last stick, wins.\n\nSimple, right?\n" << endl;
			system("pause");
			system("CLS");
			while (true) {
				cout << "Here we go! Everybody NIM!\n\n" << endl; 
				cout << "Number of sticks in the pile: " << sticks << endl;
				cout << "\n\nYou can remove up to 4 sticks" << endl;
				cout << "How many sticks would you like to remove? " << endl;
				cout << "\nPlayer One: ";
				cin >> p1;
				system("CLS");
				if (p1 > 4) {
					cout << "please choose a number between 1 and 4" << endl;
				}
				if (p1 <= 4) {
					sticks -= p1;
					if (sticks <= 0) {
						system("CLS");
						cout << "PLAYER ONE HAS... WELL, WON!" << endl;
						system("pause");
						break;
					}
				}
				cout << "Number of sticks in the pile: " << sticks << endl;
				cout << "\n\nYou can remove up to 4 sticks" << endl;
				cout << "How many sticks would you like to remove? " << endl;
				cout << "\nPlayer Two: ";
				cin >> p2;
				system("CLS");
				if (p2 > 4) {
					cout << "please choose a number between 1 and 4" << endl;
				}
				if (p2 <= 4) {
					sticks -= p2;
					if (sticks <= 0) {
						system("CLS");
						cout << "PLAYER TWO HAS WON!" << endl;
						system("pause");
						break;
					}
				}
}
			break;
		}system("CLS");

	} while (select <= 5);
    return 0;
}

