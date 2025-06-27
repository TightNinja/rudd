#import "data/scripts/shadow.c"
void toss0001(int iSTime)
{
    /*
    toss0001
    Damon Vaughn Caskey
    12/24/2009
    Adds tosstime to caller.

    iTime:      Time to add.
    */

    void vSelf = getlocalvar("self");	
    int  iTime = openborvariant("elapsed_time");

    changeentityproperty(vSelf, "tosstime", iTime + iSTime);
}

#include "data/scripts/ani0009.h"

int ani0020(int iAni, int iTAni){
    
	/*
	ani0020
	Damon Vaughn Caskey
	Perform alternate animation if target is within range and in specified animation.

	iAni:	Alternate attack.
	iTAni:	Target animation.
	*/

    void vSelf      = getlocalvar("self");					//Caller.                                                         
    void vOpp       = findtarget(vSelf, iAni);				//Nearest target in range of alternate attack.
	
	if (vOpp)												//Found a target?
	{
		if(getentityproperty(vOpp, "animationID") == iTAni)	//Animation match?
		{
			ani0009(vSelf, iAni, 0);						//Perform alternate attack.
			return 1;										//Return 1.
		}
	}

	return 0;												//Return 0.
}

void Join(int Flag)
{// Turns Join status
    changeopenborvariant("nojoin", Flag);
}

void direc(int Ratio)
{// Changes antigravity effect
    void self = getlocalvar("self");
    changeentityproperty(self, "direction", Ratio);
}

void stopz()
{// Dash with previously attained speed + flying speed
// Used by Jetpacks to prevent diving to ground and to fly back up
    void self = getlocalvar("self");
    changeentityproperty(self, "velocity", 0, 0); //Stop moving!
}

void DeControl(int Flag)
{// Activates or deactivates control for players
    void self = getlocalvar("self");
    changeentityproperty(self,"noaicontrol",Flag);
}

void ani001(void vAni1, int iFrame, int iCmd, int iMPCost, int iHPCost, float fMinX, float fMaxX, float fMinZ, float fMaxZ, float fMinY, float fMaxY){

	//ani001
	//Damon Vaughn Caskey
	//05/11/2007
	//
	//Switch calling entity to new animation and frame if player command, HP, MP, and range requirements are met.
	//
	//vAni1: Desired animation.
	//iFrame: Desired frame.
	//iCmd: Required player command.
	//iMPCost: Minimum (and to be consumed) MP.
	//iHPCost: Minimum (and to be consumed) HP.
	//fMinX: Minimum X range.
	//fMaxX: Maximim X range.
	//fMinZ: Minimum Z range.
	//fMaxZ: Maximum Z range.
	//fMaxY: Minimum Y range.
	//fMaxY: Maximum Y range.

    void vSelf = getlocalvar("self"); //Get calling entity. 
    void vTarget = findtarget(vSelf); //Get nearest hostle entity to caller.
	int iMP = getentityproperty(vSelf, "mp"); //Caller's current MP.
	int iHP = getentityproperty(vSelf, "health"); //Caller's current HP.
    float fX = getentityproperty(vSelf, "x"); //X position of caller.
    float fY = getentityproperty(vSelf, "a"); //Y position of caller.
    float fZ = getentityproperty(vSelf, "z"); //Z position of caller.
	float fTX = getentityproperty(vTarget, "x"); //X position of nearest hostile entity to caller.
    float fTY = getentityproperty(vTarget, "a"); //Y position of nearest hostile entity to caller.
    float fTZ = getentityproperty(vTarget, "z"); //Z position of nearest hostile entity to caller.
        
    if(iCmd){ //If command requirement provided, evaluate.
                  
        if(keyd001(getentityproperty(vSelf, "playerindex"), 0, vSelf) != iCmd) { //Does command match?
			
			return ;//Exit.
		
		} 
        
    }         
    
	if (!(iRan001(fX, fTX, fMinX, fMaxX))){ //Not within X range?
        
		return; //Exit.
            
    }
        
	if (!(iRan001(fZ, fTZ, fMinZ, fMaxZ))){ //Not within Z range?
        
		return; //Exit.
            
    }
    
	if (!(iRan001(fY, fTY, fMinY, fMaxY))){ //Not within Y range?
        
		return; //Exit.
            
    }
           
	if ((iMPCost) || (iHPCost)){ //Cost requirement provided?
        
		if (iMP >= iMPCost && iHP > iHPCost){ //Evaluate MP/HP costs against available supply.
		    	  
			changeentityproperty(vSelf, "mp", iMP - iMPCost); //Subtract MP cost from caller's MP.
			changeentityproperty(vSelf, "health", iHP - iHPCost); //Subtract HP cost from  caller's HP.                              	
	
		}else{  		                   	      
                                            
			return; //Exit.
        
		}                                            

	}
	
	changeentityproperty(vSelf, "animation", openborconstant(vAni1)); //Switch to desired animation.
	changeentityproperty(vSelf, "animpos", iFrame); //Switch to desired frame.
        
}

void xyleap(int Xc, int Yc, int Fr, int D)
{// Targetting X and Y position coordnates and perform a dash/leap
//Xc - x coordinate from the left side of the screen
//Yc - y coordinate from the top side of the screen
//Fr - frames to move
//D - delay of frames

    void self = getlocalvar("self");
    float x = getentityproperty(self, "x"); // Get enemy's x coordinate
    float z = getentityproperty(self, "z"); // Get enemy's z coordinate

      float Tx = (openborvariant("xpos") + Xc); // Get position's x coordinate
      float Tz = (openborvariant("ypos") + Yc); // Get position's z coordinate

      if(Tx < x){
        changeentityproperty(self, "direction", 0); // Face left
      } else {
        changeentityproperty(self, "direction", 1); // Face right
      }
      setlocalvar("x"+self, 2*(Tx-x)/(Fr*D)); // Calculate Vx then store value in local variable
      setlocalvar("z"+self, 2*(Tz-z)/(Fr*D)); // Calculate Vz then store value in local variable
      setlocalvar("y"+self, 0); // Calculate Vy then store value in local variable
}

void xyleap2(int Xc, int Yc, int Fr, int D)
{// Targetting X and Y position coordnates and perform a dash/leap
//Xc - x coordinate from the left side of the screen
//Yc - y coordinate from the top side of the screen
//Fr - frames to move
//D - delay of frames

    void self = getlocalvar("self");
    float x = getentityproperty(self, "x"); // Get enemy's x coordinate
    float z = getentityproperty(self, "z"); // Get enemy's z coordinate

      float Tx = (openborvariant("xpos") + Xc); // Get position's x coordinate
      float Tz = (openborvariant("ypos") + Yc); // Get position's z coordinate

      if(Tx < x){
        changeentityproperty(self, "direction", 0); // Face left
      } else {
        changeentityproperty(self, "direction", 1); // Face right
      }
      setlocalvar("x"+self, 2*(Tx-x)/(Fr*D)); // Calculate Vx then store value in local variable
      setlocalvar("z"+self, 2*(Tz-z)/(Fr*D*4)); // Calculate Vz then store value in local variable
      setlocalvar("y"+self, 0); // Calculate Vy then store value in local variable
}

void ani002(void vAni, int iFrame, void vReqVar, void vReqVal){
    
    //ani002
    //Damon Vaughn Caskey
	//06/20/2007
	//
	//Switches calling entity to new animation and frame if variable meets condition.
	//
	//vAni1: Desired animation.
	//iFrame: Desired frame.
	//vReq: Required animation ID.
     
    void vSelf = getlocalvar("self"); //Get calling entity
    void vVal = getglobalvar(vReqVar + vSelf); //Get persistent variable.
            
    if (vVal == vReqVal){ 
             
       changeentityproperty(vSelf, "animation", openborconstant(vAni)); //Switch to desired animation.
       changeentityproperty(vSelf, "animpos", iFrame); //Switch to desired frame.
    
    }
   
}

void dash()
{// Dash with previously attained speed!
    void self = getlocalvar("self");
    float Vx = getlocalvar("x"+self); // Attain x velocity
    float Vz = getlocalvar("z"+self); // Attain z velocity
    if( Vx!=NULL() && Vz!=NULL() ){ // Are both velocity available?
      changeentityproperty(self, "velocity", Vx, Vz); //Move towards target!
    }
} 

void ani003(void vAni, int iFrame, int iRepReq){
    
    //ani003
    //Damon Vaughn Caskey
	//06/20/2007
	//
	//Switches calling entity to new animation and frame if loop number condition is met.
	//
	//vAni1: Desired animation.
	//iFrame: Desired frame.
	//iRepReq: Required loopcount.
     
    void vSelf = getlocalvar("self"); //Get calling entity
    void iRep = getglobalvar("iLoops" + vSelf); //Get number of loops run so far.
	
    if (iRep){ //Because of the odd way BOR script works, we have to establish the variable first, then increment it.

	   iRep = ++iRep; //Loop count variable exists, count up by 1.
		    
	}else{

       iRep = 1.0; //Loop count variable does not exist. Create it using dummy value.

	}

	if (iRep < ++iRepReq){ //Is loop count lower then desired number of loops?

	   changeentityproperty(vSelf, "animation", openborconstant(vAni)); //Switch to desired animation.
       changeentityproperty(vSelf, "animpos", iFrame); //Switch to desired frame.

	}else{ //Loop count reached.

	   iRep = NULL(); //Populate variable with Null() to clean it (In BOR script, this erases variable).

	}

	setglobalvar("iLoops" + vSelf, iRep); //Set global variable.
   
}

void ani004(void vAni, int iFrame){
    
    //ani004
    //Damon Vaughn Caskey 
    //
    //Loops between given frames until caller falls below 1 height. Primarly for juggle falls to turn off bbox when landing. 
    //
    //vAni: Desired animation.
    //iFrame: Desired frame.
     
    void vSelf = getlocalvar("self"); //Get calling entity
    float fY = getentityproperty(vSelf, "a"); //Get Y location.
    float fBase = getentityproperty(vSelf, "base"); //Get base height.
        
    if (fY > 1 || fBase < 0){ //Are we still in air or over a pit?
       
       changeentityproperty(vSelf, "animation", openborconstant(vAni)); //Switch to desired animation. 
       changeentityproperty(vSelf, "animpos", iFrame); //Switch to desired frame.
    
    }
           
}

