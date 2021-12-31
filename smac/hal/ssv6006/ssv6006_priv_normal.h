/*
 * Copyright (c) 2015 South Silicon Valley Microelectronics Inc.
 * Copyright (c) 2015 iComm Corporation
 *
 * This program is free software: you can redistribute it and/or modify 
 * it under the terms of the GNU General Public License as published by 
 * the Free Software Foundation, either version 3 of the License, or 
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
 * See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _SSV6006_PRIV_MAC_H_
#define _SSV6006_PRIV_MAC_H_ 
#define REG32(_addr) REG32_R(_addr)
#define REG32_R(_addr) ({ u32 reg; SMAC_REG_READ(sh, _addr, &reg); reg;})
#define REG32_W(_addr,_value) do { SMAC_REG_WRITE(sh, _addr, _value); } while (0)
#define MSLEEP(_val) msleep(_val)
#define UDELAY(_val) udelay(_val)
#define PRINT printk
#endif
