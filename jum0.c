void jum(int RxMin, int RxMax, int Rz, int RyMin, int RyMax)
{
    void self = getlocalvar("self");
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");
    float y = getentityproperty(self, "a");
    int Dir = getentityproperty(self, "direction");

    void vEntity;                                       //Target entity placeholder.
    void vAniID;
    int  iEntity;                                       //Entity enumeration holder.
    int  iType;                                         //Entity name.
    int  iMax      = openborvariant("ent_max");         //Entity count.
    int TDir;

    float Tx;
    float Tz;
    float Ty;
    float Disx;
    float Disz;
    float Disy;

    //Enumerate and loop through entity collection.
    for(iEntity=0; iEntity<iMax; iEntity++){
      vEntity = getentity(iEntity);                 //Get target entity from current loop.
      iType   = getentityproperty(vEntity, "type");
      vAniID  = getentityproperty(vEntity,"animationID");

      if(iType == openborconstant("TYPE_ENEMY")){
        if(vAniID == openborconstant("ANI_IDLE") || vAniID == openborconstant("ANI_WALK") || vAniID == openborconstant("ANI_UP") || vAniID == openborconstant("ANI_RUN")){
          Tx = getentityproperty(vEntity, "x");
          Tz = getentityproperty(vEntity, "z");
          Ty = getentityproperty(vEntity, "a");
          TDir = getentityproperty(vEntity, "direction");
          Disx = Tx - x;
          Disz = Tz - z;
          Disy = Ty - y;


          if(Disx >= RxMin && Disx <= RxMax && Disz >= -Rz && Disz <= Rz && Disy >= RyMin && Disy <= RyMax && Dir != TDir){
            changeentityproperty(vEntity, "aiflag", "idling", 0);
            changeentityproperty(vEntity, "aiflag", "walking", 0);
            changeentityproperty(vEntity, "aiflag", "running", 0);
            changeentityproperty(vEntity, "aiflag", "jumping", 1);
            changeentityproperty(vEntity, "takeaction", "common_jump");
            changeentityproperty(vEntity, "animation", openborconstant("ANI_JUMP"));
            tossentity(vEntity, 2, -1, 0);
          }
        }
      }
    }
}

void jum2(int RxMin, int RxMax, int Rz, int RyMin, int RyMax)
{
    void self = getlocalvar("self");
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");
    float y = getentityproperty(self, "a");
    int Dir = getentityproperty(self, "direction");

    void vEntity;                                       //Target entity placeholder.
    void vAniID;
    int  iEntity;                                       //Entity enumeration holder.
    int  iType;                                         //Entity name.
    int  iMax      = openborvariant("ent_max");         //Entity count.
    int TDir;

    float Tx;
    float Tz;
    float Ty;
    float Disx;
    float Disz;
    float Disy;

    //Enumerate and loop through entity collection.
    for(iEntity=0; iEntity<iMax; iEntity++){
      vEntity = getentity(iEntity);                 //Get target entity from current loop.
      iType   = getentityproperty(vEntity, "type");
      vAniID  = getentityproperty(vEntity,"animationID");

      if(iType == openborconstant("TYPE_ENEMY")){
        if(vAniID == openborconstant("ANI_IDLE") || vAniID == openborconstant("ANI_WALK") || vAniID == openborconstant("ANI_UP") || vAniID == openborconstant("ANI_RUN")){
          Tx = getentityproperty(vEntity, "x");
          Tz = getentityproperty(vEntity, "z");
          Ty = getentityproperty(vEntity, "a");
          TDir = getentityproperty(vEntity, "direction");
          Disx = Tx - x;
          Disz = Tz - z;
          Disy = Ty - y;


          if(Disx >= RxMin && Disx <= RxMax && Disz >= -Rz && Disz <= Rz && Disy >= RyMin && Disy <= RyMax && Dir != TDir){
            changeentityproperty(vEntity, "aiflag", "idling", 0);
            changeentityproperty(vEntity, "aiflag", "walking", 0);
            changeentityproperty(vEntity, "aiflag", "running", 0);
            changeentityproperty(vEntity, "aiflag", "jumping", 1);
            changeentityproperty(vEntity, "takeaction", "common_jump");
            changeentityproperty(vEntity, "animation", openborconstant("ANI_JUMP"));
            tossentity(vEntity, 2, 1, 0);
          }
        }
      }
    }
}

