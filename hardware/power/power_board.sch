<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.5.2">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="1" fill="3" visible="no" active="no"/>
<layer number="15" name="Route15" color="4" fill="6" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="frames" urn="urn:adsk.eagle:library:229">
<description>&lt;b&gt;Frames for Sheet and Layout&lt;/b&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="FRAME_A_L" urn="urn:adsk.eagle:symbol:13882/1" library_version="1">
<frame x1="0" y1="0" x2="279.4" y2="215.9" columns="6" rows="5" layer="94" border-bottom="no"/>
</symbol>
<symbol name="DOCFIELD" urn="urn:adsk.eagle:symbol:13864/1" library_version="1">
<wire x1="0" y1="0" x2="71.12" y2="0" width="0.1016" layer="94"/>
<wire x1="101.6" y1="15.24" x2="87.63" y2="15.24" width="0.1016" layer="94"/>
<wire x1="0" y1="0" x2="0" y2="5.08" width="0.1016" layer="94"/>
<wire x1="0" y1="5.08" x2="71.12" y2="5.08" width="0.1016" layer="94"/>
<wire x1="0" y1="5.08" x2="0" y2="15.24" width="0.1016" layer="94"/>
<wire x1="101.6" y1="15.24" x2="101.6" y2="5.08" width="0.1016" layer="94"/>
<wire x1="71.12" y1="5.08" x2="71.12" y2="0" width="0.1016" layer="94"/>
<wire x1="71.12" y1="5.08" x2="87.63" y2="5.08" width="0.1016" layer="94"/>
<wire x1="71.12" y1="0" x2="101.6" y2="0" width="0.1016" layer="94"/>
<wire x1="87.63" y1="15.24" x2="87.63" y2="5.08" width="0.1016" layer="94"/>
<wire x1="87.63" y1="15.24" x2="0" y2="15.24" width="0.1016" layer="94"/>
<wire x1="87.63" y1="5.08" x2="101.6" y2="5.08" width="0.1016" layer="94"/>
<wire x1="101.6" y1="5.08" x2="101.6" y2="0" width="0.1016" layer="94"/>
<wire x1="0" y1="15.24" x2="0" y2="22.86" width="0.1016" layer="94"/>
<wire x1="101.6" y1="35.56" x2="0" y2="35.56" width="0.1016" layer="94"/>
<wire x1="101.6" y1="35.56" x2="101.6" y2="22.86" width="0.1016" layer="94"/>
<wire x1="0" y1="22.86" x2="101.6" y2="22.86" width="0.1016" layer="94"/>
<wire x1="0" y1="22.86" x2="0" y2="35.56" width="0.1016" layer="94"/>
<wire x1="101.6" y1="22.86" x2="101.6" y2="15.24" width="0.1016" layer="94"/>
<text x="1.27" y="1.27" size="2.54" layer="94">Date:</text>
<text x="12.7" y="1.27" size="2.54" layer="94">&gt;LAST_DATE_TIME</text>
<text x="72.39" y="1.27" size="2.54" layer="94">Sheet:</text>
<text x="86.36" y="1.27" size="2.54" layer="94">&gt;SHEET</text>
<text x="88.9" y="11.43" size="2.54" layer="94">REV:</text>
<text x="1.27" y="19.05" size="2.54" layer="94">TITLE:</text>
<text x="1.27" y="11.43" size="2.54" layer="94">Document Number:</text>
<text x="17.78" y="19.05" size="2.54" layer="94">&gt;DRAWING_NAME</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="FRAME_A_L" urn="urn:adsk.eagle:component:13939/1" prefix="FRAME" uservalue="yes" library_version="1">
<description>&lt;b&gt;FRAME&lt;/b&gt; A Size , 8 1/2 x 11 INCH, Landscape&lt;p&gt;</description>
<gates>
<gate name="G$1" symbol="FRAME_A_L" x="0" y="0" addlevel="always"/>
<gate name="G$2" symbol="DOCFIELD" x="172.72" y="0" addlevel="always"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="timlib" urn="urn:adsk.eagle:library:16152524">
<packages>
<package name="FASTON_MALE_RA_BLADE" urn="urn:adsk.eagle:footprint:16188665/1" locally_modified="yes" library_version="10" library_locally_modified="yes">
<pad name="P$1" x="-2.54" y="0" locked="yes" drill="1.32" diameter="2" shape="long" rot="R90"/>
<pad name="P$2" x="2.54" y="0" locked="yes" drill="1.32" diameter="2" shape="long" rot="R90"/>
</package>
<package name="MOLEX_4_RA" urn="urn:adsk.eagle:footprint:16152610/2" library_version="10" library_locally_modified="yes">
<hole x="0" y="0" drill="3" locked="yes"/>
<pad name="CIRCUIT2" x="-1.5" y="4.318" drill="1.016"/>
<pad name="CIRCUIT1" x="1.5" y="4.32" drill="1.016"/>
<pad name="CIRCUIT3" x="1.5" y="7.32" drill="1.016"/>
<pad name="CIRCUIT4" x="-1.5" y="7.32" drill="1.016"/>
<wire x1="-3.825" y1="-4.6" x2="3.825" y2="-4.6" width="0.001" layer="21"/>
<wire x1="3.825" y1="-4.6" x2="4.825" y2="-3.1" width="0.001" layer="21"/>
<wire x1="4.825" y1="-3.1" x2="4.825" y2="-1.43" width="0.001" layer="21"/>
<wire x1="4.825" y1="-1.43" x2="5.075" y2="-1.43" width="0.001" layer="21"/>
<wire x1="5.075" y1="-1.43" x2="5.075" y2="5.31" width="0.001" layer="21"/>
<wire x1="5.075" y1="5.31" x2="-5.075" y2="5.31" width="0.001" layer="21"/>
<wire x1="-5.075" y1="5.31" x2="-5.075" y2="-1.43" width="0.001" layer="21"/>
<wire x1="-5.075" y1="-1.43" x2="-4.825" y2="-1.43" width="0.001" layer="21"/>
<wire x1="-4.825" y1="-1.43" x2="-4.825" y2="-3.1" width="0.001" layer="21"/>
<wire x1="-4.825" y1="-3.1" x2="-3.825" y2="-4.6" width="0.001" layer="21"/>
</package>
<package name="PDQ30-D" urn="urn:adsk.eagle:footprint:16187993/1" library_version="11">
<wire x1="-12.2" y1="-12.7" x2="12.2" y2="-12.7" width="0.025" layer="21"/>
<wire x1="12.2" y1="-12.7" x2="12.7" y2="-12.2" width="0.025" layer="21" curve="90"/>
<wire x1="12.7" y1="-12.2" x2="12.7" y2="12.2" width="0.025" layer="21"/>
<wire x1="12.7" y1="12.2" x2="12.2" y2="12.7" width="0.025" layer="21" curve="90"/>
<wire x1="12.2" y1="12.7" x2="-12.2" y2="12.7" width="0.025" layer="21"/>
<wire x1="-12.2" y1="12.7" x2="-12.7" y2="12.2" width="0.025" layer="21" curve="90"/>
<wire x1="-12.7" y1="12.2" x2="-12.7" y2="-12.2" width="0.025" layer="21"/>
<wire x1="-12.7" y1="-12.2" x2="-12.2" y2="-12.7" width="0.025" layer="21" curve="90"/>
<circle x="-2.5" y="10.16" radius="0.5" width="0.025" layer="21"/>
<circle x="2.58" y="10.16" radius="0.5" width="0.025" layer="21"/>
<circle x="10.2" y="10.16" radius="0.5" width="0.025" layer="21"/>
<circle x="-10.12" y="-10.16" radius="0.5" width="0.025" layer="21"/>
<circle x="0.04" y="-10.16" radius="0.5" width="0.025" layer="21"/>
<circle x="10.2" y="-10.16" radius="0.5" width="0.025" layer="21"/>
<pad name="P$1" x="-2.54" y="10.16" drill="1.3" diameter="2"/>
<pad name="P$2" x="2.54" y="10.16" drill="1.3" diameter="2"/>
<pad name="P$3" x="-10.16" y="-10.16" drill="1.3" diameter="2"/>
<pad name="P$4" x="0" y="-10.16" drill="1.3" diameter="2"/>
<pad name="P$5" x="10.16" y="-10.16" drill="1.3" diameter="2"/>
<pad name="P$6" x="10.16" y="10.16" drill="1.3" diameter="2"/>
</package>
</packages>
<packages3d>
<package3d name="FASTON_MALE_RA_BLADE" urn="urn:adsk.eagle:package:16188667/2" type="model" library_version="10" library_locally_modified="yes">
<packageinstances>
<packageinstance name="FASTON_MALE_RA_BLADE"/>
</packageinstances>
</package3d>
<package3d name="MOLEX_4_RA" urn="urn:adsk.eagle:package:16152611/3" type="model" library_version="10" library_locally_modified="yes">
<packageinstances>
<packageinstance name="MOLEX_4_RA"/>
</packageinstances>
</package3d>
<package3d name="PDQ30-D" urn="urn:adsk.eagle:package:16187995/2" type="model" library_version="11">
<packageinstances>
<packageinstance name="PDQ30-D"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="BATT_TERM" urn="urn:adsk.eagle:symbol:16188666/1" library_version="10" library_locally_modified="yes">
<pin name="PIN1" x="-5.08" y="0" length="middle" direction="sup"/>
<circle x="0" y="0" radius="2.54" width="0.254" layer="94"/>
</symbol>
<symbol name="MOLEX_4" urn="urn:adsk.eagle:symbol:16175099/2" library_version="10" library_locally_modified="yes">
<pin name="CONN1" x="-10.16" y="5.08" length="middle" direction="pwr"/>
<pin name="CONN2" x="-10.16" y="2.54" length="middle" direction="pwr"/>
<pin name="CONN3" x="-10.16" y="0" length="middle" direction="pwr"/>
<pin name="CONN4" x="-10.16" y="-2.54" length="middle" direction="pwr"/>
<wire x1="-5.08" y1="7.62" x2="2.54" y2="7.62" width="0.254" layer="94"/>
<wire x1="2.54" y1="7.62" x2="2.54" y2="-5.08" width="0.254" layer="94"/>
<wire x1="2.54" y1="-5.08" x2="-5.08" y2="-5.08" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-5.08" x2="-5.08" y2="-2.54" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-2.54" x2="-5.08" y2="0" width="0.254" layer="94"/>
<wire x1="-5.08" y1="0" x2="-5.08" y2="2.54" width="0.254" layer="94"/>
<wire x1="-5.08" y1="2.54" x2="-5.08" y2="5.08" width="0.254" layer="94"/>
<wire x1="-5.08" y1="5.08" x2="-5.08" y2="7.62" width="0.254" layer="94"/>
<wire x1="-5.08" y1="5.08" x2="-2.54" y2="5.08" width="0.254" layer="94"/>
<wire x1="-5.08" y1="2.54" x2="-2.54" y2="2.54" width="0.254" layer="94"/>
<wire x1="-5.08" y1="0" x2="-2.54" y2="0" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-2.54" x2="-2.54" y2="-2.54" width="0.254" layer="94"/>
<wire x1="-2.54" y1="5.08" x2="0" y2="5.08" width="0.508" layer="94"/>
<wire x1="-2.54" y1="2.54" x2="0" y2="2.54" width="0.508" layer="94"/>
<wire x1="-2.54" y1="0" x2="0" y2="0" width="0.508" layer="94"/>
<wire x1="-2.54" y1="-2.54" x2="0" y2="-2.54" width="0.508" layer="94"/>
<text x="-5.08" y="7.874" size="1.27" layer="95" font="vector">&gt;NAME</text>
<text x="-5.08" y="-7.62" size="1.27" layer="96" font="vector">&gt;VALUE</text>
</symbol>
<symbol name="GND_12V" library_version="10" library_locally_modified="yes">
<pin name="GND_12V" x="-2.54" y="0" length="short" direction="sup"/>
<wire x1="0" y1="2.54" x2="0" y2="-2.54" width="0.508" layer="94"/>
</symbol>
<symbol name="GND_5V" library_version="10" library_locally_modified="yes">
<pin name="GND_5V" x="-2.54" y="0" length="short" direction="sup"/>
<wire x1="0" y1="2.54" x2="0" y2="-2.54" width="0.508" layer="94"/>
</symbol>
<symbol name="ISO_+5V" library_version="10" library_locally_modified="yes">
<wire x1="1.27" y1="-1.905" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-1.27" y2="-1.905" width="0.254" layer="94"/>
<wire x1="1.27" y1="-0.635" x2="0" y2="1.27" width="0.254" layer="94"/>
<wire x1="0" y1="1.27" x2="-1.27" y2="-0.635" width="0.254" layer="94"/>
<text x="-2.54" y="-5.08" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="ISO_+5V" x="0" y="-2.54" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
<symbol name="ISO_+12V" library_version="10" library_locally_modified="yes">
<wire x1="1.27" y1="-1.905" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-1.27" y2="-1.905" width="0.254" layer="94"/>
<wire x1="1.27" y1="-0.635" x2="0" y2="1.27" width="0.254" layer="94"/>
<wire x1="0" y1="1.27" x2="-1.27" y2="-0.635" width="0.254" layer="94"/>
<text x="-2.54" y="-5.08" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="ISO_+12V" x="0" y="-2.54" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
<symbol name="PDQ30-D" urn="urn:adsk.eagle:symbol:16187994/2" library_version="11">
<pin name="+VIN" x="-17.78" y="7.62" length="middle" direction="pwr"/>
<pin name="REMOTE" x="-17.78" y="-7.62" length="middle"/>
<pin name="-VIN" x="-17.78" y="0" length="middle" direction="pwr"/>
<pin name="-VOUT" x="17.78" y="-7.62" length="middle" direction="sup" rot="R180"/>
<pin name="TRIM" x="17.78" y="0" length="middle" rot="R180"/>
<pin name="+VOUT" x="17.78" y="7.62" length="middle" direction="sup" rot="R180"/>
<wire x1="-12.7" y1="12.7" x2="12.7" y2="12.7" width="0.254" layer="94"/>
<wire x1="12.7" y1="12.7" x2="12.7" y2="-12.7" width="0.254" layer="94"/>
<wire x1="12.7" y1="-12.7" x2="-12.7" y2="-12.7" width="0.254" layer="94"/>
<wire x1="-12.7" y1="-12.7" x2="-12.7" y2="12.7" width="0.254" layer="94"/>
<text x="-12.7" y="12.954" size="1.778" layer="95">&gt;NAME</text>
<text x="-12.7" y="-15.24" size="1.778" layer="96">&gt;VALUE</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="FASTON_MALE_RA_BLADE" urn="urn:adsk.eagle:component:16188674/1" prefix="J" library_version="10" library_locally_modified="yes">
<gates>
<gate name="G$1" symbol="BATT_TERM" x="0" y="0"/>
</gates>
<devices>
<device name="" package="FASTON_MALE_RA_BLADE">
<connects>
<connect gate="G$1" pin="PIN1" pad="P$1 P$2"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:16188667/2"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="MOLEX_4_RA" urn="urn:adsk.eagle:component:16152612/5" prefix="J" uservalue="yes" library_version="10" library_locally_modified="yes">
<description>Molex 4 pin right angle 

