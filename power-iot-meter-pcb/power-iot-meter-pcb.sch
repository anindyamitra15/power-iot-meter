EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L HLK-5M05:HLK-5M05 PS1
U 1 1 62A4EF7C
P 3650 4050
F 0 "PS1" H 3650 4416 50  0000 C CNN
F 1 "HLK-5M05" H 3650 4325 50  0000 C CNN
F 2 "CONV_HLK-5M05" H 3650 4050 50  0001 L BNN
F 3 "" H 3650 4050 50  0001 L BNN
F 4 "N/A" H 3650 4050 50  0001 L BNN "PARTREV"
F 5 "Manufacturer Recommendations" H 3650 4050 50  0001 L BNN "STANDARD"
F 6 "HI-LINK" H 3650 4050 50  0001 L BNN "MANUFACTURER"
	1    3650 4050
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J3
U 1 1 62A5120A
P 2700 6450
F 0 "J3" H 2618 6125 50  0000 C CNN
F 1 "AC INPUT" H 2618 6216 50  0000 C CNN
F 2 "TerminalBlock:TerminalBlock_Altech_AK300-2_P5.00mm" H 2700 6450 50  0001 C CNN
F 3 "~" H 2700 6450 50  0001 C CNN
	1    2700 6450
	-1   0    0    1   
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J1
U 1 1 62A520A7
P 2700 5400
F 0 "J1" H 2618 5075 50  0000 C CNN
F 1 "AC OUTPUT" H 2618 5166 50  0000 C CNN
F 2 "TerminalBlock:TerminalBlock_Altech_AK300-2_P5.00mm" H 2700 5400 50  0001 C CNN
F 3 "~" H 2700 5400 50  0001 C CNN
	1    2700 5400
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x03_Male J6
U 1 1 62A533D9
P 3950 1550
F 0 "J6" V 3800 1550 50  0000 C CNN
F 1 "POWER_MALE" V 3900 1600 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x03_P2.00mm_Vertical" H 3950 1550 50  0001 C CNN
F 3 "~" H 3950 1550 50  0001 C CNN
	1    3950 1550
	0    1    1    0   
$EndComp
$Comp
L Connector:Conn_01x03_Female J5
U 1 1 62A53EFB
P 3000 1550
F 0 "J5" V 3150 1500 50  0000 L CNN
F 1 "POWER_FEMALE" V 3050 1250 50  0000 L CNN
F 2 "Connector_PinSocket_2.00mm:PinSocket_1x03_P2.00mm_Vertical" H 3000 1550 50  0001 C CNN
F 3 "~" H 3000 1550 50  0001 C CNN
	1    3000 1550
	0    1    -1   0   
$EndComp
$Comp
L power:GND #PWR013
U 1 1 62A56150
P 8750 4900
F 0 "#PWR013" H 8750 4650 50  0001 C CNN
F 1 "GND" H 8755 4727 50  0000 C CNN
F 2 "" H 8750 4900 50  0001 C CNN
F 3 "" H 8750 4900 50  0001 C CNN
	1    8750 4900
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR011
U 1 1 62A56981
P 7550 2900
F 0 "#PWR011" H 7550 2750 50  0001 C CNN
F 1 "+5V" H 7565 3073 50  0000 C CNN
F 2 "" H 7550 2900 50  0001 C CNN
F 3 "" H 7550 2900 50  0001 C CNN
	1    7550 2900
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR012
U 1 1 62A576C9
P 8750 2900
F 0 "#PWR012" H 8750 2750 50  0001 C CNN
F 1 "+3V3" H 8765 3073 50  0000 C CNN
F 2 "" H 8750 2900 50  0001 C CNN
F 3 "" H 8750 2900 50  0001 C CNN
	1    8750 2900
	1    0    0    -1  
$EndComp
$Comp
L ESP32-DEVKIT-V1:ESP32-DEVKIT-V1 U1
U 1 1 62A4DB5A
P 8150 3900
F 0 "U1" H 8150 5167 50  0000 C CNN
F 1 "ESP32-DEVKIT-V1" H 8150 5076 50  0000 C CNN
F 2 "MODULE_ESP32_DEVKIT_V1:MODULE_ESP32_DEVKIT_V1" H 8150 3900 50  0001 L BNN
F 3 "" H 8150 3900 50  0001 L BNN
F 4 "N/A" H 8150 3900 50  0001 L BNN "PARTREV"
F 5 "6.8 mm" H 8150 3900 50  0001 L BNN "MAXIMUM_PACKAGE_HEIGHT"
F 6 "DOIT" H 8150 3900 50  0001 L BNN "MANUFACTURER"
F 7 "Manufacturer Recommendations" H 8150 3900 50  0001 L BNN "STANDARD"
	1    8150 3900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR05
