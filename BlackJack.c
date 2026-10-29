#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define RANKS 13
#define SUITS 4 
#define TOTALCARDS 52
#define BIGENOUGH 128
#define STR_END '\0'


/*
Game rules

- A cards value is determined by its face
    - If a cards face is 3 its value is 3
- Cards with Jack, Queen, or King face, are all worth 10
- An Ace has a value of 11 unless that makes your score exceed 21, in which case their value is 1

- At the start the player and dealer get 2 cards
- dealer has one card visible to the player, the other is hidden.

- player can choose to hit or stand
    - hitting means the player gets another card and adds to their current value
    - standing means the person doesnt draw a new card
- if hitting causes the player to go over a value of 21 they "bust" resulting in a loss

-after the player makes a decision the dealer can decide to hit or stand
    - Dealer hits below 17 and stands at 17 or higher(common practice in casinos).
-If the dealer and the player stand then the game ends

- At the end if the players value is greater than the dealer's, the player wins 
*/

void getCardText(int, int, char[]);//fucntion for printing the text of a card when given its array position
void drawCard(int[][SUITS], int hand[][12], int *);//function that will pick a random rank and suit then add it to the given hand
void printHand(int hand[][12], int count);//function will print each card in the given hand
void printDeck(int[][SUITS]);//print the deck

 

int main(){
    int column = 0;
    int row    = 0;
    int pCards = 0;//keep track of how many cards player has
    int dCards = 0;//keep track of how many cards dealer has

    int deck[13][4];
    int pHand[2][12] = {0}; 
    int dHand[2][12] = {0}; 

    srand(time(NULL));//set seed for random nums
    
    /*
    RULES FOR ARRAY

    - 13 rows, row 0 is an Ace, row 1 is a 2, etc. Jack Queen and King cards are, 10, 11, 12
    - 4 columns, 0 is hearts, 1 is diamonds, 2 is clubs, 3 is spade
        - so a 4 of clubs would be deck[3][2];
    - in the arary, by deafult every cell is set to 1.
    - a value of 1 for a cell means that card is still in the deck
    - when a card is drawn it is either set to 0 or 2
        - 0 means in the player hand 
        - 2 means in the dealer hand

    */
    /*
        Game starts
        player and dealer have 2 cards
            player can only see one of dealers cards.
        player decides to hit or stand, once they decide to stand, its the dealers turn 
        dealer flips their face down card, and hits until they are at 17 or higher
        this means the program needs a way to determine which card was draw first for the dealer, that way, while the second card is face down we only print the first card that was drawn

        best way to handle this with code
            -player and dealer pick 2 cards at the start.
            -if it is still the players turn, everytime they are prompted to stand or hit, it should print out their cards and dealers
            -so while we are still in the game loop, we need to only print the first card the dealer drew.
            -but this means we need a way to store the order the cards are drwan and added to each hand
                - this could be done by making two new arrays. 
                - playerHand[2][12]; 
                - dealerHand[2][12];    
                - think of it like this: [][][][][]...
                                        [][][][][]...
                - player draws a 2 of hearts deck[2][0]: [1][][][][]...
                                                        [0][][][][]...

                - player draws a 6 of clubs deck[5][2]:  [1][5][][][]...
                                                        [0][2][][][]...

                - each column represents one card
                    - row 0 stores the cards rank position in deck[][]
                    - row 1 stores the cards suit position in deck[][]
                - so, in the program when i want to print the first card in the dealers hand, i can do:
                - getCardText(dealerHand[0][0], dealerHand[1][0], string)
                - Awesome!
    */ 

    //set every value in the deck to 1, meaning every card is in the deck
    for(int i = 0; i < RANKS; i++){
        for(int j = 0; j < SUITS; j++){
            deck[i][j] = 1;
        }
    }
    
    printDeck(deck);
    printf("\n");
    
    //player draw
    drawCard(deck, pHand, &pCards);
    drawCard(deck, pHand, &pCards);

    //dealer draw
    drawCard(deck, dHand, &dCards);
    drawCard(deck, dHand, &dCards);

    printHand(pHand, pCards);//print the cards in player hand
    printHand(dHand, dCards);//print the cards in dealer hand

    //Make a function that will print out all of the cards in a given players hand.

    printf("\n");
    printDeck(deck);

    return 0;
}


//function takes the deck array, the given handarray, and what card number we are at for that hand (eg. 3rd card in the players hand).
void drawCard(int (*d)[SUITS], int hand[][12], int *nth){
    int randone = 0;
    int randtwo = 0;

    do {

        randone = rand() % RANKS;
        randtwo = rand() % SUITS;

    } while(d[randone][randtwo] != 1);

    //set the picked card to be 0 in the deck
    d[randone][randtwo] = 0;

    //send the picked card's rank and suit position to the given hand array
    hand[0][*nth] = randone;//save the rank
    hand[1][*nth] = randtwo;//save the suit 
    (*nth)++;
}


void getCardText(int r, int s, char *str){
    //we take a string that is already set to size 128 and is empty 
    //we need to figure out the rank and suit as a string
    //for the rank, could do a long switch statement or could try and condense it
        //when the rank is 1 that means we can add 'Ace' to the string, things like Ace and other face cards would probably need their own switch
        //but ranks like 2, 3, 4, etc. would have their own values added to the string, so they could all be in one switch.
    
    switch(r){
        case 0:     
            sprintf(str, "%s ", "Ace");
            break;
        case 10:
            sprintf(str, "%s ", "Jack");
            break;
        case 11:
            sprintf(str, "%s ", "Queen");
            break;
        case 12:
            sprintf(str, "%s ", "King");
            break;
        default:
            sprintf(str, "%d ", r+1);
            break;
    }

    switch(s){
        case 0:
            strcat(str, "of hearts");
            break;
        case 1:
            strcat(str, "of diamonds");
            break;
        case 2:
            strcat(str, "of clubs");
            break;
        default:
            strcat(str, "of spades");
            break;
    }

}


void printHand(int hand[][12], int count){
    
    for(int i = 0; i < count; i++){
        char temp[BIGENOUGH] = "";
        getCardText(hand[0][i], hand[1][i], temp);
        printf("[%s] ", temp);
    }
    printf("\n");
}


void printDeck(int (*d)[SUITS]){
    
    printf("\n");
    for(int i = 0; i < RANKS; i++){
        for(int j = 0; j < SUITS; j++){
            printf("[%d] ", d[i][j]);
        }
        printf("\n");
    }
}

 