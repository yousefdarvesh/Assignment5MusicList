// Assignment5MusicList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include <sstream>
#include <string>
using namespace std;

stringstream Song;
string Songs;
int songNumber = 1;
class Node
{
	string file;
	Node* type;
public:
	Node() {};
	void SetFile(string aFile) { file = aFile; };
	void SetNext(Node* aType) { type = aType; };
	string File() { return file; };
	Node* Type() { return type; };
};
class List
{
	Node *head;
public:
	List() { head = NULL; };
	void Display();
	void playSong();
	void insertSong(string file);
	void deleteSong(string file);
	void DeleteTheSong(int delNum);
	void skipSong(int num);
};
void List::Display()
{
	Node *tmp = head;
	int i = 1;
	if (tmp == NULL)
	{
		cout << "The Play List is EMPTY" << endl;
		return;
	}
	if (tmp->Type() == NULL)
	{
	}
	else
	{
		do
		{
			cout << i;
			cout << ": \t";
			cout << tmp->File() << endl;
			tmp = tmp->Type();
			i++;
		} while (tmp != NULL);
	}
}
void List::playSong()
{
	Node *tmp = head;
	int i = 1;
	if (tmp == NULL)
	{
		cout << "The Play List is EMPTY" << endl;
		return;
	}
	if (tmp->Type() == NULL)
	{
	}
	else
	{
		do
		{
			if (songNumber == i)
			{
				cout << " Currently playing Song " << endl;
				cout << i;
				cout << ":";
				cout << tmp->File() << endl;
				cout << endl << endl;
			}
			tmp = tmp->Type();
			i++;
		} while (tmp != NULL);
	}
}
void List::insertSong(string file)
{
	Node* newNode = new Node();
	newNode->SetFile(file);
	newNode->SetNext(NULL);
	Node *tmp = head;
	if (tmp != NULL)
	{
		while (tmp->Type() != NULL)
		{
			tmp = tmp->Type();
		}

		tmp->SetNext(newNode);
	}
	else
	{
		head = newNode;
	}
}
void List::deleteSong(string file)
{
	Node *tmp = head;
	if (tmp == NULL)
		return;
	if (tmp->Type() == NULL)
	{
		delete tmp;
		head = NULL;
	}
	else
	{
		Node *prev = NULL;
		do
		{
			if (tmp->File() == file) break;
			prev = tmp;
			tmp = tmp->Type();
		} while (tmp != NULL);
		prev->SetNext(tmp->Type());
		delete tmp;
	}
}
void List::DeleteTheSong(int delNum)
{
	Node *tmp = head;
	int i = 1;
	if (tmp == NULL)
		return;
	if (tmp->Type() == NULL)
	{
		delete tmp;
		head = NULL;
	}
	else
	{
		Node *prev = NULL;
		do
		{
			if (i == delNum)
			{
				cout << "Current song has been deleted";
				break;
			}
			prev = tmp;
			tmp = tmp->Type();
			i++;
		} while (tmp != NULL);
		prev->SetNext(tmp->Type());
		delete tmp;
	}
}
void List::skipSong(int num)
{
	cout << endl;
	cout << endl;
	Node *tmp = head;
	int i = 1;
	if (tmp == NULL)
	{
		cout << "The Play List is EMPTY" << endl;
		return;
	}


	if (tmp->Type() == NULL)
	{
		cout << "No Song on the list" << endl;
	}
	else
	{
		do
		{
			if (i == num)
			{
				cout << "currently Song playing: \t";
				cout << tmp->File() << endl;
			}
			tmp = tmp->Type();
			i++;
		} while (tmp != NULL);
	}
}
int main()
{
	List list;
	int length = 0;
	ifstream myReadFile;
	myReadFile.open("myPlayList.txt");
	string temp;
	while (getline(myReadFile, temp))
	{
		length++;
		list.insertSong(temp);
	}
	list.Display();
	cout << endl << endl;
	char ans;
	int skipnum = 0;
	do
	{
		cout << "\n1: Play a Song \n2: Skip a Song \n3: Delete a Song\n4: Play Next\n5: Display Play List\n6: Exit play List " << endl;
		cin >> ans;
		if (ans == '1')
		{
			if (songNumber>length)
				songNumber = 1;
			list.playSong();
		}
		if (ans == '2')
		{
			cout << "Please enter the number of song you want to skip :";
			cin >> skipnum;
			if (skipnum <= length)
			{
				list.skipSong(skipnum);
				songNumber = skipnum;
			}
			else
			{
				cout << "The number you entered is not in the current play list.";
			}
		}
		if (ans == '3') {
			list.DeleteTheSong(songNumber);
		}
		if (ans == '4')
		{
			songNumber++;
			if (songNumber>length)
			{
				songNumber = 1;
			}
			list.playSong();
		}
		if (ans == '5')
		{
			list.Display();
		}
	} while (ans != '6');
}

