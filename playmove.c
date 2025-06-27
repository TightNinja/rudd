void Join(int Flag)
{// Turns Join status
    changeopenborvariant("nojoin", Flag);
}

void looper(int Frame, int Limit)
{// Loops current animation
    void self = getlocalvar("self");
    void loop = getlocalvar("Loop" + self);

    if(loop==NULL()){ // Localvar empty?
      setlocalvar("Loop" + self, 0);
      loop = 0;
    } 
   
    if(loop < Limit){ // loops reach limit?
      updateframe(self, Frame); //Change frame
      setlocalvar("Loop" + self, loop+1); // Increment number of loops
    } else if(loop==Limit){ // loops reach limit?
      setlocalvar("Loop" + self, NULL());
    }
}

void DeControl(int P, int Flag)
{// Activates or deactivates control for defined player
// P : Player index starting from 0
// Flag : Control flag
    int Player = getplayerproperty(P, "entity");

    if (Player != NULL()){
      changeentityproperty(Player, "aiflag", "attacking", 0);
      changeentityproperty(Player, "aiflag", "idling", 1);
      changeentityproperty(Player,"noaicontrol",Flag);
    }
}

void AnimPlayer(int P, void Ani)
{// Forces defined player to play certain animation
// P : Player index starting from 0
// Ani : Animation to play to
    int Player = getplayerproperty(P, "entity");

    if (Player != NULL()){
      changeentityproperty(Player,"noaicontrol",1);
      performattack(Player, openborconstant(Ani));
    }
}

void IdlPlayer(int P)
{// Forces defined player to go to IDLE
// P : Player index starting from 0
    int Player = getplayerproperty(P, "entity");

    if (Player != NULL()){
      setidle(Player, openborconstant("ANI_IDLE"));
    }
}

void MovePlayer(int P, float Vx, float Vy, float Vz)
{// Forces defined player to move with defined speed
// P : Player index starting from 0
    int Player = getplayerproperty(P, "entity");

    if (Player != NULL()){
      changeentityproperty(Player, "velocity", Vx, Vz, Vy);
    }
}

void DirPlayer(int P, int Dir)
{// Changes defined player's direction
// P : Player index starting from 0
// Dir : Direction
    int Player = getplayerproperty(P, "entity");

    if (Player != NULL()){
      changeentityproperty(Player, "direction", Dir);
    }
}
