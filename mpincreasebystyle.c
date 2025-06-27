/*#define SSF1 1
#define SSF2 2
#define SSFD 3

void main()
{
    void self = getlocalvar("self");
    int mp = getentityproperty(self, "mp");
    int maxmp = getentityproperty(self, "maxmp");
    int style = getlocalvar("style"); // Use localvar for style!

    int mpGain = 1; // Default

    if(style == SSF1)      mpGain = 1; // DD1-3
    else if(style == SSF2) mpGain = 1; // DD2
    else if(style == SSFD) mpGain = 1; // Super

    if(mp < maxmp && mpGain > 0){
        int newmp = mp + mpGain;
        if(newmp > maxmp) newmp = maxmp;
        changeentityproperty(self, "mp", newmp);
    }
}
*/