430450402

&lt;p&gt;&lt;a href="https://www.molex.com/pdm_docs/sd/430450402_sd.pdf"&gt;Datasheet&lt;/a&gt;</description>
<gates>
<gate name="G$1" symbol="MOLEX_4" x="0" y="0"/>
</gates>
<devices>
<device name="" package="MOLEX_4_RA">
<connects>
<connect gate="G$1" pin="CONN1" pad="CIRCUIT1"/>
<connect gate="G$1" pin="CONN2" pad="CIRCUIT2"/>
<connect gate="G$1" pin="CONN3" pad="CIRCUIT3"/>
<connect gate="G$1" pin="CONN4" pad="CIRCUIT4"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:16152611/3"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="GND_12V" library_version="10" library_locally_modified="yes">
<gates>
<gate name="G$1" symbol="GND_12V" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="GND_5V" uservalue="yes" library_version="10" library_locally_modified="yes">
<gates>
<gate name="G$1" symbol="GND_5V" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="ISO_+5V" library_version="10" library_locally_modified="yes">
<gates>
<gate name="G$1" symbol="ISO_+5V" x="0" y="2.54"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="ISO_+12V" library_version="10" library_locally_modified="yes">
<gates>
<gate name="G$1" symbol="ISO_+12V" x="0" y="2.54"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="PDQ30-Q24-S5-D" urn="urn:adsk.eagle:component:16188019/3" prefix="U" library_version="11">
<description>PDQ30-Q24-S5-D Isolated 5v DC-DC  supply

