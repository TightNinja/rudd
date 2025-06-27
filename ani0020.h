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

