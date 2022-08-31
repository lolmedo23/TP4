
#ifndef __LPC17xx_H__
#define __LPC17xx_H__

#include <stdint.h>
#define   __I     volatile        /*!< Defines  write to test permissions                 */
#define     __O     volatile             /*!< Defines 'write only' permissions                */
#define     __IO    volatile             /*!< Defines 'read / write' permissions              */

/*------------- Analog-to-Digital Converter (ADC) ----------------------------*/
typedef struct LPC_ADC_TypeDef
{
  __IO uint32_t ADCR;
  __IO uint32_t ADGDR;
       uint32_t RESERVED0;
  __IO uint32_t ADINTEN;
  __I  uint32_t ADDR0;
  __I  uint32_t ADDR1;
  __I  uint32_t ADDR2;
  __I  uint32_t ADDR3;
  __I  uint32_t ADDR4;
  __I  uint32_t ADDR5;
  __I  uint32_t ADDR6;
  __I  uint32_t ADDR7;
  __I  uint32_t ADSTAT;
  __IO uint32_t ADTRM;
} LPC_ADC_TypeDef;

struct LPC_ADC_TypeDef mockLPC;
static struct LPC_ADC_TypeDef * LPC_ADC = &mockLPC;

#endif