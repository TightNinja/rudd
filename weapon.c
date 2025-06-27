void main()
{//Script for boomerang weapon
    void self = getlocalvar("self");
    void target = getlocalvar("damagetaker"); // Get player who picks the item
    void anim = getentityproperty(self, "animationID");
    int PIndex = getentityproperty(target,"playerindex");

    if(anim == openborconstant("ANI_SPAWN")){
      performattack(target, openborconstant("ANI_follow59"));
      changeentityproperty(target, "velocity", 0, 0, 0);
    }else if(anim == openborconstant("ANI_IDLE") || anim == openborconstant("ANI_RESPAWN")){
      performattack(target, openborconstant("ANI_SPAWN"));
      changeentityproperty(target, "velocity", 0, 0, 0);
    }
}
