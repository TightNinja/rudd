void candam(int Rx, int Rz, void Ani)
{
    void self = getlocalvar("self");
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");

    void vEntity;                                       //Target entity placeholder.
    void vAniID;
    void P1;
    void P2;
    int  iEntity;                                       //Entity enumeration holder.
    int  iType;                                         //Entity name.
    int  iMax      = openborvariant("ent_max");         //Entity count.

    float Tx;
    float Tz;
    float Disx;
    float Disz;

    //Enumerate and loop through entity collection.
    for(iEntity=0; iEntity<iMax; iEntity++){
      vEntity = getentity(iEntity);                 //Get target entity from current loop.
      iType   = getentityproperty(vEntity, "type");
      vAniID  = getentityproperty(vEntity,"animationID");

      if(iType == openborconstant("TYPE_ENEMY")){
        if(vAniID == openborconstant("ANI_SPAWN") || vAniID == openborconstant("ANI_FOLLOW100") || vAniID == openborconstant("ANI_IDLE") || vAniID == openborconstant("ANI_WALK")){
          Tx = getentityproperty(vEntity, "x");
          Tz = getentityproperty(vEntity, "z");
          Disx = Tx - x;
          Disz = Tz - z;

          if(Disx >= -Rx && Disx <= Rx && Disz >= -Rz && Disz <= Rz){
            changeentityproperty(vEntity, "hostile", openborconstant("TYPE_ENEMY"));
            changeentityproperty(vEntity, "candamage", openborconstant("TYPE_ENEMY"));
          }
        }
      }else if(iType == openborconstant("TYPE_PLAYER")){
        Tx = getentityproperty(vEntity, "x");
        Tz = getentityproperty(vEntity, "z");
        P1 = getplayerproperty(0, "entity");
        P2 = getplayerproperty(1, "entity");
        Disx = Tx - x;
        Disz = Tz - z;

        if(Disx >= -Rx && Disx <= Rx && Disz >= -Rz && Disz <= Rz){
          changeentityproperty(vEntity, "velocity", 0);
          performattack(vEntity, openborconstant(Ani));
          changeentityproperty(P1, "noaicontrol", 1);
          changeentityproperty(P2, "noaicontrol", 1);
        }
      }
    }
}

void enemkill(int Rx, int Rz)
{
    void self = getlocalvar("self");
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");

    void vEntity;                                       //Target entity placeholder.
    void vAniID;
    int  iEntity;                                       //Entity enumeration holder.
    int  iType;                                         //Entity name.
    int  iMax      = openborvariant("ent_max");         //Entity count.

    float Tx;
    float Tz;
    float Disx;
    float Disz;

    //Enumerate and loop through entity collection.
    for(iEntity=0; iEntity<iMax; iEntity++){
      vEntity = getentity(iEntity);                 //Get target entity from current loop.
      iType   = getentityproperty(vEntity, "type");
      vAniID  = getentityproperty(vEntity,"animationID");

      if(iType == openborconstant("TYPE_ENEMY")){
        if(vAniID == openborconstant("ANI_UP") || vAniID == openborconstant("ANI_IDLE") || vAniID == openborconstant("ANI_WALK")){
          Tx = getentityproperty(vEntity, "x");
          Tz = getentityproperty(vEntity, "z");
          Disx = Tx - x;
          Disz = Tz - z;

          if(Disx >= -Rx && Disx <= Rx && Disz >= -Rz && Disz <= Rz){
            setidle(vEntity, openborconstant("ANI_IDLE"), 1, 1000);
          }
        }
      }
    }
}

void enemkill2(int Rx, int Rz)
{
    void self = getlocalvar("self");
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");

    void vEntity;                                       //Target entity placeholder.
    void vAniID;
    int  iEntity;                                       //Entity enumeration holder.
    int  iType;                                         //Entity name.
    int  iMax      = openborvariant("ent_max");         //Entity count.

    float Tx;
    float Tz;
    float Disx;
    float Disz;

    //Enumerate and loop through entity collection.
    for(iEntity=0; iEntity<iMax; iEntity++){
      vEntity = getentity(iEntity);                 //Get target entity from current loop.
      iType   = getentityproperty(vEntity, "type");
      vAniID  = getentityproperty(vEntity,"animationID");

      if(iType == openborconstant("TYPE_ENEMY")){
        if(vAniID == openborconstant("ANI_UP") || vAniID == openborconstant("ANI_IDLE") || vAniID == openborconstant("ANI_WALK")){
          Tx = getentityproperty(vEntity, "x");
          Tz = getentityproperty(vEntity, "z");
          Disx = Tx - x;
          Disz = Tz - z;

          if(Disx >= -Rx && Disx <= Rx && Disz >= -Rz && Disz <= Rz){
            killentity(vEntity);
          }
        }
      }
    }
}
