#ifndef _PRU_H_
#define _PRU_H_

/* ARM register file */
#define PRU_ICSS           0x4a300000
#define PRU_BASE           PRU_ICSS

/* PRU interrupt event numbers */
#define PRU_ICSS_EVTOUT0   20
#define PRU_ICSS_EVTOUT1   21
#define PRU_ICSS_EVTOUT2   22
#define PRU_ICSS_EVTOUT3   23
#define PRU_ICSS_EVTOUT4   24
#define PRU_ICSS_EVTOUT5   25
#define PRU_ICSS_EVTOUT6   26
#define PRU_ICSS_EVTOUT7   27

#define CM_PER             0x44E00000
#define CM_PER_PRU_ICSS_CLKCTRL   ( * (vu32 *)(CM_PER+0x0e8) )
#define CM_PER_PRU_ICSS_CLKSTCTRL ( * (vu32 *)(CM_PER+0x140) )

#define CM_DPLL            0x44E00500
#define CLKSEL_PRU_ICSS_OCP_CLK   ( * (vu32 *)(CM_DPLL+0x30) )

#define CM_WKUP            0x44E00400
#define CM_IDLEST_DPLL_CORE       ( * (vu32 *)(CM_WKUP+0x5c) )
#define CM_CLKSEL_DPLL_CORE       ( * (vu32 *)(CM_WKUP+0x68) )
#define CM_CLKMODE_DPLL_CORE      ( * (vu32 *)(CM_WKUP+0x90) )

#define PRM_PER            0x44E00C00
#define RM_PER_RSTCTRL            ( * (vu32 *)(PRM_PER+0x00) )
#define PM_PER_PWRSTST            ( * (vu32 *)(PRM_PER+0x08) )
#define PM_PER_PWRSTCTRL          ( * (vu32 *)(PRM_PER+0x0c) )

#define PRU0_MAILBOX_USER 1
#define PRU1_MAILBOX_USER 2

#define DEBUGSS_DRM_PRU 0x248

/* PRU local addresses */
#define PRU_DATA_RAM0                  (vu32 *)(PRU_BASE+0x00000000)
#define PRU_DATA_RAM1                  (vu32 *)(PRU_BASE+0x00002000)
#define PRU_SHRD_RAM2                  (vu32 *)(PRU_BASE+0x00010000)

#define PRU_INTC_REGS                           PRU_BASE+0x00020000
#define PRU_PRU0_REGS                           PRU_BASE+0x00022000
#define PRU_PRU0_DBG                            PRU_BASE+0x00022400
#define PRU_PRU1_REGS                           PRU_BASE+0x00024000

#define PRU_PRU1_DBG                   (vu32 *)(PRU_BASE+0x00024400)
#define PRU_NEW_FEATS                  (vu32 *)(PRU_BASE+0x00026000)
#define PRU0_IRAM                      (vu32 *)(PRU_BASE+0x00034000)
#define PRU1_IRAM                      (vu32 *)(PRU_BASE+0x00038000)


