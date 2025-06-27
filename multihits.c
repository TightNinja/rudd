void main()
{//Script to avoid "multihits" glitch, same as the original SOR2 (NOT USED FOR NOW...)

    //WORKS FOR ATTACKER ONLY
    if(!getlocalvar("which")){
        void self        = getlocalvar("self");
        void other        = getlocalvar("other");
        void atkType    = getlocalvar("attacktype");
        int atkId        = getentityproperty(self, "attackid");

        //AVOID SOME ATTACK TYPES
        if(    atkType != openborconstant("ATK_LAND")        &&
            atkType != openborconstant("ATK_LIFESPAN")    &&
            atkType != openborconstant("ATK_PIT")        &&
            atkType != openborconstant("ATK_TIMEOVER")    ){

            //THE CURRENT ATTACKBOX ID IS SAME AS THE PREVIOUS USED ONE?? DISABLE THE ENGINE HIT HANDLING
            if(atkId == getentityvar(self, "atkId"+other)){changeopenborvariant("lasthitc", 0);}

            //SAVE THE "LAST ATTACKBOX ID" + "CURRENT PLAYER" + "DAMAGED ENTITY"
            setentityvar(self, "atkId"+other, atkId);
        }
    }
}