&lt;p&gt;&lt;a href="https://www.cui.com/product/resource/pdq30-d.pdf"&gt;Datasheet&lt;/a&gt;</description>
<gates>
<gate name="G$1" symbol="PDQ30-D" x="0" y="0"/>
</gates>
<devices>
<device name="" package="PDQ30-D">
<connects>
<connect gate="G$1" pin="+VIN" pad="P$1"/>
<connect gate="G$1" pin="+VOUT" pad="P$3"/>
<connect gate="G$1" pin="-VIN" pad="P$2"/>
<connect gate="G$1" pin="-VOUT" pad="P$5"/>
<connect gate="G$1" pin="REMOTE" pad="P$6"/>
<connect gate="G$1" pin="TRIM" pad="P$4"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:16187995/2"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="PDQ30-Q24-S12-D" urn="urn:adsk.eagle:component:16188018/3" locally_modified="yes" prefix="U" library_version="11" library_locally_modified="yes">
<description>PDQ30-Q24-S12-D Isolated 12v DC-DC  supply

&lt;p&gt;&lt;a href="https://www.cui.com/product/resource/pdq30-d.pdf"&gt;Datasheet&lt;/a&gt;</description>
<gates>
<gate name="G$1" symbol="PDQ30-D" x="0" y="0"/>
</gates>
<devices>
<device name="" package="PDQ30-D">
<connects>
<connect gate="G$1" pin="+VIN" pad="P$1"/>
<connect gate="G$1" pin="+VOUT" pad="P$3"/>
<connect gate="G$1" pin="-VIN" pad="P$2"/>
<connect gate="G$1" pin="-VOUT" pad="P$5"/>
<connect gate="G$1" pin="REMOTE" pad="P$6"/>
<connect gate="G$1" pin="TRIM" pad="P$4"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:16187995/2"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply1" urn="urn:adsk.eagle:library:371">
<description>&lt;b&gt;Supply Symbols&lt;/b&gt;&lt;p&gt;
 GND, VCC, 0V, +5V, -5V, etc.&lt;p&gt;
 Please keep in mind, that these devices are necessary for the
 automatic wiring of the supply signals.&lt;p&gt;
 The pin name defined in the symbol is identical to the net which is to be wired automatically.&lt;p&gt;
 In this library the device names are the same as the pin names of the symbols, therefore the correct signal names appear next to the supply symbols in the schematic.&lt;p&gt;
 &lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="GND" urn="urn:adsk.eagle:symbol:26925/1" library_version="1">
