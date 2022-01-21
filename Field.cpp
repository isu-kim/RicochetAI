//
// Created by pc on 2022-01-19.
//

#include "Field.h"

/**
 * A member function that gets tile information in the field
 * @param x the x pos to get info from
 * @param y the y pos to get info from
 * @return returns the Tile information
 */
SMALLTYPE Field::getTileInfo(SMALLTYPE x, SMALLTYPE y) {
    SMALLTYPE returnValue = fieldArray[8 * y + (x / 2)]; // index this one
    returnValue = returnValue >> (4 * ((x % 2)  == 0)); // if x is even, it is first tile. Else, it is second tile.
    return returnValue & 0x0F;
}

/**
 * A member function that sets tile information in the field
 * @param x the x pos to set tile info
 * @param y the y pos to set tile info
 * @param value the value to set tile info
 */
void Field::setTileInfo(SMALLTYPE x, SMALLTYPE y, SMALLTYPE value) {
    SMALLTYPE newValue;
    newValue = ((value & 0x0F) << (4 * ((x % 2) == 0)));
    fieldArray[8 * y + (x / 2)] = ((fieldArray[8 * y + (x / 2)] & (0x0F << 4 * (x % 2 == 1)) | newValue));
}

/**
 * A member function that prints out the field.
 */
void Field::printField(){
    for(SMALLTYPE i = 0 ; i < 16 ; i++){
        for(SMALLTYPE j = 0 ; j < 16 ; j++)
            printf("%2u ", getTileInfo(j, i));
        printf("\n");
    }
}

/**
 * A member function that sets the whole game field.
 * The field is included in /pic directory of the project.
 */
void Field::setField(){
    setTileInfo(1, 0, 0b1110);
    setTileInfo(2, 0, 0b1101);
    setTileInfo(4, 0, 0b1011);
    setTileInfo(8, 0, 0b1110);
    setTileInfo(9, 0, 0b1101);
    setTileInfo(11, 0, 0b1011);

    setTileInfo(4, 1, 0b0110);
    setTileInfo(5, 1, 0b1101);
    setTileInfo(10, 1, 0b1110);
    setTileInfo(11, 1, 0b0101);
    setTileInfo(15, 1, 0b1011);

    setTileInfo(14, 2, 0b1011);
    setTileInfo(15, 2, 0b0111);

    setTileInfo(0, 3, 0b1110);
    setTileInfo(1, 3, 0b1001);
    setTileInfo(14, 3, 0b0110);
    setTileInfo(15, 3, 0b1101);

    setTileInfo(1, 4, 0b0111);
    setTileInfo(5, 4, 0b1011);
    setTileInfo(9, 4, 0b1010);
    setTileInfo(10, 4, 0b1101);

    setTileInfo(0, 5, 0b1011);
    setTileInfo(4, 5, 0b1110);
    setTileInfo(5, 5, 0b0101);
    setTileInfo(9, 5, 0b0111);

    setTileInfo(0, 6, 0b0111);
    setTileInfo(3, 6, 0b1010);
    setTileInfo(4, 6, 0b1101);
    setTileInfo(7, 6, 0b1011);
    setTileInfo(8, 6, 0b1011);
    setTileInfo(11, 6, 0b1110);
    setTileInfo(12, 6, 0b1001);

    setTileInfo(2, 7, 0b1011);
    setTileInfo(3, 7, 0b0111);
    setTileInfo(6, 7, 0b1110);
    setTileInfo(7, 7, 0b0000);
    setTileInfo(8, 7, 0b0000);
    setTileInfo(9, 7, 0b1101);
    setTileInfo(12, 7, 0b0111);

    setTileInfo(2, 8, 0b0110);
    setTileInfo(3, 8, 0b1101);
    setTileInfo(6, 8, 0b1110);
    setTileInfo(7, 8, 0b0000);
    setTileInfo(8, 8, 0b0000);
    setTileInfo(9, 8, 0b1101);

    setTileInfo(4, 9, 0b1110);
    setTileInfo(5, 9, 0b1001);
    setTileInfo(7, 9, 0b0111);
    setTileInfo(8, 9, 0b0111);
    setTileInfo(11, 9, 0b1011);

    setTileInfo(1, 10, 0b1010);
    setTileInfo(2, 10, 0b1101);
    setTileInfo(5, 10, 0b0111);
    setTileInfo(10, 10, 0b1110);
    setTileInfo(11, 10, 0b0101);

    setTileInfo(1, 11, 0b0111);
    setTileInfo(4, 11, 0b1011);
    setTileInfo(10, 11, 0b1011);
    setTileInfo(12, 11, 0b1110);
    setTileInfo(13, 11, 0b1001);
    setTileInfo(15, 11, 0b1011);

    setTileInfo(0, 12, 0b1011);
    setTileInfo(4, 12, 0b0110);
    setTileInfo(5, 12, 0b1101);
    setTileInfo(10, 12, 0b0110);
    setTileInfo(11, 12, 0b1101);
    setTileInfo(13, 12, 0b0111);
    setTileInfo(15, 12, 0b0111);

    setTileInfo(0, 13, 0b0111);
    setTileInfo(6, 13, 0b1011);
    setTileInfo(12, 13, 0b1010);
    setTileInfo(13, 13, 0b1101);

    setTileInfo(5, 14, 0b1110);
    setTileInfo(6, 14, 0b0101);
    setTileInfo(12, 14, 0b0111);

    setTileInfo(3, 15, 0b1110);
    setTileInfo(4, 15, 0b1101);
    setTileInfo(9, 15, 0b1110);
    setTileInfo(10, 15, 0b0101);

    for(SMALLTYPE i = 0 ; i < 16 ; i++){
        setTileInfo(i, 0, (getTileInfo(i, 0) & 0x07)); // disable UP for y = 0
        setTileInfo(i, 15, (getTileInfo(i, 15) & 0x0B)); // disable DN for y = 15
        setTileInfo(0, i, (getTileInfo(0, i) & 0x0D)); // disable LEFT for x = 0
        setTileInfo(15, i, (getTileInfo(15, i) & 0xE)); // disable RIGHT for y = 15
    }
}