#define PRU_INTC_REVID             ( * (vu32 *)(PRU_INTC_REGS+0x0000) )
#define PRU_INTC_CR                ( * (vu32 *)(PRU_INTC_REGS+0x0004) )
#define PRU_INTC_GER               ( * (vu32 *)(PRU_INTC_REGS+0x0010) )
#define PRU_INTC_GNLR              ( * (vu32 *)(PRU_INTC_REGS+0x001c) )
#define PRU_INTC_SISR              ( * (vu32 *)(PRU_INTC_REGS+0x0020) )
#define PRU_INTC_SICR              ( * (vu32 *)(PRU_INTC_REGS+0x0024) )
#define PRU_INTC_EISR              ( * (vu32 *)(PRU_INTC_REGS+0x0028) )
#define PRU_INTC_EICR              ( * (vu32 *)(PRU_INTC_REGS+0x002c) )
#define PRU_INTC_HIEISR            ( * (vu32 *)(PRU_INTC_REGS+0x0034) )
#define PRU_INTC_HIDISR            ( * (vu32 *)(PRU_INTC_REGS+0x0038) )
#define PRU_INTC_GPIR              ( * (vu32 *)(PRU_INTC_REGS+0x0080) )
#define PRU_INTC_SRSR0             ( * (vu32 *)(PRU_INTC_REGS+0x0200) )
#define PRU_INTC_SRSR1             ( * (vu32 *)(PRU_INTC_REGS+0x0204) )
#define PRU_INTC_SECR0             ( * (vu32 *)(PRU_INTC_REGS+0x0280) )
#define PRU_INTC_SECR1             ( * (vu32 *)(PRU_INTC_REGS+0x0284) )
#define PRU_INTC_ESR0              ( * (vu32 *)(PRU_INTC_REGS+0x0300) )
#define PRU_INTC_ERS1              ( * (vu32 *)(PRU_INTC_REGS+0x0304) )
#define PRU_INTC_ECR0              ( * (vu32 *)(PRU_INTC_REGS+0x0380) )
#define PRU_INTC_ECR1              ( * (vu32 *)(PRU_INTC_REGS+0x0384) )
#define PRU_INTC_CMR0              ( * (vu32 *)(PRU_INTC_REGS+0x0400) )
#define PRU_INTC_CMR1              ( * (vu32 *)(PRU_INTC_REGS+0x0404) )
#define PRU_INTC_CMR2              ( * (vu32 *)(PRU_INTC_REGS+0x0408) )
#define PRU_INTC_CMR3              ( * (vu32 *)(PRU_INTC_REGS+0x040c) )
#define PRU_INTC_CMR4              ( * (vu32 *)(PRU_INTC_REGS+0x0410) )
#define PRU_INTC_CMR5              ( * (vu32 *)(PRU_INTC_REGS+0x0414) )
#define PRU_INTC_CMR6              ( * (vu32 *)(PRU_INTC_REGS+0x0418) )
#define PRU_INTC_CMR7              ( * (vu32 *)(PRU_INTC_REGS+0x041c) )
#define PRU_INTC_CMR8              ( * (vu32 *)(PRU_INTC_REGS+0x0420) )
#define PRU_INTC_CMR9              ( * (vu32 *)(PRU_INTC_REGS+0x0424) )
#define PRU_INTC_CMR10             ( * (vu32 *)(PRU_INTC_REGS+0x0428) )
#define PRU_INTC_CMR11             ( * (vu32 *)(PRU_INTC_REGS+0x042c) )
#define PRU_INTC_CMR12             ( * (vu32 *)(PRU_INTC_REGS+0x0430) )
#define PRU_INTC_CMR13             ( * (vu32 *)(PRU_INTC_REGS+0x0434) )
#define PRU_INTC_CMR14             ( * (vu32 *)(PRU_INTC_REGS+0x0438) )
#define PRU_INTC_CMR15             ( * (vu32 *)(PRU_INTC_REGS+0x043c) )
#define PRU_INTC_HMR0              ( * (vu32 *)(PRU_INTC_REGS+0x0800) )
#define PRU_INTC_HMR1              ( * (vu32 *)(PRU_INTC_REGS+0x0804) )
#define PRU_INTC_HMR2              ( * (vu32 *)(PRU_INTC_REGS+0x0808) )
#define PRU_INTC_HIPIR0            ( * (vu32 *)(PRU_INTC_REGS+0x0900) )
#define PRU_INTC_HIPIR1            ( * (vu32 *)(PRU_INTC_REGS+0x0904) )
#define PRU_INTC_HIPIR2            ( * (vu32 *)(PRU_INTC_REGS+0x0908) )
#define PRU_INTC_HIPIR3            ( * (vu32 *)(PRU_INTC_REGS+0x090c) )
#define PRU_INTC_HIPIR4            ( * (vu32 *)(PRU_INTC_REGS+0x0910) )
#define PRU_INTC_HIPIR5            ( * (vu32 *)(PRU_INTC_REGS+0x0914) )
#define PRU_INTC_HIPIR6            ( * (vu32 *)(PRU_INTC_REGS+0x0918) )
#define PRU_INTC_HIPIR7            ( * (vu32 *)(PRU_INTC_REGS+0x091c) )
#define PRU_INTC_HIPIR8            ( * (vu32 *)(PRU_INTC_REGS+0x0920) )
#define PRU_INTC_HIPIR9            ( * (vu32 *)(PRU_INTC_REGS+0x0924) )
#define PRU_INTC_SIPR0             ( * (vu32 *)(PRU_INTC_REGS+0x0d00) )
#define PRU_INTC_SIPR1             ( * (vu32 *)(PRU_INTC_REGS+0x0d04) )
#define PRU_INTC_SITR0             ( * (vu32 *)(PRU_INTC_REGS+0x0d80) )
#define PRU_INTC_SITR1             ( * (vu32 *)(PRU_INTC_REGS+0x0d84) )
#define PRU_INTC_HINLR0            ( * (vu32 *)(PRU_INTC_REGS+0x1100) )
#define PRU_INTC_HINLR1            ( * (vu32 *)(PRU_INTC_REGS+0x1104) )
#define PRU_INTC_HINLR2            ( * (vu32 *)(PRU_INTC_REGS+0x1108) )
#define PRU_INTC_HINLR3            ( * (vu32 *)(PRU_INTC_REGS+0x110c) )
#define PRU_INTC_HINLR4            ( * (vu32 *)(PRU_INTC_REGS+0x1110) )
#define PRU_INTC_HINLR5            ( * (vu32 *)(PRU_INTC_REGS+0x1114) )
#define PRU_INTC_HINLR6            ( * (vu32 *)(PRU_INTC_REGS+0x1118) )
#define PRU_INTC_HINLR7            ( * (vu32 *)(PRU_INTC_REGS+0x111c) )
#define PRU_INTC_HINLR8            ( * (vu32 *)(PRU_INTC_REGS+0x1120) )
#define PRU_INTC_HINLR9            ( * (vu32 *)(PRU_INTC_REGS+0x1124) )
#define PRU_INTC_HIER              ( * (vu32 *)(PRU_INTC_REGS+0x1500) )


