// ==================================================================================
// Implement all functions that you listed by prototype in deck.h
// You may include additional helper functions as necessary
// All of your code must be in deck.h and deck.cpp
//
// NOTE: These are standalone functions, not part of a class.
// ==================================================================================

#include <iostream>
#include <cassert>
#include "playing_card.h"
#include "node.h"
#include "deck.h"
#include<random>

// ==================================================================================
//calculate the side of the list
int DeckSize( Node* &deck){
	//if the deck is empty, just return 0
	if(deck==NULL){return 0;}
	int count = 0;
	Node* temp = deck;
	count += 1;
	//go through the list and calculate how many nodes in the list
	while(temp -> after != NULL){
		temp = temp -> after;
		count ++;
	}
	return count;
}
bool SamePrimaryOrder ( Node* &deck1,  Node* &deck2){
	Node* temp1 = deck1;//temp1 points to deck1
	Node* temp2 = deck2;//temp2 points to deck2

	//going through the list and compare each card
	while(temp1->after != NULL && temp2->after != NULL){
		if(temp1 -> getCard() != temp2 -> getCard()){
			return false;
		}
		temp1 = temp1->after;
		temp2 = temp2->after;
	}
	return true;
}
bool  ReversePrimaryOrder ( Node* &deck1,  Node* &deck2){
	Node* temp1 = deck1;//temp1 points to deck 1
	Node* temp2 = deck2;//temp2 points to deck2
	//going through the list so the temp1 points to the last card
	while(temp1->after != NULL){
		temp1 = temp1->after;
	}
	//going through the list and compare each card in reverse order
	while(temp1->before != NULL && temp2->after != NULL){
		if(temp1 -> getCard() != temp2 -> getCard()){return false;}
		temp1 = temp1->before;
		temp2 = temp2->after;
	}
	return true;
}


Node* CopyDeck( Node* &deck){
	//first create and copy the first card
	PlayingCard pc = deck->getCard();
	Node* new_head = new Node(PlayingCard(pc.getSuit(), pc.getCard()));

	Node* temp_new_current = new_head;//this pointer points to the new card created
	Node* temp_old = deck;//points to the old deck in order to copy
	Node* temp_new_before = NULL;//points to the last new card created to the brfore can points back
	while(temp_old->after != NULL){
		temp_old = temp_old ->after;//increment
		PlayingCard pc = temp_old->getCard();//copy and create the new card
		temp_new_current->after = new Node(PlayingCard(pc.getSuit(), pc.getCard()));
		temp_new_before = temp_new_current;//update the pointer
		temp_new_current->after->before = temp_new_before;//points back 
		temp_new_current = temp_new_current->after;//update the pointer
	}
	SortHand(new_head);
	return new_head;
}



//delete deck similar to what we had in lecture note
void DeleteAllCards( Node* &deck){
	if(deck == NULL){}
	else{
		DeleteAllCards(deck->after);
		delete deck;
		deck = NULL;
	}
}

void CutDeck(Node* &deck, Node* &top, Node* &bottom, std::string type){
	if(type == "perfect"){
		if(DeckSize(deck) ==1){
			top = NULL;
			bottom = deck;
			deck = NULL;
			return;
		}

		int size = DeckSize(deck);//cal the size of deck
		int half = size/2;
		int count = half;
		Node* temp = deck;
		//let temp points the middle of that pointer
		while(count != 1){
			temp = temp -> after;
			count--;
		}
		//bot and top can point to where I want to
		bottom = temp->after;
		top = deck;
		//"cut" the deck into half
		bottom ->before = NULL;
		temp ->after = NULL;
	}

	if(type == "random"){
		//generate a random number 
		std::random_device rd;
		int size = DeckSize(deck);
		int half = size/2;
		int count = half + rd()%6+1;

		Node* temp = deck;
		//let temp points the middle of that pointer
		while(count != 1){
			temp = temp -> after;
			count--;
		}
		//bot and top can point to where I want to
		bottom = temp->after;
		top = deck;
		//"cut" the deck into half
		bottom ->before = NULL;
		temp ->after = NULL;
	}	
}

