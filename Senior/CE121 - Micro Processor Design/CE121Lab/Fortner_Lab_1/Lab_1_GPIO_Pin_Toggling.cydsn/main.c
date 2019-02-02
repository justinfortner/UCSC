/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    //Part of Component API
    PWM_Start();
    //Part of Control Register API
    uint8 one = 1;
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        //Per-Pin API Start
        //CyPins_ClearPin(BLUE_0);
        //CyPins_ClearPin(GREEN_0);
        //CyPins_ClearPin(RED_0);
        //CyDelay(500);
        //CyPins_SetPin(RED_0);
        //CyPins_SetPin(BLUE_0);
        //CyPins_SetPin(GREEN_0);
        //CyDelay(500);
        //Per-Pin API End
      
        //Contol Register Start
        Control_Write(one);
        //Control Register End
        
    }
}

/* [] END OF FILE */
