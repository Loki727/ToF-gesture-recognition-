/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Peripherals v14.0
processor: LPC55S69
package_id: LPC55S69JBD100
mcu_data: ksdk2_0
processor_version: 15.0.1
board: LPCXpresso55S69
functionalGroups:
- name: BOARD_InitPeripherals_cm33_core0
  UUID: 61d0725d-b300-49cb-9c66-b5edfbf8ffc1
  called_from_default_init: true
  selectedCore: cm33_core0
- name: BOARD_InitPeripherals_cm33_core1
  UUID: e2041cd4-ebb6-45a5-807f-e0c2dc047d48
  selectedCore: cm33_core1
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'system'
- type_id: 'system'
- global_system_definitions:
  - user_definitions: ''
  - user_includes: ''
  - global_init: ''
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'uart_cmsis_common'
- type_id: 'uart_cmsis_common_9cb8e302497aa696fdbb5a4fd622c2a8'
- global_USART_CMSIS_common:
  - quick_selection: 'default'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'gpio_adapter_common'
- type_id: 'gpio_adapter_common_57579b9ac814fe26bf95df0a384c36b6'
- global_gpio_adapter_common:
  - quick_selection: 'default'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/
#include "peripherals.h"

/***********************************************************************************************************************
 * BOARD_InitPeripherals_cm33_core0 functional group
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * NVIC initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'NVIC'
- type: 'nvic'
- mode: 'general'
- custom_name_enabled: 'false'
- type_id: 'nvic_57b5eef3774cc60acaede6f5b8bddc67'
- functional_group: 'BOARD_InitPeripherals_cm33_core0'
- peripheral: 'NVIC'
- config_sets:
  - nvic:
    - interrupt_table: []
    - interrupts: []
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/* Empty initialization function (commented out)
static void NVIC_init(void) {
} */

/***********************************************************************************************************************
 * FLEXCOMM4 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'FLEXCOMM4'
- type: 'flexcomm_i2c'
- mode: 'I2C_Polling'
- custom_name_enabled: 'false'
- type_id: 'flexcomm_i2c_c8597948f61bd571ab263ea4330b9dd6'
- functional_group: 'BOARD_InitPeripherals_cm33_core0'
- peripheral: 'FLEXCOMM4'
- config_sets:
  - fsl_i2c:
    - i2c_mode: 'kI2C_Master'
    - clockSource: 'FXCOMFunctionClock'
    - clockSourceFreq: 'BOARD_BootClockPLL150M'
    - i2c_master_config:
      - enableMaster: 'true'
      - baudRate_Bps: '400000'
      - enableTimeout: 'false'
      - timeout_Ms: '35'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const i2c_master_config_t FLEXCOMM4_config = {
  .enableMaster = true,
  .baudRate_Bps = 400000UL,
  .enableTimeout = false,
  .timeout_Ms = 35U
};

static void FLEXCOMM4_init(void) {
  /* Initialization function */
  I2C_MasterInit(FLEXCOMM4_PERIPHERAL, &FLEXCOMM4_config, FLEXCOMM4_CLOCK_SOURCE);
}

/***********************************************************************************************************************
 * PINT initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'PINT'
- type: 'pint'
- mode: 'interrupt_mode'
- custom_name_enabled: 'false'
- type_id: 'pint_cf4a806bb2a6c1ffced58ae2ed7b43af'
- functional_group: 'BOARD_InitPeripherals_cm33_core0'
- peripheral: 'PINT'
- config_sets:
  - general:
    - interrupt_array:
      - 0:
        - interrupt_id: 'INT_0'
        - interrupt_selection: 'PINT.0'
        - interrupt_type: 'kPINT_PinIntEnableFallEdge'
        - callback_function: 'cbToF_Ready'
        - enable_callback: 'false'
        - interrupt:
          - IRQn: 'PIN_INT0_IRQn'
          - enable_priority: 'true'
          - priority: '0'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

static void PINT_init(void) {
  /* PINT initiation  */
  PINT_Init(PINT_PERIPHERAL);
  /* PINT PINT.0 configuration */
  PINT_PinInterruptConfig(PINT_PERIPHERAL, PINT_INT_0, kPINT_PinIntEnableFallEdge, cbToF_Ready);
}

/***********************************************************************************************************************
 * FLEXCOMM1 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'FLEXCOMM1'
- type: 'flexcomm_i2c'
- mode: 'I2C_Polling'
- custom_name_enabled: 'false'
- type_id: 'flexcomm_i2c_c8597948f61bd571ab263ea4330b9dd6'
- functional_group: 'BOARD_InitPeripherals_cm33_core0'
- peripheral: 'FLEXCOMM1'
- config_sets:
  - fsl_i2c:
    - i2c_mode: 'kI2C_Master'
    - clockSource: 'FXCOMFunctionClock'
    - clockSourceFreq: 'BOARD_BootClockPLL150M'
    - i2c_master_config:
      - enableMaster: 'true'
      - baudRate_Bps: '1000000'
      - enableTimeout: 'false'
      - timeout_Ms: '35'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const i2c_master_config_t FLEXCOMM1_config = {
  .enableMaster = true,
  .baudRate_Bps = 1000000UL,
  .enableTimeout = false,
  .timeout_Ms = 35U
};

static void FLEXCOMM1_init(void) {
  /* Initialization function */
  I2C_MasterInit(FLEXCOMM1_PERIPHERAL, &FLEXCOMM1_config, FLEXCOMM1_CLOCK_SOURCE);
}

/***********************************************************************************************************************
 * Initialization functions
 **********************************************************************************************************************/
void BOARD_InitPeripherals_cm33_core0(void)
{
  /* Initialize components */
  FLEXCOMM4_init();
  PINT_init();
  FLEXCOMM1_init();
}

/***********************************************************************************************************************
 * BOARD_InitBootPeripherals function
 **********************************************************************************************************************/
void BOARD_InitBootPeripherals(void)
{
  BOARD_InitPeripherals_cm33_core0();
}
