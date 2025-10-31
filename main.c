#include "node.h"
#include "library.h"
#include <time.h>

int main(int argc, char* argv[]) {
  struct song_node ** l = init();
  add(l,"AC/DC", "thunderstruck");
    add(l,"AC/DC", "Thunderstruck");
      add(l,"Beastie Boys", "Sabotage");
        add(l,"Coldplay", "Clocks");
        add(l,"Daft Punk", "Harder Better Faster Stronger");
        add(l,"Eminem", "Lose Yourself");
        add(l,"Foo Fighters", "Everlong");
        add(l,"Gorillaz", "Feels Good Inc.");
        add(l,"Hozier", "Take Me To Church");
        add(l,"Incubus", "Drive");
        add(l,"Jamiroquai", "Virtual Insanity");
        add(l,"Korn", "Freak on a Leash");
        add(l,"Linkin Park", "In the End");
        add(l,"Muse", "Hysteria");
        add(l,"Nine Inch Nails", "Closer");
        add(l,"Outkast", "Hey Ya!");
        add(l,"Pearl Jam", "alive"); add(l,"Pearl Jam", "even flow"); add(l,"Pearl Jam", "yellow ledbetter"); add(l,"Pearl Jam", "Alive");
        add(l,"Pink Floyd", "Time");
        add(l,"Powerglove", "Batman"); add(l,"Powerglove", "Gotta Catch Em All"); add(l,"Powerglove", "Inspector Gadget"); add(l,"Powerglove", "Mario Minor"); add(l,"Powerglove", "Metal Combat for the Mortal Man");
        add(l,"Queens of the Stone Age", "No One Knows");
        add(l,"Radiohead", "paranoid android"); add(l,"Radiohead", "Paranoid Android");  add(l,"Radiohead", "street spirit (fade out)");
        add(l,"Soundgarden", "Black Hole Sun");
        add(l,"Tool", "Schism");
        add(l,"U2", "One");
        add(l,"VNV Nation", "Chrome");
        add(l,"Weezer", "Buddy Holly");
        add(l,"X Japan", "Forever Love");
        add(l,"Yeah Yeah Yeahs", "Maps");
        add(l,"#1 Dads", "So Soldier");
        add(l,".38 Special", "Who's Been Messin'");
        add(l,"10cc", "I'm Not In Love");
        add(l,"3 Doors Down", "Kryptonite");
        add(l,"311", "Amber");
        add(l,"4 Non Blondes", "What's Up?");
        add(l,"50 Cent", "In Da Club");
  print_library(l);
  return 0;
}
