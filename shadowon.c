void main()
{
	int i, j;
	void spr; 
	int facing;
	float y, z, x;
	void self = getlocalvar("self"); //get caller
	int ani = getentityproperty(self, "animationid"); //current animation id
	int time = openborvariant("elapsed_time");	//current time in game
	int timer = getlocalvar("shadow."+self+".timer");	//hold a variable for timer
	//recover all properties recovered from animation script
	int max = getentityvar(self,"shadow.max");
	int delay = getentityvar(self,"shadow.delay");
	int timeout = getentityvar(self,"shadow.timeout");
	int alpha = getentityvar(self,"shadow.alpha");
	int tintm = getentityvar(self,"shadow.tintm");
	int r = getentityvar(self,"shadow.r");
	int g = getentityvar(self,"shadow.g");
	int b = getentityvar(self,"shadow.b");
	int anim = getentityvar(self,"shadow.anim");
	if(timer==NULL()){setlocalvar("shadow."+self+".timer",-1);}	//if timer has no value set timer -1
	void table = getentityproperty(self, "colourmap");

if(ani==anim && timer<time) //if the animation id from animation script matches current animation id and timer below 0
{
	spr = getentityproperty(self, "sprite");		//caller current sprite
	x = getentityproperty(self, "x");			//caller x position
	z = getentityproperty(self, "z");			//caller z position
	y = getentityproperty(self, "y");			//caller y position
	facing = !getentityproperty(self, "direction");		//caller facing direction

//settextobj(0,55, 200,3,9999999999,"working");
//drawsprite(spr,openborvariant("xpos")+x,z-y-openborvariant("ypos")-10,z,50);

	for(i=1; i<=max; i++) //find an empty shadow slot and store cuurent sprite with other details
		{
			if(getlocalvar("shadow."+self+"."+i+".s")==NULL())
			 {
				setlocalvar("shadow."+self+"."+i+".s", spr);
				setlocalvar("shadow."+self+"."+i+".x", x);
				setlocalvar("shadow."+self+"."+i+".z", z);
				setlocalvar("shadow."+self+"."+i+".y", y);
				setlocalvar("shadow."+self+"."+i+".f", facing);
				setlocalvar("shadow."+self+"."+i+".tm", tintm);
				setlocalvar("shadow."+self+"."+i+".a", alpha);
				setlocalvar("shadow."+self+"."+i+".r", r);
				setlocalvar("shadow."+self+"."+i+".g", g);
				setlocalvar("shadow."+self+"."+i+".b", b);
				setlocalvar("shadow."+self+"."+i+".t", openborvariant("elapsed_time")+timeout);
				setlocalvar("shadow."+self+".timer",openborvariant("elapsed_time")+delay);	//set a delay before next sprite can be recorded
				break; //stop the loop
			 }
		}
}

		for(j=1; j<=max; j++)//show any stored shadows or if their time is up remove them
		 {
		  if(getlocalvar("shadow."+self+"."+j+".t")!=NULL())
		  {
			if (getlocalvar("shadow."+self+"."+j+".t")<openborvariant("elapsed_time"))
			{
			setlocalvar("shadow."+self+"."+j+".s", NULL());
			setlocalvar("shadow."+self+"."+j+".x", NULL());
			setlocalvar("shadow."+self+"."+j+".z", NULL());
			setlocalvar("shadow."+self+"."+j+".y", NULL());
			setlocalvar("shadow."+self+"."+j+".f", NULL());
			setlocalvar("shadow."+self+"."+j+".c", NULL());
			setlocalvar("shadow."+self+"."+j+".t", NULL());
			setlocalvar("shadow."+self+"."+j+".tm", NULL());
			setlocalvar("shadow."+self+"."+j+".a", NULL());
			setlocalvar("shadow."+self+"."+j+".r", NULL());
			setlocalvar("shadow."+self+"."+j+".g", NULL());
			setlocalvar("shadow."+self+"."+j+".b", NULL());
			} else	{
				changedrawmethod(NULL(),"reset",1);
				changedrawmethod(NULL(), "table", table);
				changedrawmethod(NULL(),"flipx",getlocalvar("shadow."+self+"."+j+".f")); //face same as caller
				changedrawmethod(NULL(),"alpha",getlocalvar("shadow."+self+"."+j+".a")); //apply alpha effect 
				changedrawmethod(NULL(),"tintmode",getlocalvar("shadow."+self+"."+j+".tm")); //apply tint effect 
				changedrawmethod(NULL(),"tintcolor",rgbcolor(getlocalvar("shadow."+self+"."+j+".r"),getlocalvar("shadow."+self+"."+j+".g"),getlocalvar("shadow."+self+"."+j+".b"))); //set a tint 
				drawsprite(getlocalvar("shadow."+self+"."+j+".s"),getlocalvar("shadow."+self+"."+j+".x")-openborvariant("xpos"),getlocalvar("shadow."+self+"."+j+".z")-getlocalvar("shadow."+self+"."+j+".y")-openborvariant("ypos")-4,getlocalvar("shadow."+self+"."+j+".z")-j);
				changedrawmethod(NULL(),"reset",1);
				}
		  }
		 }
}