U 1 1 62A62E83
P 3950 1900
F 0 "#PWR05" H 3950 1650 50  0001 C CNN
F 1 "GND" H 3955 1727 50  0000 C CNN
F 2 "" H 3950 1900 50  0001 C CNN
F 3 "" H 3950 1900 50  0001 C CNN
	1    3950 1900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 62A6A022
P 3000 1950
F 0 "#PWR02" H 3000 1700 50  0001 C CNN
F 1 "GND" H 3005 1777 50  0000 C CNN
F 2 "" H 3000 1950 50  0001 C CNN
F 3 "" H 3000 1950 50  0001 C CNN
	1    3000 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 1950 3000 1750
Wire Wire Line
	3950 1900 3950 1750
$Comp
L power:+3V3 #PWR08
U 1 1 62A6C0FE
P 4300 1800
F 0 "#PWR08" H 4300 1650 50  0001 C CNN
F 1 "+3V3" H 4315 1973 50  0000 C CNN
F 2 "" H 4300 1800 50  0001 C CNN
F 3 "" H 4300 1800 50  0001 C CNN
	1    4300 1800
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR03
U 1 1 62A6C30D
P 3300 1800
F 0 "#PWR03" H 3300 1650 50  0001 C CNN
F 1 "+3V3" H 3315 1973 50  0000 C CNN
F 2 "" H 3300 1800 50  0001 C CNN
F 3 "" H 3300 1800 50  0001 C CNN
	1    3300 1800
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR04
U 1 1 62A72A0D
P 3600 1800
F 0 "#PWR04" H 3600 1650 50  0001 C CNN
F 1 "+5V" H 3615 1973 50  0000 C CNN
F 2 "" H 3600 1800 50  0001 C CNN
F 3 "" H 3600 1800 50  0001 C CNN
	1    3600 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 1800 3100 1800
Wire Wire Line
	3100 1800 3100 1750
Wire Wire Line
	2900 1750 2900 1800
Wire Wire Line
	2900 1800 2700 1800
Wire Wire Line
	3600 1800 3850 1800
Wire Wire Line
	3850 1800 3850 1750
Wire Wire Line
	4300 1800 4050 1800
Wire Wire Line
	4050 1800 4050 1750
$Comp
L Connector:Conn_01x04_Female J7
U 1 1 62A54EAA
P 5100 1550
F 0 "J7" V 5250 1500 50  0000 L CNN
F 1 "UART_FEMALE" V 5150 1200 50  0000 L CNN
F 2 "Connector_PinSocket_2.00mm:PinSocket_1x04_P2.00mm_Vertical" H 5100 1550 50  0001 C CNN
F 3 "~" H 5100 1550 50  0001 C CNN
	1    5100 1550
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR010
U 1 1 62A80383
P 5450 1850
F 0 "#PWR010" H 5450 1600 50  0001 C CNN
F 1 "GND" H 5455 1677 50  0000 C CNN
F 2 "" H 5450 1850 50  0001 C CNN
F 3 "" H 5450 1850 50  0001 C CNN
	1    5450 1850
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR01
U 1 1 62A6DEA4
P 2700 1800
F 0 "#PWR01" H 2700 1650 50  0001 C CNN
F 1 "+5V" H 2715 1973 50  0000 C CNN
F 2 "" H 2700 1800 50  0001 C CNN
F 3 "" H 2700 1800 50  0001 C CNN
	1    2700 1800
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR09
U 1 1 62A8286C
P 4750 1800
F 0 "#PWR09" H 4750 1650 50  0001 C CNN
F 1 "+5V" H 4765 1973 50  0000 C CNN
F 2 "" H 4750 1800 50  0001 C CNN
F 3 "" H 4750 1800 50  0001 C CNN
	1    4750 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 1800 5000 1800
Wire Wire Line
	5000 1800 5000 1750
Wire Wire Line
	5300 1750 5300 1800
Wire Wire Line
	5300 1800 5450 1800
Wire Wire Line
	5450 1800 5450 1850
Text GLabel 3100 6350 2    50   Input ~ 0
AC_IN2
Text GLabel 3100 6450 2    50   Input ~ 0
AC_IN1
Wire Wire Line
	2900 6350 3100 6350
Wire Wire Line
	2900 6450 3100 6450
Text GLabel 3100 5400 2    50   Input ~ 0
AC_OUT1
Wire Wire Line
	2900 5400 3100 5400