Node* Shuffle(Node* &top, Node* &bottom,std::string type){
	if(type == "perfect"){
		if(bottom == NULL && DeckSize(top) ==1){
			return top;
		}
		int count = DeckSize(top);
		if(DeckSize(top)== DeckSize(bottom)){//if top and bot are the same size
			Node* temp_top = top;//pointing to the top deck
			Node* temp_bottom_current = bottom;//pointing to the current element of bot
			Node* temp_bottom_after = bottom -> after;//pointing to the next element of bot

			while(count != 1){
				//making connection between elements(besically to the insert)
				temp_bottom_current -> after = temp_top->after;
				temp_top->after = temp_bottom_current;
				temp_bottom_current -> after ->before = temp_bottom_current;
				temp_bottom_current -> before = temp_top;
				//update all the pointers
				temp_top = temp_bottom_current->after;
				temp_bottom_current = temp_bottom_after;
				temp_bottom_after = temp_bottom_after->after;
				count --;
			}
			//add the last element
			temp_bottom_current -> after = temp_top->after;
			temp_top->after = temp_bottom_current;
			temp_bottom_current -> before = temp_top;

		}
		else{//if the bot and top are not the same size(assume top always > bot)
			//basically same as the first if statement
			Node* temp_top = top;
			Node* temp_bottom_current = bottom;
			Node* temp_bottom_after = bottom -> after;

			while(count != 1){
				//making connection
				temp_bottom_current -> after = temp_top->after;
				temp_top->after = temp_bottom_current;
				temp_bottom_current -> after ->before = temp_bottom_current;
				temp_bottom_current -> before = temp_top;
				//update the pointers
				temp_top = temp_bottom_current->after;
				temp_bottom_current = temp_bottom_after;
				if(temp_bottom_after != NULL){
					temp_bottom_after = temp_bottom_after->after;
				}
				count --;
			}
			

		}		
	}

	if(type == "random"){
		std::random_device rd1;//generate the first random num
		std::random_device rd2;//second
		int total = DeckSize(top) + DeckSize(bottom);//count the total deck size
		Node* temp_top = top;
		Node* temp_bot = bottom;
		while(bottom != NULL){
			int num_top = rd1()%6+1; //count the top part
			int num_bot = rd2()%6+1; //count the bot part
			//if the random number is smaller than bot size, then break the loop
			if(num_bot >= DeckSize(bottom)){break;}
			//push the temp_top randomly 
			while(num_top != 0){
				if(temp_top->after != NULL){
				temp_top = temp_top->after;}
				num_top--;
			}
			//push the temp_bot randomly
			while(num_bot != 0){
				temp_bot = temp_bot ->after;
				num_bot--;
			}

			Node* temp; //help to point to new bottom
			//then the rest of those is connecting nodes and update pointers
			temp = temp_bot -> after;
			temp_bot -> after = temp_top->after;
			temp_top ->after = bottom;
			bottom -> before = temp_top;
			temp_bot ->after ->before = temp_bot;
			bottom = temp;
			temp_bot = bottom;
		}
		//deal the rest of bot if there are still bottom cards left
		if(DeckSize(top) != total){
			while(temp_top -> after != NULL){temp_top = temp_top -> after;}
			temp_bot -> before = temp_top;
			temp_top ->after = temp_bot;
		}
	}
	return top;
}


Node* SortHand(Node* &deck){

	if(deck == NULL){return deck;}//corner case
	Node* d = deck;
	//first initialize the sorted_prev and sorted_next
	while(d != NULL){
		d->sorted_prev = NULL;
		d->sorted_next = NULL;
		d = d->after;
	}
	int count = DeckSize(deck);
	Node* sorted = deck;//started from the first element of deck
 	Node* item = deck->after;//item serves as temp pointer pointing to element need to be added next

	while(count != 1){
	  	Node* t2 = sorted;//t2 points to sorted elements to help to find where the item should insert
	  	while(t2 != NULL){
	   		Node* t1 = t2->sorted_prev;//t1 points to the one before sorted element(not necessary but easy for me to think)
	   		//there are three cases: insert in the top, insert at the end, and insert in the middle
	   		if(item->getCard() > t2->getCard()&&t2->sorted_next == NULL ){// insert bottom
	   			//making connection 
	    		item->sorted_prev = t2;
	    		item->sorted_prev->sorted_next = item;
	   			break;
	   		}
	   		if(item->getCard() < t2->getCard()&& t2->sorted_prev == NULL ){// insert top
	   			//rearrange the pointers and change the sorted pointer points to
			    item->sorted_next = t2;
			    t2->sorted_prev = item;
			    sorted = item;
		   		break; 
	   		}
	   		if(t1!= NULL&& t1->sorted_next  != NULL&& item->getCard() < t2->getCard() ){//insert in the middle
	   			//making connection between elements
			    item->sorted_next = t2;
			    item->sorted_prev = t1;
			    t1->sorted_next = item;
			    t2->sorted_prev = item;
			    break;
			}
	   		t2 = t2->sorted_next;//update t2
	  	}
	  	item = item->after;//update item
	 	count --;
	}
 	return sorted;
}
//print the sorted order of the deck, basically same as printdeckprimary
void PrintDeckSorted(const std::string &description, Node* deck) {
  std::cout << description;
  Node *tmp = deck;
  while (tmp != NULL) {
    std::cout << " " << tmp->getCard().getString();
    tmp = tmp->sorted_next;
  }
  std::cout << std::endl;
}

void Deal (Node* &deck, Node** hands, int people, const std::string& mode, int cards){
	if(mode == "one-at-a-time"){
		if (cards == 0){return;}
		if(people == 0){return;}
		
		int count = 0;
		//first deal the first card 
		while(count < people){
			hands[count] = deck;
			deck = deck ->after;
			deck ->before = NULL;
			hands[count]->after = NULL;
			count++; 
		}
		//create an array of temp pointers corresponding to hands
		Node* temp [people];
		for (int i = 0; i < people; ++i)
		{
			temp[i] = hands[i];
		}
		//then deal the rest of it
		while(cards != 1){
			count = 0;
			//deal the rest of the deck as need
			while( count < people){
				temp[count]->after = deck;//connect the hands
				deck = deck->after;//uptade the deck "top"
				temp[count]->after->before = temp[count];//connect back
				temp[count] = temp[count]->after;//update the temp to next
				count++;
			}
			//corner case: the after of last card on hand should point NULL 
			if(cards ==2){
				count = 0;
				while(count<people){
					temp[count]->after = NULL;
					count++;
				}
			}
			cards--;
		}
		//corner case: if deck is still lefting, cut deck->before
		if(deck != NULL){deck ->before = NULL;}
	}
}