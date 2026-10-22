#ifndef SHIP_H
#define SHIP_H

#include <stdint.h>
#include <stdbool.h>


//Ship classes used throughout Red Calendar.

typedef enum
{
    SHIP_PATROL_BOAT,
    SHIP_DESTROYER,
    SHIP_SUBMARINE,
    SHIP_BATTLESHIP,
    SHIP_CARRIER
} ShipType;


//Runtime ship instance.

typedef struct
{
    /* Position on map */
    int16_t x;
    int16_t y;

    /* Identification */
    ShipType type;

    /* Combat */
    uint8_t hp;
    uint8_t max_hp;
    uint8_t damage;

    /* Spotting statistics */
    int8_t spotter_min;
    int8_t spotter_max;

    /* Movement */
    uint8_t speed;

    /* Status */
    bool alive;

} Ship;

/*
 * Spotting meter affects all enemy attacks.
 *
 * Allowed range:
 * -5 <= spotted_value <= 5
 */
typedef struct
{
    int8_t value;
} SpottingMeter;


//Ship initialization functions

void Ship_InitPatrolBoat(Ship* ship, int16_t x, int16_t y);

void Ship_InitDestroyer(Ship* ship,
    int16_t x,
    int16_t y);

void Ship_InitSubmarine(Ship* ship,
    int16_t x,
    int16_t y);

void Ship_InitBattleship(Ship* ship,
    int16_t x,
    int16_t y);

void Ship_InitCarrier(Ship* ship,
    int16_t x,
    int16_t y);


/*--------------------------------------------------
 * Ship combat
 *-------------------------------------------------*/

void Ship_TakeDamage(Ship* ship, uint8_t damage);

bool Ship_IsAlive(const Ship* ship);


/*--------------------------------------------------
 * Spotting system
 *-------------------------------------------------*/

 /*
  * Generates a spotting roll from a single ship.
  */
int8_t Ship_SpottingRoll(const Ship* ship);

/*
 * Updates the player's spotting meter.
 *
 * modifier examples:
 *     surface   =  0
 *     periscope = -1
 *     deep      = -2
 */
void Spotting_Update(SpottingMeter* meter, const Ship* enemy, int8_t modifier);

/*
 * Shared spotting for multiple enemies.
 *
 * Uses:
 *     lowest spotter_min
 *     highest spotter_max
 *
 * as discussed for February and later
 * multi-ship encounters.
 */
void Spotting_UpdateGroup(SpottingMeter* meter,
    Ship enemies[],
    uint8_t count,
    int8_t modifier);

/*
 * Returns hit probability percentage.
 *
 * Examples:
 *     2 -> 40%
 *     3 -> 60%
 *     4 -> 80%
 *     5 -> 100%
 */
uint8_t Spotting_GetHitChance(const SpottingMeter* meter);

bool Spotting_CanAttack(const SpottingMeter* meter);

#endif