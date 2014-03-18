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
#define CM_PER_PRU_ICSS_CLKCTRL   ( * (vu32 *)(CM_PER+0x0e8))
#define CM_PER_PRU_ICSS_CLKSTCTRL ( * (vu32 *)(CM_PER+0x140))

#define CM_DPLL            0x44E00500
#define CLKSEL_PRU_ICSS_OCP_CLK   ( * (vu32 *)(CM_DPLL+0x30))

#define CM_WKUP            0x44E00400
#define CM_IDLEST_DPLL_CORE       ( * (vu32 *)(CM_WKUP+0x5c))
#define CM_CLKSEL_DPLL_CORE       ( * (vu32 *)(CM_WKUP+0x68))
#define CM_CLKMODE_DPLL_CORE      ( * (vu32 *)(CM_WKUP+0x90))

#define PRM_PER            0x44E00C00
#define RM_PER_RSTCTRL            ( * (vu32 *)(PRM_PER+0x00))
#define PM_PER_PWRSTST            ( * (vu32 *)(PRM_PER+0x08))
#define PM_PER_PWRSTCTRL          ( * (vu32 *)(PRM_PER+0x0c))

#define PRU0_MAILBOX_USER 1
#define PRU1_MAILBOX_USER 2

#define DEBUGSS_DRM_PRU 0x248

/* PRU local addresses */
#define PRU_DATA_RAM0                 (vu32 *)(PRU_BASE+0x00000000)
#define PRU_DATA_RAM1                 (vu32 *)(PRU_BASE+0x00002000)
#define PRU_SHRD_RAM2                 (vu32 *)(PRU_BASE+0x00010000)

#define PRU_INTC_REGS                          PRU_BASE+0x00020000
#define PRU_PRU0_REGS                          PRU_BASE+0x00022000
#define PRU_PRU0_DBG                           PRU_BASE+0x00022400
#define PRU_PRU1_REGS                          PRU_BASE+0x00024000

#define PRU_PRU1_DBG                  (vu32 *)(PRU_BASE+0x00024400)
#define PRU_NEW_FEATS                 (vu32 *)(PRU_BASE+0x00026000)
#define PRU0_IRAM                     (vu32 *)(PRU_BASE+0x00034000)
#define PRU1_IRAM                     (vu32 *)(PRU_BASE+0x00038000)