#define PRU0_CONTROL               ( * (vu32 *)(PRU_PRU0_REGS + 0x00) )
#define PRU0_STATUS                ( * (vu32 *)(PRU_PRU0_REGS + 0x04) )
#define PRU0_WAKEUP_EN             ( * (vu32 *)(PRU_PRU0_REGS + 0x08) )
#define PRU0_CYCLE                 ( * (vu32 *)(PRU_PRU0_REGS + 0x0c) )
#define PRU0_STALL                 ( * (vu32 *)(PRU_PRU0_REGS + 0x10) )
#define PRU0_CTBIR0                ( * (vu32 *)(PRU_PRU0_REGS + 0x20) )
#define PRU0_CTBIR1                ( * (vu32 *)(PRU_PRU0_REGS + 0x24) )
#define PRU0_CTPPR0                ( * (vu32 *)(PRU_PRU0_REGS + 0x28) )
#define PRU0_CTPPR1                ( * (vu32 *)(PRU_PRU0_REGS + 0x2c) )

#define PRU1_CONTROL               ( * (vu32 *)(PRU_PRU1_REGS + 0x00) )
#define PRU1_STATUS                ( * (vu32 *)(PRU_PRU1_REGS + 0x04) )
#define PRU1_WAKEUP_EN             ( * (vu32 *)(PRU_PRU1_REGS + 0x08) )
#define PRU1_CYCLE                 ( * (vu32 *)(PRU_PRU1_REGS + 0x0c) )
#define PRU1_STALL                 ( * (vu32 *)(PRU_PRU1_REGS + 0x10) )
#define PRU1_CTBIR0                ( * (vu32 *)(PRU_PRU1_REGS + 0x20) )
#define PRU1_CTBIR1                ( * (vu32 *)(PRU_PRU1_REGS + 0x24) )
#define PRU1_CTPPR0                ( * (vu32 *)(PRU_PRU1_REGS + 0x28) )
#define PRU1_CTPPR1                ( * (vu32 *)(PRU_PRU1_REGS + 0x2c) )

