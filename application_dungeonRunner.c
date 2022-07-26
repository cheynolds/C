#include <stdio.h>
#include <string.h>
#include <time.h>


/*Plyer has a character. It will explire a dungeon to find loot. In the process of
exploration, they may find treasure, they may find traps, they may encounter monsters. 

refactor 1
typedef struct treasure
{
    char name[25];
    int value;   
}Loot;


typedef struct player
{
    char name[25];
    int health;
    int attackPower;
    int defense;
}Gamer

typedef struct monster
{
    char name[25];
    int health;
    int attackPower;
    int defense;
    float runAwayChance;
}Enemy

*/

typedef struct character
{
    char name[25];
    int health;
    int attackPower;
    int defense;
}Mob;

typedef struct treasure
{
    char name[25];
    int value;   
}Loot;


typedef struct player
{
    Mob player;
    Loot treasure[10];
    
}Gamer;

typedef struct monster
{
    Mob monster;
    Loot treasure;
    float runAwayChance;
}Enemy;

Gamer CreatePlayer()
{
    Gamer gamer={ "" };
    puts("Player name?");
    scanf("%s", &gamer.player.name);
    gamer.player.attackPower = 5 + rand()% 6;
    gamer.player.defense = 2 + rand()%3;
    gamer.player.health = 10;
    return gamer;
}

void PrintStats (Gamer* gamer)
{


    Mob * mob = &gamer->player;
    printf("Player %s\nPower: %d\nDefense: %d\n, Health: %d", 
        mob->name, mob->attackPower, mob-> defense, mob->health);
        //gamer -> player.name, gamer->player.attackPower, gamer->player.defense, gamer->player.health);
    
    Loot* loot = gamer->treasure;
    for (int i =0; i<10; i++)
    {
        if (loot->value >0)
        {

        }
    }
        

}

Enemy FindEnemy()


{
    Enemy badGuy;
    int result = rand() %10;
    strcpy(badGuy.monster.name, "goblin");
    badGuy.monster.attackPower = 1 +rand() %2;
    badGuy.monster.defense = 0 + rand() %2;
    badGuy.monster.health = 2 + rand() %2;
    badGuy.runAwayChance = 0.95f;
    strcpy(badGuy.treasure.name, "silver");
    badGuy.treasure.value=1;
    if (result <5)
    {
        return badGuy;        
    }
    else if (result <9)
    {
    strcpy(badGuy.monster.name, "troll");
    badGuy.monster.attackPower ++;
    badGuy.monster.defense ++;;
    badGuy.monster.health ++;;
    badGuy.runAwayChance = 0.75f;
    badGuy.treasure.value = 3;
    return badGuy;
    }
    else if(result <10)
    {
    strcpy(badGuy.monster.name, "troll");
    badGuy.monster.attackPower ++;
    badGuy.monster.defense ++;;
    badGuy.monster.health ++;;
    badGuy.runAwayChance = 0.75f;
    badGuy.treasure.value = 3;
    return badGuy;
    }

}

void PrintEnemy(Enemy* enemy)
{
    puts (enemy->monster.name);
    printf("monster power %d, monster defense %d, monster health %d", enemy->monster.defense, enemy->monster.health)

}

void DisplayFightOptions()
{
    puts("Choose what to do:");
    puts("1. attack, 2. health 3. runaway");
    int option;
    scanf("%d", &option)
    return option;
}

void Attack(Gamer* gamer, Enemy* enemy)
{
    int playerRoll = (rand() %6) +1; //6sided dice
    int monsterRoll = (rand() %6) + 1;

    if(gamer->player.attackPower + playerRoll > enemy->monster.attackPower + monsterRoll)
    {
        int damage = gamer->player.attackPower + playerRoll - enemy->monster.attackPower + monsterRoll;
        float defenseChance = enemy->monster.defense / 100.0f;
        int defenseRoll = rand() % 100
        if (defenseRoll < defenseChance)
            puts ("hits monster, but they defensed");
        else   
        {   
            int damage = rand() %3 + 1;
            puts("hit monster for %d\n" damage, damage)
    }
}

void Heal(Gamer* gamer)
{

}

int AttemptFlee(Enemy* enemy)
{
    return 1;
}
void Fight(Gamer* gamer, Enemy* enemy)
{
    PrintStats(gamer);
    PrintEnemy(enemy);
    switch (option)
    {
        case 1:
            Attack(gamer, enemy);
        case 2:
            Heal(gamer);
            break;
        case 3:
            if (AttemptFlee(enemy))
                return;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    Gamer gamer = CreatePlayer();
    PrintStats(&gamer);
    Enemy badGuy = FindEnemy();
    PrintEnemy(&badGuy);

    return 0;
}