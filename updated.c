void zoom()
{
   void vscreen = openborvariant("vscreen");
   int maxz=openborvariant("PLAYER_MAX_Z")+1000;
   int zoom_value=getglobalvar("zoomvalue");
   int zoom_x=getglobalvar("zoomx");
   int zoom_y=getglobalvar("zoomy");
   void ent=getglobalvar("zoomentity");
   int px=getentityproperty(ent,"x") +  zoom_x - openborvariant("xpos");
   int py=getentityproperty(ent,"z") + zoom_y - openborvariant("ypos") - getentityproperty(ent,"a");
   void zoom_scr = getglobalvar("zoomscreen");
   if(!zoom_scr){
      zoom_scr = allocscreen(openborvariant("hResolution"),openborvariant("vResolution"));
      setglobalvar("zoomscreen",zoom_scr);
   }
   clearscreen(zoom_scr);

   //draw what we need 
   drawspriteq(zoom_scr,0,openborconstant("MIN_INT"),maxz,0,0);
   //setup drawMethod
   changedrawmethod(NULL(),"reset",1);
   changedrawmethod(NULL(),"enabled",1);
   changedrawmethod(NULL(),"scalex",zoom_value);
   changedrawmethod(NULL(),"scaley",zoom_value);
   changedrawmethod(NULL(),"centerx",px);
   changedrawmethod(NULL(),"centery",py);
   //Draw the resized customized screen to main screen.
   drawscreen(zoom_scr,px,py, maxz+1);
   changedrawmethod(NULL(),"enabled", 0);
   drawspriteq(vscreen, 0, maxz+1,maxz+1, 0, 0);
   drawspriteq(vscreen, 0, maxz+2,openborconstant("MAX_INT"), 0, 0);
   clearspriteq();
}


void main(){//MAIN START
   if(getglobalvar("zoomentity"))
   {
      zoom();        
   }
   
void counter= getlocalvar("counter");  // Set a variable to trigger the spawn on and off (title)
void counter2= getlocalvar("counter2");  // Set a variable to trigger the spawn on and off (select)
void counter3= getlocalvar("counter3");  // Set a variable to trigger the spawn on and off (select)
if(openborvariant("in_menuscreen")) // Check if the game is in menu screen
  {counter = setlocalvar("counter",0); }
	if((openborvariant("in_titlescreen")) &&(counter!=1)) // Check the variable to avoid double spawn
		{void subent;
		loadmodel("bgfx2"); // name of the entity to be loaded
        clearspawnentry(); // clean the spawn entry
		setspawnentry("name", "bgfx2"); // define the entity to be spawn
		setspawnentry("coords", 1,0,-1); // set the position of the entity
		subent=spawn();  //  spawn the entity
		changeentityproperty(subent, "position", 1,0,-1); //for safe, set again the position
		counter = setlocalvar("counter",1); // turn on the variable, blocking a new spawn to be made
	} 

if(openborvariant("in_menuscreen")) // Check if the game is in menu screen
  {counter2 = setlocalvar("counter2",0); }
	if((openborvariant("in_selectscreen")) &&(counter2!=1)) // Check the variable to avoid double spawn
		{void subent;
		loadmodel("bgfx"); // name of the entity to be loaded
        clearspawnentry(); // clean the spawn entry
		setspawnentry("name", "bgfx"); // define the entity to be spawn
		setspawnentry("coords", 1,0,-1); // set the position of the entity
		subent=spawn();  //  spawn the entity
		changeentityproperty(subent, "position", 1,0,-1); //for safe, set again the position
		counter2 = setlocalvar("counter2",1); // turn on the variable, blocking a new spawn to be made
	}	

if(openborvariant("in_menuscreen")) // Check if the game is in menu screen
  {counter3 = setlocalvar("counter3",0); }
	if(openborvariant("in_options") && (openborvariant("in_level")!=1) && (counter3!=1)) // Check the variable to avoid double spawn
		{void subent;
		loadmodel("options"); // name of the entity to be loaded
        clearspawnentry(); // clean the spawn entry
		setspawnentry("name", "options"); // define the entity to be spawn
		setspawnentry("coords", 1,0,-1); // set the position of the entity
		subent=spawn();  //  spawn the entity
		changeentityproperty(subent, "position", 1,0,-1); //for safe, set again the position
		counter3 = setlocalvar("counter3",1); // turn on the variable, blocking a new spawn to be made
	}	

}// MAIN END



