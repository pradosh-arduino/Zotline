#include <TVout.h>
#include <fontALL.h>
#include "cpuinfo.h"
#include "bootlogo.h"

TVout TV; // Def for composite video output

void setup() {
  TV.begin(PAL,120,96); // PAL is for old CRT and NTSC for Newer onces I have old PAL CRT so I'm gonna use it
  TV.select_font(font4x6);
  TV.bitmap(10,10,bootlogo);
  BootProcess();
  TV.clear_screen();
  panic("Test error!");
}

void BootProcess(){
  SleepMS(5000);
}

void SleepMS(int ms){
  TV.delay(ms);
  delay(ms-1); // 1ms delay diff is good because it lets the arduino run first and setup some instructions and get back to Composite
}

void halt(){
  for(;;){
    TV.delay(1);
    delay(1);
  }
}

void panic(const char* msg){
  TV.clear_screen();
  TV.draw_rect(0,0,120,96,WHITE, INVERT);
  TV.select_font(font6x8);
  TV.println("SYSTEM PANIC!");
  TV.select_font(font4x6);
  TV.println(msg);
}

void loop() {
  
}