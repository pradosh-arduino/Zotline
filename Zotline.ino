#include <TVout.h>
#include <fontALL.h>
#include "cpuinfo.h"
#include "bootlogo.h"

TVout TV; // Def for composite video output

void setup() {
  TV.begin(PAL,120,96); // PAL is for old CRT and NTSC for Newer onces I have old PAL CRT so I'm gonna use it
  TV.select_font(font4x6);
  TV.println("Booting\n");
  TV.bitmap(10,10,bootlogo);
}

void loop() {
  
}