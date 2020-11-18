EESchema Schematic File Version 5
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
Comment5 ""
Comment6 ""
Comment7 ""
Comment8 ""
Comment9 ""
$EndDescr
$Comp
L tim_mosfet:SMAJ12A D?
U 1 1 5E0C5031
P 4350 4700
F 0 "D?" H 4350 4915 50  0000 C CNN
F 1 "SMAJ12A" H 4350 4824 50  0000 C CNN
F 2 "Diode_SMD:D_SMA" H 4350 4700 50  0001 C CNN
F 3 "https://www.littelfuse.com/~/media/electronics/datasheets/tvs_diodes/littelfuse_tvs_diode_smaj_datasheet.pdf.pdf" H 4350 4700 50  0001 C CNN
	1    4350 4700
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR?
U 1 1 5E0CCF8D
P 3150 1000
F 0 "#PWR?" H 3150 850 50  0001 C CNN
F 1 "+BATT" H 3165 1173 50  0000 C CNN
F 2 "" H 3150 1000 50  0001 C CNN
F 3 "" H 3150 1000 50  0001 C CNN
	1    3150 1000
	0    -1   -1   0   
$EndComp
$Comp
L power:-BATT #PWR?
U 1 1 5E0CCFA6
P 3150 1300
F 0 "#PWR?" H 3150 1150 50  0001 C CNN
F 1 "-BATT" H 3165 1473 50  0000 C CNN
F 2 "" H 3150 1300 50  0001 C CNN
F 3 "" H 3150 1300 50  0001 C CNN
	1    3150 1300
	0    -1   -1   0   
$EndComp
$Comp
L pspice:INDUCTOR L?
U 1 1 5E0DD00E
P 3750 1000
F 0 "L?" H 3750 1214 50  0000 C CNN
F 1 "0.47uH" H 3750 1123 50  0000 C CNN
F 2 "" H 3750 1000 50  0001 C CNN
F 3 "~" H 3750 1000 50  0001 C CNN
	1    3750 1000
	1    0    0    -1  
$EndComp
$Comp
L Device:CP1 C?
U 1 1 5E0DF5F3
P 3325 1150
F 0 "C?" H 3440 1195 50  0000 L CNN
F 1 "100 uF" H 3440 1105 50  0000 L CNN
F 2 "" H 3325 1150 50  0001 C CNN
F 3 "~" H 3325 1150 50  0001 C CNN
	1    3325 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 1000 3325 1000
Wire Wire Line
	3325 1000 3500 1000
Connection ~ 3325 1000
Wire Wire Line
	3150 1300 3325 1300
Wire Wire Line
	3325 1300 3750 1300
Wire Wire Line
	3750 1300 3750 1150
Connection ~ 3325 1300
$Comp
L power:+5V #PWR?
U 1 1 5E0D195B
P 5100 975
F 0 "#PWR?" H 5100 825 50  0001 C CNN
F 1 "+5V" H 5115 1148 50  0000 C CNN
F 2 "" H 5100 975 50  0001 C CNN
F 3 "" H 5100 975 50  0001 C CNN
	1    5100 975 
	0    1    1    0   
$EndComp
$Comp
L tim_mosfet:PDQ30-Q24-S5-D U?
U 1 1 5E0E3CEB
P 4450 1150
F 0 "U?" V 4865 1150 50  0000 C CNN
F 1 "PDQ30-Q24-S5-D" V 4774 1150 50  0000 C CNN
F 2 "" H 4450 1150 50  0001 C CNN
F 3 "https://www.cui.com/product/resource/pdq30-d.pdf" H 4450 530 50  0001 C CNN
	1    4450 1150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3750 1150 4100 1150
Wire Wire Line
	4000 1000 4050 1000
$Comp
L tim_mosfet:GND_5 #PWR?
U 1 1 5E0E4E17
P 5100 1300
F 0 "#PWR?" H 5100 1050 50  0001 C CNN
F 1 "GND_5" V 5105 1172 50  0000 R CNN
F 2 "" H 5100 1300 50  0001 C CNN
F 3 "" H 5100 1300 50  0001 C CNN
	1    5100 1300
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4800 1300 5100 1300
Wire Wire Line
	4800 975  5100 975 
