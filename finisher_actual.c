void actual_main()
{// Endure script (to protect entity from non knockdown finishing blow)
    void self = getlocalvar("self"); //Get calling entity.
    int HP = getentityproperty(self, "health"); //Get current HP
    int Damage = getlocalvar("damage"); //Get received damage
    int Knock = getlocalvar("drop"); //Get knockdown power
    int Type = getlocalvar("attacktype");

//  if(Type != openborconstant("ATK_PIT") || Type != openborconstant("ATK_LAND") || Type != openborconstant("ATK_NORMAL49")){

    if(Type != openborconstant("ATK_PIT") && Type != openborconstant("ATK_LAND") && Type != openborconstant("ATK_NORMAL49")){

      if(HP <= Damage && HP <= 1 && Knock == 0){
        changeentityproperty(self, "health", 1);
      }
    }
}