#define PRU_INTC_REVID            ( * (vu32 *)(PRU_INTC_REGS+0x0000))
#define PRU_INTC_CR               ( * (vu32 *)(PRU_INTC_REGS+0x0004))
#define PRU_INTC_GER              ( * (vu32 *)(PRU_INTC_REGS+0x0010))
#define PRU_INTC_GNLR             ( * (vu32 *)(PRU_INTC_REGS+0x001c))
#define PRU_INTC_SISR             ( * (vu32 *)(PRU_INTC_REGS+0x0020))
#define PRU_INTC_SICR             ( * (vu32 *)(PRU_INTC_REGS+0x0024))
#define PRU_INTC_EISR             ( * (vu32 *)(PRU_INTC_REGS+0x0028))
#define PRU_INTC_EICR             ( * (vu32 *)(PRU_INTC_REGS+0x002c))
#define PRU_INTC_HIEISR           ( * (vu32 *)(PRU_INTC_REGS+0x0034))
#define PRU_INTC_HIDISR           ( * (vu32 *)(PRU_INTC_REGS+0x0038))
#define PRU_INTC_GPIR             ( * (vu32 *)(PRU_INTC_REGS+0x0080))
#define PRU_INTC_SRSR0            ( * (vu32 *)(PRU_INTC_REGS+0x0200))
#define PRU_INTC_SRSR1            ( * (vu32 *)(PRU_INTC_REGS+0x0204))
#define PRU_INTC_SECR0            ( * (vu32 *)(PRU_INTC_REGS+0x0280))
#define PRU_INTC_SECR1            ( * (vu32 *)(PRU_INTC_REGS+0x0284))
#define PRU_INTC_ESR0             ( * (vu32 *)(PRU_INTC_REGS+0x0300))
#define PRU_INTC_ERS1             ( * (vu32 *)(PRU_INTC_REGS+0x0304))
#define PRU_INTC_ECR0             ( * (vu32 *)(PRU_INTC_REGS+0x0380))
#define PRU_INTC_ECR1             ( * (vu32 *)(PRU_INTC_REGS+0x0384))
#define PRU_INTC_CMR0             ( * (vu32 *)(PRU_INTC_REGS+0x0400))
#define PRU_INTC_CMR1             ( * (vu32 *)(PRU_INTC_REGS+0x0404))
#define PRU_INTC_CMR2             ( * (vu32 *)(PRU_INTC_REGS+0x0408))
#define PRU_INTC_CMR3             ( * (vu32 *)(PRU_INTC_REGS+0x040c))
#define PRU_INTC_CMR4             ( * (vu32 *)(PRU_INTC_REGS+0x0410))
#define PRU_INTC_CMR5             ( * (vu32 *)(PRU_INTC_REGS+0x0414))
#define PRU_INTC_CMR6             ( * (vu32 *)(PRU_INTC_REGS+0x0418))
#define PRU_INTC_CMR7             ( * (vu32 *)(PRU_INTC_REGS+0x041c))
#define PRU_INTC_CMR8             ( * (vu32 *)(PRU_INTC_REGS+0x0420))
#define PRU_INTC_CMR9             ( * (vu32 *)(PRU_INTC_REGS+0x0424))
#define PRU_INTC_CMR10            ( * (vu32 *)(PRU_INTC_REGS+0x0428))
#define PRU_INTC_CMR11            ( * (vu32 *)(PRU_INTC_REGS+0x042c))
#define PRU_INTC_CMR12            ( * (vu32 *)(PRU_INTC_REGS+0x0430))
#define PRU_INTC_CMR13            ( * (vu32 *)(PRU_INTC_REGS+0x0434))
#define PRU_INTC_CMR14            ( * (vu32 *)(PRU_INTC_REGS+0x0438))
#define PRU_INTC_CMR15            ( * (vu32 *)(PRU_INTC_REGS+0x043c))
#define PRU_INTC_HMR0             ( * (vu32 *)(PRU_INTC_REGS+0x0800))
#define PRU_INTC_HMR1             ( * (vu32 *)(PRU_INTC_REGS+0x0804))
#define PRU_INTC_HMR2             ( * (vu32 *)(PRU_INTC_REGS+0x0808))
#define PRU_INTC_HIPIR0           ( * (vu32 *)(PRU_INTC_REGS+0x0900))
#define PRU_INTC_HIPIR1           ( * (vu32 *)(PRU_INTC_REGS+0x0904))
#define PRU_INTC_HIPIR2           ( * (vu32 *)(PRU_INTC_REGS+0x0908))
#define PRU_INTC_HIPIR3           ( * (vu32 *)(PRU_INTC_REGS+0x090c))
#define PRU_INTC_HIPIR4           ( * (vu32 *)(PRU_INTC_REGS+0x0910))
#define PRU_INTC_HIPIR5           ( * (vu32 *)(PRU_INTC_REGS+0x0914))
#define PRU_INTC_HIPIR6           ( * (vu32 *)(PRU_INTC_REGS+0x0918))
#define PRU_INTC_HIPIR7           ( * (vu32 *)(PRU_INTC_REGS+0x091c))
#define PRU_INTC_HIPIR8           ( * (vu32 *)(PRU_INTC_REGS+0x0920))
#define PRU_INTC_HIPIR9           ( * (vu32 *)(PRU_INTC_REGS+0x0924))
#define PRU_INTC_SIPR0            ( * (vu32 *)(PRU_INTC_REGS+0x0d00))
#define PRU_INTC_SIPR1            ( * (vu32 *)(PRU_INTC_REGS+0x0d04))
#define PRU_INTC_SITR0            ( * (vu32 *)(PRU_INTC_REGS+0x0d80))
#define PRU_INTC_SITR1            ( * (vu32 *)(PRU_INTC_REGS+0x0d84))
#define PRU_INTC_HINLR0           ( * (vu32 *)(PRU_INTC_REGS+0x1100))
#define PRU_INTC_HINLR1           ( * (vu32 *)(PRU_INTC_REGS+0x1104))
#define PRU_INTC_HINLR2           ( * (vu32 *)(PRU_INTC_REGS+0x1108))
#define PRU_INTC_HINLR3           ( * (vu32 *)(PRU_INTC_REGS+0x110c))
#define PRU_INTC_HINLR4           ( * (vu32 *)(PRU_INTC_REGS+0x1110))
#define PRU_INTC_HINLR5           ( * (vu32 *)(PRU_INTC_REGS+0x1114))
#define PRU_INTC_HINLR6           ( * (vu32 *)(PRU_INTC_REGS+0x1118))
#define PRU_INTC_HINLR7           ( * (vu32 *)(PRU_INTC_REGS+0x111c))
#define PRU_INTC_HINLR8           ( * (vu32 *)(PRU_INTC_REGS+0x1120))
#define PRU_INTC_HINLR9           ( * (vu32 *)(PRU_INTC_REGS+0x1124))
#define PRU_INTC_HIER             ( * (vu32 *)(PRU_INTC_REGS+0x1500))


