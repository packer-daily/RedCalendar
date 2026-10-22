#include "ships.h"
enum
{
    PB_SPAWN,
    PB_PATROL,
    PB_ATTACK,
    PB_SUNK
};

void Ship_TickPatrolBoat(Ship* boat, SpottingMeter* spottedValue)
{
    if (boat->hp == 0)
    {
        boat->CurrentState = PB_SUNK;
    }

    switch (boat->CurrentState)
    {
    case PB_SPAWN:

        boat->CurrentState = PB_PATROL;

        break;

    case PB_PATROL:

        PatrolBoat_Move(boat);

        if (spottedValue > 2)
        {
            boat->CurrentState = PB_ATTACK;
        }

        break;

    case PB_ATTACK:

        if (spottedValue <= 2)
        {
            boat->CurrentState = PB_PATROL;
        }

        break;

    case PB_SUNK:

        boat->alive = false;

        break;

    default:

        boat->CurrentState = PB_PATROL;

        break;
    }

}
