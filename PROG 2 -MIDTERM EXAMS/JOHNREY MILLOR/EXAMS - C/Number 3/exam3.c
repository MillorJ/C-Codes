#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Title Deed structure
typedef struct {
	int id;
	char name[20];
	char color[20];
	double amount[9]; 			// rent lot but empty, 1, 2, 3, 4, hotel, mortgage, house cost, hotel cost (house cost * 5) 
	int houseCount;				// will be used only if players owns already the property
	int hotelCount;				// will be used only if players owns already the property
	int mortgage;				// will be used only if players owns already the property and value is 1 - under mortgage, 0 - not in mortgage 
} TitleDeed;

typedef struct {
	char cardType[20];
	char cardDescription[100];
} Card, Cards[16];

// Used to store Title Deeds in a linkled list 
typedef struct prop {
	TitleDeed lot;
	struct prop *next;
} Prop, *PropLList, *SortedPropLList;

// Used to store Title Deeds in an array list 
typedef struct {
	TitleDeed *lot;
	int count;
	int max;
} PropAList, SortedPropAList;

// Player structure
typedef struct {
	int id;
	SortedPropLList owned;		// initially empty but insertSorted when adding ownership to a title deed based on id
	int moneyCount[7];			// 2pcs-$500, 2pcs-$100, 2pcs-$50, 6pcs-$20, 5pcs-$10, 5pcs-$5, 5pcs-$1
	double totalMoney;			// $1500
	int position;				// current position in board starts at 0
} Player;

// GameBoard structure
typedef struct {
	PropLList ownedBank;		// the collection of title deeds not yet owned by a player
	int boardLot[40];			// compromises the lot area
	int moneyCount[7];			// 30pcs-$500, 30pcs-$100, 30pcs-$50, 30pcs-$20, 30pcs-$10, 30pcs-$5, 30pcs-$1
	double totalMoney;			// $20580
	Player players[8];			// players of the game
	int playerCount;			// current count of players
	int houseCount;				// 32 houses
	int hotelCount;				// 12 hotels
	Cards chance;				// chance cards
	int currChanceTop;			// initially starts at 0 then moves once the player lands a chance lot
	Cards communityChest;		// commmunity chest cards
	int currCommunityChestTop;	// initially starts at 0 then moves once the player lands a community chest lot
	int dice[2];				// will contain the dice values (0 for the dice 1 and 1 for dice 2)
} GameBoard;

//	> 0 special(-1 community chest, -2 chance, -3 free parking, -4 income tax, -5 jail, -6 electric company, -7 water works, -8 road 1, -9 road 2, -10 road 3, -11 road 4, -12)
//  0 owned by bank, id of the player if lot is owned by a player
//  initial value of board lot 0, *0, -1, *0, -4, -8, !0, -2, !0, !0, -5, *0, -6, *0, *0, -9, !0, -1, !0, !0, -3, *0, -2, *0, *0, -10, !0, !0, -7, !0, -12, *0, *0, -1, *0, -11, -2, !0, -4, !0

// must implement
bool acquireProperty(GameBoard * board, int player_id, int property_id);

// place the other function prototypes needed
void initGameBoard(GameBoard *board);
bool addPlayer(GameBoard *board, int player_id);
PropAList readTitleDeed(char filename[], char mode[]);
void displayTitleDeed(TitleDeed td);


int main(int argc, char *argv[]) {
GameBoard board;
initGameBoard(&board);


addPlayer(&board, 1);
addPlayer(&board, 2);
addPlayer(&board, 3);
	return 0;
}
PropAList readTitleDeed(char filename[], char mode[]) {
	FILE *fp;
    PropAList titles;
    titles.count = 0;
    titles.max = 10;
    titles.lot = (TitleDeed *)malloc(sizeof(TitleDeed) * titles.max);

    fp = fopen(filename, mode);
    if (fp == NULL) {
        printf("Error: Could not open %s file\n", filename);
        exit(1);
    }

    while (!feof(fp)) {
        if (titles.count >= titles.max) {
            titles.max *= 2;
            titles.lot = (TitleDeed *)realloc(titles.lot, sizeof(TitleDeed) * titles.max);
        }

        fscanf(fp, "%d %s %s %lf %lf %lf %lf %lf %lf %lf %d %d %d %d", &titles.lot[titles.count].id, titles.lot[titles.count].name, titles.lot[titles.count].color,
            &titles.lot[titles.count].amount[0], &titles.lot[titles.count].amount[1], &titles.lot[titles.count].amount[2],
            &titles.lot[titles.count].amount[3], &titles.lot[titles.count].amount[4], &titles.lot[titles.count].amount[5],
            &titles.lot[titles.count].amount[6], &titles.lot[titles.count].houseCount, &titles.lot[titles.count].hotelCount,
            &titles.lot[titles.count].mortgage);
        titles.count++;
    }

    fclose(fp);
    return titles;
}

void displayTitleDeed(TitleDeed td) {
	printf("%2d - %30s - %15s", td.id, td.name, td.color);
}
void initGameBoard(GameBoard *board) {
	int i;
    board->ownedBank = NULL;
    for (i = 0; i < 40; i++) {
        board->boardLot[i] = 0;
    }
    for (i = 0; i < 7; i++) {
        board->moneyCount[i] = 0;
    }
    board->totalMoney = 20580;
    board->playerCount = 0;
    board->houseCount = 32;
    board->hotelCount = 12;
    board->currChanceTop = 0;
    board->currCommunityChestTop = 0;
    board->dice[0] = 0;
    board->dice[1] = 0;
    for (i = 0; i < 16; i++) {
        strcpy(board->chance[i].cardType, "");
        strcpy(board->chance[i].cardDescription, "");
        strcpy(board->communityChest[i].cardType, "");
        strcpy(board->communityChest[i].cardDescription, "");
    }
}

bool addPlayer(GameBoard *board, int player_id) {

    if (board->playerCount >= 8) {
        return false;
    }
    
    board->playerCount++;

    Player newPlayer;
    newPlayer.id = player_id;

   
    newPlayer.owned = NULL;

    newPlayer.moneyCount[0] = 2;
    newPlayer.moneyCount[1] = 2;
    newPlayer.moneyCount[2] = 2;
    newPlayer.moneyCount[3] = 6;
    newPlayer.moneyCount[4] = 5;
    newPlayer.moneyCount[5] = 5;
    newPlayer.moneyCount[6] = 5;

    newPlayer.totalMoney = 1500;

    newPlayer.position = 0;

    board->players[board->playerCount - 1] = newPlayer;

    return true;
}