#define CONTROL_MODULE             0x44E10000
#define BANDGAP_CTRL               ( * (vu32 *)(CONTROL_MODULE+0x448) )
#define BANDGAP_TRIM               ( * (vu32 *)(CONTROL_MODULE+0x44c) )
#define DEV_FEATURE                ( * (vu32 *)(CONTROL_MODULE+0x604) )
#define INIT_PRIORITY_0            ( * (vu32 *)(CONTROL_MODULE+0x608) )
#define MREQPRIO_0                 ( * (vu32 *)(CONTROL_MODULE+0x670) )
#define ADC_EVT_CAPT               ( * (vu32 *)(CONTROL_MODULE+0xfd8) )

/* CONTROL_MODULE pin muxing */
#define CONF_GPMC_AD0              ( * (vu32 *)(CONTROL_MODULE+0x800) )
#define CONF_GPMC_AD1              ( * (vu32 *)(CONTROL_MODULE+0x804) )
#define CONF_GPMC_AD2              ( * (vu32 *)(CONTROL_MODULE+0x808) )
#define CONF_GPMC_AD3              ( * (vu32 *)(CONTROL_MODULE+0x80c) )
#define CONF_GPMC_AD4              ( * (vu32 *)(CONTROL_MODULE+0x810) )
#define CONF_GPMC_AD5              ( * (vu32 *)(CONTROL_MODULE+0x814) )
#define CONF_GPMC_AD6              ( * (vu32 *)(CONTROL_MODULE+0x818) )
#define CONF_GPMC_AD7              ( * (vu32 *)(CONTROL_MODULE+0x81c) )
#define CONF_GPMC_AD8              ( * (vu32 *)(CONTROL_MODULE+0x820) )
#define CONF_GPMC_AD9              ( * (vu32 *)(CONTROL_MODULE+0x824) )
#define CONF_GPMC_AD10             ( * (vu32 *)(CONTROL_MODULE+0x828) )
#define CONF_GPMC_AD11             ( * (vu32 *)(CONTROL_MODULE+0x82c) )
#define CONF_GPMC_AD12             ( * (vu32 *)(CONTROL_MODULE+0x830) )
#define CONF_GPMC_AD13             ( * (vu32 *)(CONTROL_MODULE+0x834) )
#define CONF_GPMC_AD14             ( * (vu32 *)(CONTROL_MODULE+0x838) )
#define CONF_GPMC_AD15             ( * (vu32 *)(CONTROL_MODULE+0x83c) )
#define CONF_GPMC_A0               ( * (vu32 *)(CONTROL_MODULE+0x840) )
#define CONF_GPMC_A1               ( * (vu32 *)(CONTROL_MODULE+0x844) )
#define CONF_GPMC_A2               ( * (vu32 *)(CONTROL_MODULE+0x848) )
#define CONF_GPMC_A3               ( * (vu32 *)(CONTROL_MODULE+0x84c) )
#define CONF_GPMC_A4               ( * (vu32 *)(CONTROL_MODULE+0x850) )
#define CONF_GPMC_A5               ( * (vu32 *)(CONTROL_MODULE+0x854) )
#define CONF_GPMC_A6               ( * (vu32 *)(CONTROL_MODULE+0x858) )
#define CONF_GPMC_A7               ( * (vu32 *)(CONTROL_MODULE+0x85c) )
#define CONF_GPMC_A8               ( * (vu32 *)(CONTROL_MODULE+0x860) )
#define CONF_GPMC_A9               ( * (vu32 *)(CONTROL_MODULE+0x864) )
#define CONF_GPMC_A10              ( * (vu32 *)(CONTROL_MODULE+0x868) )
#define CONF_GPMC_A11              ( * (vu32 *)(CONTROL_MODULE+0x86c) )
#define CONF_GPMC_WAIT0            ( * (vu32 *)(CONTROL_MODULE+0x870) )
#define CONF_GPMC_WPN              ( * (vu32 *)(CONTROL_MODULE+0x874) )
#define CONF_GPMC_BEN1             ( * (vu32 *)(CONTROL_MODULE+0x878) )
#define CONF_GPMC_CSN0             ( * (vu32 *)(CONTROL_MODULE+0x87c) )
#define CONF_GPMC_CSN1             ( * (vu32 *)(CONTROL_MODULE+0x880) )
#define CONF_GPMC_CSN2             ( * (vu32 *)(CONTROL_MODULE+0x884) )
#define CONF_GPMC_CSN3             ( * (vu32 *)(CONTROL_MODULE+0x888) )
#define CONF_GPMC_CLK              ( * (vu32 *)(CONTROL_MODULE+0x88c) )
#define CONF_GPMC_ADVN_ALE         ( * (vu32 *)(CONTROL_MODULE+0x890) )
#define CONF_GPMC_OEN_REN          ( * (vu32 *)(CONTROL_MODULE+0x894) )
#define CONF_GPMC_WEN              ( * (vu32 *)(CONTROL_MODULE+0x898) )
#define CONF_GPMC_BEN0_CLE         ( * (vu32 *)(CONTROL_MODULE+0x89c) )
#define CONF_LCD_DATA0             ( * (vu32 *)(CONTROL_MODULE+0x8a0) )
#define CONF_LCD_DATA1             ( * (vu32 *)(CONTROL_MODULE+0x8a4) )
#define CONF_LCD_DATA2             ( * (vu32 *)(CONTROL_MODULE+0x8a8) )
#define CONF_LCD_DATA3             ( * (vu32 *)(CONTROL_MODULE+0x8ac) )
#define CONF_LCD_DATA4             ( * (vu32 *)(CONTROL_MODULE+0x8b0) )
#define CONF_LCD_DATA5             ( * (vu32 *)(CONTROL_MODULE+0x8b4) )
#define CONF_LCD_DATA6             ( * (vu32 *)(CONTROL_MODULE+0x8b8) )
#define CONF_LCD_DATA7             ( * (vu32 *)(CONTROL_MODULE+0x8bc) )
#define CONF_LCD_DATA8             ( * (vu32 *)(CONTROL_MODULE+0x8c0) )
#define CONF_LCD_DATA9             ( * (vu32 *)(CONTROL_MODULE+0x8c4) )
#define CONF_LCD_DATA10            ( * (vu32 *)(CONTROL_MODULE+0x8c8) )
#define CONF_LCD_DATA11            ( * (vu32 *)(CONTROL_MODULE+0x8cc) )
#define CONF_LCD_DATA12            ( * (vu32 *)(CONTROL_MODULE+0x8d0) )
#define CONF_LCD_DATA13            ( * (vu32 *)(CONTROL_MODULE+0x8d4) )
#define CONF_LCD_DATA14            ( * (vu32 *)(CONTROL_MODULE+0x8d8) )
#define CONF_LCD_DATA15            ( * (vu32 *)(CONTROL_MODULE+0x8dc) )
#define CONF_LCD_VSYNC             ( * (vu32 *)(CONTROL_MODULE+0x8e0) )
#define CONF_LCD_HSYNC             ( * (vu32 *)(CONTROL_MODULE+0x8e4) )
#define CONF_LCD_PCLK              ( * (vu32 *)(CONTROL_MODULE+0x8e8) )
#define CONF_LCD_AC_BIAS_EN        ( * (vu32 *)(CONTROL_MODULE+0x8ec) )
#define CONF_MMC0_DAT3             ( * (vu32 *)(CONTROL_MODULE+0x8f0) )
#define CONF_MMC0_DAT2             ( * (vu32 *)(CONTROL_MODULE+0x8f4) )
#define CONF_MMC0_DAT1             ( * (vu32 *)(CONTROL_MODULE+0x8f8) )
#define CONF_MMC0_DAT0             ( * (vu32 *)(CONTROL_MODULE+0x8fc) )
#define CONF_MMC0_CLK              ( * (vu32 *)(CONTROL_MODULE+0x900) )
#define CONF_MMC0_CMD              ( * (vu32 *)(CONTROL_MODULE+0x904) )
#define CONF_MII1_COL              ( * (vu32 *)(CONTROL_MODULE+0x908) )
#define CONF_MII1_CRS              ( * (vu32 *)(CONTROL_MODULE+0x90c) )
#define CONF_MII1_RX_ER            ( * (vu32 *)(CONTROL_MODULE+0x910) )
#define CONF_MII1_TX_EN            ( * (vu32 *)(CONTROL_MODULE+0x914) )
#define CONF_MII1_RX_DV            ( * (vu32 *)(CONTROL_MODULE+0x918) )
#define CONF_MII1_TXD3             ( * (vu32 *)(CONTROL_MODULE+0x91c) )
#define CONF_MII1_TXD2             ( * (vu32 *)(CONTROL_MODULE+0x920) )
#define CONF_MII1_TXD1             ( * (vu32 *)(CONTROL_MODULE+0x924) )
#define CONF_MII1_TXD0             ( * (vu32 *)(CONTROL_MODULE+0x928) )
#define CONF_MII1_TX_CLK           ( * (vu32 *)(CONTROL_MODULE+0x92c) )
#define CONF_MII1_RX_CLK           ( * (vu32 *)(CONTROL_MODULE+0x930) )
#define CONF_MII1_RXD3             ( * (vu32 *)(CONTROL_MODULE+0x934) )
#define CONF_MII1_RXD2             ( * (vu32 *)(CONTROL_MODULE+0x938) )
#define CONF_MII1_RXD1             ( * (vu32 *)(CONTROL_MODULE+0x93c) )
#define CONF_MII1_RXD0             ( * (vu32 *)(CONTROL_MODULE+0x940) )
#define CONF_RMII1_REF_CLK         ( * (vu32 *)(CONTROL_MODULE+0x944) )
#define CONF_MDIO                  ( * (vu32 *)(CONTROL_MODULE+0x948) )
#define CONF_MDC                   ( * (vu32 *)(CONTROL_MODULE+0x94c) )
#define CONF_SPI0_SCLK             ( * (vu32 *)(CONTROL_MODULE+0x950) )
#define CONF_SPI0_D0               ( * (vu32 *)(CONTROL_MODULE+0x954) )
#define CONF_SPI0_D1               ( * (vu32 *)(CONTROL_MODULE+0x958) )
#define CONF_SPI0_CS0              ( * (vu32 *)(CONTROL_MODULE+0x95c) )
#define CONF_SPI0_CS1              ( * (vu32 *)(CONTROL_MODULE+0x960) )
#define CONF_ECAP0_IN_PWM0_OUT     ( * (vu32 *)(CONTROL_MODULE+0x964) )
#define CONF_UART0_CTSN            ( * (vu32 *)(CONTROL_MODULE+0x968) )
#define CONF_UART0_RTSN            ( * (vu32 *)(CONTROL_MODULE+0x96c) )
#define CONF_UART0_RXD             ( * (vu32 *)(CONTROL_MODULE+0x970) )
#define CONF_UART0_TXD             ( * (vu32 *)(CONTROL_MODULE+0x974) )
#define CONF_UART1_CTSN            ( * (vu32 *)(CONTROL_MODULE+0x978) )
#define CONF_UART1_RTSN            ( * (vu32 *)(CONTROL_MODULE+0x97c) )
#define CONF_UART1_RXD             ( * (vu32 *)(CONTROL_MODULE+0x980) )
#define CONF_UART1_TXD             ( * (vu32 *)(CONTROL_MODULE+0x984) )
#define CONF_I2C0_SDA              ( * (vu32 *)(CONTROL_MODULE+0x988) )
#define CONF_I2C0_SCL              ( * (vu32 *)(CONTROL_MODULE+0x98c) )
#define CONF_MCASP0_ACLKX          ( * (vu32 *)(CONTROL_MODULE+0x990) )
#define CONF_MCASP0_FSX            ( * (vu32 *)(CONTROL_MODULE+0x994) )
#define CONF_MCASP0_AXR0           ( * (vu32 *)(CONTROL_MODULE+0x998) )
#define CONF_MCASP0_AHCLKR         ( * (vu32 *)(CONTROL_MODULE+0x99c) )
#define CONF_MCASP0_ACLKR          ( * (vu32 *)(CONTROL_MODULE+0x9a0) )
#define CONF_MCASP0_FSR            ( * (vu32 *)(CONTROL_MODULE+0x9a4) )
#define CONF_MCASP0_AXR1           ( * (vu32 *)(CONTROL_MODULE+0x9a8) )
#define CONF_MCASP0_AHCLKX         ( * (vu32 *)(CONTROL_MODULE+0x9ac) )
#define CONF_XDMA_EVENT_INTR0      ( * (vu32 *)(CONTROL_MODULE+0x9b0) )
#define CONF_XDMA_EVENT_INTR1      ( * (vu32 *)(CONTROL_MODULE+0x9b4) )
#define CONF_WARMRSTN              ( * (vu32 *)(CONTROL_MODULE+0x9b8) )
#define CONF_NNMI                  ( * (vu32 *)(CONTROL_MODULE+0x9c0) )
#define CONF_TMS                   ( * (vu32 *)(CONTROL_MODULE+0x9d0) )
#define CONF_TDI                   ( * (vu32 *)(CONTROL_MODULE+0x9d4) )
#define CONF_TDO                   ( * (vu32 *)(CONTROL_MODULE+0x9d8) )
#define CONF_TCK                   ( * (vu32 *)(CONTROL_MODULE+0x9dc) )
#define CONF_TRSTN                 ( * (vu32 *)(CONTROL_MODULE+0x9e0) )
#define CONF_EMU0                  ( * (vu32 *)(CONTROL_MODULE+0x9e4) )
#define CONF_EMU1                  ( * (vu32 *)(CONTROL_MODULE+0x9e8) )
#define CONF_RTC_PWRONRSTN         ( * (vu32 *)(CONTROL_MODULE+0x9f8) )
#define CONF_PMIC_POWER_EN         ( * (vu32 *)(CONTROL_MODULE+0x9fc) )
#define CONF_EXT_WAKEUP            ( * (vu32 *)(CONTROL_MODULE+0xa00) )
#define CONF_RTC_KALDO_ENN         ( * (vu32 *)(CONTROL_MODULE+0xa04) )
#define CONF_USB0_DRVVBUS          ( * (vu32 *)(CONTROL_MODULE+0xa1c) )
#define CONF_USB1_DRVVBUS          ( * (vu32 *)(CONTROL_MODULE+0xa34) )