#define PRU0_CONTROL              ( * (vu32 *)(PRU_PRU0_REGS + 0x00))
#define PRU0_STATUS               ( * (vu32 *)(PRU_PRU0_REGS + 0x04))
#define PRU0_WAKEUP_EN            ( * (vu32 *)(PRU_PRU0_REGS + 0x08))
#define PRU0_CYCLE                ( * (vu32 *)(PRU_PRU0_REGS + 0x0c))
#define PRU0_STALL                ( * (vu32 *)(PRU_PRU0_REGS + 0x10))
#define PRU0_CTBIR0               ( * (vu32 *)(PRU_PRU0_REGS + 0x20))
#define PRU0_CTBIR1               ( * (vu32 *)(PRU_PRU0_REGS + 0x24))
#define PRU0_CTPPR0               ( * (vu32 *)(PRU_PRU0_REGS + 0x28))
#define PRU0_CTPPR1               ( * (vu32 *)(PRU_PRU0_REGS + 0x2c))

#define PRU1_CONTROL              ( * (vu32 *)(PRU_PRU1_REGS + 0x00))
#define PRU1_STATUS               ( * (vu32 *)(PRU_PRU1_REGS + 0x04))
#define PRU1_WAKEUP_EN            ( * (vu32 *)(PRU_PRU1_REGS + 0x08))
#define PRU1_CYCLE                ( * (vu32 *)(PRU_PRU1_REGS + 0x0c))
#define PRU1_STALL                ( * (vu32 *)(PRU_PRU1_REGS + 0x10))
#define PRU1_CTBIR0               ( * (vu32 *)(PRU_PRU1_REGS + 0x20))
#define PRU1_CTBIR1               ( * (vu32 *)(PRU_PRU1_REGS + 0x24))
#define PRU1_CTPPR0               ( * (vu32 *)(PRU_PRU1_REGS + 0x28))
#define PRU1_CTPPR1               ( * (vu32 *)(PRU_PRU1_REGS + 0x2c))

#define CONTROL_MODULE               0x44E10000
#define DEV_FEATURE                ( * (vu32 *)(CONTROL_MODULE+0x604))
#define INIT_PRIORITY_0            ( * (vu32 *)(CONTROL_MODULE+0x608))
#define MREQPRIO_0                 ( * (vu32 *)(CONTROL_MODULE+0x670))
#define ADC_EVT_CAPT               ( * (vu32 *)(CONTROL_MODULE+0xfd8))


#define PRU_CFG PRU_NEW_FEATS

#define PRU_CFG_REVID      ( * (vu32 *)(PRU_CFG+0x0))
#define PRU_CFG_SYSCFG     ( * (vu32 *)(PRU_CFG+0x4))
#define PRU_CFG_GPCFG0     ( * (vu32 *)(PRU_CFG+0x8))
#define PRU_CFG_GPCFG1     ( * (vu32 *)(PRU_CFG+0xC))
#define PRU_CFG_CGR        ( * (vu32 *)(PRU_CFG+0x10))
#define PRU_CFG_ISRP       ( * (vu32 *)(PRU_CFG+0x14))
#define PRU_CFG_ISP        ( * (vu32 *)(PRU_CFG+0x18))
#define PRU_CFG_IESP       ( * (vu32 *)(PRU_CFG+0x1C))
#define PRU_CFG_IECP       ( * (vu32 *)(PRU_CFG+0x20))
#define PRU_CFG_PMAO       ( * (vu32 *)(PRU_CFG+0x28))
#define PRU_CFG_MII_RT     ( * (vu32 *)(PRU_CFG+0x2C))
#define PRU_CFG_IEPCLK     ( * (vu32 *)(PRU_CFG+0x30))
#define PRU_CFG_SPP        ( * (vu32 *)(PRU_CFG+0x34))
#define PRU_CFG_PIN_MX     ( * (vu32 *)(PRU_CFG+0x40))


void init_pru_clocks(void);
void start_pru(int pru_nr);
void load_pru(int pru_nr);
void init_pru(void);
void pru_test(void);

#endif /* _PRU_H_ */