<wire x1="-1.905" y1="0" x2="1.905" y2="0" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
<symbol name="+24V" urn="urn:adsk.eagle:symbol:26935/1" library_version="1">
<wire x1="1.27" y1="-0.635" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-1.27" y2="-0.635" width="0.254" layer="94"/>
<wire x1="1.27" y1="-0.635" x2="0" y2="1.27" width="0.254" layer="94"/>
<wire x1="0" y1="1.27" x2="-1.27" y2="-0.635" width="0.254" layer="94"/>
<text x="-2.54" y="-5.08" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="+24V" x="0" y="-2.54" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="GND" urn="urn:adsk.eagle:component:26954/1" prefix="GND" library_version="1">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="GND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="+24V" urn="urn:adsk.eagle:component:26964/1" prefix="P+" library_version="1">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="+24V" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
<class number="1" name="High current" width="0.762" drill="0">
</class>
</classes>
<groups>
<schematic_group name="BATT_TERM"/>
<schematic_group name="ISO_POWER_OUT"/>
</groups>
<parts>
<part name="FRAME1" library="frames" library_urn="urn:adsk.eagle:library:229" deviceset="FRAME_A_L" device=""/>
<part name="J1" library="timlib" library_urn="urn:adsk.eagle:library:16152524" deviceset="FASTON_MALE_RA_BLADE" device="" package3d_urn="urn:adsk.eagle:package:16188667/2"/>
<part name="J2" library="timlib" library_urn="urn:adsk.eagle:library:16152524" deviceset="FASTON_MALE_RA_BLADE" device="" package3d_urn="urn:adsk.eagle:package:16188667/2"/>
<part name="GND1" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="P+1" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="+24V" device=""/>
<part name="J3" library="timlib" library_urn="urn:adsk.eagle:library:16152524" deviceset="MOLEX_4_RA" device="" package3d_urn="urn:adsk.eagle:package:16152611/3" value="12v"/>
<part name="J4" library="timlib" library_urn="urn:adsk.eagle:library:16152524" deviceset="MOLEX_4_RA" device="" package3d_urn="urn:adsk.eagle:package:16152611/3" value="5v"/>
<part name="U$1" library="timlib" library_urn="urn:adsk.eagle:library:16152524" deviceset="GND_12V" device=""/>
<part name="U$2" library="timlib" library_urn="urn:adsk.eagle:library:16152524" deviceset="GND_5V" device=""/>
<part name="U$3" library="timlib" library_urn="urn:adsk.eagle:library:16152524" deviceset="ISO_+5V" device=""/>
<part name="U$4" library="timlib" library_urn="urn:adsk.eagle:library:16152524" deviceset="ISO_+12V" device=""/>
<part name="U1" library="timlib" library_urn="urn:adsk.eagle:library:16152524" deviceset="PDQ30-Q24-S5-D" device="" package3d_urn="urn:adsk.eagle:package:16187995/2"/>
<part name="U2" library="timlib" library_urn="urn:adsk.eagle:library:16152524" deviceset="PDQ30-Q24-S12-D" device="" package3d_urn="urn:adsk.eagle:package:16187995/2"/>
<part name="P+2" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="+24V" device=""/>
<part name="GND2" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="U$5" library="timlib" library_urn="urn:adsk.eagle:library:16152524" deviceset="ISO_+5V" device=""/>
<part name="U$6" library="timlib" library_urn="urn:adsk.eagle:library:16152524" deviceset="GND_5V" device=""/>
<part name="U$7" library="timlib" library_urn="urn:adsk.eagle:library:16152524" deviceset="GND_12V" device=""/>
<part name="U$8" library="timlib" library_urn="urn:adsk.eagle:library:16152524" deviceset="ISO_+12V" device=""/>
<part name="P+3" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="+24V" device=""/>
<part name="GND3" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="FRAME1" gate="G$1" x="0" y="0" smashed="yes"/>
<instance part="FRAME1" gate="G$2" x="172.72" y="0" smashed="yes">
<attribute name="LAST_DATE_TIME" x="185.42" y="1.27" size="2.54" layer="94"/>
<attribute name="SHEET" x="259.08" y="1.27" size="2.54" layer="94"/>
<attribute name="DRAWING_NAME" x="190.5" y="19.05" size="2.54" layer="94"/>
</instance>
<instance part="J1" gate="G$1" x="20.32" y="200.66" smashed="yes" grouprefs="BATT_TERM"/>
<instance part="J2" gate="G$1" x="20.32" y="193.04" smashed="yes" grouprefs="BATT_TERM"/>
<instance part="GND1" gate="1" x="10.16" y="193.04" smashed="yes" rot="R270" grouprefs="BATT_TERM">
<attribute name="VALUE" x="7.62" y="195.58" size="1.778" layer="96" rot="R270"/>
</instance>
<instance part="P+1" gate="1" x="10.16" y="200.66" smashed="yes" rot="R90" grouprefs="BATT_TERM">
<attribute name="VALUE" x="15.24" y="198.12" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="J3" gate="G$1" x="66.04" y="190.5" smashed="yes" grouprefs="ISO_POWER_OUT">
<attribute name="NAME" x="60.96" y="198.374" size="1.27" layer="95" font="vector"/>
<attribute name="VALUE" x="60.96" y="182.88" size="1.27" layer="96" font="vector"/>
</instance>
<instance part="J4" gate="G$1" x="101.6" y="190.5" smashed="yes" grouprefs="ISO_POWER_OUT">
<attribute name="NAME" x="96.52" y="198.374" size="1.27" layer="95" font="vector"/>
<attribute name="VALUE" x="96.52" y="182.88" size="1.27" layer="96" font="vector"/>
</instance>
<instance part="U$1" gate="G$1" x="40.64" y="185.42" smashed="yes" rot="R270" grouprefs="ISO_POWER_OUT"/>
<instance part="U$2" gate="G$1" x="76.2" y="185.42" smashed="yes" rot="R270" grouprefs="ISO_POWER_OUT"/>
<instance part="U$3" gate="G$1" x="76.2" y="198.12" smashed="yes" grouprefs="ISO_POWER_OUT">
<attribute name="VALUE" x="73.66" y="193.04" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="U$4" gate="G$1" x="40.64" y="198.12" smashed="yes" grouprefs="ISO_POWER_OUT">
<attribute name="VALUE" x="38.1" y="193.04" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="U1" gate="G$1" x="55.88" y="139.7" smashed="yes">
<attribute name="NAME" x="43.18" y="152.654" size="1.778" layer="95"/>
<attribute name="VALUE" x="43.18" y="124.46" size="1.778" layer="96"/>
</instance>
<instance part="U2" gate="G$1" x="55.88" y="99.06" smashed="yes">
<attribute name="NAME" x="43.18" y="112.014" size="1.778" layer="95"/>
<attribute name="VALUE" x="43.18" y="83.82" size="1.778" layer="96"/>
</instance>
<instance part="P+2" gate="1" x="33.02" y="154.94" smashed="yes">
<attribute name="VALUE" x="30.48" y="149.86" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="GND2" gate="1" x="33.02" y="132.08" smashed="yes">
<attribute name="VALUE" x="30.48" y="129.54" size="1.778" layer="96"/>
</instance>
<instance part="U$5" gate="G$1" x="78.74" y="154.94" smashed="yes">
<attribute name="VALUE" x="76.2" y="149.86" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="U$6" gate="G$1" x="78.74" y="127" smashed="yes" rot="R270"/>
<instance part="U$7" gate="G$1" x="78.74" y="83.82" smashed="yes" rot="R270"/>
<instance part="U$8" gate="G$1" x="78.74" y="114.3" smashed="yes">
<attribute name="VALUE" x="76.2" y="109.22" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="P+3" gate="1" x="33.02" y="114.3" smashed="yes">
<attribute name="VALUE" x="30.48" y="109.22" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="GND3" gate="1" x="33.02" y="91.44" smashed="yes">
<attribute name="VALUE" x="30.48" y="88.9" size="1.778" layer="96"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="+24V" class="1">
<segment>
<pinref part="J1" gate="G$1" pin="PIN1"/>
<pinref part="P+1" gate="1" pin="+24V"/>
<wire x1="15.24" y1="200.66" x2="12.7" y2="200.66" width="0.1524" layer="91" grouprefs="BATT_TERM"/>
</segment>
<segment>
<pinref part="P+2" gate="1" pin="+24V"/>
<wire x1="33.02" y1="152.4" x2="33.02" y2="147.32" width="0.1524" layer="91"/>
<pinref part="U1" gate="G$1" pin="+VIN"/>
<wire x1="33.02" y1="147.32" x2="38.1" y2="147.32" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="P+3" gate="1" pin="+24V"/>
<wire x1="33.02" y1="111.76" x2="33.02" y2="106.68" width="0.1524" layer="91"/>
<wire x1="33.02" y1="106.68" x2="38.1" y2="106.68" width="0.1524" layer="91"/>
<pinref part="U2" gate="G$1" pin="+VIN"/>
</segment>
</net>
<net name="GND_12V" class="0">
<segment>
<pinref part="J3" gate="G$1" pin="CONN3"/>
<wire x1="55.88" y1="190.5" x2="48.26" y2="190.5" width="0.1524" layer="91" grouprefs="ISO_POWER_OUT"/>
<wire x1="48.26" y1="190.5" x2="40.64" y2="190.5" width="0.1524" layer="91" grouprefs="ISO_POWER_OUT"/>
<wire x1="40.64" y1="190.5" x2="40.64" y2="187.96" width="0.1524" layer="91" grouprefs="ISO_POWER_OUT"/>
<pinref part="U$1" gate="G$1" pin="GND_12V"/>
<pinref part="J3" gate="G$1" pin="CONN1"/>
<wire x1="55.88" y1="195.58" x2="48.26" y2="195.58" width="0.1524" layer="91" grouprefs="ISO_POWER_OUT"/>
<wire x1="48.26" y1="195.58" x2="48.26" y2="190.5" width="0.1524" layer="91" grouprefs="ISO_POWER_OUT"/>
<junction x="48.26" y="190.5" grouprefs="ISO_POWER_OUT"/>
</segment>
<segment>
<pinref part="U2" gate="G$1" pin="-VOUT"/>
<wire x1="73.66" y1="91.44" x2="78.74" y2="91.44" width="0.1524" layer="91"/>
<pinref part="U$7" gate="G$1" pin="GND_12V"/>
<wire x1="78.74" y1="91.44" x2="78.74" y2="86.36" width="0.1524" layer="91"/>
</segment>
</net>
<net name="GND_5V" class="0">
<segment>
<pinref part="J4" gate="G$1" pin="CONN1"/>
<wire x1="91.44" y1="195.58" x2="83.82" y2="195.58" width="0.1524" layer="91" grouprefs="ISO_POWER_OUT"/>
<wire x1="83.82" y1="195.58" x2="83.82" y2="190.5" width="0.1524" layer="91" grouprefs="ISO_POWER_OUT"/>
<pinref part="J4" gate="G$1" pin="CONN3"/>
<wire x1="83.82" y1="190.5" x2="91.44" y2="190.5" width="0.1524" layer="91" grouprefs="ISO_POWER_OUT"/>
<wire x1="83.82" y1="190.5" x2="76.2" y2="190.5" width="0.1524" layer="91" grouprefs="ISO_POWER_OUT"/>
<junction x="83.82" y="190.5" grouprefs="ISO_POWER_OUT"/>
<wire x1="76.2" y1="190.5" x2="76.2" y2="187.96" width="0.1524" layer="91" grouprefs="ISO_POWER_OUT"/>
<pinref part="U$2" gate="G$1" pin="GND_5V"/>
</segment>
<segment>
<pinref part="U$6" gate="G$1" pin="GND_5V"/>
<wire x1="78.74" y1="129.54" x2="78.74" y2="132.08" width="0.1524" layer="91"/>
<pinref part="U1" gate="G$1" pin="-VOUT"/>
<wire x1="78.74" y1="132.08" x2="73.66" y2="132.08" width="0.1524" layer="91"/>
</segment>
</net>
<net name="ISO_+12V" class="0">
<segment>
<pinref part="J3" gate="G$1" pin="CONN2"/>
<wire x1="55.88" y1="193.04" x2="50.8" y2="193.04" width="0.1524" layer="91" grouprefs="ISO_POWER_OUT"/>
<wire x1="50.8" y1="193.04" x2="50.8" y2="187.96" width="0.1524" layer="91" grouprefs="ISO_POWER_OUT"/>
<pinref part="J3" gate="G$1" pin="CONN4"/>
<wire x1="50.8" y1="187.96" x2="55.88" y2="187.96" width="0.1524" layer="91" grouprefs="ISO_POWER_OUT"/>
<wire x1="50.8" y1="193.04" x2="40.64" y2="193.04" width="0.1524" layer="91" grouprefs="ISO_POWER_OUT"/>
<junction x="50.8" y="193.04" grouprefs="ISO_POWER_OUT"/>
<wire x1="40.64" y1="193.04" x2="40.64" y2="195.58" width="0.1524" layer="91" grouprefs="ISO_POWER_OUT"/>
<pinref part="U$4" gate="G$1" pin="ISO_+12V"/>
</segment>
<segment>
<pinref part="U$8" gate="G$1" pin="ISO_+12V"/>
<wire x1="78.74" y1="111.76" x2="78.74" y2="106.68" width="0.1524" layer="91"/>
<pinref part="U2" gate="G$1" pin="+VOUT"/>
<wire x1="78.74" y1="106.68" x2="73.66" y2="106.68" width="0.1524" layer="91"/>
</segment>
</net>
<net name="ISO_+5V" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="ISO_+5V"/>
<wire x1="76.2" y1="195.58" x2="76.2" y2="193.04" width="0.1524" layer="91" grouprefs="ISO_POWER_OUT"/>
<pinref part="J4" gate="G$1" pin="CONN2"/>
<wire x1="76.2" y1="193.04" x2="86.36" y2="193.04" width="0.1524" layer="91" grouprefs="ISO_POWER_OUT"/>
<pinref part="J4" gate="G$1" pin="CONN4"/>
<wire x1="86.36" y1="193.04" x2="91.44" y2="193.04" width="0.1524" layer="91" grouprefs="ISO_POWER_OUT"/>
<wire x1="91.44" y1="187.96" x2="86.36" y2="187.96" width="0.1524" layer="91" grouprefs="ISO_POWER_OUT"/>
<wire x1="86.36" y1="187.96" x2="86.36" y2="193.04" width="0.1524" layer="91" grouprefs="ISO_POWER_OUT"/>
<junction x="86.36" y="193.04" grouprefs="ISO_POWER_OUT"/>
</segment>
<segment>
<pinref part="U1" gate="G$1" pin="+VOUT"/>
<wire x1="73.66" y1="147.32" x2="78.74" y2="147.32" width="0.1524" layer="91"/>
<pinref part="U$5" gate="G$1" pin="ISO_+5V"/>
<wire x1="78.74" y1="147.32" x2="78.74" y2="152.4" width="0.1524" layer="91"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="-VIN"/>
<pinref part="GND2" gate="1" pin="GND"/>
<wire x1="38.1" y1="139.7" x2="33.02" y2="139.7" width="0.1524" layer="91"/>
<wire x1="33.02" y1="139.7" x2="33.02" y2="134.62" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND3" gate="1" pin="GND"/>
<wire x1="38.1" y1="99.06" x2="33.02" y2="99.06" width="0.1524" layer="91"/>
<wire x1="33.02" y1="99.06" x2="33.02" y2="93.98" width="0.1524" layer="91"/>
<pinref part="U2" gate="G$1" pin="-VIN"/>
</segment>
<segment>
<pinref part="J2" gate="G$1" pin="PIN1"/>
<pinref part="GND1" gate="1" pin="GND"/>
<wire x1="15.24" y1="193.04" x2="12.7" y2="193.04" width="0.1524" layer="91" grouprefs="BATT_TERM"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports the association of 3D packages
with devices in libraries, schematics, and board files. Those 3D
packages will not be understood (or retained) with this version.
</note>
<note version="9.5" severity="warning">
Since Version 9.5, EAGLE supports persistent groups with
schematics, and board files. Those persistent groups
will not be understood (or retained) with this version.
</note>
<note version="8.5" severity="warning">
Since Version 8.5, EAGLE supports locking for holes, vias, wires and polygons. 
The locking property on all objects of these types will not be understood in this version. 
</note>
</compatibility>
</eagle>
