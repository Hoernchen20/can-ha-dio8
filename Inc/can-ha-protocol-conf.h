﻿/*
 * example_can-ha-protocol-conf.h
 *
 * Copyright 2015  Felix Horn
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */


/* General configuration -----------------------------------------------------*/
#define NODE_ID         262140
#define HEARTBEAT_TIME  20
#define REFRESH_TIME    60

/* Single Indications --------------------------------------------------------*/
/* Size of single indications */
#define TX_SINGLE_INDICATION_SIZE   8
#define RX_SINGLE_INDICATION_SIZE   0

/* Identifier of transmitted single indications */
#define TX_SINGLE_INDICATION_0_ID   262138
#define TX_SINGLE_INDICATION_1_ID   15001
#define TX_SINGLE_INDICATION_2_ID   15002
#define TX_SINGLE_INDICATION_3_ID   15003
#define TX_SINGLE_INDICATION_4_ID   15004
#define TX_SINGLE_INDICATION_5_ID   15005
#define TX_SINGLE_INDICATION_6_ID   15006
#define TX_SINGLE_INDICATION_7_ID   15007
#define TX_SINGLE_INDICATION_8_ID   15008
#define TX_SINGLE_INDICATION_9_ID   15009
#define TX_SINGLE_INDICATION_10_ID  15010
#define TX_SINGLE_INDICATION_11_ID  15011
#define TX_SINGLE_INDICATION_12_ID  15012
#define TX_SINGLE_INDICATION_13_ID  15013
#define TX_SINGLE_INDICATION_14_ID  15014
#define TX_SINGLE_INDICATION_15_ID  15015
#define TX_SINGLE_INDICATION_16_ID  15016
#define TX_SINGLE_INDICATION_17_ID  15017
#define TX_SINGLE_INDICATION_18_ID  15018
#define TX_SINGLE_INDICATION_19_ID  15019

/* Identifier of received single indications */
#define RX_SINGLE_INDICATION_0_ID    16000
#define RX_SINGLE_INDICATION_1_ID    16001
#define RX_SINGLE_INDICATION_2_ID    16002
#define RX_SINGLE_INDICATION_3_ID    16003
#define RX_SINGLE_INDICATION_4_ID    16004
#define RX_SINGLE_INDICATION_5_ID    16005
#define RX_SINGLE_INDICATION_6_ID    16006
#define RX_SINGLE_INDICATION_7_ID    16007
#define RX_SINGLE_INDICATION_8_ID    16008
#define RX_SINGLE_INDICATION_9_ID    16009
#define RX_SINGLE_INDICATION_10_ID   16010
#define RX_SINGLE_INDICATION_11_ID   16011
#define RX_SINGLE_INDICATION_12_ID   16012
#define RX_SINGLE_INDICATION_13_ID   16013
#define RX_SINGLE_INDICATION_14_ID   16014
#define RX_SINGLE_INDICATION_15_ID   16015
#define RX_SINGLE_INDICATION_16_ID   16016
#define RX_SINGLE_INDICATION_17_ID   16017
#define RX_SINGLE_INDICATION_18_ID   16018
#define RX_SINGLE_INDICATION_19_ID   16019

/* Double Indications --------------------------------------------------------*/
/* Size of double indications */
#define TX_DOUBLE_INDICATION_SIZE   0
#define RX_DOUBLE_INDICATION_SIZE   0

