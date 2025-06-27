void main(){
    changePalette();
}

void changePalette(){
    void self = getlocalvar("self");
    void parent = getentityproperty(self, "parent");
    int Pmap = getentityproperty(parent, "map");

    if(Pmap){
        changeentityproperty(self, "map", Pmap);
    }
}