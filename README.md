# <img src="https://github.com/Rillmo/so_long/assets/51233626/6db1c86b-ed23-4583-9361-9fb1176a12d6" size=50/> so_long
This is simple cat game made in C

## Before start
This game has 2 versions, ***basic*** and ***bonus***. <br/>
<br/>
***BASIC VERSION***
- The main goal of the game is to reach the carpet.
- To make cat rest on the carpet, you have to finish eat all the tuna cans.
- The game ends when the cat finishes all the tuna cans and reaches the carpet.
<br/>

***BONUS VERSION***
- Cat will be chased by the robot vacuum cleaner.
- When the robot vacuum cleaner catches cat, you'll lose.
- Avoid robot vacuums, eat all the tuna cans and reach the carpet!

## About map
Simple maps provided in game, but you can make your own maps to play.
To make a map, you have to follow several rules below.
- 0 for an empty space,
- 1 for a wall,
- C for a tuna can,
- E for a map exit,
- P for the cat’s starting position
- X for the robot vacuum cleaner's starting position (only in ***bonus version***)


## How to start
1. Clone this repository to your local directory.
```
git clone <your-dirname>
```
2. Run Makefile command to complie C program.
```
// BASIC VERSION
make
// BONUS VERSION
make bonus
```
3. Now you can play the game with your maps.
```
// BASIC VERSION
./so_long maps/<map>
// BONUS VERSION
./so_long_bonus maps/<map>
```

## How to remove
If you want to remove object files, run this command.
```
make clean
```
If you want to remove object files, and also game program, run this command.
```
make fclean
```