void ani005(void vTar, void vAni, int iFrame){

     //ani005
     //Damon Vaughn Caskey
     //07/31/2007
     //
     //Change target entity to desired animation.
     //
     //vTar: Target entity (see vTar001 for settings).
     //vAni: Animation cosntant.
     //iFrame: Frame.

     void vSelf = getlocalvar("self"); //Get calling entity
     void vTarget = vTar001(vTar, vSelf); //Target.  

     changeentityproperty(vTarget, "animation", openborconstant(vAni)); //Switch to desired animation. 
     changeentityproperty(vTarget, "animpos", iFrame); //Switch to desired frame.     
     
}

void boun001(int iYMin, void vAni){

    //boun001
	//Damon Vaughn caskey
	//05/11/2007
	//
    //Bounce calling entity upon reaching given height.
    //
    //iYmin: Height entity must fall to before "bouncing".
    //vAni: Animation to play during bounce.
    
    void vSelf = getlocalvar("self"); //Get self.
    
    if (getentityproperty(vSelf, "a") > iYMin ) { return; } //No need to go further, exit script. 
               
    if (vAni){ changeentityproperty(vSelf, "animation", openborconstant(vAni)); } //Set animation.
                   
    jump001(2, -2, 0); //Bounce effect.

}

void dama001(int vTar, void vType, int iForce, int iDrop, float fY, float fX, float fZ){

    //dama001
    //Damon Vaughn Caskey
    //06/28/2007
    //
    //Toss target entity.
    //
	//iTarget: Desired target. 0 = Last entity hit, 1 = Current opponent, 2 = Current hold victum, 3 = Nearest target.
    //fY, fX, fZ: Vertical, horizontal, and depth distance respectively.

    void vSelf = getlocalvar("self"); //Get calling entity.
    void vTarget = vTar001(vTar, vSelf); //Target.

	if (iDrop > 2 && getentityproperty(vSelf, "a") > 0){ //iDrop more then 2 and opponent off the ground?

		toss001(vTarget, 0.05, 0, 0); //Lift target a tiny bit to force a fall when damage is applied.

	}
        
	damageentity(vTarget, vSelf, iForce, iDrop, openborconstant(vType)); //Apply damage.

	if ((fX) || (fY) || (fZ)){ //Is a distance adjustmnt requested?
				
		toss001(vTarget, fY, fX, fZ); //Toss entity.
			
	}

}

void dama002(void vAttacker, int iDamage, int iDrop, int iType){
 
     //dama002
     //Damon Vaughn Caskey
     //09/03/2007
     //
     //Performs specific actions when caller receives damage.
     //
     //vAttacker: Attacking entity.
     //iDamage: Hit point amount.
     //iDrop: Knockdown factor.
     //iType: Attack type.
 
     void vSelf = getlocalvar("self"); //Calling entity.
     int fMaxHP = getentityproperty(vSelf, "maxhealth"); //Get caller's maximum HP.
     int iHP = getentityproperty(vSelf, "health"); //Get caller's current HP.
        
     if (iDamage >= iHP){ //Damage enough to kill caller?
    
        if (iType == openborconstant("ATK_NORMAL")){ //Not any special attack type?
    		
            deat001(vSelf); //Run death function on caller.

        }
    
     }
		
}
void deat001(void vTarget){

	//deat001
	//Damon Vaughn Caskey
	//07/14/2007
	//
	//Changes color map to "death" color and clears any variables that might be associated with target.
    //
    //vTarget: Target entity.          
	
	changeentityproperty(vTarget, "map", 1); //Switch to "death" color map.
		
	killentity(getglobalvar("vDumm001" + vTarget)); //Destroy any dummy entity.

	setglobalvar("head" + vTarget, NULL()); //Clear head entity variable.
	setglobalvar("vSpawn" + vTarget,  NULL()); //Clear last spawn variable.
	setglobalvar("iMap" + vTarget,  NULL()); //Clear remap variable.
	setglobalvar("iLoops" + vTarget,  NULL()); //Clear loop count variable.
	setglobalvar("vDumm001" + vTarget,  NULL()); //Clear dummy entity global variable.
	setglobalvar("iAni" + vTarget,  NULL()); //Clear animation ID variable.
	setglobalvar("vTarget" + vTarget,  NULL()); //Clear last target variable.
	setglobalvar("vTargetDir" + vTarget,  NULL()); //Clear target direction global variable.
	setglobalvar("fXA" + vTarget,  NULL()); //Clear X adjustment.
    setglobalvar("fYA" + vTarget,  NULL()); //Clear Y adjustment.
    setglobalvar("fZA" + vTarget,  NULL()); //Clear Z adjustment.
}

void deat002(void vTarget){

	void vSelf = getlocalvar("self"); //Calling entity.
    
	deat001(vTar001(vTarget, vSelf));

}

void deat003(void vTarget){

	void vSelf = getlocalvar("self"); //Calling entity.
    void vTarget = vTar001(vTarget,vSelf); //Target.
    float fX = getentityproperty(vTarget, "x"); //Y location.
    float fY = getentityproperty(vTarget, "a"); //Y location.
    float fB = getentityproperty(vTarget, "base"); //Y location.
    float fXP = openborvariant("xpos");
    
    drawstring(4, 70, 0, fXP);
    
    if (fY <= fB && fB >= 0){
    
       killentity(vTarget);   
           
    }
    
}

void knife(int Rx, int Rz, int RyMin, int RyMax, void Ani)
{// Performs climb ladder up animation if ClimbSpot is found within defined range
// Rx = x distance to find knife1
// Rz = z distance to find knife1
// Ani = Animation to change
    void self = getlocalvar("self");
    float x = getentityproperty(self, "x");
    float y = getentityproperty(self, "a");
    float z = getentityproperty(self, "z");
    int Dir = getentityproperty(self, "direction");

    void vEntity;                                       //Target entity placeholder.
    void vAniID;
    int  iEntity;                                       //Entity enumeration holder.
    int  iName;                                         //Entity name.
    int  iMax      = openborvariant("ent_max");         //Entity count.
    int TDir;

    float Tx;
    float Ty;
    float Tz;
    float Disx;
    float Disz;
    float Disy;

    //Enumerate and loop through entity collection.
    for(iEntity=0; iEntity<iMax; iEntity++){
      vEntity = getentity(iEntity);                 //Get target entity from current loop.
      iName   = getentityproperty(vEntity, "defaultname"); //Get target name
      vAniID  = getentityproperty(vEntity,"animationID");

      if(iName == "knife02" || iName == "knife03" || iName == "Star"){
        if(vAniID != openborconstant("ANI_FOLLOW2")){
          Tx = getentityproperty(vEntity, "x");
          Ty = getentityproperty(vEntity, "a");
          Tz = getentityproperty(vEntity, "z");
          TDir = getentityproperty(vEntity, "direction");
          Disx = Tx - x;
          Disz = Tz - z;
          Disy = Ty - y;

          if(Disx >= -Rx && Disx <= Rx && Disz >= -Rz && Disz <= Rz && Disy >= RyMin && Disy <= RyMax && Dir != TDir){
            changeentityproperty(vEntity, "velocity", 0, 0, 0);
            changeentityproperty(vEntity, "animation", openborconstant(Ani));
          }
        }
      }
    }
}

void deat004(void vTarget){

	void vSelf = getlocalvar("self"); //Calling entity.
    
	deat001(vTar001(vTarget, vSelf));
    killentity(vTar001(vTarget, vSelf));

}

void debu001(){
     
     //return;

     void vSelf = getlocalvar("self"); //Calling entity.
     float fX = getentityproperty(vSelf, "x"); //X location.
     float fY = getentityproperty(vSelf, "a"); //Y location.
	 float fZ = getentityproperty(vSelf, "z"); //Z location.
     float fB = getentityproperty(vSelf, "base"); //Z location.
     int iAniID = getentityproperty(vSelf, "animationID"); //Animation ID.

	 drawstring(4, 60, 0, iAniID);
     drawstring(4, 70, 0, openborvariant("xpos"));
     drawstring(4, 80, 0, "X: "+ fX + ", Y: " + fY + ", Z: " + fZ + ", B: " + fB);
	 drawstring(4, 90, 0,  getglobalvar("hanz0004" + vSelf));
     
}

void effe002(int iEffectMap, int iAni){
	
	//effe002
	//Damon Vaughn Caskey
	//
	//07/21/2007
	//
	//Syncronizes location of special effect entity with parent entity while remaping parent.
	//
	//iEffectMap: Desired remap to set on parent.
	//iAni: Animation requirement.
	
    void vSelf = getlocalvar("self"); //Calling entity.
    void vParent = getentityproperty(vSelf, "parent"); //Parent entity.
    int iMap = getentityproperty(vParent, "map"); //Parent's current color map.
    int iOGMap = getglobalvar("map" + vParent); //Parents orginal color map.
    int iAniID = getentityproperty(vParent,"animationID"); //Parent's current animation ID.
    
    if(iAniID != iAni){ //Not in iAni.
                  
         changeentityproperty(vParent, "map", iOGMap); //Change parent to orginal map.
         deat001(vSelf); //Run death function on caller to clear variables.
         killentity(vSelf); //Destroy caller.
             
    }else{ //In iAni.
                 
         if(iEffectMap != iMap){ //Not using effect map?        
    
              setglobalvar("map" + vParent, iMap); //Store parent's orginal map.
              changeentityproperty(vParent, "map", iEffectMap); //Change parent to effect map.      
                                  
        }
    
	}
    
    float fX = getglobalvar("fXA" + vSelf); //X adjustment.
    float fY = getglobalvar("fYA" + vSelf); //Y adjustment.
	float fZ = getglobalvar("fZA" + vSelf); //Z adjustment.

    loc001(vSelf, vParent, fX, fY, fZ, 0); //Perform location sync.

}

