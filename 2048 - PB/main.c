#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int bSize=4;
int board[4][4];
int emptyBoard[9];

int resetBoard() {
    int i,j;
    for(i=0;i<bSize;i++) {
        for(j=0;j<bSize;j++) {
            board[i][j] = 0;
        }
    }
    return 0;
}

int resetEmptyBoard() {
    int i;
    for(i=0;i<bSize*2;i++) {
        emptyBoard[i] = 0;
    }
    return 0;
}

int iptKey() {
    if(kbhit()) {
        return getch();
    }
    return 0;
}

int optScreen(){
    int i,j;
    for(i=0;i<bSize;i++) {
        for(j=0;j<bSize;j++) {
            printf("%d ",board[i][j]);
            if(j==(bSize-1)) {
                printf("\n");
            }
        }
    }

    printf("=====\n");
    return 0;
}

int isBoardEmpty() {
    int i,j,k;
    k=0;

    for(i=0;i<bSize;i++) {
        for(j=0;j<bSize;j++) {
            if(board[i][j] == 0) {
                k++;
            }
        }
    }
    if(k!=0) {
        return 1;
    } else {
        return 0;
    }
}

int addNumAtBrd2(int ifEmptyYes) {
    int r,r2,m;

    if(ifEmptyYes) {
        r=rand()%bSize;
        r2=rand()%bSize;
        m=board[r][r2];

        if(m==0) {
            board[r][r2]=1;
        } else {
            addNumAtBrd2(ifEmptyYes);
        }
    }
    return 0;
}


int calBoard(int Key) {
    int m,i,l;
    switch(Key) {
    case 56:
        for (m=0;m<bSize;m++) {
            for(i=1;i<bSize;i++) {
                for(l=0;l<bSize;l++) {
                    if(board[i-1][l]==board[i][l]) {
                        board[i-1][l] = board[i-1][l]*2;
                        board[i][l] = 0;
                    } else if(board[i-1][l]==0) {
                        board[i-1][l] = board[i][l];
                        board[i][l] = 0;
                    }
                }
            }
        }
        addNumAtBrd2(isBoardEmpty());
        optScreen();

        break;

    case 50:
        for (m=0;m<bSize;m++) {
            for(i=bSize-2;i>=0;i--) {
                for(l=0;l<bSize;l++) {
                    if(board[i+1][l]==board[i][l]) {
                        board[i+1][l] = board[i+1][l]*2;
                        board[i][l] = 0;
                    } else if(board[i+1][l]==0) {
                        board[i+1][l] = board[i][l];
                        board[i][l] = 0;
                    }
                }
            }
        }
        addNumAtBrd2(isBoardEmpty());
        optScreen();

        break;

    case 52:
        for (m=0;m<bSize;m++) {
            for(l=1;l<bSize;l++) {
                for(i=0;i<bSize;i++) {
                    if(board[i][l-1]==board[i][l]) {
                        board[i][l-1] = board[i][l-1]*2;
                        board[i][l] = 0;
                    }
                    else if(board[i][l-1]==0) {
                        board[i][l-1] = board[i][l];
                        board[i][l] = 0;
                    }
                }
            }
        }
        addNumAtBrd2(isBoardEmpty());
        optScreen();

        break;

    case 54:
        for (m=0;m<bSize;m++) {
            for(l=bSize-2;l>=0;l--) {
                for(i=0;i<bSize;i++) {
                    if(board[i][l+1]==board[i][l]) {
                        board[i][l+1] = board[i][l+1]*2;
                        board[i][l] = 0;
                    } else if(board[i][l+1]==0) {
                        board[i][l+1] = board[i][l];
                        board[i][l] = 0;
                    }
                }
            }
        }
        addNumAtBrd2(isBoardEmpty());
        optScreen();

        break;
    }
    return 0;
}

int main() {
    char cKeyBD;

    resetBoard();
    addNumAtBrd2(isBoardEmpty());
    addNumAtBrd2(isBoardEmpty());
    addNumAtBrd2(isBoardEmpty());
    addNumAtBrd2(isBoardEmpty());
    addNumAtBrd2(isBoardEmpty());
    addNumAtBrd2(isBoardEmpty());
    addNumAtBrd2(isBoardEmpty());
    optScreen();

    while(1) {
        cKeyBD = iptKey();
        if(cKeyBD != '\0') {
            calBoard(cKeyBD);
        }
    }
    return 0;
}
