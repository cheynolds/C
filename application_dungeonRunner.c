#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*
* Player has a character, it will explore a dungeon to find
* loot. In the the process of exploration, they may find treasure
* they may find traps, and they may encounter monsters.
* Treasure is added to inventory.
* Traps cause damage.
* Monsters are fought or fleed from, and may have treasure themselves.
*/


typedef struct treasure
{
    char name[25];
    int value;
}Loot;

typedef struct character
{
    char name[25];
    int health;
    int attackPower;
    int defense;
}Mob;

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
    Gamer gamer = { "" };
    puts("Player Name?");
    scanf("%s", &gamer.player.name);

    gamer.player.attackPower = 5 + rand() % 6;
    gamer.player.defense = 2 + rand() % 3;
    gamer.player.health = 10;

    return gamer;
}

void PrintStats(Gamer* gamer)
{
    
    printf("Player %s\nPower: %d\nDefense: %d\nHealth: %d\n",
        gamer->player.name, gamer->player.attackPower, gamer->player.defense,
        gamer->player.health);

    Mob* mob = &gamer->player;
    printf("Player %s\nPower: %d\nDefense: %d\nHealth: %d\n",
        mob->name, mob->attackPower, mob->defense, mob->health);

    Loot* loot = gamer->treasure;
    for (int i = 0; i < 10; i++)
    {
        if (loot->value > 0)
        {
            printf("%s is worth %d\n", loot->name, loot->value);
        }
        loot++;
    }
}

Enemy FindEnemy()
{
    Enemy badGuy;
    int result = rand() % 10;

    strcpy(badGuy.monster.name, "goblin");
    badGuy.monster.attackPower = 1 + rand() % 2;
    badGuy.monster.defense = 0 + rand() % 2;
    badGuy.monster.health = 2 + rand() % 2;
    badGuy.runAwayChance = 0.95f;
    strcpy(badGuy.treasure.name, "silver");
    badGuy.treasure.value = 1;

    if (result < 5)
    {
        return badGuy;
    }
    else if (result < 9)
    {
        strcpy(badGuy.monster.name, "troll");
        badGuy.monster.attackPower++;
        badGuy.monster.defense++;
        badGuy.monster.health++;
        badGuy.runAwayChance = 0.75f;
        badGuy.treasure.value = 3;
        return badGuy;
    }
    else if (result < 10)
    {
        strcpy(badGuy.monster.name, "dragon");
        badGuy.monster.attackPower += 3;
        badGuy.monster.defense += 2;
        badGuy.monster.health += 10;
        badGuy.runAwayChance = 0.35f;
        badGuy.treasure.value = 8;
        return badGuy;
    }

    return badGuy;
}

void PrintEnemy(Enemy* enemy)
{
    puts(enemy->monster.name);
    printf("%d %d %d\n", enemy->monster.attackPower, enemy->monster.defense, enemy->monster.health);
}

int DisplayFightOptions()
{
    puts("Choose what to do:");
    puts("1. Attack");
    puts("2. Heal");
    puts("3. Run away");
    int option;
    scanf("%d", &option);
    return option;
}

void Attack(Gamer* gamer, Enemy* enemy)
{
    int playerRoll = (rand() % 6) + 1;
    int monsterRoll = (rand() % 6) + 1;

    if (gamer->player.attackPower + playerRoll > enemy->monster.attackPower + monsterRoll)
    {
        int damage = gamer->player.attackPower + playerRoll -
            enemy->monster.attackPower + monsterRoll;

        float defenseChance = enemy->monster.defense / 100.0f;
        int defenseRoll = rand() % 100;
        if (defenseRoll < defenseChance)
            puts("Hit monster, but they defended.");
        else
        {
            int damage = rand() % 3 + 1;
            printf("Hit monster for %d\n", damage);
            enemy->monster.health -= damage;
        }
    }
    else
        puts("You missed.");
}

void Heal(Gamer* gamer)
{
    gamer->player.health += 3;
}

int AttemptFlee(Enemy* enemy)
{
    return 1;
}

void Fight(Gamer* gamer, Enemy* enemy)
{
    do
    {
        PrintStats(gamer);
        PrintEnemy(enemy);
        int option = DisplayFightOptions();
        switch (option)
        {
        case 1:
            Attack(gamer, enemy);
            break;
        case 2:
            Heal(gamer);
            break;
        case 3:
            if (AttemptFlee(enemy))
                return;
        }
    } while (1);
}

int main()
{
    srand((unsigned)time(NULL));
    Gamer gamer = CreatePlayer();
    //PrintStats(&gamer);
    Enemy badGuy = FindEnemy();
    //PrintEnemy(&badGuy);

    Fight(&gamer, &badGuy);

    return 0;
}