void grav001(void vTar, float fGrav){

     void vSelf = getlocalvar("self"); //Calling entity.
     void vTarget = vTar001(vTar, vSelf); //Target entity.

     changeentityproperty(vTarget, "antigravity", fGrav); //Set gravity effect.
          
}

void hit001(void vTarget, int iBlocked){

	//hit001
	//Damon V. Caskey
	//08/21/2007
	//
	//Processes event when caller hits target.
	//
	//vTarget: Entity hit by attack event.
	//iBlocked: If attack is blocked.

	void vSelf = getlocalvar("self"); //Caller.
	void vParent = getentityproperty(vSelf, "parent"); //Name of caller.
	void vName = getentityproperty(vSelf, "name"); //Name of caller.
	int iAniID = getentityproperty(vSelf, "animationID"); //Get current animation ID.
	//int iType = getentityproperty(vParent, "type"); 
             
    if (vName == "Kuna0001" || vName == "Kuna0002" || vName == "hanz0008" || vName == "hanz0009" || vName == "hanz0020" || vName == "hanz0021"){
    
        changeentityproperty(vParent, "opponent" , vTarget); //Set attacker's opponent as target.
        changeentityproperty(vTarget, "opponent" , vParent); //Set target's opponent as attacker.
        deat001(vSelf); //Clean variables.
        //killentity(vSelf);
              
    }else{
          
        setglobalvar("vTarget" + vSelf, vTarget); //Set a global variable containing the entity caller hit.
	    setglobalvar("iAni" + vSelf, iAniID); //Set a global variable containing the animation of caller.
	         
    }
    
}

void jump001(float fY, float fX, float fZ){
	
	//jump001
	//Damon Vaughn Caskey
	//05/08/2007
	//
	//Replicates jumpframe effect.
	//
	//fY: Jumpheight.
	//fX: Horizontal distance.
	//fZ: Z axis distance.

	void vSelf = getlocalvar("self"); //Get calling entity

	toss001(vSelf, fY, fX, fZ); //Call toss001.

}

void jump002(){
	
	//jump002
	//Damon Vaughn Caskey
	//06/29/2007
	//
	//In conjunction with ani003, provides "flight" path according to number of reps. Designed primary for Hanzou's Ninpo Korin Kazan move.
	
	void vSelf = getlocalvar("self"); //Get calling entity
	int iRep = getglobalvar("iLoops" + vSelf); //Get number of loops run so far.
    float fX = 0;
    float fY = 0;
    float fZ = 0;
    
    if(iRep <= 3){
    
       fY = -1.5;
       fX = 3;         
                
    }else if(iRep > 3 && iRep <= 6){
    
       fY = -0.5;
       fX = 3.5;

    }else if(iRep > 6 && iRep < 9){
    
       fY = 0.07;
       fX = 3.5;
    
    }else{
        
       fY = 1;
       fX = 3;
    
    }        

	toss001(vSelf, fY, fX, fZ); //Call toss001.

}

int keyd001(int iIndex, int iNewKey, void vSelf){
     
     //keyd001
     //Damon Vaughn Caskey
     //05/13/2007
     //
     //Wrapper for players keys function, returns integer based on key pressed.
     //
     //iIndex: Player index for key press.
     //iNewKey: New key press or "holding".
     //vSelf: Target entity. 
          
     if (getentityproperty(vSelf, "direction")==1 && (playerkeys(iIndex,iNewKey, "moveright"))){
     
          return 10; //"Forward" (facing right).

     }else if (getentityproperty(vSelf, "direction")==0 && (playerkeys(iIndex,iNewKey, "moveleft"))){
     
          return 10; //"Forward" (facing left).
          
     }else if (getentityproperty(vSelf, "direction")==1 && (playerkeys(iIndex,iNewKey, "moveleft"))){
     
          return 11; //"Back" (facing right).

     }else if (getentityproperty(vSelf, "direction")==0 && (playerkeys(iIndex,iNewKey, "moveright"))){
     
          return 11; //"Back" (facing left).
          
     }else if (playerkeys(iIndex,iNewKey, "moveleft")){
                                   
          return 1; //Left.
     
     }else if (playerkeys(iIndex,iNewKey, "moveright")){
     
          return 2; //Right.
                    
     }else if (playerkeys(iIndex,iNewKey, "moveup")){
     
          return 3; //Up.
                    
     }else if (playerkeys(iIndex,iNewKey, "movedown")){
     
          return 4; //Down.
                    
     }else if (playerkeys(iIndex,iNewKey, "esc")){
     
          return 5; //Escape.
                    
     }else if (playerkeys(iIndex,iNewKey, "start")){
     
          return 6; //Start.
                    
     }else if (playerkeys(iIndex,iNewKey, "special")){
     
          return 7; //Special.
                    
     }else if (playerkeys(iIndex,iNewKey, "jump")){
     
          return 8; //Jump.
                    
     }else if (playerkeys(iIndex,iNewKey, "attack")){
     
          return 9; //Attack 1.
                    
     }
     
}

void loc001(void vSync, void vTarget, float fX, float fY, float fZ, int iDirection){
    
    //loc001
	//Damon Vaughn Caskey
	//04/20/2007
	//
	//Syncronizes location of entity to second entity.
	//
	//vSync: Entity to sync.
	//vTarget: Entity to sync to.
	//fX: X distance adjustment.
	//fZ: Y distance adjustment.
    //fY: Z distance adjustment.
    //iDirection: Desired direction of sync (0 same as target, 1 = Opposing target, 2 = left, 3 = right)
	
    int iDir = getentityproperty(vTarget, "direction");
         
    if (iDir == 0){ //Target facing left?
             
         fX = -fX; //-fXP; //Reverse horizontal adjustment. 
             
    }
    
	if (!(fX)){

		fX = 0.0;
	
	}

	if (!(fY)){

		fX = 0.0;
	
	}

	if (!(fZ)){

		fX = 0.0;
	
	}

    fX = fX + getentityproperty(vTarget, "x"); //Get target entity X location.
    fY = fY + getentityproperty(vTarget, "a"); //Get target entity Y location.
    fZ = fZ + getentityproperty(vTarget, "z"); //Get target entity Z location.
               
    if (iDirection == 1){ //Direction setting 1 (Opposing target)?
	
		if (iDir){ //Facing left?

			iDirection = 0; //Force right facing.

		}else{ //Facing right?

			iDirection = 1; //Force left facing.

		}

	}else if (iDirection == 2){ //Direction setting 2 (left)?

		iDirection = 1; //Force left facing.

	}else if (iDirection == 3){ //Direction setting 3 (right)?

		iDirection = 0; //Force right facing.

	}else if (iDirection == 0 || !(iDirection)){ //Direction setting 0 (same as target)?

		iDirection = iDir; //Force facing same as target.
	
	}
    
    changeentityproperty(vSync, "direction", iDirection); //Adjust sync entity direction.   
    changeentityproperty(vSync, "position", fX, fZ, fY); //Adjust sync entity location.    

}

void vPro001(void vName, void vMap, float fX, float fY, float fZ, float fXSpeed, float fYSpeed, float fZSpeed){

     //vPro001
     //Damon Vaughn Caskey
     //09/07/2007
     //Spawns entity and applies desired directional velocity.
     //
     //vName: Entity model name.
     //vMap: Entity remap.
     //fX: Spawn X location.
     //fY: Spawn Y location.
     //fZ: Spawn Z location.
     //fXSpeed: X speed.
     //fYSpeed: Y speed.
     //fZSpeed: Z speed.
     
     void vSelf = getlocalvar("self"); //Get calling entity.     
     int iDirection = getentityproperty(vSelf, "direction"); //Get calling entity direction.
     void vSpawn;
     
     if (iDirection == 0){ //Is caller facing right?                  
                
         fXSpeed = -fXSpeed; //Reverse X adjustment to match facing.
		 
     }
     
     vSpawn = spawn001(vName, vName, vMap, fX, fY, fZ, 0); 
         
     changeentityproperty(vSpawn, "direction", iDirection); //Apply movement.
     changeentityproperty(vSpawn, "velocity", fXSpeed, fZSpeed, fYSpeed); //Apply movement.

     return vSpawn;

}


void vPro002(void vName, int iCount, void vMap, float fX, float fY, float fZ, float fXS, float fYS, float fZMin, float fZMax){
     
     int iCnt;
     float fZAdd = (fZMax - fZMin) / iCount; 
     
     for (iCnt = 0; iCnt < iCount; iCnt++){
    
         vPro001(vName, vMap, fX, fY, fZ, fXS, fYS, fZMin);
         fZMin = fZMin + fZAdd; 
    
     }
   
}

int iRan001(float fLoc1, float fLoc2, float fMin, float fMax){

	//iRange
	//Damon Vaughn Caskey
	//08/07/2007
	//Returns 1 if distance between two locations falls within Minimum and Maximum range.
	//
	//fLoc1: First entity.
	//fLoc2: Second entity.
	//fMin: Minumum range value.
	//fMax: maximum range value.

	int fDis = fLoc1 - fLoc2;

	if ((fMin) || (fMax)){ //Min or max range provided?
            
		if(fDis > fMin && fDis < fMax){ //Are entities within minimum and maximum range?
        
			return 1; //Return 1.
            
		}else{

			return 0; //Return 0.

		}
    
	}else{ //Within range or ranges simply not provided.

		return 1;  //Return 1.

	}

}

void rema001(int iMap){
     
    //rema001
	//Damon Vaughn Caskey
	//07/14/2007
	//
	//Changes color map as desired.
	//
	//iMap: Desired color map.
     
     void vSelf = getlocalvar("self"); //Get calling entity.     

     setglobalvar("iMap" + vSelf, getentityproperty(vSelf,"map")); //Record current map.
     
     changeentityproperty(vSelf, "map", iMap); //Switch to desired color map.
     
}

void rema002(){
     
    //rema002
	//Damon Vaughn Caskey
	//07/14/2007
	//
	//Changes color map to last recorded remap.
	       
     void vSelf = getlocalvar("self"); //Get calling entity.     
     changeentityproperty(vSelf, "map", getglobalvar("iMap" + vSelf)); //Switch to last color map.
     
}

