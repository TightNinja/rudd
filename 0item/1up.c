void main()
{
  void self = getlocalvar("self");
  void opponent = getentityproperty(self, "opponent");
  int iSnd = loadsample("data/chars/0item/1up.wav");
  
  playsample(iSnd, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0); //Get Item SFX
}