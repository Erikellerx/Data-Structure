#include "playing_card.h"
#include "node.h"
#include <string>

// ==================================================================================
// prototypes for provided functions (implemented in main.cpp)
// ==================================================================================

bool SanityCheckPrimary(Node* top);
bool SanityCheckSorted(Node* first);
Node* CreateDeck(int numCards);
void DeckPushBackCard(Node* &deck, const std::string& suit, int num);
void PrintDeckPrimary(const std::string &description, Node* deck);


// ==================================================================================
//
// Write all the prototypes for the your functions here
// (they will be implemented in deck.cpp)
//
// NOTE: These are standalone functions, not part of a class.
//
// You may include additional helper functions as necessary
// All of your code must be in deck.h and deck.cpp
//
// ==================================================================================

int DeckSize( Node* &deck);
bool SamePrimaryOrder ( Node* &deck,  Node* &deck2);
bool ReversePrimaryOrder ( Node* &deck,  Node* &deck2);
Node* CopyDeck ( Node* &deck);
void Copy_all_list(Node* &old_head, Node* new_head);
void DeleteAllCards( Node* &deck);
void CutDeck(Node* &deck, Node* &top, Node* &bottom, std::string type);

Node* Shuffle(Node* &top, Node* &bottom, std::string type);

Node* SortHand(Node* &deck);


void PrintDeckSorted(const std::string &description, Node* deck);
void Deal (Node* &deck, Node** hands, int people, const std::string& mode, int cards);