SMALLTYPE* getDistanceFrom(Field curField, SMALLTYPE pos){
    SMALLTYPE* distanceArr;
    distanceArr = (SMALLTYPE*) malloc(sizeof(SMALLTYPE) * 256);
    for(uint16_t i = 0 ; i < 256 ; i++) distanceArr[i] = 0xFF;
    printf("GETTING DISTANCE\n");
    getDistance(curField, ((pos >> 4) & 0x0F), (pos & 0x0F), distanceArr, 0);
    printf("POS : (%u, %u)\n",((pos >> 4) & 0x0F), (pos & 0x0F));
    distanceArr[(((pos >> 4) & 0x0F) + (15 * (pos & 0x0F)))] = 0;

    for(SMALLTYPE i = 0 ; i < 16 ; i++){
        for(SMALLTYPE j = 0 ; j < 15 ; j++)
            printf("%3u ", distanceArr[15 * i + j]);
        printf("\n");
    }
    return distanceArr;
}

void getDistance(Field curField, SMALLTYPE x, SMALLTYPE y, SMALLTYPE* distanceARR, SMALLTYPE distance){
    if ((curField.getTileInfo(x, y) & 0x08) == 0x08) goDirection(curField, x, y - 1, distanceARR, distance + 1, 0x08);
    if ((curField.getTileInfo(x, y) & 0x04) == 0x04) goDirection(curField, x, y + 1, distanceARR, distance + 1, 0x04);
    if ((curField.getTileInfo(x, y) & 0x02) == 0x02) goDirection(curField, x - 1, y, distanceARR, distance + 1, 0x02);
    if ((curField.getTileInfo(x, y) & 0x01) == 0x01) goDirection(curField, x + 1, y, distanceARR, distance + 1, 0x01);
}

void goDirection(Field curField, SMALLTYPE x, SMALLTYPE y, SMALLTYPE* distanceARR, SMALLTYPE distance, SMALLTYPE direction){
    if ((curField.getTileInfo(x, y) & direction) != direction) { // if not able to move into the direction anymore;
        if (distanceARR[15 * y + x] > distance){
            distanceARR[15 * y + x] = distance; // do relaxation
            getDistance(curField, x, y, distanceARR, distance);
        }
        else{
            return;
        }
    }
    else{
        switch (direction) {
            case 0x08:
                goDirection(curField, x, y - 1, distanceARR, distance, direction);
                break;
            case 0x04:
                goDirection(curField, x, y + 1, distanceARR, distance, direction);
                break;
            case 0x02:
                goDirection(curField, x - 1, y, distanceARR, distance, direction);
                break;
            case 0x01:
                goDirection(curField, x + 1, y, distanceARR, distance, direction);
        }
    }
}