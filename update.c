void main(){
  playerHP();
}

void playerHP(){ // MAIN: START
  if(openborvariant("in_level") == 1){ // IN_LEVEL: START
    int P1 = getplayerproperty(0, "entity");
    int P2 = getplayerproperty(1, "entity");

    void P1Name;
    void P2Name;
    int HP1; int HP2;

    void Bar = getglobalvar("Bar");
    void Bar2 = getglobalvar("Bar2");
    void Bar3 = getglobalvar("Bar3");
    void Bar4 = getglobalvar("Bar4");
    void Bar5 = getglobalvar("Bar5");
    void Bar6 = getglobalvar("Bar6");
    void Bar7 = getglobalvar("Bar7");
    void Bar8 = getglobalvar("Bar8");

    if(!Bar){
      Bar = loadsprite("data/sprites/bar.gif");
      setglobalvar("Bar", Bar);
    }

    if(!Bar2){
      Bar2 = loadsprite("data/sprites/bar2.gif");
      setglobalvar("Bar2", Bar2);
    }

    if(!Bar3){
      Bar3 = loadsprite("data/sprites/bar3.gif");
      setglobalvar("Bar3", Bar3);
    }

    if(!Bar4){
      Bar4 = loadsprite("data/sprites/bar4.gif");
      setglobalvar("Bar4", Bar4);
    }

    if(!Bar5){
      Bar5 = loadsprite("data/sprites/bar5.gif");
      setglobalvar("Bar5", Bar5);
    }

    if(!Bar6){
      Bar6 = loadsprite("data/sprites/bar6.gif");
      setglobalvar("Bar6", Bar6);
    }

    if(!Bar7){
      Bar7 = loadsprite("data/sprites/bar7.gif");
      setglobalvar("Bar7", Bar7);
    }

    if(!Bar8){
      Bar8 = loadsprite("data/sprites/bar8.gif");
      setglobalvar("Bar8", Bar8);
    }

    if(P1){
      P1Name = getentityproperty(P1, "defaultname");
      HP1 = getentityproperty(P1, "health");
      if(getentityvar(P1, "playerOne") == NULL()){setentityvar(P1, "playerOne", HP1);}

      if(HP1 < getentityvar(P1, "playerOne")){ //If HP box smaller than damage box
	      if(getentityvar(P1, 1) == NULL()){
	       setentityvar(P1, 1, 0); //Set entity var 1 to zero if null this is a timer
	      }
	      setentityvar(P1, 1, getentityvar(P1, 1)+1); //Add 1 to timer; this will run every game tick
	      if(getentityvar(P1, 1) > 7){ //If timer over 7
	       setentityvar(P1, "playerOne", getentityvar(P1, "playerOne")-1); //Reduce displayed damage by 1
	       setentityvar(P1, 1, 0); //Reset timer to zero; this will cause a loop until damage is the same as hp
	      }
      }

      if(P1Name == "Billy"){
        drawbox(26, 9, getentityvar(P1, "playerOne")-3, 10, 999, rgbcolor(56,160,248), 0);
        drawsprite(Bar, 1, 8, 2500);
      }else if(P1Name == "Jimmy"){
        drawbox(26, 9, getentityvar(P1, "playerOne")-3, 10, 999, rgbcolor(246,130,130), 0);
        drawsprite(Bar2, 1, 8, 2500);
      }else if(P1Name == "1jeff"){
        drawbox(26, 9, getentityvar(P1, "playerOne")-3, 10, 999, rgbcolor(41,220,113), 0);
        drawsprite(Bar3, 1, 8, 2500);
      }else if(P1Name == "CBilly"){
        drawbox(26, 9, getentityvar(P1, "playerOne")-3, 10, 999, rgbcolor(128,0,240), 0);
        drawsprite(Bar4, 1, 8, 2500);
      }else if(P1Name == "Sonny"){
        drawbox(26, 9, getentityvar(P1, "playerOne")-3, 10, 999, rgbcolor(239,181,418), 0);
        drawsprite(Bar5, 1, 8, 2500);
      }else if(P1Name == "chinsei"){
        drawbox(26,9,getentityvar(P1, "playerOne")-3,10,999,rgbcolor(252,252,252),0);
        drawsprite(Bar6, 1, 8, 2500);
      }else if(P1Name == "esq"){
        drawbox(26,9,getentityvar(P1, "playerOne")-3,10,999,rgbcolor(165,113,225),0);
        drawsprite(Bar7, 1, 8, 2500);
      }else if(P1Name == "ess"){
        drawbox(26,9,getentityvar(P1, "playerOne")-3,10,999,rgbcolor(0,248,0),0);
        drawsprite(Bar8, 1, 8, 2500);
      }else if(P1Name == "ndra"){
        drawbox(26,9,getentityvar(P1, "playerOne")-3,10,999,rgbcolor(128,0,240),0);
        drawsprite(Bar4, 1, 8, 2500);
      }else if(P1Name == "ndra2"){
        drawbox(26,9,getentityvar(P1, "playerOne")-3,10,999,rgbcolor(128,0,240),0);
        drawsprite(Bar4, 1, 8, 2500);
      }

      
    }
    if(P2){
      P2Name = getentityproperty(P2, "defaultname");
      HP2 = getentityproperty(P2, "health");
      if(getentityvar(P2, "playerTwo") == NULL()){setentityvar(P2, "playerTwo", HP2);}

      if(HP2 < getentityvar(P2, "playerTwo")){
	      if(getentityvar(P2, 1) == NULL()){
	       setentityvar(P2, 1, 0);
	      }
	      setentityvar(P2, 1, getentityvar(P2, 1)+1);
	      if(getentityvar(P2, 1) > 7){
	       setentityvar(P2, "playerTwo", getentityvar(P2, "playerTwo")-1);
	       setentityvar(P2, 1, 0);
	      }
      }

      if(P2Name == "Billy"){
        drawbox(156, 9, getentityvar(P2, "playerTwo")-3, 10, 999, rgbcolor(56,160,248), 0);
        drawsprite(Bar, 131, 8, 2500);
      }else if(P2Name == "Jimmy"){
        drawbox(156, 9, getentityvar(P2, "playerTwo")-3, 10, 999, rgbcolor(246,130,130), 0);
        drawsprite(Bar2, 131, 8, 2500);
      }else if(P2Name == "1jeff"){
        drawbox(156, 9, getentityvar(P2, "playerTwo")-3, 10, 999, rgbcolor(41,220,113), 0);
        drawsprite(Bar3, 131, 8, 2500);
      }else if(P2Name == "CBilly"){
        drawbox(156, 9, getentityvar(P2, "playerTwo")-3, 10, 999, rgbcolor(128,0,240), 0);
        drawsprite(Bar4, 131, 8, 2500);
      }else if(P2Name == "Sonny"){
        drawbox(156, 9, getentityvar(P2, "playerTwo")-3, 10, 999, rgbcolor(239,181,418), 0);
        drawsprite(Bar5, 131, 8, 2500);
      }else if(P2Name == "chinsei"){
        drawbox(156,9,getentityvar(P2, "playerTwo")-3,10,999,rgbcolor(252,252,252),0);
        drawsprite(Bar6, 131, 8, 2500);
      }else if(P2Name == "esq"){
        drawbox(156,9,getentityvar(P2, "playerTwo")-3,10,999,rgbcolor(165,113,225),0);
        drawsprite(Bar7, 131, 8, 2500);
      }else if(P2Name == "ess"){
        drawbox(156,9,getentityvar(P2, "playerTwo")-3,10,999,rgbcolor(0,248,0),0);
        drawsprite(Bar8, 131, 8, 2500);
      }else if(P2Name == "ndra"){
        drawbox(156,9,getentityvar(P2, "playerTwo")-3,10,999,rgbcolor(128,0,240),0);
        drawsprite(Bar4, 131, 8, 2500);
      }else if(P2Name == "ndra2"){
        drawbox(156,9,getentityvar(P2, "playerTwo")-3,10,999,rgbcolor(128,0,240),0);
        drawsprite(Bar4, 131, 8, 2500);
      }
    }
  } //IN_LEVEL: END
} // MAIN: END