#define PRU_CFG PRU_NEW_FEATS

#define PRU_CFG_REVID              ( * (vu32 *)(PRU_CFG+0x00) )
#define PRU_CFG_SYSCFG             ( * (vu32 *)(PRU_CFG+0x04) )
#define PRU_CFG_GPCFG0             ( * (vu32 *)(PRU_CFG+0x08) )
#define PRU_CFG_GPCFG1             ( * (vu32 *)(PRU_CFG+0x0c) )
#define PRU_CFG_CGR                ( * (vu32 *)(PRU_CFG+0x10) )
#define PRU_CFG_ISRP               ( * (vu32 *)(PRU_CFG+0x14) )
#define PRU_CFG_ISP                ( * (vu32 *)(PRU_CFG+0x18) )
#define PRU_CFG_IESP               ( * (vu32 *)(PRU_CFG+0x1c) )
#define PRU_CFG_IECP               ( * (vu32 *)(PRU_CFG+0x20) )
#define PRU_CFG_PMAO               ( * (vu32 *)(PRU_CFG+0x28) )
#define PRU_CFG_MII_RT             ( * (vu32 *)(PRU_CFG+0x2c) )
#define PRU_CFG_IEPCLK             ( * (vu32 *)(PRU_CFG+0x30) )
#define PRU_CFG_SPP                ( * (vu32 *)(PRU_CFG+0x34) )
#define PRU_CFG_PIN_MX             ( * (vu32 *)(PRU_CFG+0x40) )


void init_pru_clocks(void);
void start_pru(int pru_nr);
void load_pru(int pru_nr);
void init_pru(void);
void pru_test(void);

#endif /* _PRU_H_ */

