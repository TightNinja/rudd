void main()
{
    void self = getlocalvar("self");
    int damType = getlocalvar("damagetype"); // Get the incoming damage type
    int block = getlocalvar("blocked");      // 1 if the attack was blocked, 0 otherwise

    int currMP = getentityproperty(self, "mp");

    // If blocked and normal damage, reduce mp by 1. Currently MP increases by 1 when player blocks - not supposed to happen
    if(block == 1 && damType == 1)
    {
        if(currMP > 0) {
            changeentityproperty(self, "mp", currMP - 1);
        }
    }
    // If NOT blocked and takes ANY damage, reduce mp by 1. Currently MP increases by 1 when player is hit - not supposed to happen
    else if(block == 0)
    {
        if(currMP > 0) {
            changeentityproperty(self, "mp", currMP - 1);
        }
    }
}