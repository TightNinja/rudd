void main()
{
    void self = getlocalvar("self");
    int mp = getentityproperty(self, "mp");
    int maxmp = getentityproperty(self, "maxmp");

    // Debug log: print current and max MP before increasing
    void name = getentityproperty(self, "name");
    void anim = getentityproperty(self, "animationid");
    void blockstate = getentityproperty(self, "aiflag", "blocking");

    void logmsg = "mpincreaseonhit.c: Entity '" + name + "' (block=" + blockstate + ", anim=" + anim + ") mp=" + mp + "/" + maxmp;
    log(logmsg);

    // Increase MP by 1 on hit, but don't exceed maxmp
    if(mp < maxmp) {
        changeentityproperty(self, "mp", mp + 1);
        log("mpincreaseonhit.c: MP increased to " + (mp + 1));
    }
}