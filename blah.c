#include <stdio.h>
#include <string.h>

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

void getCardText(int rank, int suit, char[]); 

int main(){

    int column = 0;
    int row    = 0;

    int deck[13][4];
    /*
    RULES FOR ARRAY

    - 13 rows, row 0 is an Ace, row 1 is a 2, etc. Jack Queen and King cards are, 10, 11, 12
    - 4 columns, 0 is hearts, 1 is diamonds, 2 is clubs, 3 is spade
        - so a 4 of clubs would be deck[3][2];
    - in the arary, by deafult every cell is set to 1.
    - a value of 1 for a cell means that card is still in the deck
    - when a card is drawn the cell is set to 0 

    */

    //set every value in the deck to 1, meaning every card is in the deck
    for(int i = 0; i < RANKS; i++){
        for(int j = 0; j < SUITS; j++){
            deck[i][j] = 1;
            // printf("[%d] ", deck[i][j]);
        }
        // printf("\n");
    }
    
    //make it so i can input deck[3][2] and have terminal say "4 of clubs"

    // printf("What Row?");
    // scanf("%d", &row);
    
    // printf("What Column?");
    // scanf("%d", &column);

    //have it call a new function called Get Card
    // getCard(row, column);

    // for(int i = 0; i < RANKS; i++){
    //     for(int j = 0; j < SUITS; j++){
    //         getCard(i, j);
    //     }
    //     printf("\n");
    // }

    char currentC[BIGENOUGH] = "";
    getCardText(13, 3, currentC);
    printf("%s", currentC);
    return 0;
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