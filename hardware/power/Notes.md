Bkatz design:

_Robot power supply board, which generates an isolated 5V logic supply distributes power to the legs and computer, and has pass transistors for turning on and off motor power and logic power. The underside of the power supply (right) has board mount FASTON terminals which mate with the spades built into the battery._

 - [KHHD006A0A41Z dc-dc transformer board](https://www.mouser.com/ProductDetail/ABB-Embedded-Power/KHHD006A0A41Z?qs=613q%2FuFLIwR01m7qvhkVZQ%3D%3D)
 - [FASTON male type 1217156-1](https://www.mouser.com/ProductDetail/TE-Connectivity-AMP/1217156-1?qs=sGAEpiMZZMvz8LftK4jeriFVV82M7NYm7Fj9uy51a%252Bk%3D)

# Potential power isolators for 5V circuit

- [Murata UWS-5/10-Q48NM-C](https://www.digikey.com/product-detail/en/murata-power-solutions-inc/UWS-5-10-Q48NM-C/811-2364-2-ND/3041705)
  - supposedly is 50W (??)
  - [datasheet](https://power.murata.com/pub/data/power/uws.pdf)
- [KHHD006A0A41Z dc-dc transformer board](https://www.mouser.com/ProductDetail/ABB-Embedded-Power/KHHD006A0A41Z?qs=613q%2FuFLIwR01m7qvhkVZQ%3D%3D)
  - 5v 6A 30W
  - [datasheet](https://www.mouser.com/datasheet/2/167/KHHD006A0A-473808.pdf)
  - [$36 from digikey](https://www.digikey.com/products/en?keywords=KHHD006A0A41Z)

Thinking of going with KHHD010A0A41Z due to OCP/OVP. [Mouser](https://www.mouser.com/ProductDetail/ABB-Embedded-Power/KHHD010A0A41Z?qs=%2Fha2pyFaduhRbhEp%2Fp9xfelzYGS0U7KA7NVvaepaCllW8M91y3XbXw%3D%3D) and [Digikey](https://www.digikey.com/product-detail/en/abb-embedded-power/KHHD010A0A41Z/555-1297-ND/3878331)


# MOSFET

Mainly two options:

- [Infineon IAUT300N10S5N015](https://www.digikey.com/product-detail/en/infineon-technologies/IAUT300N10S5N015ATMA1/IAUT300N10S5N015ATMA1CT-ND/8818777) ([datasheet](https://www.infineon.com/dgdl/Infineon-IAUT300N10S5N015-DS-v01_00-EN.pdf?fileId=5546d4625ee5d4cd015f2469d7203245))
- [Fairchild FDBL0200N100](https://www.digikey.com/product-detail/en/on-semiconductor/FDBL0200N100/FDBL0200N100OSCT-ND/9086508) ([datasheet](https://www.onsemi.com/pub/Collateral/FDBL0200N100-D.pdf))

Probably going to be IAUT300N10S5N015, simply for lower Rds.

- Falstad beta: 39.2156862745098
- at Id 275ua, Vgs(th) = 3
  
Turns out the auto one isn't very common. will use IPT015N10N5 instead (it's non-auto sibling)

# Power connectors

Mini-Fit Jr is the type ben used in the corner.

# 12v regulator

- [ZXTR2005K](https://www.diodes.com/assets/Datasheets/ZXTR2005K.pdf) - 100v>5v, 50ma 

# P Mosfet

- [BSS84-7-F](https://www.digikey.com/product-detail/en/diodes-incorporated/BSS84-7-F/BSS84-FDICT-ND/717844)

# Pot

- [TC33X-2-204E](https://www.digikey.com/product-detail/en/bourns-inc/TC33X-2-204E/TC33X-2-204EDKR-ND/3438442)

# Darlington

- [MMBTA28-7-F](https://www.digikey.com/product-detail/en/diodes-incorporated/MMBTA28-7-F/MMBTA28-FDIDKR-ND/1837082)

# Flip-flop
- [SN74LVC1G175](https://www.digikey.com/product-detail/en/texas-instruments/SN74LVC1G175DBVR/296-17617-6-ND/1849578)