/* Identifier of transmitted single indications */
#define TX_DOUBLE_INDICATION_0_ID   15000
#define TX_DOUBLE_INDICATION_1_ID   15001
#define TX_DOUBLE_INDICATION_2_ID   15002
#define TX_DOUBLE_INDICATION_3_ID   15003
#define TX_DOUBLE_INDICATION_4_ID   15004
#define TX_DOUBLE_INDICATION_5_ID   15005
#define TX_DOUBLE_INDICATION_6_ID   15006
#define TX_DOUBLE_INDICATION_7_ID   15007
#define TX_DOUBLE_INDICATION_8_ID   15008
#define TX_DOUBLE_INDICATION_9_ID   15009
#define TX_DOUBLE_INDICATION_10_ID  15010
#define TX_DOUBLE_INDICATION_11_ID  15011
#define TX_DOUBLE_INDICATION_12_ID  15012
#define TX_DOUBLE_INDICATION_13_ID  15013
#define TX_DOUBLE_INDICATION_14_ID  15014
#define TX_DOUBLE_INDICATION_15_ID  15015
#define TX_DOUBLE_INDICATION_16_ID  15016
#define TX_DOUBLE_INDICATION_17_ID  15017
#define TX_DOUBLE_INDICATION_18_ID  15018
#define TX_DOUBLE_INDICATION_19_ID  15019

/* Identifier of received single indications */
#define RX_DOUBLE_INDICATION_0_ID    16000
#define RX_DOUBLE_INDICATION_1_ID    16001
#define RX_DOUBLE_INDICATION_2_ID    16002
#define RX_DOUBLE_INDICATION_3_ID    16003
#define RX_DOUBLE_INDICATION_4_ID    16004
#define RX_DOUBLE_INDICATION_5_ID    16005
#define RX_DOUBLE_INDICATION_6_ID    16006
#define RX_DOUBLE_INDICATION_7_ID    16007
#define RX_DOUBLE_INDICATION_8_ID    16008
#define RX_DOUBLE_INDICATION_9_ID    16009
#define RX_DOUBLE_INDICATION_10_ID   16010
#define RX_DOUBLE_INDICATION_11_ID   16011
#define RX_DOUBLE_INDICATION_12_ID   16012
#define RX_DOUBLE_INDICATION_13_ID   16013
#define RX_DOUBLE_INDICATION_14_ID   16014
#define RX_DOUBLE_INDICATION_15_ID   16015
#define RX_DOUBLE_INDICATION_16_ID   16016
#define RX_DOUBLE_INDICATION_17_ID   16017
#define RX_DOUBLE_INDICATION_18_ID   16018
#define RX_DOUBLE_INDICATION_19_ID   16019

/* 16bit Measured Values -----------------------------------------------------*/
/* Size of measured values */
#define TX_MEASURED_VALUE_16_SIZE   0
#define RX_MEASURED_VALUE_16_SIZE   0

/* Identifier of transmitted measured values */
#define TX_MEASURED_VALUE_16_0_ID    19000
#define TX_MEASURED_VALUE_16_1_ID    19001
#define TX_MEASURED_VALUE_16_2_ID    19002
#define TX_MEASURED_VALUE_16_3_ID    19003
#define TX_MEASURED_VALUE_16_4_ID    19004
#define TX_MEASURED_VALUE_16_5_ID    19005
#define TX_MEASURED_VALUE_16_6_ID    19006
#define TX_MEASURED_VALUE_16_7_ID    19007
#define TX_MEASURED_VALUE_16_8_ID    19008
#define TX_MEASURED_VALUE_16_9_ID    19009
#define TX_MEASURED_VALUE_16_10_ID   19010
#define TX_MEASURED_VALUE_16_11_ID   19011
#define TX_MEASURED_VALUE_16_12_ID   19012
#define TX_MEASURED_VALUE_16_13_ID   19013
#define TX_MEASURED_VALUE_16_14_ID   19014
#define TX_MEASURED_VALUE_16_15_ID   19015
#define TX_MEASURED_VALUE_16_16_ID   19016
#define TX_MEASURED_VALUE_16_17_ID   19017
#define TX_MEASURED_VALUE_16_18_ID   19018
#define TX_MEASURED_VALUE_16_19_ID   19019

