#include <stdio.h>

int minimumPageTurns(int totalPages, int targetPage) {
   
    int turnsFromFront = targetPage / 2;

    int turnsFromBack = (totalPages / 2) - (targetPage / 2);

    if (turnsFromFront < turnsFromBack)
        return turnsFromFront;
    else
        return turnsFromBack;
}

int main() {
    int totalPages, pageToReach;
    scanf("%d %d", &totalPages, &pageToReach);

    int result = minimumPageTurns(totalPages, pageToReach);
    printf("%d\n", result);

    return 0;
}
