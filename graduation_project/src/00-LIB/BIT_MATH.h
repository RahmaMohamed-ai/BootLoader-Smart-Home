/***
 *      ____ _____ _______   __  __       _______ _    _   _
 *     |  _ \_   _|__   __| |  \/  |   /\|__   __| |  | | | |
 *     | |_) || |    | |    | \  / |  /  \  | |  | |__| | | |__
 *     |  _ < | |    | |    | |\/| | / /\ \ | |  |  __  | | '_ \
 *     | |_) || |_   | |    | |  | |/ ____ \| |  | |  | |_| | | |
 *     |____/_____|  |_|    |_|  |_/_/    \_\_|  |_|  |_(_)_| |_|
 *
 *  	Created on: 16/10/2022
 *      Author: Mohamed Assem
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(VAR,BIT) (VAR) |=  (1 << (BIT))
#define CLR_BIT(VAR,BIT) (VAR) &= ~(1 << (BIT))
#define TOG_BIT(VAR,BIT) (VAR) ^=  (1 << (BIT))
#define GET_BIT(VAR,BIT) (((VAR) >> (BIT)) & 0x01)


#endif /* BIT_MATH_H_ */