$Comp
L power:+BATT #PWR?
U 1 1 5E0E5393
P 3175 1775
F 0 "#PWR?" H 3175 1625 50  0001 C CNN
F 1 "+BATT" H 3190 1948 50  0000 C CNN
F 2 "" H 3175 1775 50  0001 C CNN
F 3 "" H 3175 1775 50  0001 C CNN
	1    3175 1775
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3775 2075 3775 1925
Wire Wire Line
	3775 1925 4125 1925
Connection ~ 3350 2075
Wire Wire Line
	3350 2075 3775 2075
$Comp
L power:-BATT #PWR?
U 1 1 5E0E5405
P 3175 2075
F 0 "#PWR?" H 3175 1925 50  0001 C CNN
F 1 "-BATT" H 3190 2248 50  0000 C CNN
F 2 "" H 3175 2075 50  0001 C CNN
F 3 "" H 3175 2075 50  0001 C CNN
	1    3175 2075
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3175 2075 3350 2075
$Comp
L Device:CP1 C?
U 1 1 5E0E5432
P 3350 1925
F 0 "C?" H 3465 1970 50  0000 L CNN
F 1 "100 uF" H 3465 1880 50  0000 L CNN
F 2 "" H 3350 1925 50  0001 C CNN
F 3 "~" H 3350 1925 50  0001 C CNN
	1    3350 1925
	1    0    0    -1  
$EndComp
$Comp
L pspice:INDUCTOR L?
U 1 1 5E0E5454
P 3775 1775
F 0 "L?" H 3775 1989 50  0000 C CNN
F 1 "0.47uH" H 3775 1898 50  0000 C CNN
F 2 "" H 3775 1775 50  0001 C CNN
F 3 "~" H 3775 1775 50  0001 C CNN
	1    3775 1775
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 1775 3525 1775
Wire Wire Line
	4025 1775 4050 1775
Wire Wire Line
	3175 1775 3350 1775
Wire Wire Line
	4825 1750 5125 1750
Connection ~ 3350 1775
$Comp
L tim_mosfet:PDQ30-Q24-S12-D U?
U 1 1 5E0EAF1E
P 4475 1925
F 0 "U?" V 4890 1925 50  0000 C CNN
F 1 "PDQ30-Q24-S12-D" V 4799 1925 50  0000 C CNN
F 2 "" H 4475 1925 50  0001 C CNN
F 3 "https://www.cui.com/product/resource/pdq30-d.pdf" H 4475 1305 50  0001 C CNN
	1    4475 1925
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4825 2075 5125 2075
Wire Wire Line
	4050 1775 4050 2075
Wire Wire Line
	4050 2075 4125 2075
Connection ~ 4050 1775
Wire Wire Line
	4050 1775 4125 1775
Wire Wire Line
	4050 1000 4050 1300
Wire Wire Line
	4050 1300 4100 1300
Connection ~ 4050 1000
Wire Wire Line
	4050 1000 4100 1000
$Comp
L tim_mosfet:GND_12 #PWR?
U 1 1 5E0EE928
P 5125 2075
F 0 "#PWR?" H 5125 1825 50  0001 C CNN
F 1 "GND_12" V 5130 1947 50  0000 R CNN
F 2 "" H 5125 2075 50  0001 C CNN
F 3 "" H 5125 2075 50  0001 C CNN
	1    5125 2075
	0    -1   -1   0   
$EndComp
$Comp
L power:+12V #PWR?
U 1 1 5E0EEFDF
P 5125 1750
F 0 "#PWR?" H 5125 1600 50  0001 C CNN
F 1 "+12V" V 5140 1878 50  0000 L CNN
F 2 "" H 5125 1750 50  0001 C CNN
F 3 "" H 5125 1750 50  0001 C CNN
	1    5125 1750
	0    1    1    0   
$EndComp
$EndSCHEMATC