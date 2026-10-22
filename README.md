# Red Calendar

Red Calendar is a submarine-themed roguelike being developed in C for the ESP32.

The player commands a submarine through a series of naval engagements represented by the months of the year. Success depends on balancing oxygen, stealth, and firepower while avoiding enemy detection.

## Current Scope

Initial implementation includes:

- January
- February
- March

No upgrade system is planned for the first release.

## Gameplay

The player controls a submarine with three depth states:

### Surface (0)

- Oxygen refills
- Deck gun available
- No stealth bonus

### Periscope Depth (-1)

- Oxygen remains constant
- Torpedoes available
- Spotting modifier: -1

### Deep (< -1)

- Oxygen decreases
- Torpedoes available
- Spotting modifier: -2

## Spotting System

Enemies contribute to a global spotted value.