void rema003(){
     
    //rema003
	//Damon Vaughn Caskey
	//08/28/2007
	//
	//Changes color map to parent's remap.
	
     void vSelf = getlocalvar("self"); //Get calling entity.
     void vParent = getentityproperty(vSelf, "parent");
     void iPmap = getentityproperty(vParent, "map");
     
     changeentityproperty(vSelf, "map", iPmap); //Switch to parent's color map.
     
}
 
void soun001(void vSample, int iPri, int iL, int iR, int iSpeed, int iLoop, int iUnload){
 
     //soun001
     //Damon Vaughn Caskey
     //08/07/2007
     //
     //Plays sound sample.
     //
     //vSample: Sound file.
     //iPri: Play priority (0).
     //iL: Left volume (120).
     //iR: Right volume (120).
     //iSpeed: Speed of play (100).
     //iLoop: Loop setting (1 = loop).     
     //iUnload: Unload sample (1 = yes, 2 = no).
     
    int iSample = loadsample(vSample);
    
    playsample(iSample, iPri, iL, iR, iSpeed, iLoop);
    
    if (iUnload == 1){

        unloadsample(iSample);
    
    }
    
}

void spawn001(void vName, void vAlias, void vMap, float fX, float fY, float fZ, int iAdjust){

	//spawn001
	//Damon Vaughn Caskey
	//07/06/2007
	//
	//Spawns entity with various adjustments as requested.
	//
	//vName: Model name of entity to be spawned in.
	//vAlias: Alias name given to spawned entity.
	//iMap: Color remap of spawned entity.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
    //fY: Z location adjustment.
	//iAdjust: Starting postion and adjustment behavior -
	//
	//	0. Caller location.
	//  1. Caller location and store adjustment on caller for later use.
	//  2. Current area of screen.
	//	3. Caller's current opponent.
	//	4. Caller's location and store adjustment on spawn for later use.

	void vSelf = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	int iDirection = getentityproperty(vSelf, "direction"); //Get calling entity direction.


    clearspawnentry(); //Clear current spawn entry.
    setspawnentry("name", vName); //Aquire spawn entity by name.
    setspawnentry("alias", vAlias); //Set alias.
	setspawnentry("map", vMap); //Set color remap.
	setspawnentry("coords", fX, fZ, fY); //Set spawn location
    
    vSpawn = spawn(); //Spawn entity.
    clearspawnentry(); //Clear current spawn entry.
   
    if (iDirection == 0){ //Is caller facing right?                  
     
         fX = -fX; //Reverse X adjustment to match facing.
		     
	}
   
	if (!(iAdjust)){ //Adjust spawn to caller.

		fX = fX + getentityproperty(vSelf, "x"); //Get X location and add adjustment.
		fY = fY + getentityproperty(vSelf, "a"); //Get Y location and add adjustment.
		fZ = fZ + getentityproperty(vSelf, "z"); //Get Z location and add adjustment.

	}else if (iAdjust == 1){ //Adjust spawn to caller and store adjustments on caller for later use.
          
        //Store adjustment variables on caller.
        setglobalvar("fXA" + vSelf, fX); //X adjustment.
		setglobalvar("fYA" + vSelf, fY); //Y adjustment.
		setglobalvar("fZA" + vSelf, fZ); //Z adjustment.
 
		fX = fX + getentityproperty(vSelf, "x"); //Get X location and add adjustment.
		fY = fY + getentityproperty(vSelf, "a"); //Get Y location and add adjustment.
		fZ = fZ + getentityproperty(vSelf, "z"); //Get Z location and add adjustment.

	}else if (iAdjust == 2){//Adjust entity to caller Z, Y, with X base relating to stage location.
		
		fX = fX + openborvariant("xpos"); //X = Stage location + X adjustment.
		
	}else if (iAdjust == 3){ //Adjustment from current opponent.

		void vTarget = vTar001(1, vSelf); //Caller's current opponent.

        //Store adjustment varaibles on current opponent.
		fX = fX + getentityproperty(vTarget, "x"); //Get X location and add adjustment.
		fY = fY + getentityproperty(vTarget, "a"); //Get Y location and add adjustment.
		fZ = fZ + getentityproperty(vTarget, "z"); //Get Z location and add adjustment.
	
	}else if (iAdjust == 4){ //Adjust spawn to caller and store adjustments on spawn for later use.
                
        //Store adjustment varaibles on spawn.
        setglobalvar("fXA" + vSpawn, fX); //X adjustment.
		setglobalvar("fYA" + vSpawn, fY); //Y adjustment.
		setglobalvar("fZA" + vSpawn, fZ); //Z adjustment.
    
        fX = fX + getentityproperty(vSelf, "x"); //Get X location and add adjustment.
		fY = fY + getentityproperty(vSelf, "a"); //Get Y location and add adjustment.
		fZ = fZ + getentityproperty(vSelf, "z"); //Get Z location and add adjustment.
    
    }else if (iAdjust == 5){ //No adjustment at all.
    
        return vSpawn;
    
    }
   
	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
	changeentityproperty(vSpawn, "parent", vSelf); //Set caller as parent.
	changeentityproperty(vSpawn, "direction", iDirection); //Set direction.
    
    setglobalvar(vAlias + vSelf, vSpawn); //Store spawned entity in persistent global variable.
	    
    return vSpawn; //Return spawn.

}

void spawn002(void vName, void vAlias, int iMap, float fX, float fY, float fZ, float fYJ, float fXJ, float fZJ){
     
    //spawn002
	//Damon Vaughn Caskey
	//07/14/2007
	//
	//Spawns desired entity, then kills it. Intended for decapitation and lost body parts.
	//
	//vName: Spawn model name.
	//iMap: Desired starting remap of spawn.
	//fX: Starting X location adjustment.
	//fY: Starting Y location adjustment.
	//fZ: Starting Z location adjustment.
	//fYJ: Y flight distance.
	//fXJ: X flight distance.
	//fZJ: Z flight distance.
         
     void vSelf = getlocalvar("self"); //Get calling entity.
     int iHP = getentityproperty(vSelf, "health"); //Get caller's current HP.
     
	 void vSpawn = spawn001(vName, vAlias, iMap, fX, fY, fZ, 0); //Spawn entity to be killed with appropriate adjustments.
     
	 damageentity(vSpawn, vSpawn, 10000000, 1, openborconstant("ATK_NORMAL")); //Kill spawned entity (No, killentity() won't work here).
     toss001(vSpawn, fYJ, fXJ, fZJ); //Call toss001.	 
     
}


void spawn003(void vName, void vAlias, int vMap, float fX, float fY, float fZ, int iAdjust, int iDirection){

	//spawn003
	//Damon Vaughn Caskey
	//08/28/2007
	//
	//Calls spawn001 and adds direction adjustment. See spawn001 for parameters.
	
	void vSpawn = spawn001(vName, vAlias, vMap, fX, fY, fZ, iAdjust);
	void vParent = getentityproperty(vSpawn, "parent");
    int iDir = getentityproperty(vParent, "direction");

	if (iDirection == 1){ //Direction setting 1 (Opposing target)?
	
		if (iDir){ //Facing left?

			iDirection = 0; //Force right facing.

		}else{ //Facing right?

			iDirection = 0; //Force left facing.

		}

	}else if (iDirection == 2){ //Direction setting 2 (left)?

		iDirection = 0; //Force left facing.

	}else if (iDirection == 3){ //Direction setting 3 (right)?

		iDirection = 0; //Force right facing.

	}else if (iDirection == 0 || !(iDirection)){ //Direction setting 0 (same as target)?

		iDirection = iDir; //Force facing same as target.
	
	}
    
    changeentityproperty(vSpawn, "direction", iDirection); //Adjust spawn direction.
    return vSpawn;

}

void spawn004(void vName, void vAlias, int vMap, float fX, float fY, float fZ, int iAdjust,int iDirection,void vAni3,int iFrame){

	//spawn003
	//Damon Vaughn Caskey
	//08/28/2007
	//
	//Calls spawn001 and adds direction adjustment. See spawn001 for parameters.
	void vSpawn = spawn001(vName, vAlias, vMap, fX, fY, fZ, iAdjust);
	void vParent = getentityproperty(vSpawn, "parent");
    int iDir = getentityproperty(vParent, "direction");

	if (iDirection == 1){ //Direction setting 1 (Opposing target)?
	
		if (iDir){ //Facing left?

			iDirection = 0; //Force right facing.

		}else{ //Facing right?

			iDirection = 0; //Force left facing.

		}

	}else if (iDirection == 2){ //Direction setting 2 (left)?

		iDirection = 0; //Force left facing.

	}else if (iDirection == 3){ //Direction setting 3 (right)?

		iDirection = 0; //Force right facing.

	}else if (iDirection == 0 || !(iDirection)){ //Direction setting 0 (same as target)?

		iDirection = iDir; //Force facing same as target.
	
	}
    
    changeentityproperty(vSpawn, "direction", iDirection); //Adjust spawn direction.
    changeentityproperty(vSpawn, "animation", vAni3); 
    changeentityproperty(vSpawn, "animpos", iFrame); 

    return vSpawn;
    
}
void spawn005(void vName, void vAlias, int vMap, float fX, float fY, float fZ, int iAdjust, int iDirection){

	//spawn003
	//Damon Vaughn Caskey
	//08/28/2007
	//
	//Calls spawn001 and adds direction adjustment. See spawn001 for parameters.
	
	void vSpawn = spawn001(vName, vAlias, vMap, fX, fY, fZ, iAdjust);
	void vParent = getentityproperty(vSpawn, "parent");
    int iDir = getentityproperty(vParent, "direction");

	if (iDirection == 1){ //Direction setting 1 (Opposing target)?
	
		if (iDir){ //Facing left?

			iDirection = 0; //Force right facing.

		}else{ //Facing right?

			iDirection = 1; //Force left facing.

		}

	}else if (iDirection == 2){ //Direction setting 2 (left)?

		iDirection = 1; //Force left facing.

	}else if (iDirection == 3){ //Direction setting 3 (right)?

		iDirection = 0; //Force right facing.

	}else if (iDirection == 0 || !(iDirection)){ //Direction setting 0 (same as target)?

		iDirection = iDir; //Force facing same as target.
	
	}
    
    changeentityproperty(vSpawn, "direction", iDirection); //Adjust spawn direction.
    return vSpawn;

}
void sync002(void vSyncSet, float fX, float fY, float fZ, int iDirection){
    
    //sync002
	//Damon Vaughn Caskey
	//06/20/2007
	//
	//Syncronizes target with caller's location.
	//
	//iSync: Sync target setting (see vTar001 function).
	//fX: X distance adjustment (from caller).
	//fZ: Y distance adjustment (from caller).
    //fY: Z distance adjustment (from caller).
    //iDirection: Direction adjustment (see loc001 function).
    
    void vSelf = getlocalvar("self"); //Get calling entity
    void vSync = vTar001(vSyncSet, vSelf); //Get appropriate target.
    
    loc001(vSync, vSelf, fX, fY, fZ, iDirection); //Call loc001 function to perform location sync.       
    
}

