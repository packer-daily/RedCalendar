#ifndef SUBMARINE_H
#define SUBMARINE_H

#include <stdint.h>
#include <stdbool.h>

/*
 * Depth states.
 *
 * SURFACE:
 *     Can fire deck gun
 *     Refills oxygen
 *     No spotting modifier
 *
 * PERISCOPE:
 *     Oxygen unchanged
 *     Spotting modifier -1
 *
 * DEEP:
 *     Consumes oxygen
 *     Spotting modifier -2
 */


typedef enum
{
    DEPTH_SURFACE,
    DEPTH_PERISCOPE,
    DEPTH_DEEP
} DepthState;


/*
 * Player submarine.
 */
typedef struct
{
    /* Position */
    int16_t x;
    int16_t y;

    /* Health */
    uint8_t hp;
    uint8_t max_hp;

    /* Oxygen */
    uint8_t oxygen;
    uint8_t max_oxygen;

    /* Depth */
    DepthState depth;

    /* Weapons */
    uint16_t shells;
    uint16_t torpedoes;

    /* Spotting */
    int8_t spotted_value;

    /* Status */
    bool alive;

} Submarine;



//Initialization


void Submarine_Init(Submarine* sub, int16_t start_x, int16_t start_y);



//Movement


void Submarine_MoveNorth(Submarine* sub);
void Submarine_MoveSouth(Submarine* sub);
void Submarine_MoveEast(Submarine* sub);
void Submarine_MoveWest(Submarine* sub);


/*-----------------------------------------
 * Depth Control
 *----------------------------------------*/

void Submarine_Surface(Submarine* sub);
void Submarine_PeriscopeDepth(Submarine* sub);
void Submarine_Dive(Submarine* sub);
DepthState Submarine_GetDepth(const Submarine* sub);


/*-----------------------------------------
 * Oxygen
 *----------------------------------------*/

 /*
  * Called once per second.
  */
void Submarine_UpdateOxygen(Submarine* sub);

bool Submarine_HasOxygen(const Submarine* sub);


//Combat


bool Submarine_CanFireDeckGun(const Submarine* sub);

bool Submarine_FireDeckGun(Submarine* sub);

bool Submarine_FireTorpedo(Submarine* sub);

void Submarine_TakeDamage(Submarine* sub, uint8_t damage);



//Spotting


// * Surface:   0
// * Periscope: -1
// * Deep:      -2


int8_t Submarine_GetSpottingModifier(const Submarine* sub);

void Submarine_ModifySpottedValue(Submarine* sub, int8_t change);

void Submarine_ResetSpottedValue(Submarine* sub);


//Status


bool Submarine_IsAlive(const Submarine* sub);

#endif