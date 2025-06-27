void main()
{
    void self = getlocalvar("self");
    void vAniID  = getentityproperty(self,"animationID");
    int Dir = getentityproperty(self, "direction");
    int x = getentityproperty(self, "x");
    int y = getentityproperty(self, "a");
    int z = getentityproperty(self, "z");
    int Vx = getentityproperty(self, "xdir");
    int C;
    int D;

    if(Dir == 1){
      C = 15;
      D = 0;
    } else {
      C = -15;
      D = 1;
    }

    if(y < checkwall(x+C,z) && vAniID == openborconstant("ANI_IDLE")){
      changeentityproperty(self, "velocity", 0, 0, 0);
      changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1"));
    }

    if(y < checkbasemap(x+C,z) && vAniID == openborconstant("ANI_IDLE")){
      changeentityproperty(self, "velocity", 0, 0, 0);
      changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1"));
    }
}