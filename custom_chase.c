void main()
{
    void self = getlocalvar("self");
    void target = findtarget(self); // locked opponent
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");
    int dir = getentityproperty(self,"direction");

    if( target != NULL() && getentityproperty(target,"exists")){
      int tdir = getentityproperty(target,"direction");
      float tx = getentityproperty(target, "x");
      float tz = getentityproperty(target, "z");
      int vEnemy = openborvariant("count_enemies");
      float Disx = tx - x;
      float Disz = tz - z;

      if(Disx < 0){
        Disx = -Disx;
      }

      if ( vEnemy > 1 ) {
         if ( dir == 0 && dir != tdir && Disz <= 6 && Disz <= 12 && (getentityproperty(self,"aiflag","attacking") == 0 || getentityproperty(self,"aiflag","walking") == 1) && (getentityproperty(target,"aiflag","attacking") == 1 || getentityproperty(target,"aiflag","inpain") == 1) ) {
             changeentityproperty(self, "aimove", openborconstant("AIMOVE1_NORMAL"));
	     changeentityproperty(self, "destz", tz+18);
	     changeentityproperty(self, "destx", x-30);
         } else if ( dir == 0 && dir != tdir && Disz > 12 && (getentityproperty(self,"aiflag","attacking") == 0 || getentityproperty(self,"aiflag","walking") == 1) && (getentityproperty(target,"aiflag","attacking") == 1 || getentityproperty(target,"aiflag","inpain") == 1) ) {
	     changeentityproperty(self, "destx", tx);
	     changeentityproperty(self, "destz", tz+18);
	     changeentityproperty(self, "destx", x-30);
         } else if ( dir == 1 && dir != tdir && Disz <= 6 && Disz <= 12 && (getentityproperty(self,"aiflag","attacking") == 0 || getentityproperty(self,"aiflag","walking") == 1) && (getentityproperty(target,"aiflag","attacking") == 1 || getentityproperty(target,"aiflag","inpain") == 1) ) {
             changeentityproperty(self, "aimove", openborconstant("AIMOVE1_NORMAL"));
	     changeentityproperty(self, "destz", tz+18);
	     changeentityproperty(self, "destx", x+30);
         } else if ( dir == 1 && dir != tdir && Disz > 12 && (getentityproperty(self,"aiflag","attacking") == 0 || getentityproperty(self,"aiflag","walking") == 1) && (getentityproperty(target,"aiflag","attacking") == 1 || getentityproperty(target,"aiflag","inpain") == 1) ) {
	     changeentityproperty(self, "destx", tx);
	     changeentityproperty(self, "destz", tz+18);
	     changeentityproperty(self, "destx", x+30);
         } else if ( dir == 0 && dir != tdir && Disz <= -6 && Disz <= -12 && (getentityproperty(self,"aiflag","attacking") == 0 || getentityproperty(self,"aiflag","walking") == 1) && (getentityproperty(target,"aiflag","attacking") == 1 || getentityproperty(target,"aiflag","inpain") == 1) ) {
             changeentityproperty(self, "aimove", openborconstant("AIMOVE1_NORMAL"));
	     changeentityproperty(self, "destz", tz-18);
	     changeentityproperty(self, "destx", x-30);
         } else if ( dir == 0 && dir != tdir && Disz > -12 && (getentityproperty(self,"aiflag","attacking") == 0 || getentityproperty(self,"aiflag","walking") == 1) && (getentityproperty(target,"aiflag","attacking") == 1 || getentityproperty(target,"aiflag","inpain") == 1) ) {
	     changeentityproperty(self, "destx", tx);
	     changeentityproperty(self, "destz", tz-18);
	     changeentityproperty(self, "destx", x-30);
         } else if ( dir == 1 && dir != tdir && Disz <= -6 && Disz <= -12 && (getentityproperty(self,"aiflag","attacking") == 0 || getentityproperty(self,"aiflag","walking") == 1) && (getentityproperty(target,"aiflag","attacking") == 1 || getentityproperty(target,"aiflag","inpain") == 1) ) {
             changeentityproperty(self, "aimove", openborconstant("AIMOVE1_NORMAL"));
	     changeentityproperty(self, "destz", tz-18);
	     changeentityproperty(self, "destx", x+30);
         } else if ( dir == 1 && dir != tdir && Disz > -12 && (getentityproperty(self,"aiflag","attacking") == 0 || getentityproperty(self,"aiflag","walking") == 1) && (getentityproperty(target,"aiflag","attacking") == 1 || getentityproperty(target,"aiflag","inpain") == 1) ) {
	     changeentityproperty(self, "destx", tx);
	     changeentityproperty(self, "destz", tz-18);
	     changeentityproperty(self, "destx", x+30);
         } else if ( dir == 0 && dir == tdir && Disx < 30 ) {
             changeentityproperty(self, "aimove", openborconstant("AIMOVE1_NORMAL"));
             changeentityproperty(self, "destx", x+30);
	     changeentityproperty(self, "destz", tz);
         } else if ( dir == 0 && dir == tdir && Disx > 30 ) {
	     changeentityproperty(self, "aimove", openborconstant("AIMOVE1_CHASE"));
         } else if ( dir == 1 && dir == tdir && Disx < 30 ) {
             changeentityproperty(self, "aimove", openborconstant("AIMOVE1_NORMAL"));
             changeentityproperty(self, "destx", x-30);
	     changeentityproperty(self, "destz", tz);
         } else if ( dir == 1 && dir == tdir && Disx > 30 ) {
	     changeentityproperty(self, "aimove", openborconstant("AIMOVE1_CHASE"));
         }
      } else if ( vEnemy == 1 ) {
         changeentityproperty(self, "aimove", openborconstant("AIMOVE1_CHASE"));
      }
   }
}