void sync003(void vSpawn, void vAni, int iFrame){
    
    //sync003
	//Damon Vaughn Caskey
	//07/14/2007
	//
	//Syncronizes callers last spanwed entity with desired animation frame.
	//
	//vAni: Desired animation.
	//iFrame: Desired frame.
        
    void vSelf = getlocalvar("self"); //Get calling entity.
    void vTarget = getglobalvar(vSpawn + vSelf); //Get last spawned entity.
           
    //changeentityproperty(vTarget, "animation", openborconstant(vAni)); //Switch to desired animation.
    changeentityproperty(vTarget, "animpos", 4); //Switch to desired frame.
    
}

void sync004(void vName, int iStatus, int vTarget){

	//sync004
	//Damon Vaughn Caskey
	//08/02/2007
	//
	//Starts or stops persistent syncing of target entity to caller.
	//
	//iTarget: Synching target, see below.
	//iStatus: Start or stop synching.
	//iDirection: Desired direction of sync target (0 same as caller, 1 = Opposing calller, 2 = left, 3 = right)
	
	void vSelf = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
		
	if (iStatus == 0){
				
		vSpawn = spawn001(vName, vName, 0, 0, 0, 0, 0); //Spawn entity.
		
		setglobalvar("vTarget" + vSelf, vTar001(vTarget, vSelf)); //Store target entity as global variable.    
		//setglobalvar("vTargetDir" + vSelf, iDirection); //Store desired direction as global variable.    

	}else if (iStatus == 1){

		killentity(getglobalvar(vName + vSelf)); //Destroy entity.
		
		setglobalvar(vName + vSelf, 0); //Clear spawned entity persistent global variable.
		setglobalvar("fXA" + vSelf, 0); //Clear X location global variable.
		setglobalvar("fYA" + vSelf, 0); //Clear Y location global variable.
		setglobalvar("fZA" + vSelf, 0); //Clear Z location global variable.
		setglobalvar("vTarget" + vSelf, 0); //Clear target global variable.    
        setglobalvar("vTargetDir" + vSelf, 0); //Clear target direction global variable.    

	}

}

void sync005(void vTar, float fX, float fY, float fZ, int iDirection){
    
    //sync005
	//Damon Vaughn Caskey
	//06/20/2007
	//
	//Syncronizes caller with with target.
	//
	//iSync: Sync target setting (see vTar001 function).
	//fX: X distance adjustment (from caller).
	//fZ: Y distance adjustment (from caller).
    //fY: Z distance adjustment (from caller).
    //iDirection: Direction adjustment (see loc001 function).
    
    void vSelf = getlocalvar("self"); //Get calling entity
    void vSync = vTar001(vTar, vSelf); //Get appropriate target.
    
    loc001(vSelf, vSync, fX, fY, fZ, iDirection); //Call loc001 function to perform location sync.       
    
}

void sync006(){

	//sync006
	//Damon Vaughn Caskey
	//08/14/2007
	//
	//Syncs caller location with parent, then designated target to caller.

	void vSelf = getlocalvar("self"); //Calling entity.
    void vParent = getentityproperty(vSelf, "parent"); //Parent entity.
	void vTarget = getglobalvar("vTarget" + vParent); //Target entity.
    int iDirection = getglobalvar("vTargetDir" + vParent); //Direction djustment.
    float fX = getglobalvar("fXA" + vParent); //X synch adjustment.
    float fY = getglobalvar("fYA" + vParent); //Y synch adjustment.
    float fZ = getglobalvar("fZA" + vParent); //Z synch adjustment.	
    
	//drawstring(4, 170, 0, getglobalvar("dumm0001"));

	loc001(vSelf, vParent, fX, fY, fZ, iDirection); //Sync self with parent.
    loc001(vTarget, vParent, fX, fY, fZ, iDirection); //Sync target with parent including adjustments.

}

void sync007(float fX, float fY, float fZ, int iDirection){

	//sync007
	//Damon Vaughn Caskey
	//08/16/2007
	//
	//Changes adjustments for dummy syncing (see sync004).
	//
	//fX, fY, fZ: New X, Y, and Z adjustments respectivly.

	void vSelf = getlocalvar("self"); //Calling entity.
    		
	setglobalvar("vTargetDir" + vSelf, iDirection); //Direction djustment.
    setglobalvar("fXA" + vSelf, fX); //Set X sync adjustment.
    setglobalvar("fYA" + vSelf, fY); //Set Y sync adjustment.
    setglobalvar("fZA" + vSelf, fZ); //Set Z sync adjustment.	
    
}

void sync008(){

	//sync008
	//Damon Vaughn Caskey
	//08/14/2007
	//
	//Syncs designated target to caller.

	void vSelf = getlocalvar("self"); //Calling entity.
	void vParent = getentityproperty(vSelf, "parent"); //Parent entity.
	void vTarget = getglobalvar("vTarget" + vParent); //Target entity.
    int iDirection = getentityproperty(vSelf, "direction"); //Direction djustment.
        
    loc001(vTarget, vSelf, 0, 0, 0, iDirection); //Sync target with self.

}

void vTar001(void vTarget, void vSelf){
	
	//vTar001
	//Damon Vaughn Caskey
	//08/02/2007
	//
	//Returns target entity handle from desired source.
	//
	//itarget: Desired target source.
	//vSelf: Entity searching for target.

	if (!(vTarget)){ //Self.

		return vSelf; //Return "self".
	
	}else if (vTarget == 1){//Current opponent.
		
		return getentityproperty(vSelf, "opponent"); //Get current opponent. 

	}else if (vTarget == 2){ //Current hold victum.

		return getentityproperty(vSelf, "grabbing"); //Get entity vSelf is holding.

	}else if (vTarget == 3){ //Nearest hostile entity.

		return findtarget(vSelf); 
		
    }else if (vTarget == 4){ //Caller's parent.

		return getentityproperty(vSelf, "parent");

	}else{ //Variable.

		return getglobalvar(vTarget + vSelf); //Get and return variable matching caller and vTarget.

	}

}

void toss001(void vTarget, float fY, float fX, float fZ){

    //toss001
    //Damon Vaughn Caskey
    //06/28/2007
    //
    //Toss target entity.
    //
	//vTarget: Entity to toss.
	//fY, fX, fZ: Vertical, horizontal, and depth distance respectively.
    
	if (getentityproperty(vTarget, "direction") == 0){ //Facing left?
		
		fX = -fX; //Reverse horizontal adjustment.
	
	} 
    
	tossentity(vTarget, fY, fX, fZ); //Perform toss action on target.
    
}

void toss002(void vTarget, float fY, float fX, float fZ){

    //toss001
    //Damon Vaughn Caskey
    //06/28/2007
    //
    //Determine target of caller and toss.
    //
	//vTarget: Entity or target set.
	//fY, fX, fZ: Vertical, horizontal, and depth distance respectively.
    
	void vSelf = getlocalvar("self"); //Get calling entity.

	toss001(vTar001(vTarget,vSelf), fY, fX, fZ); //Activate toss function with target.
    
}

void var001(void vName, void vValue){

	void vSelf = getlocalvar("self"); //Get calling entity.

	setglobalvar(vName + vSelf, vValue);	

}

void velo001(float fX, float fZ, float fY){
     
    //velo001
	//Damon Vaughn Caskey
	//05/06/2007
	//
	//Replicates movement effect.
	//
	//fX: X axis speed.
	//fZ: Z axis speed.
	//fY: Y axis speed.
	
	void vSelf = getlocalvar("self"); //Get calling entity.
	
	if (getentityproperty(vSelf, "direction")==0){ //Is entity facing right?                  
     
         fX = -fX; ////Reverse X direction to match facing.
         
    }         
	
	changeentityproperty(vSelf, "velocity", fX, fZ, fY); //Apply movement.

}

void weap001(int iWep){
 
    //weap001
	//Damon Vaughn Caskey
	//06/30/2007
    //Sets callers weapon model.
    //
    //iWep: Desired weapon model index.
     
     void vSelf = getlocalvar("self"); //Get calling entity.
     int iMap = getentityproperty(vSelf, "map"); //Get current remap.
     
     if ((iWep) && (iMap)){ //If requested model is not default and a remap is being used, record remap.
     
        setglobalvar("iMap" + vSelf, iMap); 
          
     } 
     
	 changeentityproperty(vSelf, "weapon", iWep, 0); //Switch to desired model.
     changeentityproperty(vSelf, "map", getglobalvar("iMap" + vSelf)); //Defeat weapon remap bug by forcing a switch back to remap.
     
}

void bind(int null, float x, float z, float y, int dir){
	void self = getlocalvar("self");
	void opp = getentityproperty(self, "opponent");
	if(null == 1)
	{
		bindentity(opp, self, x, z, y, dir, 0);
	}
	else if(null == 0)
	{
		bindentity(opp, NULL());
	}
}
void antiwall(int Dist, int Move, int Distz)
{// Checks if there is wall at defined distance
// If there is wall, entity will be moved away with defined movement
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int z = getentityproperty(self, "z");
   float H;
   float Hz;

   if (Direction == 0){ //Is entity facing left?                  
      Dist = -Dist; //Reverse Dist to match facing
      Move = -Move; //Reverse Move to match facing
   }

   H = checkwall(x+Dist,z);
   Hz = checkwall(x+Dist,z+Distz);

   if(Hz > 0)
   {
     changeentityproperty(self, "position", x, z-Distz);
   }

   if(H > 0)
   {
     changeentityproperty(self, "position", x+Move);
   }
}

