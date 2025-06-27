void shadow(int max, int delay, int timeout, int alpha, int tintm, int r, int g, int b)
{//animation script for shadow trails
	void self = getlocalvar("self"); //Get calling entity.
	int anim = getentityproperty(self, "animationid");//Get calling animation id.
	//if any values null set defaults
	if(max==NULL()){max=5;}
	if(delay==NULL()){delay=20;}
	if(timeout==NULL()){timeout=90;}
	if(alpha==NULL()){alpha=6;}
	if(tintm==NULL()){tintm=2;}
	if(r==NULL()){r=0;}
	if(g==NULL()){g=0;}
	if(b==NULL()){b=255;}
	//store all recorded data into entity variables.
	setentityvar(self,"shadow.anim", anim);
	setentityvar(self,"shadow.max", max);
	setentityvar(self,"shadow.delay", delay);
	setentityvar(self,"shadow.timeout", timeout);
	setentityvar(self,"shadow.alpha", alpha);
	setentityvar(self,"shadow.tintm", tintm);
	setentityvar(self,"shadow.r", r);
	setentityvar(self,"shadow.g", g);
	setentityvar(self,"shadow.b", b);

}