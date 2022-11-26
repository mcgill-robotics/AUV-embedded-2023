#pragma once

/** Sets the nth bit in a register.*/
#define SET_BIT(REG, BIT)     ((REG) |= (1ul << BIT))

/** Clears the nth bit in a register. */
#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(1ul << BIT))

/** Reads only the nth bit from a register. */
#define READ_BIT(REG, BIT)    ((REG) & (1ul << BIT))