void jum3(int RxMin, int RxMax, int Rz, int RyMin, int RyMax)
{
    void self = getlocalvar("self");
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");
    float y = getentityproperty(self, "a");
    int Dir = getentityproperty(self, "direction");

    void vEntity;                                       //Target entity placeholder.
    void vAniID;
    int  iEntity;                                       //Entity enumeration holder.
    int  iType;                                         //Entity name.
    int  iMax      = openborvariant("ent_max");         //Entity count.
    int TDir;

    float Tx;
    float Tz;
    float Ty;
    float Disx;
    float Disz;
    float Disy;

    //Enumerate and loop through entity collection.
    for(iEntity=0; iEntity<iMax; iEntity++){
      vEntity = getentity(iEntity);                 //Get target entity from current loop.
      iType   = getentityproperty(vEntity, "type");
      vAniID  = getentityproperty(vEntity,"animationID");

      if(iType == openborconstant("TYPE_ENEMY")){
        if(vAniID == openborconstant("ANI_IDLE") || vAniID == openborconstant("ANI_WALK") || vAniID == openborconstant("ANI_UP") || vAniID == openborconstant("ANI_RUN")){
          Tx = getentityproperty(vEntity, "x");
          Tz = getentityproperty(vEntity, "z");
          Ty = getentityproperty(vEntity, "a");
          TDir = getentityproperty(vEntity, "direction");
          Disx = Tx - x;
          Disz = Tz - z;
          Disy = Ty - y;


          if(Disx >= RxMin && Disx <= RxMax && Disz >= -Rz && Disz <= Rz && Disy >= RyMin && Disy <= RyMax){
            changeentityproperty(vEntity, "subject_to_gravity", 1);
            performattack(vEntity, openborconstant("ANI_FOLLOW103"));
          }
        }
      }
    }
}

void jum4(int RxMin, int RxMax, int Rz, int RyMin, int RyMax)
{
    void self = getlocalvar("self");
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");
    float y = getentityproperty(self, "a");
    int Dir = getentityproperty(self, "direction");

    void vEntity;                                       //Target entity placeholder.
    void vAniID;
    int  iEntity;                                       //Entity enumeration holder.
    int  iType;                                         //Entity name.
    int  iMax      = openborvariant("ent_max");         //Entity count.
    int TDir;

    float Tx;
    float Tz;
    float Ty;
    float Disx;
    float Disz;
    float Disy;

    //Enumerate and loop through entity collection.
    for(iEntity=0; iEntity<iMax; iEntity++){
      vEntity = getentity(iEntity);                 //Get target entity from current loop.
      iType   = getentityproperty(vEntity, "type");
      vAniID  = getentityproperty(vEntity,"animationID");

      if(iType == openborconstant("TYPE_ENEMY")){
        if(vAniID == openborconstant("ANI_IDLE") || vAniID == openborconstant("ANI_WALK") || vAniID == openborconstant("ANI_UP") || vAniID == openborconstant("ANI_RUN")){
          Tx = getentityproperty(vEntity, "x");
          Tz = getentityproperty(vEntity, "z");
          Ty = getentityproperty(vEntity, "a");
          TDir = getentityproperty(vEntity, "direction");
          Disx = Tx - x;
          Disz = Tz - z;
          Disy = Ty - y;


          if(Disx >= RxMin && Disx <= RxMax && Disz >= -Rz && Disz <= Rz && Disy >= RyMin && Disy <= RyMax){
            changeentityproperty(vEntity, "subject_to_gravity", 1);
            performattack(vEntity, openborconstant("ANI_FOLLOW104"));
          }
        }
      }
    }
}
