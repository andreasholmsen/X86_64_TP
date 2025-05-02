typedef struct
{
  uint32_t CPUID;                   /*!< Offset: 0x000 (R/ )  CPUID Base Register                                   */
  uint32_t ICSR;                    /*!< Offset: 0x004 (R/W)  Interrupt Control and State Register                  */
#if (__VTOR_PRESENT == 1)
  uint32_t VTOR;                    /*!< Offset: 0x008 (R/W)  Vector Table Offset Register                          */
#else
       uint32_t RESERVED0;
#endif
  uint32_t AIRCR;                   /*!< Offset: 0x00C (R/W)  Application Interrupt and Reset Control Register      */
  uint32_t SCR;                     /*!< Offset: 0x010 (R/W)  System Control Register                               */
  uint32_t CCR;                     /*!< Offset: 0x014 (R/W)  Configuration Control Register                        */
       uint32_t RESERVED1;
  uint32_t SHP[2];                  /*!< Offset: 0x01C (R/W)  System Handlers Priority Registers. [0] is RESERVED   */
  uint32_t SHCSR;                   /*!< Offset: 0x024 (R/W)  System Handler Control and State Register             */
} SCB_Type;

#define SCS_BASE            (0xE000E000UL)
#define SCB_BASE            (SCS_BASE +  0x0D00UL) 
#define SCB                 ((SCB_Type       *)     SCB_BASE      )

#define SCB_AIRCR_VECTKEY_Pos              16
#define SCB_AIRCR_VECTKEY_Msk              (0xFFFFUL << SCB_AIRCR_VECTKEY_Pos)

#define SCB_AIRCR_SYSRESETREQ_Pos           2
#define SCB_AIRCR_SYSRESETREQ_Msk          (1UL << SCB_AIRCR_SYSRESETREQ_Pos)

#define Reset()      (SCB->AIRCR = (0x5FA<<SCB_AIRCR_VECTKEY_Pos) | SCB_AIRCR_SYSRESETREQ_Msk)
