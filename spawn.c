#define MAX_ALTITUDE 5000
void main() {
    void self = getlocalvar("self");
    void P1 = getplayerproperty(0, "entity");
    void P2 = getplayerproperty(1, "entity");

    set_coordsP1_predeath(self);
    set_coordsP1(self);
    set_coordsP2_predeath(self);
    set_coordsP2(self);
}

int set_coordsP1(void P1) {
    if ( getentityproperty(P1, "animationid") == openborconstant("ANI_RESPAWN") ) {
        int x3 = getentityproperty(P1, "x");
        int y3 = getentityproperty(P1, "a");
        int z3 = getentityproperty(P1, "z");
        float x1,z1,a1;
        float Hz1;
        float Hz5;
        float Hz3;
        float Hz7;
        float dir1;
        int t;

        x1 = getglobalvar("P1"+"respawn_x");
        z1 = getglobalvar("P1"+"respawn_z");
        a1 = getglobalvar("P1"+"respawn_a");

        Hz1 = checkwall(x1+5,z1);
        Hz3 = checkwall(x1,z1);
        Hz5 = checkhole(x1+8,z1);

        if ( x1 != NULL() && z1 != NULL() && a1 != NULL() && Hz1 > y3 ) {
            changeentityproperty(P1, "position", x1-25, z1, a1);
        }else if ( x1 != NULL() && z1 != NULL() && a1 != NULL() && Hz1 < y3 ) {
            changeentityproperty(P1, "position", x1-25, z1, a1);
        }else if ( x1 != NULL() && z1 != NULL() && a1 != NULL() && Hz3 > y3 ) {
            changeentityproperty(P1, "position", x1-15, z1, a1);
        }else if ( x1 != NULL() && z1 != NULL() && a1 != NULL() && Hz3 < y3 ) {
            changeentityproperty(P1, "position", x1-15, z1, a1);
        }else if ( x1 != NULL() && z1 != NULL() && a1 != NULL() && Hz5 > y3 ) {
            changeentityproperty(P1, "position", x1-25, z1, a1);
        }else if ( x1 != NULL() && z1 != NULL() && a1 != NULL() && Hz5 < y3 ) {
            changeentityproperty(P1, "position", x1, z1, a1);
        }else if ( x1 != NULL() && z1 != NULL() && a1 != NULL() ) {
            changeentityproperty(P1, "position", x1, z1, a1);
        }
    }
}

int set_coordsP1_predeath(void P1) {
    int frames = 2, mem_frames = 2; // 150
    int refresh_time = openborvariant("elapsed_time")%frames;
    int anim_id = getentityproperty(P1, "animationid");

    if ( refresh_time == 0 && anim_id != openborconstant("ANI_RESPAWN") ) {
        float x1 = getentityproperty(P1, "x");
        float z1 = getentityproperty(P1, "z");
        float a1 = getentityproperty(P1, "a");
        float dir1 = getentityproperty(P1, "direction");
        float base1 = getentityproperty(P1, "base");

        if ( ( anim_id == openborconstant("ANI_IDLE") || anim_id == openborconstant("ANI_RUN") || anim_id == openborconstant("ANI_WALK") || anim_id == openborconstant("ANI_LAND")
            || anim_id == openborconstant("ANI_GET") || anim_id == openborconstant("ANI_BLOCK") || anim_id == openborconstant("ANI_UP") || anim_id == openborconstant("ANI_DOWN")
            || anim_id == openborconstant("ANI_JUMPLAND") )
            && checkhole(x1,z1) == 0 && (a1 == base1) ) {

            setglobalvar("P1"+"respawn_x", x1+15);
            setglobalvar("P1"+"respawn_z", z1);
            setglobalvar("P1"+"respawn_a", base1);
        }
    }
}

int set_coordsP2(void P2) {
    if ( getentityproperty(P2, "animationid") == openborconstant("ANI_RESPAWN") ) {
        int x4 = getentityproperty(P2, "x");
        int y4 = getentityproperty(P2, "a");
        int z4 = getentityproperty(P2, "z");
        float x2,z2,a2;
        float Hz2;
        float Hz4;
        float Hz6;
        float Hz8;
        float dir2;
        int t;

        x2 = getglobalvar("P2"+"respawn_x");
        z2 = getglobalvar("P2"+"respawn_z");
        a2 = getglobalvar("P2"+"respawn_a");

        Hz2 = checkwall(x2+5,z2);
        Hz4 = checkwall(x2,z2);
        Hz6 = checkhole(x2+8,z2);

        if ( x2 != NULL() && z2 != NULL() && a2 != NULL() && Hz2 > y4 ) {
            changeentityproperty(P2, "position", x2-25, z2, a2);
        }else if ( x2 != NULL() && z2 != NULL() && a2 != NULL() && Hz2 < y4 ) {
            changeentityproperty(P2, "position", x2-25, z2, a2);
        }else if ( x2 != NULL() && z2 != NULL() && a2 != NULL() && Hz4 > y4 ) {
            changeentityproperty(P2, "position", x2-15, z2, a2);
        }else if ( x2 != NULL() && z2 != NULL() && a2 != NULL() && Hz4 < y4 ) {
            changeentityproperty(P2, "position", x2-15, z2, a2);
        }else if ( x2 != NULL() && z2 != NULL() && a2 != NULL() && Hz6 > y4 ) {
            changeentityproperty(P2, "position", x2-25, z2, a2);
        }else if ( x2 != NULL() && z2 != NULL() && a2 != NULL() && Hz6 < y4 ) {
            changeentityproperty(P2, "position", x2, z2, a2);
        }else if ( x2 != NULL() && z2 != NULL() && a2 != NULL() ) {
            changeentityproperty(P2, "position", x2, z2, a2);
        }
    }
}

int set_coordsP2_predeath(void P2) {
    int frames = 2, mem_frames = 2; // 150
    int refresh_time = openborvariant("elapsed_time")%frames;
    int anim_id = getentityproperty(P2, "animationid");

    if ( refresh_time == 0 && anim_id != openborconstant("ANI_RESPAWN") ) {
        float x2 = getentityproperty(P2, "x");
        float z2 = getentityproperty(P2, "z");
        float a2 = getentityproperty(P2, "a");
        int dir2 = getentityproperty(P2, "direction");
        float base2 = getentityproperty(P2, "base");

        if ( ( anim_id == openborconstant("ANI_IDLE") || anim_id == openborconstant("ANI_RUN") || anim_id == openborconstant("ANI_WALK") || anim_id == openborconstant("ANI_LAND")
            || anim_id == openborconstant("ANI_GET") || anim_id == openborconstant("ANI_BLOCK") || anim_id == openborconstant("ANI_UP") || anim_id == openborconstant("ANI_DOWN")
            || anim_id == openborconstant("ANI_JUMPLAND") )
            && checkhole(x2,z2) == 0 && (a2 == base2) ) {

            setglobalvar("P2"+"respawn_x", x2+15);
            setglobalvar("P2"+"respawn_z", z2);
            setglobalvar("P2"+"respawn_a", base2);
        }
    }
}
