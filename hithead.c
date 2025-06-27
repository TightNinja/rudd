void main()
{ // Limits y movement to certain y coords
    void self = getlocalvar("self");
    int y = getentityproperty(self,"y");
    int Limit = getglobalvar("Atap");

    if(Limit && y >= Limit){ // Reached y limit
      changeentityproperty(self, "position", NULL(), NULL(), Limit);
      changeentityproperty(self, "velocity", NULL(), NULL(), -0.1);
    }
}

