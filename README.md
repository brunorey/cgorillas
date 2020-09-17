# cgorillas
A clone of Microsoft's qbasic [gorillas.bas](https://en.wikipedia.org/wiki/Gorillas_(video_game)) written in C. If you don't know the original game, it's playable in [the emulators of The Internet Archive](https://archive.org/details/GorillasQbasic)

This clone was done as a hobby project. It's been some time since I coded anything in C and I was getting rusty, thought it would be good to write something from scratch. Also, I had never coded anything with graphics in my entire career.

## Compilation

Requires `libgraph`.

Compile by running `make`

Then simply run `./gorillas`

![Game preview](https://raw.githubusercontent.com/brunorey/cgorillas/master/cgorillas.gif)

## Why redo this game?

There's many reasons. None of them in particular defines the choice.
 - This is one of the first games I remember playing as a kid (along with simcity 1, paperboy, accolade F1 and others). My father was learning QBasic at the time and would tune the game for us adding things that were attractive to kids like bigger explosions.
 - Software development and coding standards have changed a lot in 30 years and it's fun to study old code and find the differences.
 - Back in the day graphics programming was done in a very artisanal manner (I tried to maintain some of that by using libgraph: turboc graphs ported to linux)
 - I found many many ports of this game but didn't find any one in C or C++.

## Project status
This was recently started and I just wanted to get something functional fast. The code is very dirty.

At the moment it only allows one shot, still not functional as it doesn't have turns or scores.

As this is just a hobby, I'll be improving it as I find the time and motivation (also, there's a considerable chance this will be abandoned at some point).

### TO-DOs
 - Animate gorillas
 - Turns
 - Wind
 - Option to do multiple games ("best of three")
 - Draw the sun (with faces and reactions, like the original)
 - Two-player or single-player (and a rudimentary AI for single player)
 - CODE CLEANUP
 - Add tests
 - Maybe move to C++? (instead of plain C)
 - Better support for compilation (libgraph dependency, mostly)
 - Makefile autogeneration (automake, makefile...)
 - Packaging (build .deb)