void antiwall2(int Dist, int Move, int Distz)
{// Checks if there is wall at defined distance
// If there is wall, entity will be moved away with defined movement
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   float H;
   float Hz;

   if(Direction == 0){ //Is entity facing left?                  
      Dist = -Dist; //Reverse Dist to match facing
      Move = -Move; //Reverse Move to match facing
   }

   H = checkwall(x+Dist,z);
   Hz = checkwall(x+Dist,z+Distz);

   if(Hz > y)
   {
     changeentityproperty(self, "position", x, z-Distz);
   }

   if(H > y)
   {
     changeentityproperty(self, "position", x+Move);
   }
}

void antiwall4(int Dist, void Ani)
{// Checks if there is wall at defined distance
// If there is wall, entity will be moved away with defined movement
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   float H;
   float H2;

   if(Direction == 0){ //Is entity facing left?                  
      Dist = -Dist; //Reverse Dist to match facing
   }

   H = checkwall(x+Dist,z);
   H2 = checkbasemap(x+Dist,z);

   if(H >= y)

   {
     changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
     changeentityproperty(self, "animation", openborconstant(Ani));
   }

   if(H2 >= y)

   {
     changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
     changeentityproperty(self, "animation", openborconstant(Ani));
   }
}

void antibasemap(int Dist, int Move, int Distz)
{// Checks if there is wall at defined distance
// If there is wall, entity will be moved away with defined movement
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int b = getentityproperty(self, "base");
   int z = getentityproperty(self, "z");
   float H;
   float Hz;

   if(Direction == 0){ //Is entity facing left?                  
      Dist = -Dist; //Reverse Dist to match facing
      Move = -Move; //Reverse Move to match facing
   }

   H = checkbasemap(x+Dist,z);
   Hz = checkbasemap(x+Dist,z+Distz);

   if(Hz > y)
   {
     tossentity(self, 0, 0, 0);
     changeentityproperty(self, "position", x, z-Distz);
   }

   if(H > y)
   {
     tossentity(self, 0, 0, 0);
     changeentityproperty(self, "position", x+Move);
   }
}

void shooter2(void vName, float fX, float fY, float fZ, float Vx, float Vy, float Vz)
{//Spawns projectile next to caller and move it with speed
 //vName: Model name of entity to be spawned in
 //fX: X location adjustment
 //fY: Y location adjustment
 //fZ: Z location adjustment
 //Vx: X speed
 //Vy: Y speed
 //Vz: Z speed

   void self = getlocalvar("self"); //Get calling entity
   int Direction = getentityproperty(self, "direction");
   void vSpawn; //Spawn object.
	
   vSpawn = spawn01(vName, fX, fY, fZ); //Spawn in projectile
   if (Direction == 0){ //Is entity facing left?                  
      Vx = -Vx; //Reverse Vx direction to match facing
   }

   changeentityproperty(vSpawn, "velocity", Vx, Vz, Vy);
}

void forceanim(int anim){
	void self = getlocalvar("self");
	void opp = getentityproperty(self, "opponent");
	changeentityproperty(opp, "animation", anim);

}

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

void spawn01(void vName, float fX, float fY, float fZ)
{
	//spawn01 (Generic spawner)
	//Damon Vaughn Caskey
	//Spawns entity next to caller.
	//
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
        //fY: Z location adjustment.

	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	int  iDirection = getentityproperty(self, "direction");
	clearspawnentry(); //Clear current spawn entry.
      setspawnentry("name", vName); //Acquire spawn entity by name.

	if (iDirection == 0){ //Is entity facing left?                  
          fX = -fX; //Reverse X direction to match facing.
	}

      fX = fX + getentityproperty(self, "x"); //Get X location and add adjustment.
      fY = fY + getentityproperty(self, "a"); //Get Y location and add adjustment.
      fZ = fZ + getentityproperty(self, "z"); //Get Z location and add adjustment.
	
	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
	changeentityproperty(vSpawn, "direction", iDirection); //Set direction.
	return vSpawn; //Return spawn.
}

void spawnbind(void Name, float dx, float dy, float dz)
{ // Spawn and bind other entity
   void self = getlocalvar("self");
   void Spawn;

   Spawn = spawn01(Name, dx, dy, 0);
   bindentity(Spawn, self, dx, dz, dy, 0, 0);
}

void spawn02(void vName, float fX, float fY, float fZ, void Alias)
{
	//spawn02 (Generic spawner with alias)
	//Spawns entity next to caller.
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
        //fY: Z location adjustment.
	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	int  iDirection = getentityproperty(self, "direction");

	clearspawnentry(); //Clear current spawn entry.
      setspawnentry("name",vName); //Acquire spawn entity by name.
	if (iDirection == 0){ //Is entity facing left?                  
          fX = -fX; //Reverse X direction to match facing.
	}

      fX = fX + getentityproperty(self, "x"); //Get X location and add adjustment.
      fY = fY + getentityproperty(self, "a"); //Get Y location and add adjustment.
      fZ = fZ + getentityproperty(self, "z"); //Get Z location and add adjustment.
	
	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
	changeentityproperty(vSpawn, "direction", iDirection); //Set direction.
    	changeentityproperty(vSpawn, "name", Alias); //Set Alias to spawned entity
	return vSpawn; //Return spawn.
}

void spawnbind02(void Name, float dx, float dy, float dz)
{ // Spawn and bind other entity
   void self = getlocalvar("self");
   void frame = getentityproperty(self, "animpos");
   void Spawn;

   Spawn = spawn(Name, dx, dy, 0);
   bindentity(Spawn, self, dx, dz, dy, 0, 0);
   updateframe(Spawn, frame);
}

void spawn04(void vName, float fX, float fY, float fZ, float fX2, float fY2, float fZ2)
{
	//spawn01 (Generic spawner)
	//Damon Vaughn Caskey
	//07/06/2007
	//
	//Spawns entity next to caller.
	//
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
      //fY: Z location adjustment.

	void self = getlocalvar("self"); //Get calling entity.
        void P1 = getplayerproperty(0, "entity");
        void P2 = getplayerproperty(1, "entity");
	void vSpawn; //Spawn object.
        int Direction = getentityproperty(self, "direction");
        int XPos = openborvariant("xpos"); 
        int YPos = openborvariant("ypos");
        int Screen = openborvariant("hResolution");

	clearspawnentry(); //Clear current spawn entry.
      setspawnentry("name", vName); //Acquire spawn entity by name.

	vSpawn = spawn(); //Spawn in entity.

        if(P1 && P2){
          if(self == P1){
	    changeentityproperty(vSpawn, "position", fX+XPos, fZ+YPos, fY);
	    changeentityproperty(vSpawn, "direction", 1);
          }else if(self == P2){
	    changeentityproperty(vSpawn, "position", fX2+XPos, fZ2+YPos, fY);
	    changeentityproperty(vSpawn, "direction", 1);
          }
        }else if(self == P1){
	  changeentityproperty(vSpawn, "position", fX+XPos, fZ+YPos, fY);
	  changeentityproperty(vSpawn, "direction", 1);
        }else if(self == P2){
	  changeentityproperty(vSpawn, "position", fX2+XPos, fZ2+YPos, fY);
	  changeentityproperty(vSpawn, "direction", 1);
        }
	return vSpawn; //Return spawn.
}

void grabcheck()
{// Prevents hero from performing the slam if he/she's not grabbing anyone
   void self = getlocalvar("self");
   void target = getentityproperty(self, "grabbing");

   if(target==NULL())
   {
     setidle(self); //Don't perform the slam.
   }
}

void dethrown()
{// Disables thrown status
    void self = getlocalvar("self");

    changeentityproperty(self, "attacking", 0);
    changeentityproperty(self, "damage_on_landing", 0);
    changeentityproperty(self, "projectile", 0);
}

void beidle()
{// Go to IDLE animation!
    void self = getlocalvar("self");

    setidle(self);
}

void anti()
{ // Makes grabbed opponent slighty lifted to air
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     tossentity(target, 1, 0, 0); // Toss opponent a little ;)
   }
}

void anichange(void Ani)
{// Animation changer
    void self = getlocalvar("self");

    changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
}

void slamstart()
{ // Slam Starter
// Use finish after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL80")); // Slam Starter
   }
}

void slamstart2()
{ // Slam Starter for nongrab slams
// Use finish or throw after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL80")); // Slam Starter
   }
}

void position(int Frame, float dx, float dy, float dz, int face)
{ // Modify grabbed entity's position relative to grabber
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     updateframe(target, Frame);
     bindentity(target, self, dx, dz, dy, face, 0);
   }
}

void depost(int Gr)
{// Release grabbed entity
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     bindentity(target, NULL());

     if(Gr == 1)
     {
       int x = getentityproperty(target, "x");
       int z = getentityproperty(target, "z");
       changeentityproperty(target, "position", x, z, 0);
     }
   }
}

void hurt2(int Damage)
{ // Damage without altering opponent's animation + less damage if opponent has less health
// Mainly used for slams
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     int THealth = getentityproperty(target,"health"); //Get target's health
     int TAniPos = getentityproperty(target,"animpos"); //Get target's animation frame
     if(THealth > Damage)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL80")); // Damage target with desired damage
       updateframe(target, TAniPos);
     } else {
       int Damage2 = THealth - 1;
       damageentity(target, self, Damage2, 1, openborconstant("ATK_NORMAL80")); //Damage target with less damage
       updateframe(target, TAniPos);
     }
   }
}

