/********************************************************************* 
 ** Program Filename: final.cpp
 ** Author: Tristan Hari
 ** Date: 3/17/2015
 ** Description: A basic RPG type game to show inheritance
 ** Input: Directions
 ** Output: Virtual Reality
 *********************************************************************/
#include <iostream>
#include <stdlib.h>

using namespace std;

//Parent class for room, only used for polymorphic function
class Room {
private:
	static int lastRoom;
	int roomNum;
public:
	Room *north, *west, *east, *south;
	
	Room() { this->roomNum = ++lastRoom; }
	void Show();
	int getRoomNum() { return this->roomNum; }
	virtual string hasKey();
	virtual void tellStory();
	virtual void showHint();
	virtual void theBox(int havekey);
};

int Room::lastRoom = 0;

void Room::theBox(int havekey){
	
}


void PrintExit(Room *room, const char *label) {
	if(room){
		cout << label << "(" << room->getRoomNum() << ")";
	}
	
}

void Room::Show() {
	PrintExit(this, "Room") ; 
	cout << ": ";
	PrintExit(this->north, " (N)orth");
	PrintExit(this->west, " (W)est");
	PrintExit(this->east, " (E)ast");
	PrintExit(this->south, " (S)outh");
	cout << " (Q)uit";
	cout << endl;
}

string Room::hasKey(){
	return "No Key in room";
}

void Room::tellStory(){

}

void Room::showHint(){

}

//StoryRoom derived from Parent Room, contains flavor text.
class StoryRoom : public Room{
private:
	static int lastRoom;
	int roomNum;
public:
	StoryRoom *north, *west, *east, *south;
	
	StoryRoom(){
		this->roomNum = ++lastRoom;
	}
	void Show();
	int getRoomNum() { return this->roomNum; }
	string hasKey();
	void tellStory();
	void theBox();
};
int StoryRoom::lastRoom = 0;

//Flavor text for worthless rooms.
void StoryRoom::tellStory(){
	int rng = rand() % 4 + 1;
	
	if(rng == 1){
		cout << "Although the train is fairly well lit, it feels ominously dark" << endl;
		cout << "everywhere, a feeling that you cannot explain. Shaking the thought," << endl;
		cout << "you look around and see nothing of importance in this room..." << endl;
	}
	if(rng == 2){
		cout << "You feel the power of the train through your feet, it must be going" << endl;
		cout << "fairly fast. You wonder where it is going, how you even got here." << endl;
		cout << "Before the thought consumes you, you feel a sense of urgency and "<< endl;
		cout << "quickly scan the room finding nothing of importance. " << endl;
	}
	if(rng == 3){
		cout << "You can't help but begin to notice how old everything in the train" << endl;
		cout << "looks. Yet, all of it appears to be very clean. No cobwebs, no dust, " << endl;
		cout << "The thought passes away as you look around and find nothing important." << endl;		
	}
	if(rng == 4){
		cout << "You turn in a quick circle and realize there are no windows on the" << endl;
		cout << "train. Odd, trains normally have some sort of outlet. Nor are there" << endl;
		cout << "any exit doors. Just, what seems to be endless room after room..." << endl;
		cout << "You find nothing of importance in this room." << endl;
	}
	cout << endl;
}

string StoryRoom::hasKey(){
	return "No key in here.";
}

void StoryRoom::theBox(){
	
}

//room that contains a hint
class HintRoom : public Room{
private:
	static int lastRoom;
	int roomNum;
public:
	HintRoom *north, *west, *east, *south;
	
	HintRoom(){
		this->roomNum = ++lastRoom;
	}
	void Show();
	int getRoomNum() { return this->roomNum; }
	string hasKey();
	void showHint();
	void theBox();
};

int HintRoom::lastRoom = 0;

//Random hints for the player
void HintRoom::showHint(){
	int rng = rand() % 3 + 1;
	
	if(rng == 1){
		cout << "The room quickly darkens, and a sounds that is almost as faint as a breeze" << endl;
		cout << "grows to an audible state, you begin to hear the words.." << endl << endl;
		cout << "What is half of 138?" << endl << endl;
		cout << "The room immediately returns to it's original state of light as the voice" << endl;
		cout << "fades. Despite the oddness you quickly scan the room and see nothing else." << endl;	
	}
	if(rng == 2){
		cout << "The room quickly darkens, and a sounds that is almost as faint as a breeze" << endl;
		cout << "grows to an audible state, you begin to hear the words.." << endl << endl;
		cout << "What is 9 past sixty??" << endl << endl;
		cout << "The room immediately returns to it's original state of light as the voice" << endl;
		cout << "fades. Despite the oddness you quickly scan the room and see nothing else." << endl;	
	}
	if(rng == 3){
		cout << "The room quickly darkens, and a sounds that is almost as faint as a breeze" << endl;
		cout << "grows to an audible state, you begin to hear the words.." << endl << endl;
		cout << "What is the funniest number?" << endl << endl;
		cout << "The room immediately returns to it's original state of light as the voice" << endl;
		cout << "fades. Despite the oddness you quickly scan the room and see nothing else." << endl;	
	}
	cout << endl;
}

