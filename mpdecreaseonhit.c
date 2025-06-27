void main()
{
    void self = getlocalvar("self");
    int mp = getentityproperty(self, "mp");
    log("onblockscript triggered, current mp: " + mp);

    if(mp > 0) {
        changeentityproperty(self, "mp", mp - 1);
        int mp_after = getentityproperty(self, "mp");
        log("mp after reduction: " + mp_after);
    } else {
        log("mp is zero or less, not reduced.");
    }
}