void finish(int Damage, int Type, int x, int y, int z, int Face)
{ // Damage as slam or throw finisher
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);
   int SDir = getentityproperty(target,"direction");
   int MDir;

   if(Face==0){ // Same facing?
       MDir = SDir;
   }

   if(Face==1){ // Opposite facing?

     if(SDir==0){ // Facing left?
       MDir = 1;
     } else { MDir = 0;}
   }

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     int dir = getentityproperty(target,"direction"); //Get opponent's facing direction
     if(dir==0){ // Facing left?
       x = -x;
     }

     if(Type==1)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL")); // 1st Finisher
     }

     if(Type==2)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL12")); // 2nd Finisher (flip throws)
     }

     if(Type==3)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL10")); // 3rd Finisher (ddthrows)
     }

     if(Type==4)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL30")); // 4th Finisher (colossus)
     }

     if(Type==5)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL20")); // 5th Finisher (slams)
     }

     if(Type==6)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL95")); // Ultra Finisher (slams)
     }

     if(Type==7)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL96")); // Sonic blastman Finisher (slams)
     }
     if(Type==8)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL103")); //  WWF BILLY
     }
     if(Type==9)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL104")); //  WWF BILLY
     }
     if(Type==10)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL105")); //  WWF JIMMY
     }
     if(Type==11)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL106")); //  WWF JIMMY
     }
     if(Type==12)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL107")); //  WWF JIMMY
     }
     if(Type==13)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL81")); //  ESS MK11
     }
     tossentity(target, y, x, z); // Toss opponent ;)
     changeentityproperty(target, "direction", MDir);
   }
}

void throw(int Damage, int Type, int x, int y, int z, int Face)
{ // Damage as throw finisher
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);
   int SDir = getentityproperty(target,"direction");
   int MDir;

   if(Face==0){ // Same facing?
       MDir = SDir;
   }

   if(Face==1){ // Opposite facing?

     if(SDir==0){ // Facing left?
       MDir = 1;
     } else { MDir = 0;}
   }

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     int dir = getentityproperty(target,"direction"); //Get opponent's facing direction
     if(dir==0){ // Facing left?
       x = -x;
     }

     if(Type==1)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL")); // 1st throw type
     }

     if(Type==2)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL9")); // 2nd throw type
     }

     if(Type==3)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL2")); // 3rd throw type
     }
     if(Type==4)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL10")); // 4th throw type (back throw)
     }
     if(Type==5)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL101")); // 5th throw type
     }
     if(Type==6)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL30")); // 6th Finisher (colossus)
     }
     if(Type==7)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL102")); // 4th throw type (coop back throw)
     }

     changeentityproperty(target, "attacking", 1);
     changeentityproperty(target, "damage_on_landing", Damage);
     changeentityproperty(target, "projectile", 1);
     changeentityproperty(target, "direction", MDir);
     tossentity(target, y, x, z); // Toss opponent ;)
   }
}

void degravity(int Ratio)
{// Changes antigravity effect
    void self = getlocalvar("self");
    changeentityproperty(self, "antigravity", Ratio);
}

void stwall(int Ratio, int Ratio2, int Ratio3)
{// Changes antigravity effect
    void self = getlocalvar("self");
    changeentityproperty(self, "subject_to_wall", Ratio);
    changeentityproperty(self, "subject_to_hole", Ratio2);
    changeentityproperty(self, "subject_to_gravity", Ratio3);
}

void move(int dx, int dz,int da)
{ // Moves entity freely and ignores obstacles
    void self = getlocalvar("self");
    int x = getentityproperty(self,"x"); //Get character's x coordinate
    int z = getentityproperty(self,"z"); //Get character's z coordinate
    int a = getentityproperty(self,"a"); //Get character's a coordinate
    int dir = getentityproperty(self,"direction"); //Get character's facing direction

     if(dir==0){ // Facing left?
      changeentityproperty(self, "position", x-dx, z+dz, a+da); //Move
     }
     else if(dir==1){ // Facing right?
      changeentityproperty(self, "position", x+dx, z+dz, a+da); //Move
     }
}

void antiwall5(int Dist, int Move, int Distz)
{// Checks if there is wall at defined distance
// If there is wall, entity will be moved away with defined movement
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   float H;
   float Hz;

   if(Direction == 0){ //Is entity facing left?                  
      Dist = -Dist; //Reverse Dist to match facing
      Move = -Move; //Reverse Move to match facing
   }

   H = checkwall(x+Dist,z);
   Hz = checkwall(x+Dist,z+Distz);

   if(Hz > 0)
   {
     changeentityproperty(self, "velocity", 0, 0, 0);
     changeentityproperty(self, "position", x, z-Distz);
   }

   if(H > 0)
   {
     changeentityproperty(self, "velocity", 0, 0, 0);
     changeentityproperty(self, "position", x+Move);
   }
}

void dasher( float Vx, float Vy, float Vz )
{// Dash with desired speed!
    void self = getlocalvar("self");
    int dir = getentityproperty(self,"direction");

    if(dir==0){ // Facing left?
      Vx = -Vx ;
    }

    changeentityproperty(self, "velocity", Vx, Vz, Vy); //Move!
}

void leaper( float Vx, float Vy, float Vz )
{// Leap with desired speed!
    void self = getlocalvar("self");
    int dir = getentityproperty(self,"direction");

    if(dir==0){ // Facing left?
      Vx = -Vx ;
    }

    tossentity(self, Vy, Vx, Vz); //Leap!
}

void stop()
{// Stop hero's movement!
    void self = getlocalvar("self");
    changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
}

void clearL()
{// Clears all local variables
     clearlocalvar();
}

void slammed(int Damage)
{
   // Hurt self
    void self = getlocalvar("self");
    damageentity(self, self, Damage, 1, openborconstant("ATK_NORMAL9")); // Slam damage is inserted here
    tossentity(self, 2, 0, 0);
}

void keyint(void Ani, int Frame, void Key, int Hflag, int Limit)
{// Change current animation if proper key is pressed or released provided HP is more than limit
    void self = getlocalvar("self");
    void Health = getentityproperty(self,"health");    
    int iPIndex = getentityproperty(self,"playerindex"); //Get player index
    void iRKey;

      if (Key=="U"){ //Up Required?
       iRKey = playerkeys(iPIndex, 0, "moveup"); // "Up"
	}

      if (Key=="D"){ //Down Required?
        iRKey = playerkeys(iPIndex, 0, "movedown"); // "Down"
	}

      if (Key=="J"){ //Jump Required?
        iRKey = playerkeys(iPIndex, 0, "jump"); // "Jump"
	}

      if (Key=="A"){ //Attack Required?
        iRKey = playerkeys(iPIndex, 0, "attack"); // "Attack"
	}

      if (Key=="S"){ //Special Required?
        iRKey = playerkeys(iPIndex, 0, "special"); // "Special"
	}

      if (Key=="A2"){ //Attack2 Required?
        iRKey = playerkeys(iPIndex, 0, "attack2"); // "Attack2"
	}

      if (Key=="UJ"){ //Up and Jump Required?
        iRKey = playerkeys(iPIndex, 0, "moveup", "jump"); // "Up" + "Jump"
	}

      if (Hflag==1){ //Not holding the button case?
        iRKey = !iRKey; //Take the opposite condition
	}

      if ((Health > Limit)&&iRKey){
        changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
        changeentityproperty(self, "animpos", Frame);

        if (Key=="UJ"){ 
          // This is copy of dethrown
          changeentityproperty(self, "attacking", 0);
          changeentityproperty(self, "damage_on_landing", 0);
          changeentityproperty(self, "projectile", 0);
        }
      }
}

void keyflip()
{// Change hero's facing direction if left or right is pressed
    void self = getlocalvar("self");
    int iPIndex = getentityproperty(self,"playerindex"); //Get player index

    if (playerkeys(iPIndex, 0, "moveleft")){ // Left is pressed?
      changeentityproperty(self, "direction", 0); //Face left
    } else if (playerkeys(iPIndex, 0, "moveright")){ // Right is pressed?
      changeentityproperty(self, "direction", 1); //Face right
    }
}

void keymove(float V)
{// Move hero if direction button is pressed
      void self = getlocalvar("self");
      int iPIndex = getentityproperty(self,"playerindex"); //Get player index
	float xdir = 0;
	float zdir = 0;

      if (playerkeys(iPIndex, 0, "moveleft")){// Left is pressed?
	  xdir = -V;
	} else if(playerkeys(iPIndex, 0, "moveright")){// Right is pressed?
	  xdir = V;
      }

	if(playerkeys(iPIndex, 0, "moveup")){// Up is pressed?
	  zdir = -V/2;
	} else if(playerkeys(iPIndex, 0, "movedown")){// Down is pressed?
	  zdir = V/2;
      }

	changeentityproperty(self, "velocity", xdir, zdir);
}

void attackoff()
{// Cancels attack if targetted player is fallen on ground
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player

    if(target!=NULL()){
      void PAnim = getentityproperty(target, "animationID");

      if(PAnim == openborconstant("ANI_FALL") || PAnim == openborconstant("ANI_RISE")){
        setidle(self, openborconstant("ANI_IDLE"));
      }
    }
}

void conditionalflip3()
{ // Flipping based on currently grabbed enemy
   void self = getlocalvar("self");
   void target = getentityproperty(self, "opponent");

   if(target)
   {
     int Direction = getentityproperty(self, "direction");
     int TDir = getentityproperty(target, "direction");

     if(TDir == 1 && Direction == 1){             
       changeentityproperty(self, "direction", 0);
     } else if(TDir == 0 && Direction == 0){
       changeentityproperty(self, "direction", 1);
     }
   }
}
void spawn044(void vName, float fX, float fY, float fZ)
{
	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
        int Direction = getentityproperty(self, "direction");
        int XPos = openborvariant("xpos"); 
        int YPos = openborvariant("ypos");
        int Screen = openborvariant("hResolution");

	clearspawnentry(); //Clear current spawn entry.
      setspawnentry("name", vName); //Acquire spawn entity by name.

	vSpawn = spawn(); //Spawn in entity.

	if (Direction == 1){                  
          changeentityproperty(vSpawn, "position", fX+XPos, fZ+YPos, fY);
	  changeentityproperty(vSpawn, "direction", 0);
	  return vSpawn; //Return spawn.
	}else if (Direction == 0){                  
          changeentityproperty(vSpawn, "position", fX+XPos, fZ+YPos, fY);
	  changeentityproperty(vSpawn, "direction", 1);
	  return vSpawn; //Return spawn.
	}
}