string HintRoom::hasKey(){
	return "No key in here.";
}

void HintRoom::theBox(){
	
}

//Class for a room that has a key in it..
//There can be multiple keys!
class KeyRoom : public Room{
private:
	static int lastRoom;
	int roomNum;
public:
	KeyRoom *north, *west, *east, *south;
	
	KeyRoom(){
		this->roomNum = ++lastRoom;
	}
	void Show();
	int getRoomNum() { return this->roomNum; }
	string hasKey();
	void theBox();
};

int KeyRoom::lastRoom = 0;

string KeyRoom::hasKey(){
	return "yea";
}

void KeyRoom::theBox(){
	
}

//Class for Room that has box in it to leave doom train
class FinalRoom : public Room{
private:
	static int lastRoom;
	int roomNum;
public:
	FinalRoom *north, *west, *east, *south;
	
	FinalRoom(){
		this->roomNum = ++lastRoom;
	}
	void Show();
	int getRoomNum() { return this->roomNum; }
	string hasKey();
	void theBox(int havekey);
};

int FinalRoom::lastRoom = 0;

//The finale function, its great.
void FinalRoom::theBox(int havekey){
	char putitin;
	int entry;
	
	cout << "You step into what appears to be an entirely dark room with" << endl;
	cout << "no doors in it besides the one you entered from. An ominous" << endl;
	cout << "beam of light shines on a small box in the middle of the room." << endl;
	cout << endl << "There appears to be a small keyhole in it...." << endl;
	
	if(havekey == 1){
		cout << "The key you found earlier appears that it would fit in the" << endl;
		cout << "box. Would you like to try it? You get the feeling that there is" << endl;
		cout << "No turning back once you put the key in. (y/n)" << endl;
		cin >> putitin;
		if(putitin == 'y'){
			cout << "You nervously insert the key into the strange box. It opens" << endl;
			cout << "to reveal a two number input, old, and made of iron. You move" << endl;
			cout << "your hands to touch it, and they are instantly pulled to it," << endl;
			cout << "unable to pull away. You realize you must enter the correct" << endl;
			cout << "combination or it all ends here. What do you enter?" << endl;
			cin >> entry;
			
			if(entry != 69){
				cout << "You die and everyone you've every loved dies too." << endl;
				cout << "WELCOME TO DOOM TRAIN MOTHERFUCKER..." << endl;
				exit(1);
			}else{
				cout << "You glow in blazing light as you realize this was the right" << endl;
				cout << "entry. You are immediately whisked away to your home and live" << endl;
				cout << "Happily ever after." << endl;
				exit(1);
			}
		}	
		else{
			
		}
	}else{
		cout << "Maybe you should find the key....." << endl;
	}
}

string FinalRoom::hasKey(){
}

//Intro to the program
void intro(){
	cout << endl << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "You wake up, the sound of heavy iron ringing in you ears, the smell of" << endl;
	cout << "smoke and coal in the air. As you prop yourself up on your elbows, you feel" << endl;
	cout << "the vibration in the floor, steady and strong. You look into your hand and" << endl;
	cout << "find a small piece of paper crumpled within. It reads..." << endl << endl;
	cout << "WELCOME TO THE DOOM TRAIN, FIND YOUR WAY OUT SOON OR PERISH" << endl << endl;
	cout << "You are unsure of what will happen next, but you dust yourself off and" << endl;
	cout << "bravely take a step into the first cart of the train..." << endl;

}

//Function that acts as the timer.
void doom_train(int &count){

	count++;
	if(count == 40){
		cout << " You have taken too long! The DOOM TRAIN takes it's wrath" << endl;
		cout << "upon you. You explode in a fury and you die." << endl;
		cout << "WELCOME TO THE DOOM TRAIN HA HA HA" << endl;
		exit(1);
	}
	if(count == 30){
		cout << "You feel ever closer to losing it, and you aren't sure why." << endl;
		cout << "You had better find a way out quickly or else." << endl;
	}
	if(count == 20){
		cout << " As more time passes you feel a more urgent presence to leave." << endl;
	}
	if(count == 10){
		cout << "A rush of worry pulls over you. You become more hurried to find" << endl;
		cout << "an exit." << endl;
	}
	cout << endl;
}