Text GLabel 3100 5300 2    50   Input ~ 0
AC_OUT2
Wire Wire Line
	2900 5300 3100 5300
Text GLabel 3050 4150 0    50   Input ~ 0
AC_IN2
Text GLabel 3050 3950 0    50   Input ~ 0
AC_IN1
Wire Wire Line
	3050 4150 3150 4150
Wire Wire Line
	3050 3950 3150 3950
$Comp
L power:+5V #PWR06
U 1 1 62A8C81A
P 4250 3850
F 0 "#PWR06" H 4250 3700 50  0001 C CNN
F 1 "+5V" H 4265 4023 50  0000 C CNN
F 2 "" H 4250 3850 50  0001 C CNN
F 3 "" H 4250 3850 50  0001 C CNN
	1    4250 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 3850 4250 3950
Wire Wire Line
	4250 3950 4150 3950
$Comp
L power:GND #PWR07
U 1 1 62A8D82F
P 4250 4250
F 0 "#PWR07" H 4250 4000 50  0001 C CNN
F 1 "GND" H 4255 4077 50  0000 C CNN
F 2 "" H 4250 4250 50  0001 C CNN
F 3 "" H 4250 4250 50  0001 C CNN
	1    4250 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 4150 4250 4150
Wire Wire Line
	4250 4150 4250 4250
Text GLabel 5200 1950 3    50   Input ~ 0
Tx
Text GLabel 5100 1950 3    50   Input ~ 0
Rx
Text GLabel 8900 3600 2    50   Input ~ 0
Tx
Text GLabel 8900 3500 2    50   Input ~ 0
Rx
Wire Wire Line
	8900 3500 8750 3500
Wire Wire Line
	8900 3600 8750 3600
Wire Wire Line
	5200 1950 5200 1750
Wire Wire Line
	5100 1750 5100 1950
NoConn ~ 7550 3000
NoConn ~ 7550 3200
NoConn ~ 7550 3300
NoConn ~ 7550 3800
NoConn ~ 7550 3900
NoConn ~ 7550 4000
NoConn ~ 7550 4100
NoConn ~ 7550 4200
NoConn ~ 7550 4300
NoConn ~ 7550 4400
NoConn ~ 7550 4500
NoConn ~ 7550 4600
NoConn ~ 7550 4700
NoConn ~ 8750 4600
NoConn ~ 8750 4500
NoConn ~ 8750 4400
NoConn ~ 8750 4300
NoConn ~ 8750 4200
NoConn ~ 8750 4100
NoConn ~ 8750 3900
NoConn ~ 8750 4000
NoConn ~ 8750 3800
$Comp
L Connector:Screw_Terminal_01x02 J2
U 1 1 62AACC81
P 2700 5800
F 0 "J2" H 2618 6017 50  0000 C CNN
F 1 "AC Current Sensor" H 2618 5926 50  0000 C CNN
F 2 "Connector_Wire:SolderWire-0.5sqmm_1x02_P4.6mm_D0.9mm_OD2.1mm_Relief" H 2700 5800 50  0001 C CNN
F 3 "~" H 2700 5800 50  0001 C CNN
	1    2700 5800
	-1   0    0    -1  
$EndComp
Text GLabel 3050 5800 2    50   Input ~ 0
AC_OUT1
Text GLabel 3050 5900 2    50   Input ~ 0
AC_IN2
Wire Wire Line
	3050 5800 2900 5800
Wire Wire Line
	2900 5900 3050 5900
Text GLabel 4000 5700 1    50   Input ~ 0
AC_OUT2
Text GLabel 4000 6100 3    50   Input ~ 0
AC_IN1
Wire Wire Line
	4000 5700 4000 6100
$Comp
L Connector:Screw_Terminal_01x02 J4
U 1 1 62AB7B35
P 2700 7000
F 0 "J4" H 2618 6675 50  0000 C CNN
F 1 "AC Voltage Sensor" H 2618 6766 50  0000 C CNN
F 2 "Connector_Wire:SolderWire-0.5sqmm_1x02_P4.6mm_D0.9mm_OD2.1mm_Relief" H 2700 7000 50  0001 C CNN
F 3 "~" H 2700 7000 50  0001 C CNN
	1    2700 7000
	-1   0    0    1   
$EndComp
Wire Wire Line
	3050 6900 2900 6900
Wire Wire Line
	2900 7000 3050 7000
Text GLabel 3050 6900 2    50   Input ~ 0
AC_IN2
Text GLabel 3050 7000 2    50   Input ~ 0
AC_IN1
$EndSCHEMATC