void spawn044M(void vName, float fX, float fY, float fZ)
{
	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
        int Direction = getentityproperty(self, "direction");
        int XPos = openborvariant("xpos"); 
        int YPos = openborvariant("ypos");
        int Screen = openborvariant("hResolution");
        int map = getentityproperty(self,"map");

	clearspawnentry(); //Clear current spawn entry.
      setspawnentry("name", vName); //Acquire spawn entity by name.

	vSpawn = spawn(); //Spawn in entity.

	if (Direction == 1){                  
          changeentityproperty(vSpawn, "position", fX+XPos, fZ+YPos, fY);
	  changeentityproperty(vSpawn, "direction", 0);
          changeentityproperty(vSpawn, "map", map);
	  return vSpawn; //Return spawn.
	}else if (Direction == 0){                  
          changeentityproperty(vSpawn, "position", fX+XPos, fZ+YPos, fY);
	  changeentityproperty(vSpawn, "direction", 1);
          changeentityproperty(vSpawn, "map", map);
	  return vSpawn; //Return spawn.
	}
}




void shoot(void Shot, float dx, float dy, float dz)
{ // Shooting projectile
	void self = getlocalvar("self");
	int Direction = getentityproperty(self, "direction");
	int x = getentityproperty(self, "x");
	int y = getentityproperty(self, "a");
	int z = getentityproperty(self, "z");

	if (!Direction)
	{
		dx = -dx;
	}else{}

	void vSpawn=projectile(Shot, x+dx, z+dz, y+dy, Direction, 0, 0, 0);

	if (getentityproperty(self,"type")==openborconstant("type_player"))
	{
		changeentityproperty(vSpawn,"candamage","type_enemy","type_obstacle");
	}else if(getentityproperty(self,"type")==openborconstant("type_enemy"))
	{
		changeentityproperty(vSpawn,"candamage","type_player","type_npc");
	}
}
void tosser(void Bomb, float dx, float dy, float dz, float Vx, float Vy, float Vz)
{
	void self = getlocalvar("self");
	int Direction = getentityproperty(self, "direction");
	int x = getentityproperty(self, "x");
	int y = getentityproperty(self, "a");
	int z = getentityproperty(self, "z");
	if (!Direction){
		dx=-dx;
	}else{}
	void Shot = projectile(Bomb, x+dx, z+dz, y+dy, Direction, 0, 1, 0);
	changeentityproperty(Shot, "parent", self);
	tossentity(Shot, Vy, Vx, Vz);
	changeentityproperty(Shot, "speed", Vx);
	changeentityproperty(Shot, "hostile", getentityproperty(self, "hostile")+openborconstant("TYPE_RESERVED"));
	changeentityproperty(Shot, "candamage", getentityproperty(self, "candamage")+openborconstant("TYPE_RESERVED"));
}
void shoot2(void Shot, float dx, float dy, float dz,float vx, float vy, float vz)
{
	void self = getlocalvar("self");
	int Direction = getentityproperty(self, "direction");
	int x = getentityproperty(self, "x");
	int y = getentityproperty(self, "a");
	int z = getentityproperty(self, "z");
	if (!Direction){
	  dx = -dx;
	}else{}
	void vSpawn=projectile(Shot, x+dx, z+dz, y+dy, Direction, 0, 1, 0);
	changeentityproperty(vSpawn,"speed",vx);
	changeentityproperty(vSpawn,"velocity",vx,vz,vy);
	changeentityproperty(vSpawn, "hostile", getentityproperty(self, "hostile")+openborconstant("TYPE_RESERVED"));
	changeentityproperty(vSpawn, "candamage", getentityproperty(self, "candamage")+openborconstant("TYPE_RESERVED"));
}


void shootM(void Shot, float dx, float dy, float dz)
{ // Shooting projectile with same palette
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int Map = getentityproperty(self, "map");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   void vShot;

   if (Direction == 0){ //Is entity facing left?
      dx = -dx; //Reverse X direction to match facing
   }

   vShot = projectile(Shot, x+dx, z+dz, y+dy, Direction, 0, 0, Map);
   return vShot;
}

void shootP(void Shot, float dx, float dy, float dz)
{ // Shooting projectile and set it as child
   void self = getlocalvar("self");
   void vShot;

   vShot = shoot(Shot, dx, dy, dz);
   changeentityproperty(vShot, "parent", self);
}

void spawnvic(void vName, float fX, float fY, float fZ, float fX2, float fY2, float fZ2)
{
	//Spawns entity with same palette when victory screen occurs

	void self = getlocalvar("self"); //Get calling entity.
        void P1 = getplayerproperty(0, "entity");
        void P2 = getplayerproperty(1, "entity");
int Map1 = getentityproperty(P1, "map");
int Map2 = getentityproperty(P2, "map");
	void vSpawn; //Spawn object.
        int Direction = getentityproperty(self, "direction");
        int XPos = openborvariant("xpos"); 
        int YPos = openborvariant("ypos");
        int Screen = openborvariant("hResolution");

	clearspawnentry(); //Clear current spawn entry.
      setspawnentry("name", vName); //Acquire spawn entity by name.

	vSpawn = spawn(); //Spawn in entity.

        if(P1 && P2){
          if(self == P1){
	    changeentityproperty(vSpawn, "position", fX+XPos, fZ+YPos, fY);
	    changeentityproperty(vSpawn, "direction", 1);
changeentityproperty(vSpawn, "map", Map1);
          }else if(self == P2){
	    changeentityproperty(vSpawn, "position", fX2+XPos, fZ2+YPos, fY);
	    changeentityproperty(vSpawn, "direction", 1);
changeentityproperty(vSpawn, "map", Map2);
          }
        }else if(self == P1){
	  changeentityproperty(vSpawn, "position", fX+XPos, fZ+YPos, fY);
	  changeentityproperty(vSpawn, "direction", 1);
changeentityproperty(vSpawn, "map", Map1);
        }else if(self == P2){
	  changeentityproperty(vSpawn, "position", fX2+XPos, fZ2+YPos, fY);
	  changeentityproperty(vSpawn, "direction", 1);
changeentityproperty(vSpawn, "map", Map2);
        }
	return vSpawn; //Return spawn.
}

void Pause(int Flag)
{// Turns Pause status
    changeopenborvariant("nopause", Flag);
}

void spawnM(void Name, float dx, float dy, float dz)
{ // Spawn certain entity and matches its map with own's map
   void self = getlocalvar("self");
   int map = getentityproperty(self,"map");
   void Spawn;

   Spawn = spawn01(Name, dx, dy, dz);
   changeentityproperty(Spawn, "map", map);
}


void keyint(void Ani, int Frame, void Key, int Hflag, int Limit)
{// Change current animation if proper key is pressed or released
    void self = getlocalvar("self");
    void MP = getentityproperty(self,"mp"); 
    int iDir = getentityproperty(self, "direction"); 
    int iPIndex = getentityproperty(self,"playerindex"); //Get player index
    void iRKey;

      if (Key=="U"){ //Up Required?
        iRKey = playerkeys(iPIndex, 0, "moveup"); // "Up"
      } else if (Key=="D"){ //Down Required?
        iRKey = playerkeys(iPIndex, 0, "movedown"); // "Down"
      } else if (Key=="L"){ //Left Required?
        iRKey = playerkeys(iPIndex, 0, "moveleft"); // "Left"
      } else if (Key=="R"){ //Right Required?
        iRKey = playerkeys(iPIndex, 0, "moveright"); // "Right"
      } else if (Key=="F"){ //Forward Required?
        if (iDir==0){ //Facing left?
         iRKey = playerkeys(iPIndex, 0, "moveleft"); // "Left"
        } else if (iDir==1){ //Facing right?
         iRKey = playerkeys(iPIndex, 0, "moveright"); // "Right"
        }
      } else if (Key=="J"){ //Jump Required?
        iRKey = playerkeys(iPIndex, 0, "jump"); // "Jump"
      } else if (Key=="A"){ //Attack Required?
        iRKey = playerkeys(iPIndex, 0, "attack"); // "Attack"
      } else if (Key=="S"){ //Special Required?
        iRKey = playerkeys(iPIndex, 0, "special"); // "Special"
      } else if (Key=="A2"){ //Attack2 Required?
        iRKey = playerkeys(iPIndex, 0, "attack2"); // "Attack2"
      } else if (Key=="A3"){ //Attack3 Required?
        iRKey = playerkeys(iPIndex, 0, "attack3"); // "Attack3"
      } else if (Key=="A4"){ //Attack4 Required?
        iRKey = playerkeys(iPIndex, 0, "attack4"); // "Attack4"
      }

      if (Hflag==1){ //Not holding the button case?
        iRKey = !iRKey; //Take the opposite condition
      }

      if ((MP > Limit)&&iRKey){
        changeentityproperty(self, "animation", openborconstant(Ani), 2);
        changeentityproperty(self, "animpos", Frame);
      }
}


void flip()
{// Turns around
    void self = getlocalvar("self");
    int Direction = getentityproperty(self, "direction");

    if (Direction == 0){ //Is entity facing left?                  
      changeentityproperty(self, "direction", 1);
    } else {
      changeentityproperty(self, "direction", 0);
    }
}

void cancelgrab(int Ani)
        {// Check grabbed opponent's name
        // If it's forbidden to grab him/her, revert to IDLE
           void self = getlocalvar("self");
           void target = getlocalvar("Target" + self);


           if(target==NULL())
           {
             target = getentityproperty(self, "opponent");
             setlocalvar("Target" + self, target);
           }
           if(target!=NULL())
           {
             char iType = getentityproperty(target, "type");
             int tGrab = getentityproperty(target, "antigrab");
          
             if (tGrab==9999)
             {
                 changeentityproperty(self, "animation", Ani);
             }

             if(iType == openborconstant("TYPE_OBSTACLE") || iType ==openborconstant("TYPE_ITEM") || iType ==openborconstant("TYPE_NPC"))
             {
                 //clearlocalvar();
                 changeentityproperty(self, "animation", Ani);
             }
           }
        }



