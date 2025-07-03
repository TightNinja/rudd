void main()
{
    void self = getlocalvar("self");
    int oldmp = getlocalvar("prehitmp");

    // If MP value was stored before hit, restore it to prevent increase
    if(oldmp != NULL())
    {
        changeentityproperty(self, "mp", oldmp);
        setlocalvar("prehitmp", NULL()); // Clear for next hit
        log("preventmpincreaseonhit.c: MP restored to " + oldmp + " to prevent increase on hit.");
    }
}

// Call this function before any hit-based MP increase script runs
void presave_mp()
{
    void self = getlocalvar("self");
    int mp = getentityproperty(self, "mp");
    setlocalvar("prehitmp", mp);
    log("preventmpincreaseonhit.c: Pre-hit MP saved as " + mp);
}