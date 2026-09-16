#include <stdio.h>

int main(void)
{
    // --- Variables contenant les valeurs affichees ---
    int vitesse = 245;          // km/h, echelle 0 a 300
    int altitude = 3200;        // ft, echelle 2000 a 4000
    int cap = 235;              // degres, 0 a 360
    int angle_horizon = 5;      // degres
    int angle_virage = -5;      // degres, negatif = gauche, positif = droite

    // --- Positions des reperes deduites par calcul ---

    // Anemometre :
    // la ligne "0 100 200 300" commence a la colonne 3
    // et "300" est a la colonne 21
    int col_vitesse = 3 + vitesse * 18 / 300;

    // Altimetre :
    // la ligne "2000 3000 4000" commence a la colonne 59
    // et "4000" est a la colonne 74
    int col_altitude = 59 + (altitude - 2000) * 15 / 2000;


    // --- Point cardinal deduit du cap ---

    char cardinal[3];

    if (cap >= 338 || cap < 23)
    {
        cardinal[0] = 'N';
        cardinal[1] = '\0';
    }
    else if (cap < 68)
    {
        cardinal[0] = 'N';
        cardinal[1] = 'E';
        cardinal[2] = '\0';
    }
    else if (cap < 113)
    {
        cardinal[0] = 'E';
        cardinal[1] = '\0';
    }
    else if (cap < 158)
    {
        cardinal[0] = 'S';
        cardinal[1] = 'E';
        cardinal[2] = '\0';
    }
    else if (cap < 203)
    {
        cardinal[0] = 'S';
        cardinal[1] = '\0';
    }
    else if (cap < 248)
    {
        cardinal[0] = 'S';
        cardinal[1] = 'O';
        cardinal[2] = '\0';
    }
    else if (cap < 293)
    {
        cardinal[0] = 'O';
        cardinal[1] = '\0';
    }
    else
    {
        cardinal[0] = 'N';
        cardinal[1] = 'O';
        cardinal[2] = '\0';
    }


    // --- Affichage du tableau de bord ---

    printf(" ANEMOMETRE          HORIZON ARTIFICIEL          ALTIMETRE\n");
    printf(" +----------+                                  +----------+\n");
    printf(" |          |        10 ----------------       |          |\n");
    printf(" |   %3d    |         5 -------------          |   %4d   |\n",
           vitesse, altitude);

    // Horizon artificiel
    if (angle_horizon >= 5)
    {
        printf(" |   km/h   |            ----[ + ]----         |    ft    |\n");
    }
    else if (angle_horizon <= -5)
    {
        printf(" |   km/h   |      ----[ + ]----               |    ft    |\n");
    }
    else
    {
        printf(" |   km/h   |         ----[ + ]----            |    ft    |\n");
    }

    printf(" |          |        -5 -------------          |          |\n");
    printf(" +----------+       -10 ----------------       +----------+\n");

    printf("   0  100  200  300             2000 3000 4000\n");
    printf("   |....|....|....|....| VIRAGE |.....|.....|\n");

    // Reperes vitesse et altitude
    printf("%*c%*c\n",
           col_vitesse + 1, '^',
           col_altitude - col_vitesse, '^');


    // --- Indicateur de virage ---

    printf("                    L 10 5 0 5 10 R\n");
    printf("                        \\ | | | /\n");

    if (angle_virage <= -5)
    {
        printf("                         [V]----\n");
    }
    else if (angle_virage >= 5)
    {
        printf("                         ----[V]\n");
    }
    else
    {
        printf("                          -[V]-\n");
    }

    printf("                 HORIZON : %d deg\n", angle_horizon);
    printf("                 VIRAGE  : %d deg\n", angle_virage);


    // --- Indicateur directionnel ---

    printf("\n");
    printf("                    ----------------------\n");
    printf("                    |         N          |\n");
    printf("                    |     NO     NE      |\n");
    printf("                    |   O     X     E    |\n");
    printf("                    |     SO     SE      |\n");
    printf("                    |         S          |\n");
    printf("                    ----------------------\n");

    printf("                    CAP : %3d deg (%s)\n", cap, cardinal);


    return 0;
}
