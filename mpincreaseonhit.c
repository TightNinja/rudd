void main()
{
    void self = getlocalvar("self");
    int mp = getentityproperty(self, "mp");
    int maxmp = getentityproperty(self, "maxmp");

    // Increase MP by 1 on hit, but don't exceed maxmp
    if(mp < maxmp) {
        changeentityproperty(self, "mp", mp + 1);
    }
}