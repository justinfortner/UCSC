/*******************************************************************************
* File Name: Dial.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Dial_H) /* Pins Dial_H */
#define CY_PINS_Dial_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Dial_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Dial__PORT == 15 && ((Dial__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Dial_Write(uint8 value);
void    Dial_SetDriveMode(uint8 mode);
uint8   Dial_ReadDataReg(void);
uint8   Dial_Read(void);
void    Dial_SetInterruptMode(uint16 position, uint16 mode);
uint8   Dial_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Dial_SetDriveMode() function.
     *  @{
     */
        #define Dial_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Dial_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Dial_DM_RES_UP          PIN_DM_RES_UP
        #define Dial_DM_RES_DWN         PIN_DM_RES_DWN
        #define Dial_DM_OD_LO           PIN_DM_OD_LO
        #define Dial_DM_OD_HI           PIN_DM_OD_HI
        #define Dial_DM_STRONG          PIN_DM_STRONG
        #define Dial_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Dial_MASK               Dial__MASK
#define Dial_SHIFT              Dial__SHIFT
#define Dial_WIDTH              1u

/* Interrupt constants */
#if defined(Dial__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Dial_SetInterruptMode() function.
     *  @{
     */
        #define Dial_INTR_NONE      (uint16)(0x0000u)
        #define Dial_INTR_RISING    (uint16)(0x0001u)
        #define Dial_INTR_FALLING   (uint16)(0x0002u)
        #define Dial_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Dial_INTR_MASK      (0x01u) 
#endif /* (Dial__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Dial_PS                     (* (reg8 *) Dial__PS)
/* Data Register */
#define Dial_DR                     (* (reg8 *) Dial__DR)
/* Port Number */
#define Dial_PRT_NUM                (* (reg8 *) Dial__PRT) 
/* Connect to Analog Globals */                                                  
#define Dial_AG                     (* (reg8 *) Dial__AG)                       
/* Analog MUX bux enable */
#define Dial_AMUX                   (* (reg8 *) Dial__AMUX) 
/* Bidirectional Enable */                                                        
#define Dial_BIE                    (* (reg8 *) Dial__BIE)
/* Bit-mask for Aliased Register Access */
#define Dial_BIT_MASK               (* (reg8 *) Dial__BIT_MASK)
/* Bypass Enable */
#define Dial_BYP                    (* (reg8 *) Dial__BYP)
/* Port wide control signals */                                                   
#define Dial_CTL                    (* (reg8 *) Dial__CTL)
/* Drive Modes */
#define Dial_DM0                    (* (reg8 *) Dial__DM0) 
#define Dial_DM1                    (* (reg8 *) Dial__DM1)
#define Dial_DM2                    (* (reg8 *) Dial__DM2) 
/* Input Buffer Disable Override */
#define Dial_INP_DIS                (* (reg8 *) Dial__INP_DIS)
/* LCD Common or Segment Drive */
#define Dial_LCD_COM_SEG            (* (reg8 *) Dial__LCD_COM_SEG)
/* Enable Segment LCD */
#define Dial_LCD_EN                 (* (reg8 *) Dial__LCD_EN)
/* Slew Rate Control */
#define Dial_SLW                    (* (reg8 *) Dial__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Dial_PRTDSI__CAPS_SEL       (* (reg8 *) Dial__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Dial_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Dial__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Dial_PRTDSI__OE_SEL0        (* (reg8 *) Dial__PRTDSI__OE_SEL0) 
#define Dial_PRTDSI__OE_SEL1        (* (reg8 *) Dial__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Dial_PRTDSI__OUT_SEL0       (* (reg8 *) Dial__PRTDSI__OUT_SEL0) 
#define Dial_PRTDSI__OUT_SEL1       (* (reg8 *) Dial__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Dial_PRTDSI__SYNC_OUT       (* (reg8 *) Dial__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Dial__SIO_CFG)
    #define Dial_SIO_HYST_EN        (* (reg8 *) Dial__SIO_HYST_EN)
    #define Dial_SIO_REG_HIFREQ     (* (reg8 *) Dial__SIO_REG_HIFREQ)
    #define Dial_SIO_CFG            (* (reg8 *) Dial__SIO_CFG)
    #define Dial_SIO_DIFF           (* (reg8 *) Dial__SIO_DIFF)
#endif /* (Dial__SIO_CFG) */

/* Interrupt Registers */
#if defined(Dial__INTSTAT)
    #define Dial_INTSTAT            (* (reg8 *) Dial__INTSTAT)
    #define Dial_SNAP               (* (reg8 *) Dial__SNAP)
    
	#define Dial_0_INTTYPE_REG 		(* (reg8 *) Dial__0__INTTYPE)
#endif /* (Dial__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Dial_H */


/* [] END OF FILE */