int main(int argc, char** argv) {
	
	Room *current_room;
	
	//Declare dungeon
	Room *room = new Room();
	//Room 2
	room->east = new StoryRoom();
	room->east->west = room;
		//TopRoom
		room->east->north = new HintRoom();
		room->east->north->south = room->east;
		//BottomRoom
		room->east->south = new StoryRoom();
		room->east->south->north = room->east;
	current_room = room->east;
	
	//Room 3
	current_room->east = new StoryRoom();
	current_room->east->west = current_room;
	current_room = current_room->east;
	
	//Room 4
	current_room->east = new StoryRoom();
	current_room->east->west = current_room;
	current_room = current_room->east;
		//toproom
		current_room->north = new KeyRoom();
		current_room->north->south = current_room;
		//BottomRoom
		current_room->south = new HintRoom();
		current_room->south->north = current_room;
	current_room->east = new StoryRoom();
	current_room->east->west = current_room;
	current_room = current_room->east;
	
	//Room 5
	current_room->east = new StoryRoom();
	current_room->east->west = current_room;
	//current_room = current_room->east;

	//Room 6
	current_room->east = new StoryRoom();
	current_room->east->west = current_room;
	current_room = current_room->east;
		//toproom
		current_room->north = new StoryRoom();
		current_room->north->south = current_room;
		//BottomRoom
		current_room->south = new StoryRoom();
		current_room->south->north = current_room;
	current_room->east = new StoryRoom();
	current_room->east->west = current_room;
	current_room = current_room->east;
	
	//Room 7
	current_room->east = new StoryRoom();
	current_room->east->west = current_room;
	
	//Room 8
	current_room->east = new StoryRoom();
	current_room->east->west = current_room;
	current_room = current_room->east;
		//toproom
		current_room->north = new HintRoom();
		current_room->north->south = current_room;
		//BottomRoom
		current_room->south = new StoryRoom();
		current_room->south->north = current_room;
	current_room->east = new FinalRoom();
	current_room->east->west = current_room;
	current_room = current_room->east;
	
	//Start at beginning
	current_room = room;	
	
	//Introduce player
	intro();
	
	current_room->Show();
	int count = 0, found_key = 0;
	char x;
	
	//Random Seed
	srand (time(NULL));
	do{
		
		cout << "Looking around, you decide to go..." << endl;
		cout << "***************************************************" << endl;
		cin >> x;
		switch(x){
			case 'e': //Go east
				if(current_room->east){
					current_room = current_room->east;
					cout << "You enter the room. " << endl << endl;
					current_room->showHint();
					current_room->tellStory();
					int tester = current_room->getRoomNum();
					//Find if it's the final room.
					if(tester == 19){
						current_room->theBox(found_key);
					}
					current_room->Show();
				}else{
					cout << "You can't go that way! No room there! Try again." << endl;
					current_room->Show();
				}
				break;
			case 'w': //Go west
				if(current_room->west){
					current_room = current_room->west;
					cout << "You enter the room. " << endl << endl;
					current_room->showHint();
					current_room->tellStory();
					current_room->Show();
				}else{
					cout << "You can't go that way! No room there! Try again." << endl;
					current_room->Show();
				}
				break;
			case 'n': //Go north
				if(current_room->north){
					current_room = current_room->north;
					cout << "You enter the room. " << endl << endl;
					current_room->showHint();
					//Check if room has a key in it.
					if(current_room->hasKey() == "yea"){
						cout << "Found A key! I wonder what it does...." << endl;
						found_key = 1;
					}
					current_room->tellStory();
					current_room->Show();
				}else{
					cout << "You can't go that way! No room there! Try again." << endl;
					current_room->Show();
				}
				break;
			case 's': //Go south
				if(current_room->south){
					current_room = current_room->south;
					cout << "You enter the room. " << endl << endl;
					current_room->showHint();
					//Check if room has a key in it.
					if(current_room->hasKey() == "yea"){
						cout << "Found A key! I wonder what it does...." << endl;
						found_key = 1;
					}
					current_room->tellStory();
					current_room->Show();
				}else{
					cout << "You can't go that way! No room there! Try again." << endl;
					current_room->Show();
				}
				break;
			case 'q':
				break;	
			default:
				cout << "You've entered an Invalid option tho. Try a valid input." << endl;
		}
		
		//Time the player
		doom_train(count);
		
	}while(!(x == 'q'));
	
	//End program.
	return (EXIT_SUCCESS);
}

