void caskill(int Rx, int Rz, void Ani)
{
    void self = getlocalvar("self");
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");

    void vEntity;                                       //Target entity placeholder.
    int  iEntity;                                       //Entity enumeration holder.
    int  iName;                                         //Entity name.
    int  iMax      = openborvariant("ent_max");         //Entity count.

    float Tx;
    float Tz;
    float Disx;
    float Disz;

    //Enumerate and loop through entity collection.
    for(iEntity=0; iEntity<iMax; iEntity++){
      vEntity = getentity(iEntity);                 //Get target entity from current loop.
      iName   = getentityproperty(vEntity, "defaultname"); //Get target name

      if(iName == "cas01" || "LevelEnd"){
        Tx = getentityproperty(vEntity, "x");
        Tz = getentityproperty(vEntity, "z");
        Disx = Tx - x;
        Disz = Tz - z;

        if(Disx >= -Rx && Disx <= Rx && Disz >= -Rz && Disz <= Rz){
          changeentityproperty(vEntity, "animation", openborconstant(Ani));
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
        if(vAniID == openborconstant("ANI_SPAWN") || vAniID == openborconstant("ANI_FOLLOW100") || vAniID == openborconstant("ANI_IDLE") || vAniID == openborconstant("ANI_WALK")){
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

void enemkill2(int Rx, int Rz)
{
    void self = getlocalvar("self");
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");

    void vEntity;                                       //Target entity placeholder.
    void vAniID;
    int  iEntity;                                       //Entity enumeration holder.
    int  iName;
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
      iName   = getentityproperty(vEntity, "defaultname");
      vAniID  = getentityproperty(vEntity,"animationID");

      if(iType == openborconstant("TYPE_ENEMY") && iName != "delay" && iName != "delay2"){
        if((vAniID == openborconstant("ANI_SPAWN") || vAniID == openborconstant("ANI_WALK") || vAniID == openborconstant("ANI_IDLE") || vAniID == openborconstant("ANI_RUN")) && (vAniID != openborconstant("ANI_FALL49") || vAniID != openborconstant("ANI_DIE49"))){
          Tx = getentityproperty(vEntity, "x");
          Tz = getentityproperty(vEntity, "z");
          Disx = Tx - x;
          Disz = Tz - z;

          if(Disx >= -Rx && Disx <= Rx && Disz >= -Rz && Disz <= Rz){
            killentity(vEntity);
          }
        }
      }else if(iType == openborconstant("TYPE_PLAYER")){
        if((vAniID == openborconstant("ANI_IDLE") || vAniID == openborconstant("ANI_WALK") || vAniID == openborconstant("ANI_RUN")) && (vAniID != openborconstant("ANI_FOLLOW110"))){
          Tx = getentityproperty(vEntity, "x");
          Tz = getentityproperty(vEntity, "z");
          Disx = Tx - x;
          Disz = Tz - z;

          if(Disx >= -Rx && Disx <= Rx && Disz >= -Rz && Disz <= Rz){
	  performattack(vEntity, openborconstant("ANI_FOLLOW110"));
          }
        }
      }
    }
}
