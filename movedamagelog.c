void main()
{
    void self = getlocalvar("self");
    void target = getlocalvar("target");
    int damage = getlocalvar("damage");
    
    if(target)
    {
        log("HIT! Damage: " + damage + " Target: " + getentityproperty(target, "name"));
    }

}