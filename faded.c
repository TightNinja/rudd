void main()
{// Fade out death script
  int Screen = openborvariant("hResolution"); // Get screen width

  spawn06("slowitm3", Screen*0.5, 0, 300);
}

void spawn06(void vName, float fX, float fY, float fZ)
{
    //Spawns entity based on left screen edge and z axis
    //Auto adjust with camera's position
    //vName: Model name of entity to be spawned in.
    //fX: X distance relative to left edge
    //fY: Y height from ground
      //fZ: Z coordinate

    void self = getlocalvar("self"); //Get calling entity.
    void vSpawn; //Spawn object.
    int Direction = getentityproperty(self, "direction");
        int XPos = openborvariant("xpos"); //Get screen edge's position
        int YPos = openborvariant("ypos"); // Get camera position
        int Screen = openborvariant("hResolution"); // Get screen width

    clearspawnentry(); //Clear current spawn entry.
      setspawnentry("name", vName); //Acquire spawn entity by name.

   if (Direction == 0){ //Is entity facing left?
      fX = Screen-fX; //Reverse X direction to match facing and screen length
   }

    vSpawn = spawn(); //Spawn in entity.

    changeentityproperty(vSpawn, "position", fX + XPos, fZ + YPos, fY); //Set spawn location.
    return vSpawn; //Return spawn
}