void oncreate()
{
    void Bar;
    void Bar2;
    void Bar3;
    void Bar4;
    void Bar5;
    void Bar6;
    void Bar7;
    void Bar8;

    if(!Bar){
      Bar = loadsprite("data/sprites/bar.gif");
      Bar2 = loadsprite("data/sprites/bar2.gif");
      Bar3 = loadsprite("data/sprites/bar3.gif");
      Bar4 = loadsprite("data/sprites/bar4.gif");
      Bar5 = loadsprite("data/sprites/bar5.gif");
      Bar6 = loadsprite("data/sprites/bar6.gif");
      Bar7 = loadsprite("data/sprites/bar7.gif");
      Bar8 = loadsprite("data/sprites/bar8.gif");
      setglobalvar("Bar", Bar);
      setglobalvar("Bar2", Bar2);
      setglobalvar("Bar3", Bar3);
      setglobalvar("Bar4", Bar4);
      setglobalvar("Bar5", Bar5);
      setglobalvar("Bar6", Bar6);
      setglobalvar("Bar7", Bar7);
      setglobalvar("Bar8", Bar8);
    }
}

void ondestroy(){
    void Bar = getglobalvar("Bar");
    void Bar2 = getglobalvar("Bar2");
    void Bar3 = getglobalvar("Bar3");
    void Bar4 = getglobalvar("Bar4");
    void Bar5 = getglobalvar("Bar5");
    void Bar6 = getglobalvar("Bar6");
    void Bar7 = getglobalvar("Bar7");
    void Bar8 = getglobalvar("Bar8");

    if(Bar){
      free(Bar);
      free(Bar2);
      free(Bar3);
      free(Bar4);
      free(Bar5);
      free(Bar6);
      free(Bar7);
      free(Bar8);
      setglobalvar("Bar", NULL());
      setglobalvar("Bar2", NULL());
      setglobalvar("Bar3", NULL());
      setglobalvar("Bar4", NULL());
      setglobalvar("Bar5", NULL());
      setglobalvar("Bar6", NULL());
      setglobalvar("Bar7", NULL());
      setglobalvar("Bar8", NULL());
    }
}
