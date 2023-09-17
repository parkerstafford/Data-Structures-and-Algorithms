#include <stdio.h>

void eatBanana(int bananas);

int main() {

    eatBanana(10);

    return 0;
}

void eatBanana(int bananas) {
    if (bananas < 1) return;
    printf("You ate a banana!\n");

    eatBanana(bananas - 1);
}
