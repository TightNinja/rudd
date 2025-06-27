void main()
{
    void self = getlocalvar("self");
    void Dir = getentityproperty(self, "direction");
    void vAniID = getentityproperty(self,"animationID");
    void wallt = getlocalvar("type");
    void vSpawn;
    int SFX = loadsample("data/sounds/beatxm2.wav");
    int x = getentityproperty(self, "x");
    int y = getentityproperty(self, "a");
    int z = getentityproperty(self, "z");

    if(wallt==1){
      if(vAniID != openborconstant("ANI_FALL80")){
        clearspawnentry();
        setspawnentry("name", "Bflash");
        vSpawn = spawn();
        changeentityproperty(vSpawn, "position", x-5, z+2, y+51);
        changeentityproperty(vSpawn, "direction", Dir);
        spawn();
        damageentity(self, self, 10, 1, openborconstant("ATK_NORMAL"));
        changeentityproperty(self, "direction", 0);
        tossentity(self, 1.3, 0.8, 0);
        playsample(SFX, 0, 60, 60, 100, 0);
      }
    }else if(wallt==2){
      if(vAniID != openborconstant("ANI_FALL80")){
        clearspawnentry();
        setspawnentry("name", "Bflash");
        vSpawn = spawn();
        changeentityproperty(vSpawn, "position", x+5, z+2, y+51);
        changeentityproperty(vSpawn, "direction", Dir);
        spawn();
        damageentity(self, self, 10, 1, openborconstant("ATK_NORMAL"));
        changeentityproperty(self, "direction", 1);
        tossentity(self, 1.3, -0.8, 0);
        playsample(SFX, 0, 60, 60, 100, 0);
      }
    }
}
