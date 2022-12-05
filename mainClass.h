#pragma once

#include "SSC-Follow-Me/src/visionClass.h";
#include "SSC-Follow-Me/src/uwbClass.h";
#include "SSC-Follow-Me/src/usClass.h";

class main
{
    public:
        void initialise()
        { 
            Vision vision_obj = new Vision();
            UWB uwb_obj = new UWB();
            Ultrasonic us_chain_obj = new Ultrasonic();  
        }

        void safeMode()
        {
            
        }

        void obstacleMode()
        {

        }

        void idleMode()
        {

        }

};

// Driver Code
int main()
{
    class main obj;

    obj.initialise()
}
