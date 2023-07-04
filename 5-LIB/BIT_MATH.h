#ifndef  BIT_MAITH_H
#define  BIT_MAITH_H


#define SET_BIT(REG,BITNO)  REG |= (1<<BITNO)
#define GET_BIT(REG,BITNO)  ((REG>>BITNO) & 1)
#define CLR_BIT(REG,BITNO)  REG &= (~(1<<BITNO))
#define TOG_BIT(REG,BITNO)  REG ^= (1<<BITNO)


#endif