/* Identifier of received measured values */
#define RX_MEASURED_VALUE_16_0_ID    20000
#define RX_MEASURED_VALUE_16_1_ID    20001
#define RX_MEASURED_VALUE_16_2_ID    20002
#define RX_MEASURED_VALUE_16_3_ID    20003
#define RX_MEASURED_VALUE_16_4_ID    20004
#define RX_MEASURED_VALUE_16_5_ID    20005
#define RX_MEASURED_VALUE_16_6_ID    20006
#define RX_MEASURED_VALUE_16_7_ID    20007
#define RX_MEASURED_VALUE_16_8_ID    20008
#define RX_MEASURED_VALUE_16_9_ID    20009
#define RX_MEASURED_VALUE_16_10_ID   20010
#define RX_MEASURED_VALUE_16_11_ID   20011
#define RX_MEASURED_VALUE_16_12_ID   20012
#define RX_MEASURED_VALUE_16_13_ID   20013
#define RX_MEASURED_VALUE_16_14_ID   20014
#define RX_MEASURED_VALUE_16_15_ID   20015
#define RX_MEASURED_VALUE_16_16_ID   20016
#define RX_MEASURED_VALUE_16_17_ID   20017
#define RX_MEASURED_VALUE_16_18_ID   20018
#define RX_MEASURED_VALUE_16_19_ID   20019

/* 32bit Measured Values -----------------------------------------------------*/
/* Size of measured values */
#define TX_MEASURED_VALUE_32_SIZE   0
#define RX_MEASURED_VALUE_32_SIZE   0

/* Identifier of transmitted measured values */
#define TX_MEASURED_VALUE_32_0_ID    21000
#define TX_MEASURED_VALUE_32_1_ID    21001
#define TX_MEASURED_VALUE_32_2_ID    21002
#define TX_MEASURED_VALUE_32_3_ID    21003
#define TX_MEASURED_VALUE_32_4_ID    21004
#define TX_MEASURED_VALUE_32_5_ID    21005
#define TX_MEASURED_VALUE_32_6_ID    21006
#define TX_MEASURED_VALUE_32_7_ID    21007
#define TX_MEASURED_VALUE_32_8_ID    21008
#define TX_MEASURED_VALUE_32_9_ID    21009
#define TX_MEASURED_VALUE_32_10_ID   21010
#define TX_MEASURED_VALUE_32_11_ID   21011
#define TX_MEASURED_VALUE_32_12_ID   21012
#define TX_MEASURED_VALUE_32_13_ID   21013
#define TX_MEASURED_VALUE_32_14_ID   21014
#define TX_MEASURED_VALUE_32_15_ID   21015
#define TX_MEASURED_VALUE_32_16_ID   21016
#define TX_MEASURED_VALUE_32_17_ID   21017
#define TX_MEASURED_VALUE_32_18_ID   21018
#define TX_MEASURED_VALUE_32_19_ID   21019

/* Identifier of received measured values */
#define RX_MEASURED_VALUE_32_0_ID    22000
#define RX_MEASURED_VALUE_32_1_ID    22001
#define RX_MEASURED_VALUE_32_2_ID    22002
#define RX_MEASURED_VALUE_32_3_ID    22003
#define RX_MEASURED_VALUE_32_4_ID    22004
#define RX_MEASURED_VALUE_32_5_ID    22005
#define RX_MEASURED_VALUE_32_6_ID    22006
#define RX_MEASURED_VALUE_32_7_ID    22007
#define RX_MEASURED_VALUE_32_8_ID    22008
#define RX_MEASURED_VALUE_32_9_ID    22009
#define RX_MEASURED_VALUE_32_10_ID   22010
#define RX_MEASURED_VALUE_32_11_ID   22011
#define RX_MEASURED_VALUE_32_12_ID   22012
#define RX_MEASURED_VALUE_32_13_ID   22013
#define RX_MEASURED_VALUE_32_14_ID   22014
#define RX_MEASURED_VALUE_32_15_ID   22015
#define RX_MEASURED_VALUE_32_16_ID   22016
#define RX_MEASURED_VALUE_32_17_ID   22017
#define RX_MEASURED_VALUE_32_18_ID   22018
#define RX_MEASURED_VALUE_32_19_ID   22019