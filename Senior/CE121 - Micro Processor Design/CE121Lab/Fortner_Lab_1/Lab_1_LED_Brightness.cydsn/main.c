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
    PWM_Start();
    ADC_Start();
    uint16 val;
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        val = ADC_Read16();
        //val = ADC_Read32();
        PWM_WriteCompare(val / 60);
    }
}

/* [] END OF FILE */
