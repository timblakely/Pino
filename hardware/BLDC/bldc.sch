<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.6.1">
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
<library name="_T_ic" urn="urn:adsk.eagle:library:19571245">
<packages>
<package name="QFN-16_3X3" urn="urn:adsk.eagle:footprint:19571297/2" library_version="5" library_locally_modified="yes">
<smd name="PAD" x="0" y="0" dx="1.7" dy="1.7" layer="1"/>
<smd name="1" x="-1.45" y="0.75" dx="0.7" dy="0.25" layer="1"/>
<smd name="2" x="-1.45" y="0.25" dx="0.7" dy="0.25" layer="1"/>
<smd name="3" x="-1.45" y="-0.25" dx="0.7" dy="0.25" layer="1"/>
<smd name="4" x="-1.45" y="-0.75" dx="0.7" dy="0.25" layer="1"/>
<smd name="5" x="-0.75" y="-1.45" dx="0.7" dy="0.25" layer="1" rot="R90"/>
<smd name="6" x="-0.25" y="-1.45" dx="0.7" dy="0.25" layer="1" rot="R90"/>
<smd name="7" x="0.25" y="-1.45" dx="0.7" dy="0.25" layer="1" rot="R90"/>
<smd name="8" x="0.75" y="-1.45" dx="0.7" dy="0.25" layer="1" rot="R90"/>
<smd name="9" x="1.45" y="-0.75" dx="0.7" dy="0.25" layer="1" rot="R180"/>
<smd name="10" x="1.45" y="-0.25" dx="0.7" dy="0.25" layer="1" rot="R180"/>
<smd name="11" x="1.45" y="0.25" dx="0.7" dy="0.25" layer="1" rot="R180"/>
<smd name="12" x="1.45" y="0.75" dx="0.7" dy="0.25" layer="1" rot="R180"/>
<smd name="13" x="0.75" y="1.45" dx="0.7" dy="0.25" layer="1" rot="R270"/>
<smd name="14" x="0.25" y="1.45" dx="0.7" dy="0.25" layer="1" rot="R270"/>
<smd name="15" x="-0.25" y="1.45" dx="0.7" dy="0.25" layer="1" rot="R270"/>
<smd name="16" x="-0.75" y="1.45" dx="0.7" dy="0.25" layer="1" rot="R270"/>
<text x="-3.15" y="1.99" size="1.27" layer="25">&gt;NAME</text>
<text x="-3.2" y="-3.15" size="1.27" layer="27">&gt;VALUE</text>
<wire x1="-1.5" y1="1.5" x2="-1.1" y2="1.5" width="0.127" layer="21"/>
<wire x1="-1.1" y1="1.5" x2="1.5" y2="1.5" width="0.127" layer="21"/>
<wire x1="1.5" y1="1.5" x2="1.5" y2="-1.5" width="0.127" layer="21"/>
<wire x1="1.5" y1="-1.5" x2="-1.5" y2="-1.5" width="0.127" layer="21"/>
<wire x1="-1.5" y1="-1.5" x2="-1.5" y2="1.1" width="0.127" layer="21"/>
<wire x1="-1.5" y1="1.1" x2="-1.5" y2="1.5" width="0.127" layer="21"/>
<wire x1="-1.5" y1="1.1" x2="-1.1" y2="1.5" width="0.127" layer="21"/>
<circle x="-1.7" y="1.7" radius="0.070709375" width="0.127" layer="21"/>
</package>
<package name="VQFN-48_7X7" urn="urn:adsk.eagle:footprint:19571843/2" library_version="5">
<wire x1="-3.5" y1="3.5" x2="3.5" y2="3.5" width="0.127" layer="21"/>
<wire x1="3.5" y1="3.5" x2="3.5" y2="-3.5" width="0.127" layer="21"/>
<wire x1="3.5" y1="-3.5" x2="-3.5" y2="-3.5" width="0.127" layer="21"/>
<wire x1="-3.5" y1="-3.5" x2="-3.5" y2="3.5" width="0.127" layer="21"/>
<wire x1="-3.5" y1="3.05" x2="-3.05" y2="3.5" width="0.127" layer="27"/>
<smd name="PAD" x="0" y="0" dx="5.15" dy="5.15" layer="1" cream="no"/>
<smd name="1" x="-3.4" y="2.75" dx="0.6" dy="0.24" layer="1"/>
<smd name="2" x="-3.4" y="2.25" dx="0.6" dy="0.24" layer="1" rot="R180"/>
<smd name="3" x="-3.4" y="1.75" dx="0.6" dy="0.24" layer="1" rot="R180"/>
<smd name="4" x="-3.4" y="1.25" dx="0.6" dy="0.24" layer="1" rot="R180"/>
<smd name="5" x="-3.4" y="0.75" dx="0.6" dy="0.24" layer="1" rot="R180"/>
<smd name="6" x="-3.4" y="0.25" dx="0.6" dy="0.24" layer="1" rot="R180"/>
<smd name="7" x="-3.4" y="-0.25" dx="0.6" dy="0.24" layer="1" rot="R180"/>
<smd name="8" x="-3.4" y="-0.75" dx="0.6" dy="0.24" layer="1" rot="R180"/>
<smd name="9" x="-3.4" y="-1.25" dx="0.6" dy="0.24" layer="1" rot="R180"/>
<smd name="10" x="-3.4" y="-1.75" dx="0.6" dy="0.24" layer="1" rot="R180"/>
<smd name="11" x="-3.4" y="-2.25" dx="0.6" dy="0.24" layer="1" rot="R180"/>
<smd name="12" x="-3.4" y="-2.75" dx="0.6" dy="0.24" layer="1" rot="R180"/>
<smd name="13" x="-2.75" y="-3.4" dx="0.6" dy="0.24" layer="1" rot="R90"/>
<smd name="14" x="-2.25" y="-3.4" dx="0.6" dy="0.24" layer="1" rot="R270"/>
<smd name="15" x="-1.75" y="-3.4" dx="0.6" dy="0.24" layer="1" rot="R270"/>
<smd name="16" x="-1.25" y="-3.4" dx="0.6" dy="0.24" layer="1" rot="R270"/>
<smd name="17" x="-0.75" y="-3.4" dx="0.6" dy="0.24" layer="1" rot="R270"/>
<smd name="18" x="-0.25" y="-3.4" dx="0.6" dy="0.24" layer="1" rot="R270"/>
<smd name="19" x="0.25" y="-3.4" dx="0.6" dy="0.24" layer="1" rot="R270"/>
<smd name="20" x="0.75" y="-3.4" dx="0.6" dy="0.24" layer="1" rot="R270"/>
<smd name="21" x="1.25" y="-3.4" dx="0.6" dy="0.24" layer="1" rot="R270"/>
<smd name="22" x="1.75" y="-3.4" dx="0.6" dy="0.24" layer="1" rot="R270"/>
<smd name="23" x="2.25" y="-3.4" dx="0.6" dy="0.24" layer="1" rot="R270"/>
<smd name="24" x="2.75" y="-3.4" dx="0.6" dy="0.24" layer="1" rot="R270"/>
<smd name="25" x="3.4" y="-2.75" dx="0.6" dy="0.24" layer="1" rot="R180"/>
<smd name="26" x="3.4" y="-2.25" dx="0.6" dy="0.24" layer="1"/>
<smd name="27" x="3.4" y="-1.75" dx="0.6" dy="0.24" layer="1"/>
<smd name="28" x="3.4" y="-1.25" dx="0.6" dy="0.24" layer="1"/>
<smd name="29" x="3.4" y="-0.75" dx="0.6" dy="0.24" layer="1"/>
<smd name="30" x="3.4" y="-0.25" dx="0.6" dy="0.24" layer="1"/>
<smd name="31" x="3.4" y="0.25" dx="0.6" dy="0.24" layer="1"/>
<smd name="32" x="3.4" y="0.75" dx="0.6" dy="0.24" layer="1"/>
<smd name="33" x="3.4" y="1.25" dx="0.6" dy="0.24" layer="1"/>
<smd name="34" x="3.4" y="1.75" dx="0.6" dy="0.24" layer="1"/>
<smd name="35" x="3.4" y="2.25" dx="0.6" dy="0.24" layer="1"/>
<smd name="36" x="3.4" y="2.75" dx="0.6" dy="0.24" layer="1"/>
<smd name="37" x="2.75" y="3.4" dx="0.6" dy="0.24" layer="1" rot="R270"/>
<smd name="38" x="2.25" y="3.4" dx="0.6" dy="0.24" layer="1" rot="R90"/>
<smd name="39" x="1.75" y="3.4" dx="0.6" dy="0.24" layer="1" rot="R90"/>
<smd name="40" x="1.25" y="3.4" dx="0.6" dy="0.24" layer="1" rot="R90"/>
<smd name="41" x="0.75" y="3.4" dx="0.6" dy="0.24" layer="1" rot="R90"/>
<smd name="42" x="0.25" y="3.4" dx="0.6" dy="0.24" layer="1" rot="R90"/>
<smd name="43" x="-0.25" y="3.4" dx="0.6" dy="0.24" layer="1" rot="R90"/>
<smd name="44" x="-0.75" y="3.4" dx="0.6" dy="0.24" layer="1" rot="R90"/>
<smd name="45" x="-1.25" y="3.4" dx="0.6" dy="0.24" layer="1" rot="R90"/>
<smd name="46" x="-1.75" y="3.4" dx="0.6" dy="0.24" layer="1" rot="R90"/>
<smd name="47" x="-2.25" y="3.4" dx="0.6" dy="0.24" layer="1" rot="R90"/>
<smd name="48" x="-2.75" y="3.4" dx="0.6" dy="0.24" layer="1" rot="R90"/>
<text x="-2.8" y="4.24" size="1.27" layer="25">&gt;NAME</text>
<text x="-3.3" y="-5.35" size="1.27" layer="27">&gt;VALUE</text>
<circle x="-3.75" y="3.8" radius="0.05" width="0.127" layer="27"/>
<rectangle x1="-1.17" y1="1.36" x2="-0.11" y2="2.42" layer="31"/>
<rectangle x1="0.09" y1="1.36" x2="1.15" y2="2.42" layer="31"/>
<rectangle x1="1.35" y1="1.36" x2="2.41" y2="2.42" layer="31"/>
<rectangle x1="-2.43" y1="-2.42" x2="-1.37" y2="-1.36" layer="31"/>
<rectangle x1="-2.43" y1="-1.16" x2="-1.37" y2="-0.1" layer="31"/>
<rectangle x1="-2.43" y1="0.1" x2="-1.37" y2="1.16" layer="31"/>
<rectangle x1="-2.43" y1="1.36" x2="-1.37" y2="2.42" layer="31"/>
<rectangle x1="-1.17" y1="-2.42" x2="-0.11" y2="-1.36" layer="31"/>
<rectangle x1="-1.17" y1="-1.16" x2="-0.11" y2="-0.1" layer="31"/>
<rectangle x1="-1.17" y1="0.1" x2="-0.11" y2="1.16" layer="31"/>
<rectangle x1="0.09" y1="-2.42" x2="1.15" y2="-1.36" layer="31"/>
<rectangle x1="0.09" y1="-1.16" x2="1.15" y2="-0.1" layer="31"/>
<rectangle x1="0.09" y1="0.1" x2="1.15" y2="1.16" layer="31"/>
<rectangle x1="1.35" y1="-2.42" x2="2.41" y2="-1.36" layer="31"/>
<rectangle x1="1.35" y1="-1.16" x2="2.41" y2="-0.1" layer="31"/>
<rectangle x1="1.35" y1="0.1" x2="2.41" y2="1.16" layer="31"/>
</package>
</packages>
<packages3d>
<package3d name="QFN-16_3X3" urn="urn:adsk.eagle:package:19571298/3" type="model" library_version="5" library_locally_modified="yes">
<packageinstances>
<packageinstance name="QFN-16_3X3"/>
</packageinstances>
</package3d>
<package3d name="VQFN-48_7X7" urn="urn:adsk.eagle:package:19571846/3" type="model" library_version="5">
<packageinstances>
<packageinstance name="VQFN-48_7X7"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="MA702" urn="urn:adsk.eagle:symbol:19571845/1" locally_modified="yes" library_version="5" library_locally_modified="yes">
<pin name="PWM" x="-20.32" y="-15.24" length="middle"/>
<pin name="TEST" x="-20.32" y="12.7" length="middle"/>
<pin name="MGL" x="20.32" y="0" length="middle" rot="R180"/>
<pin name="SCLK" x="-20.32" y="5.08" length="middle"/>
<pin name="VDD" x="-20.32" y="15.24" length="middle"/>
<pin name="NC" x="0" y="0" visible="off" length="point" rot="R90"/>
<pin name="SSCK" x="-20.32" y="-7.62" length="middle"/>
<pin name="MGH" x="20.32" y="2.54" length="middle" rot="R180"/>
<pin name="SSD" x="-20.32" y="-10.16" length="middle"/>
<pin name="A" x="20.32" y="12.7" length="middle" rot="R180"/>
<pin name="Z" x="20.32" y="7.62" length="middle" rot="R180"/>
<pin name="MOSI" x="-20.32" y="2.54" length="middle"/>
<pin name="CS" x="-20.32" y="-2.54" length="middle"/>
<pin name="B" x="20.32" y="10.16" length="middle" rot="R180"/>
<pin name="MISO" x="-20.32" y="0" length="middle"/>
<pin name="GND" x="-20.32" y="10.16" length="middle"/>
<wire x1="-15.24" y1="17.78" x2="15.24" y2="17.78" width="0.254" layer="94"/>
<wire x1="15.24" y1="17.78" x2="15.24" y2="-17.78" width="0.254" layer="94"/>
<wire x1="15.24" y1="-17.78" x2="-15.24" y2="-17.78" width="0.254" layer="94"/>
<wire x1="-15.24" y1="-17.78" x2="-15.24" y2="17.78" width="0.254" layer="94"/>
<text x="-17.78" y="20.574" size="1.27" layer="95">&gt;NAME</text>
<text x="-17.78" y="-20.32" size="1.27" layer="96">&gt;VALUE</text>
</symbol>
<symbol name="DRV8323RS" urn="urn:adsk.eagle:symbol:19571844/1" library_version="5">
<pin name="FB" x="20.32" y="-43.18" length="middle" rot="R180"/>
<pin name="PGND" x="-20.32" y="20.32" length="middle"/>
<pin name="CPL" x="-20.32" y="35.56" length="middle"/>
<pin name="CPH" x="-20.32" y="38.1" length="middle"/>
<pin name="VCP" x="-20.32" y="43.18" length="middle"/>
<pin name="VM" x="-20.32" y="45.72" length="middle"/>
<pin name="VDRAIN" x="20.32" y="45.72" length="middle" rot="R180"/>
<pin name="GHA" x="20.32" y="40.64" length="middle" rot="R180"/>
<pin name="SHA" x="20.32" y="38.1" length="middle" rot="R180"/>
<pin name="GLA" x="20.32" y="35.56" length="middle" rot="R180"/>
<pin name="SPA" x="20.32" y="-10.16" length="middle" rot="R180"/>
<pin name="SNA" x="20.32" y="-12.7" length="middle" rot="R180"/>
<pin name="SNB" x="20.32" y="-5.08" length="middle" rot="R180"/>
<pin name="SPB" x="20.32" y="-2.54" length="middle" rot="R180"/>
<pin name="GLB" x="20.32" y="25.4" length="middle" rot="R180"/>
<pin name="SHB" x="20.32" y="27.94" length="middle" rot="R180"/>
<pin name="GHB" x="20.32" y="30.48" length="middle" rot="R180"/>
<pin name="GHC" x="20.32" y="20.32" length="middle" rot="R180"/>
<pin name="SHC" x="20.32" y="17.78" length="middle" rot="R180"/>
<pin name="GLC" x="20.32" y="15.24" length="middle" rot="R180"/>
<pin name="SPC" x="20.32" y="5.08" length="middle" rot="R180"/>
<pin name="SNC" x="20.32" y="2.54" length="middle" rot="R180"/>
<pin name="SOC" x="-20.32" y="-22.86" length="middle"/>
<pin name="SOB" x="-20.32" y="-25.4" length="middle"/>
<pin name="SOA" x="-20.32" y="-27.94" length="middle"/>
<pin name="VREF" x="-20.32" y="-20.32" length="middle"/>
<pin name="DGND" x="-20.32" y="30.48" length="middle"/>
<pin name="NFAULT" x="20.32" y="10.16" length="middle" rot="R180"/>
<pin name="SDO" x="-20.32" y="-10.16" length="middle"/>
<pin name="SDI" x="-20.32" y="-7.62" length="middle"/>
<pin name="SCLK" x="-20.32" y="-12.7" length="middle"/>
<pin name="NSCS" x="-20.32" y="-15.24" length="middle"/>
<pin name="ENABLE" x="-20.32" y="15.24" length="middle"/>
<pin name="CAL" x="-20.32" y="-33.02" length="middle"/>
<pin name="AGND" x="-20.32" y="22.86" length="middle"/>
<pin name="DVDD" x="-20.32" y="25.4" length="middle"/>
<pin name="INHA" x="-20.32" y="10.16" length="middle"/>
<pin name="INLA" x="-20.32" y="7.62" length="middle"/>
<pin name="INHB" x="-20.32" y="5.08" length="middle"/>
<pin name="INLB" x="-20.32" y="2.54" length="middle"/>
<pin name="INHC" x="-20.32" y="0" length="middle"/>
<pin name="INLC" x="-20.32" y="-2.54" length="middle"/>
<pin name="BGND" x="-20.32" y="-43.18" length="middle"/>
<pin name="CB" x="20.32" y="-38.1" length="middle" rot="R180"/>
<pin name="SW" x="20.32" y="-40.64" length="middle" rot="R180"/>
<pin name="NC" x="0" y="0" visible="off" length="point" rot="R90"/>
<pin name="VIN" x="-20.32" y="-38.1" length="middle"/>
<pin name="NSHDN" x="-20.32" y="-40.64" length="middle"/>
<wire x1="-15.24" y1="48.26" x2="15.24" y2="48.26" width="0.254" layer="94"/>
<wire x1="15.24" y1="48.26" x2="15.24" y2="-35.56" width="0.254" layer="94"/>
<wire x1="15.24" y1="-35.56" x2="15.24" y2="-48.26" width="0.254" layer="94"/>
<wire x1="15.24" y1="-48.26" x2="-15.24" y2="-48.26" width="0.254" layer="94"/>
<wire x1="-15.24" y1="-48.26" x2="-15.24" y2="-35.56" width="0.254" layer="94"/>
<wire x1="-15.24" y1="-35.56" x2="-15.24" y2="48.26" width="0.254" layer="94"/>
<wire x1="-15.24" y1="-35.56" x2="15.24" y2="-35.56" width="0.254" layer="94" style="shortdash"/>
<text x="-10.16" y="51.054" size="1.778" layer="95">&gt;NAME</text>
<text x="-10.16" y="-53.34" size="1.778" layer="96">&gt;VALUE</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="MA702" urn="urn:adsk.eagle:component:19571847/1" locally_modified="yes" prefix="U" library_version="5" library_locally_modified="yes">
<gates>
<gate name="G$1" symbol="MA702" x="0" y="0"/>
</gates>
<devices>
<device name="" package="QFN-16_3X3">
<connects>
<connect gate="G$1" pin="A" pad="2"/>
<connect gate="G$1" pin="B" pad="6"/>
<connect gate="G$1" pin="CS" pad="5"/>
<connect gate="G$1" pin="GND" pad="8 PAD"/>
<connect gate="G$1" pin="MGH" pad="16"/>
<connect gate="G$1" pin="MGL" pad="11"/>
<connect gate="G$1" pin="MISO" pad="7"/>
<connect gate="G$1" pin="MOSI" pad="4"/>
<connect gate="G$1" pin="NC" pad="14"/>
<connect gate="G$1" pin="PWM" pad="9"/>
<connect gate="G$1" pin="SCLK" pad="12"/>
<connect gate="G$1" pin="SSCK" pad="15"/>
<connect gate="G$1" pin="SSD" pad="1"/>
<connect gate="G$1" pin="TEST" pad="10"/>
<connect gate="G$1" pin="VDD" pad="13"/>
<connect gate="G$1" pin="Z" pad="3"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:19571298/3"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="DATASHEET" value="https://www.monolithicpower.com/en/documentview/productdocument/index/version/2/document_type/Datasheet/lang/en/sku/MA702/" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="DRV8323RS" urn="urn:adsk.eagle:component:19571916/1" locally_modified="yes" prefix="U" library_version="5" library_locally_modified="yes">
<gates>
<gate name="G$1" symbol="DRV8323RS" x="0" y="0"/>
</gates>
<devices>
<device name="" package="VQFN-48_7X7">
<connects>
<connect gate="G$1" pin="AGND" pad="35"/>
<connect gate="G$1" pin="BGND" pad="43"/>
<connect gate="G$1" pin="CAL" pad="34"/>
<connect gate="G$1" pin="CB" pad="44"/>
<connect gate="G$1" pin="CPH" pad="4"/>
<connect gate="G$1" pin="CPL" pad="3"/>
<connect gate="G$1" pin="DGND" pad="27"/>
<connect gate="G$1" pin="DVDD" pad="36"/>
<connect gate="G$1" pin="ENABLE" pad="33"/>
<connect gate="G$1" pin="FB" pad="1"/>
<connect gate="G$1" pin="GHA" pad="8"/>
<connect gate="G$1" pin="GHB" pad="17"/>
<connect gate="G$1" pin="GHC" pad="18"/>
<connect gate="G$1" pin="GLA" pad="10"/>
<connect gate="G$1" pin="GLB" pad="15"/>
<connect gate="G$1" pin="GLC" pad="20"/>
<connect gate="G$1" pin="INHA" pad="37"/>
<connect gate="G$1" pin="INHB" pad="39"/>
<connect gate="G$1" pin="INHC" pad="41"/>
<connect gate="G$1" pin="INLA" pad="38"/>
<connect gate="G$1" pin="INLB" pad="40"/>
<connect gate="G$1" pin="INLC" pad="42"/>
<connect gate="G$1" pin="NC" pad="46"/>
<connect gate="G$1" pin="NFAULT" pad="28"/>
<connect gate="G$1" pin="NSCS" pad="32"/>
<connect gate="G$1" pin="NSHDN" pad="48"/>
<connect gate="G$1" pin="PGND" pad="2 PAD"/>
<connect gate="G$1" pin="SCLK" pad="31"/>
<connect gate="G$1" pin="SDI" pad="30"/>
<connect gate="G$1" pin="SDO" pad="29"/>
<connect gate="G$1" pin="SHA" pad="9"/>
<connect gate="G$1" pin="SHB" pad="16"/>
<connect gate="G$1" pin="SHC" pad="19"/>
<connect gate="G$1" pin="SNA" pad="12"/>
<connect gate="G$1" pin="SNB" pad="13"/>
<connect gate="G$1" pin="SNC" pad="22"/>
<connect gate="G$1" pin="SOA" pad="25"/>
<connect gate="G$1" pin="SOB" pad="24"/>
<connect gate="G$1" pin="SOC" pad="23"/>
<connect gate="G$1" pin="SPA" pad="11"/>
<connect gate="G$1" pin="SPB" pad="14"/>
<connect gate="G$1" pin="SPC" pad="21"/>
<connect gate="G$1" pin="SW" pad="45"/>
<connect gate="G$1" pin="VCP" pad="5"/>
<connect gate="G$1" pin="VDRAIN" pad="7"/>
<connect gate="G$1" pin="VIN" pad="47"/>
<connect gate="G$1" pin="VM" pad="6"/>
<connect gate="G$1" pin="VREF" pad="26"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:19571846/3"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="DATASHEET" value="https://www.ti.com/lit/ds/symlink/drv8323r.pdf?ts=1587957100782" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="_T_power" urn="urn:adsk.eagle:library:19572085">
<packages>
</packages>
<symbols>
<symbol name="GND" library_version="1" library_locally_modified="yes">
<wire x1="-1.27" y1="0" x2="1.27" y2="0" width="0.254" layer="94"/>
<wire x1="1.27" y1="0" x2="0" y2="-1.27" width="0.254" layer="94"/>
<wire x1="0" y1="-1.27" x2="-1.27" y2="0" width="0.254" layer="94"/>
<text x="-1.905" y="-3.175" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
<symbol name="+3V3" library_version="1" library_locally_modified="yes">
<wire x1="1.27" y1="-1.905" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-1.27" y2="-1.905" width="0.254" layer="94"/>
<text x="-2.54" y="-5.08" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="+3V3" x="0" y="-2.54" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="GND" prefix="GND" library_version="1" library_locally_modified="yes">
<gates>
<gate name="G$1" symbol="GND" x="0" y="-2.54"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="+3V3" prefix="+3V3" library_version="1" library_locally_modified="yes">
<gates>
<gate name="G$1" symbol="+3V3" x="0" y="2.54"/>
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
<library name="_T_rcl" urn="urn:adsk.eagle:library:19571919">
<packages>
<package name="C0402" urn="urn:adsk.eagle:footprint:19572003/1" library_version="2" library_locally_modified="yes">
<smd name="1" x="0.5" y="0" dx="0.6" dy="0.7" layer="1"/>
<smd name="2" x="-0.5" y="0" dx="0.6" dy="0.7" layer="1"/>
<wire x1="-0.5" y1="0.25" x2="0.5" y2="0.25" width="0.05" layer="51"/>
<wire x1="-0.5" y1="-0.25" x2="0.5" y2="-0.25" width="0.05" layer="51"/>
<wire x1="-0.5" y1="0.25" x2="-0.5" y2="-0.25" width="0.05" layer="51"/>
<wire x1="0.5" y1="0.25" x2="0.5" y2="-0.25" width="0.05" layer="51"/>
</package>
<package name="C0603" urn="urn:adsk.eagle:footprint:19572001/1" library_version="2" library_locally_modified="yes">
<smd name="1" x="0.75" y="0" dx="0.6" dy="0.9" layer="1"/>
<smd name="2" x="-0.75" y="0" dx="0.6" dy="0.9" layer="1"/>
<wire x1="-0.775" y1="0.425" x2="0.775" y2="0.425" width="0.05" layer="51"/>
<wire x1="-0.775" y1="-0.425" x2="0.775" y2="-0.425" width="0.05" layer="51"/>
<wire x1="0.775" y1="-0.425" x2="0.775" y2="0.425" width="0.05" layer="51"/>
<wire x1="-0.775" y1="-0.425" x2="-0.775" y2="0.425" width="0.05" layer="51"/>
</package>
<package name="R0805" urn="urn:adsk.eagle:footprint:19572000/1" library_version="2" library_locally_modified="yes">
<smd name="1" x="0.95" y="0" dx="0.7" dy="1.3" layer="1"/>
<smd name="2" x="-0.95" y="0" dx="0.7" dy="1.3" layer="1"/>
<wire x1="-1" y1="0.6" x2="1" y2="0.6" width="0.05" layer="51"/>
<wire x1="1" y1="0.6" x2="1" y2="-0.6" width="0.05" layer="51"/>
<wire x1="1" y1="-0.6" x2="-1" y2="-0.6" width="0.05" layer="51"/>
<wire x1="-1" y1="-0.6" x2="-1" y2="0.6" width="0.05" layer="51"/>
</package>
</packages>
<packages3d>
<package3d name="C0402" urn="urn:adsk.eagle:package:19572013/3" type="model" library_version="2" library_locally_modified="yes">
<description>Chip, 1.00 X 0.50 X 0.35 mm body
&lt;p&gt;Chip package with body size 1.00 X 0.50 X 0.35 mm&lt;/p&gt;</description>
<packageinstances>
<packageinstance name="C0402"/>
</packageinstances>
</package3d>
<package3d name="C0603" urn="urn:adsk.eagle:package:19572011/2" type="model" library_version="2" library_locally_modified="yes">
<description>Chip, 1.55 X 0.85 X 0.45 mm body
&lt;p&gt;Chip package with body size 1.55 X 0.85 X 0.45 mm&lt;/p&gt;</description>
<packageinstances>
<packageinstance name="C0603"/>
</packageinstances>
</package3d>
<package3d name="R0805" urn="urn:adsk.eagle:package:19572010/2" type="model" library_version="2" library_locally_modified="yes">
<description>Chip, 2.00 X 1.20 X 0.45 mm body
&lt;p&gt;Chip package with body size 2.00 X 1.20 X 0.45 mm&lt;/p&gt;</description>
<packageinstances>
<packageinstance name="R0805"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="C" urn="urn:adsk.eagle:symbol:19572007/1" library_version="2" library_locally_modified="yes">
<wire x1="0" y1="0" x2="0" y2="-0.508" width="0.1524" layer="94"/>
<wire x1="0" y1="-2.54" x2="0" y2="-2.032" width="0.1524" layer="94"/>
<text x="1.524" y="0.381" size="1.778" layer="95">&gt;NAME</text>
<text x="1.524" y="-4.699" size="1.778" layer="96">&gt;VALUE</text>
<rectangle x1="-2.032" y1="-2.032" x2="2.032" y2="-1.524" layer="94"/>
<rectangle x1="-2.032" y1="-1.016" x2="2.032" y2="-0.508" layer="94"/>
<pin name="1" x="0" y="2.54" visible="off" length="short" direction="pas" swaplevel="1" rot="R270"/>
<pin name="2" x="0" y="-5.08" visible="off" length="short" direction="pas" swaplevel="1" rot="R90"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="C" prefix="C" uservalue="yes" library_version="2" library_locally_modified="yes">
<gates>
<gate name="G$1" symbol="C" x="0" y="2.54"/>
</gates>
<devices>
<device name="0402" package="C0402">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:19572013/3"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="0603" package="C0603">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:19572011/2"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="0805" package="R0805">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:19572010/2"/>
</package3dinstances>
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
</classes>
<parts>
<part name="FRAME1" library="frames" library_urn="urn:adsk.eagle:library:229" deviceset="FRAME_A_L" device=""/>
<part name="U1" library="_T_ic" library_urn="urn:adsk.eagle:library:19571245" deviceset="MA702" device="" package3d_urn="urn:adsk.eagle:package:19571298/3"/>
<part name="U2" library="_T_ic" library_urn="urn:adsk.eagle:library:19571245" deviceset="DRV8323RS" device="" package3d_urn="urn:adsk.eagle:package:19571846/3"/>
<part name="GND1" library="_T_power" library_urn="urn:adsk.eagle:library:19572085" deviceset="GND" device=""/>
<part name="C1" library="_T_rcl" library_urn="urn:adsk.eagle:library:19571919" deviceset="C" device="0402" package3d_urn="urn:adsk.eagle:package:19572013/3" value="1uf 10v"/>
<part name="+3V1" library="_T_power" library_urn="urn:adsk.eagle:library:19572085" deviceset="+3V3" device=""/>
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
<instance part="U1" gate="G$1" x="190.5" y="91.44" smashed="yes">
<attribute name="NAME" x="170.18" y="109.474" size="1.27" layer="95"/>
<attribute name="VALUE" x="170.18" y="73.66" size="1.27" layer="96"/>
</instance>
<instance part="U2" gate="G$1" x="96.52" y="93.98" smashed="yes">
<attribute name="NAME" x="86.36" y="145.034" size="1.778" layer="95"/>
<attribute name="VALUE" x="86.36" y="40.64" size="1.778" layer="96"/>
</instance>
<instance part="GND1" gate="G$1" x="152.4" y="96.52" smashed="yes">
<attribute name="VALUE" x="150.495" y="93.345" size="1.778" layer="96"/>
</instance>
<instance part="C1" gate="G$1" x="152.4" y="106.68" smashed="yes">
<attribute name="NAME" x="153.924" y="107.061" size="1.778" layer="95"/>
<attribute name="VALUE" x="153.924" y="101.981" size="1.778" layer="96"/>
</instance>
<instance part="+3V1" gate="G$1" x="152.4" y="116.84" smashed="yes">
<attribute name="VALUE" x="149.86" y="111.76" size="1.778" layer="96" rot="R90"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="SNS_SCLK" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="SCLK"/>
<wire x1="170.18" y1="96.52" x2="167.64" y2="96.52" width="0.1524" layer="91"/>
<label x="167.64" y="96.52" size="1.778" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="SNS_MOSI" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="MOSI"/>
<wire x1="170.18" y1="93.98" x2="167.64" y2="93.98" width="0.1524" layer="91"/>
<label x="167.64" y="93.98" size="1.778" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="SNS_MISO" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="MISO"/>
<wire x1="170.18" y1="91.44" x2="167.64" y2="91.44" width="0.1524" layer="91"/>
<label x="167.64" y="91.44" size="1.778" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="SNS_CS" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="CS"/>
<wire x1="170.18" y1="88.9" x2="167.64" y2="88.9" width="0.1524" layer="91"/>
<label x="167.64" y="88.9" size="1.778" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="GND"/>
<pinref part="C1" gate="G$1" pin="2"/>
<wire x1="170.18" y1="101.6" x2="167.64" y2="101.6" width="0.1524" layer="91"/>
<pinref part="GND1" gate="G$1" pin="GND"/>
<wire x1="167.64" y1="101.6" x2="152.4" y2="101.6" width="0.1524" layer="91"/>
<wire x1="152.4" y1="101.6" x2="152.4" y2="99.06" width="0.1524" layer="91"/>
<junction x="152.4" y="101.6"/>
<pinref part="U1" gate="G$1" pin="TEST"/>
<wire x1="170.18" y1="104.14" x2="167.64" y2="104.14" width="0.1524" layer="91"/>
<wire x1="167.64" y1="104.14" x2="167.64" y2="101.6" width="0.1524" layer="91"/>
<junction x="167.64" y="101.6"/>
</segment>
</net>
<net name="+3V3" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="VDD"/>
<pinref part="C1" gate="G$1" pin="1"/>
<wire x1="170.18" y1="106.68" x2="170.18" y2="109.22" width="0.1524" layer="91"/>
<wire x1="170.18" y1="109.22" x2="152.4" y2="109.22" width="0.1524" layer="91"/>
<pinref part="+3V1" gate="G$1" pin="+3V3"/>
<wire x1="152.4" y1="114.3" x2="152.4" y2="109.22" width="0.1524" layer="91"/>
<junction x="152.4" y="109.22"/>
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
</compatibility>
</eagle>
