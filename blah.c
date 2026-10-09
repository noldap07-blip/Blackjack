#include <stdio.h>

#define CARDNUM 13
#define SUITS 4 


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

void getCard(int r, int c);
void myPrint(char p);

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

    for(int i = 0; i < CARDNUM; i++){
        for(int j = 0; j < SUITS; j++){
            deck[i][j] = 1;
            // printf("[%d] ", deck[i][j]);
        }
        // printf("\n");
    }
    
    //make it so i can input deck[3][2] and have terminal say "4 of clubs"

    printf("What Row?");
    scanf("%d", &row);
    
    printf("What Column?");
    scanf("%d", &column);

    //have it call a new function called Get Card
    getCard(row, column);

    return 0;
}

void getCard(int r, int c){
    //first figure out what face the card is, row 0 is ace, row 1 is 2, row 2 is 3, etc.
    int rowcheck = r + 1;
    int colcheck = c + 1;

    char rcard = '0';

    switch (rowcheck) {
        case 1:
            rcard = 'A';
            break;
        case 2:
            rcard = '2';
            break;
        case 3:
            rcard = '3';
            break;
        case 4:
            rcard = '4';
            break;
        case 5:
            rcard = '5';
            break;
        case 6:
            rcard = '6';
            break;
        case 7:
            rcard = '7';
            break;
        case 8:
            rcard = '8';
            break;
        case 9:
            rcard = '9';
            break;
        case 10:
            printf("10");
            break;
        case 11:
            rcard = 'J';
            break;
        case 12:
            rcard = 'Q';
            break;
        default:
            rcard = 'K';
            break;
    }

    printf("%c", rcard);

    switch(colcheck){
        case 1:
            printf("of Hearts");
            break;
        case 2:
            printf("of Diamonds");
            break;
        case 3:
            printf("of Clubs");
            break;
        default:
            printf("of Spades");
            break;
    }
}