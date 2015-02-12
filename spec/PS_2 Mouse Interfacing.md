<!DOCTYPE doctype PUBLIC "-//w3c//dtd html 4.0 transitional//en">
<html>
<head>

                        
  <meta http-equiv="Content-Type"
 content="text/html; charset=iso-8859-1">
                        
  <meta name="GENERATOR"
 content="Mozilla/4.7 [en] (Win98; U) [Netscape]">
                        
  <meta name="Author" content="Adam Chapweske">
  <title>PS/2 Mouse Interfacing</title>

</head>
  <body bgcolor="#ffffff" link="#3333ff" vlink="#3333ff" alink="#3333ff">
   <small><b><font face="Arial,Helvetica"><font size="+3"><small>The PS/2 
Mouse  Interface</small></font></font></b></small><br>

            
<center></center>
            
<center>              
<hr width="400" size="1" align="left" noshade="noshade"></center>
                 <br>
    <font face="Arial,Helvetica">Source: <a
 href="http://www.Computer-Engineering.org">http://www.Computer-Engineering.org</a></font><br>
     <font face="Arial,Helvetica">Author: Adam Chapweske<br>
    Last Updated: 04/01/03<br>

    <br>
   <br>

<a name="Legal_Information"></a><h2> Legal Information </h2>
<p>All information within this article is provided "as is" and without
any express or implied warranties, including, without limitation, the
implied warranties of merchantibility and fitness for a particular
purpose. </p><p>This article is protected under copyright law. This document
may be copied only if the source, author, date, and legal information
is included.
</p>
<a name="Abstract"></a><h2> Abstract </h2>
<p>This article attempts to explain every aspect of the PS/2 mouse
interface including the physical and electrical interface, low-level protocol, modes of operation, commands, and extensions.
</p>
<a name="General_Description"></a><h2> General Description </h2>
<p>There are many types of pointing devices available for the modern PC
including mice, trackballs, touchpads, electronic whiteboards, etc.
Virtually all of these devices communicate on one of two interfaces:
Universal Serial Bus (USB) or the PS/2 mouse interface. Older pointing
device interfaces include the Apple Desktop Bus (ADB), RS-232 serial
port, and the bus mouse interface. These are obsolete and are not
covered in this article.
</p><p>The PS/2 mouse interface originally appeared in IBM's "Personal
System/2" computers in the late 80's and it remains a widely-supported
interface. However, USB has quickly caught on these last few years and
will eventually replace the PS/2 interface entirely.
</p><p>The PS/2 mouse interface utilizes a bidirectional serial protocol to transmit movement and button-state data to the computer's auxiliary
device controller (part of the keyboard controller). The controller, in
turn, may send a number of commands to the mouse to set the report
rate, resolution, reset the mouse, disable the mouse, etc. The host
provides the mouse with a 5V ~100 mA power supply.
</p>
<a name="Electrical_Interface_.2F_Protocol"></a><h2> Electrical Interface / Protocol </h2>
<p>The PS/2 mouse uses the same protocol as the PS/2 keyboard (a.k.a. AT keyboard).  Click <a href="http://www.computer-engineering.org/index.php?title=PS/2_Mouse/Keyboard_Protocol" title="PS/2 Mouse/Keyboard Protocol">here</a> for detailed information on this protocol.
</p>
<a name="Inputs.2C_Resolution.2C_and_Scaling"></a><h2> Inputs, Resolution, and Scaling </h2>
<p>The standard PS/2 mouse interface supports the following inputs: X
(right/left) movement, Y (up/down) movement, left button, middle
button, and right button. The mouse periodically reads these inputs and
updates various counters and flags to reflect movement and button
states. There are many PS/2 pointing devices that have additional
inputs and may report data differently than described in this document.
One popular extension covered later in this document is the Microsoft
Intellimouse, which includes support for the standard inputs as well as
a scrolling wheel and two additional buttons. </p><p>The standard mouse has two counters that keep track of
movement: the X movement counter and the Y movement counter. These are
9-bit 2's complement values and each has an associated overflow flag.
Their contents, along with the state of the three mouse buttons, are
sent to the host in the form of a 3-byte movement data packet. The
movement counters represent the mouse's offset relative to its position
when the previous movement data packet was issued, or when the last
non-"Resend" (0xFE) command was successfully sent to the host.
</p><p>When the mouse reads its inputs it records the current state of
its buttons and increments/decrements the movement counters according
to the amount of movement that has occurred since the last input
sample. If either of the counters has overflowed, the appropriate
overflow flag is set. Futher modification of the counter is disabled
until it the counters are reset (due to a packet being sent).
</p><p>The parameter that determines the amount by which the movement counters are incremented/decremented is the <i>resolution</i>. The default resolution is 4 counts/mm and the host may change that value using the "Set Resolution" (0xE8) command. 
</p><p>There is a parameter that does not affect the movement counters,
but does affect the reported value of these counters. This parameter is
<i>scaling</i>. By default, the mouse uses 1:1 scaling, which has no
effect on the reported mouse movement. However, the host may select 2:1
scaling by issuing the "Set Scaling 2:1" (0xE7) command. If 2:1 scaling
is enabled, the mouse will apply the following algorithm to the
movement counters before sending their contents to the host: </p>
<table border="1" cellpadding="4">

<tbody><tr>
<th> Movement Counter </th><th> Reported Movement
</th></tr>
<tr>
<td> 0 </td><td> 0
</td></tr>
<tr>
<td> 1 </td><td> 1
</td></tr>
<tr>
<td> 2 </td><td> 1
</td></tr>
<tr>
<td> 3 </td><td> 3
</td></tr>
<tr>
<td> 4 </td><td> 6
</td></tr>
<tr>
<td> 5 </td><td> 9
</td></tr>
<tr>
<td> N &gt; 5 </td><td> 2 * N
</td></tr></tbody></table>
<p>2:1 scaling only applies to the automatic data reporting in stream
mode. It does not affect the reported data sent in response to the
"Read Data" (0xEB) command.
</p>
<a name="Movement_Data_Packet"></a><h2> Movement Data Packet </h2>
<p>The standard PS/2 mouse sends movement/button information to the host using the following 3-byte packet:
</p>
<table border="1" cellpadding="4">

<tbody><tr>
<th> </th><th> Bit 7 </th><th> Bit 6 </th><th> Bit 5 </th><th> Bit 4 </th><th> Bit 3 </th><th> Bit 2 </th><th> Bit 1 </th><th> Bit 0
</th></tr>
<tr>
<th> Byte 1
</th><td> Y overflow </td><td> X overflow </td><td> Y sign bit </td><td> X sign bit </td><td> Always 1 </td><td> Middle Btn </td><td> Right Btn </td><td> Left Btn
</td></tr>
<tr>
<th> Byte 2
</th><td colspan="8" align="center"> X movement
</td></tr>
<tr>
<th> Byte 3
</th><td colspan="8" align="center"> Y movement
</td></tr></tbody></table>
<p>The movement values are 9-bit 2's complement integers, where the
most significant bit appears as a "sign" bit in byte 1 of the movement
data packet. Their value represents the mouse's offset relative to its
position when the previous packet was sent, in units determined by the
current resolution. The range of values that can be expressed is -255
to +255. If this range is exceeded, the appropriate overflow bit is
set.
</p>
<a name="Modes_of_Operation"></a><h2> Modes of Operation </h2>
<p>Data reporting is handled according to the mode in which the mouse is operating.  There are four modes of operation:  
</p>
<ul><li>Reset - The initial mode, in which the mouse performs initialization and self-diagnostics.
</li><li>Stream - The default operating mode, in which the mouse issues
movement data packets when movement occurs or button state changes.
</li><li>Remote - The host must poll for movement data packets.
</li><li>Wrap - A purely diagnostic mode where the mouse echoes every received packet back to the host.
</li></ul>
<a name="Reset_Mode"></a><h3> Reset Mode </h3>
<p>The mouse enters reset mode at power-on or in response to the
"Reset" (0xFF) command. Upon entering this mode, the mouse performs a
diagnostic self-test called <i>BAT</i> (Basic Assurance Test) and sets the following default values: 
</p>
<ul><li>Sample Rate = 100 samples/sec 
</li><li>Resolution = 4 counts/mm 
</li><li>Scaling = 1:1 
</li><li>Data Reporting = disabled
</li></ul>
<p>The mouse then sends a BAT completion code of either 0xAA (BAT
successful) or 0xFC (Error). The host's response to a completion code
other than 0xAA is undefined. </p><p>Following the BAT completion code (0xAA or 0xFC), the mouse
sends its device ID of 0x00. This distinguishes it from a keyboard or
nonstandard mouse. I have read documents indicating the host should not
transmit any data until it receives a device ID. However I've found
some BIOS's will send the "Reset" (0xFF) command immediately following
the 0xAA received after a power-on reset. </p><p>Once the mouse has sent its device ID to the host, it enters stream mode.
</p>
<a name="Stream_Mode"></a><h3> Stream Mode </h3>
<p>In stream mode the mouse sends movement data when it detects
movement or a change in state of one or more mouse buttons. The maximum
rate at which this data may be reported is known as the <i>sample rate</i>.
This parameter ranges from 10-200 samples/sec, with a default value of
100 samples/sec. The host may set this value using the "Set Sample
Rate" (0xF3) command. </p><p>Note that reporting is <b>disabled</b> by default. The mouse
will not actually issue any movement data packets until it receives the
"Enable Data Reporting" (0xF4) command. </p><p>Stream mode is the default operating mode, and is otherwise set using the "Set Stream Mode" (0xEA) command.
</p>
<a name="Remote_Mode"></a><h3> Remote Mode </h3>
<p>In remote mode the mouse reads its inputs and updates its
counters/flags at the current sample rate, but it does not
automatically issue data packets when movement has occured. Instead,
the host polls the mouse using the "Read Data" (0xEB) command. Upon
receiving this command the mouse will issue a single movement data
packet and reset its movement counters.
</p><p>The mouse enters remote mode upon receiving the "Set Remote Mode" (0xF0) command.
</p><p>Remote mode is rarely used.
</p>
<a name="Wrap_Mode"></a><h3> Wrap Mode </h3>
<p>This is an "echoing" mode in which every byte received by the mouse
is sent back to the host. Even if the byte represents a valid command,
the mouse will not respond to that command--it will only echo that byte
back to the host. There are two exceptions to this: the "Reset" (0xFF)
and "Reset Wrap Mode" (0xEC) commands. The mouse treats these as valid
commands and does not echo them back to the host.
</p><p>Wrap mode is rarely used.
</p>
<a name="Intellimouse_Extensions"></a><h2> Intellimouse Extensions </h2>
<p>A popular extension to the standard PS/2 mouse is the Microsoft
Intellimouse. This includes support for a total of five mouse buttons
and three axes of movement (right-left, up-down, and a scrolling
wheel). These additional features require the use of a 4-byte movement
data packet rather than the standard 3-byte packet. Since standard PS/2
mouse drivers cannot recognize this packet format, the Intellimouse is
required to operate exactly like a standard PS/2 mouse unless it knows
the drivers support the extended packet format. This way, if an
Intellimouse is used on a computer which only supports the standard
PS/2 mouse, it will still function except its scrolling wheel and 4th
and 5th buttons will be disabled. </p><p>After power-on or reset the Microsoft Intellimouse operates
just like a standard PS/2 mouse (ie, it uses a 3-byte movement data
packet, responds to all commands in the same way as a standard PS/2
mouse, and reports a device ID of 0x00.) To enable the scrolling wheel,
the host sends the following command sequence: </p>
<ol><li>Set sample rate 200 
</li><li>Set sample rate 100 
</li><li>Set sample rate 80
</li></ol>
<p>The host then issues the "Get device ID" (0xF2) command and waits
for a response. If a standard PS/2 mouse (i.e., non-Intellimouse) is
attached, it will respond with a device ID of 0x00. In this case, the
host will recognize the fact that the mouse does have a scrolling wheel
and will continue to treat it as a standard PS/2 mouse. However, if a
Microsoft Intellimouse is attached, it will respond with an ID of 0x03.
This tells the host that the attached pointing device has a scrolling
wheel, and the host will then expect the mouse to use the following
4-byte movement data packet: </p>
<table border="1" cellpadding="4">

<tbody><tr>
<th> </th><th> Bit 7 </th><th> Bit 6 </th><th> Bit 5 </th><th> Bit 4 </th><th> Bit 3 </th><th> Bit 2 </th><th> Bit 1 </th><th> Bit 0
</th></tr>
<tr>
<th> Byte 1
</th><td> Y overflow </td><td> X overflow </td><td> Y sign bit </td><td> X sign bit </td><td> Always 1 </td><td> Middle Btn </td><td> Right Btn </td><td> Left Btn
</td></tr>
<tr>
<th> Byte 2
</th><td colspan="8" align="center"> X movement
</td></tr>
<tr>
<th> Byte 3
</th><td colspan="8" align="center"> Y movement
</td></tr>
<tr>
<th> Byte 4
</th><td colspan="8" align="center"> Z movement
</td></tr></tbody></table>
<p>"Z movement" is a 2's complement value that represents the scrolling
wheel's movement since the last data report. Valid values are in the
range of -8 to +7. This means the number is actually represented only
by the least significant four bits; the upper four bits act only as
sign extension.
</p><p>To enable the scrolling wheel AND the 4th and 5th buttons, the host sends the following command sequence: 
</p>
<ul><li>Set sample rate 200 
</li><li>Set sample rate 200 
</li><li>Set sample rate 80
</li></ul>
<p>The host then issues the "Get device ID" (0xF2) command and waits
for a response. A Microsoft Intellimouse will respond with a device ID
of 0x04, then uses the following 4-byte movement data packet: </p>
<table border="1" cellpadding="4">

<tbody><tr>
<th> </th><th> Bit 7 </th><th> Bit 6 </th><th> Bit 5 </th><th> Bit 4 </th><th> Bit 3 </th><th> Bit 2 </th><th> Bit 1 </th><th> Bit 0
</th></tr>
<tr>
<th> Byte 1
</th><td> Y overflow </td><td> X overflow </td><td> Y sign bit </td><td> X sign bit </td><td> Always 1 </td><td> Middle Btn </td><td> Right Btn </td><td> Left Btn
</td></tr>
<tr>
<th> Byte 2
</th><td colspan="8" align="center"> X movement
</td></tr>
<tr>
<th> Byte 3
</th><td colspan="8" align="center"> Y movement
</td></tr>
<tr>
<th> Byte 4
</th><td> Always 0 </td><td> Always 0 </td><td> 5th Btn </td><td> 4th Btn </td><td colspan="4" align="center"> Z movement
</td></tr></tbody></table>
<p>"4th Btn" = 1 iff the 4th mouse button is pressed, and "5th Btn" = 1
iff the 5th mouse button is pressed. "Z movement" is a 2's complement
value which represents the amount of movement that has occurred since
the last data report. Valid values range from -8 to +7. </p><p>There are mice with two scrolling wheels, one vertical and the
other horizontal. These mice use the Microsoft Intellimouse data packet
format as described above. If the vertical wheel is scrolled upward,
the Z-counter is incremented by one and if that wheel is scrolled down,
the Z-counter is decremented by one. This is normal operation for a
scrolling wheel. However, if the horizontal wheel is scrolled right,
the Z-counter is incremented by two and if it is scrolled left, the
Z-counter is decremented by two. This seems like an odd way to
implement the second scrolling wheel, but it works since the placement
of the two wheels make it virtually impossible to use both of them at
the same time (and if you try to trick the software and use both at the
same time, it will ignore the horizontal wheel).
</p>
<a name="Command_Set"></a><h2> Command Set </h2>
<p>Following is the set of commands accepted by the standard PS/2
mouse. If the mouse is in stream mode, the host should disable data
reporting (command 0xF5) before sending any other commands. </p>
<ul><li>0xFF (Reset) - The mouse responds to this command with "acknowledge" (0xFA) then enters reset mode. 
</li><li>0xFE (Resend) - The host sends this command whenever it
receives invalid data from the mouse. The mouse responds by resending
the last packet it sent to the host. If the mouse responds to the
"Resend" command with another invalid packet, the host may either issue
another "Resend" command, issue an "Error" (0xFC) command, cycle the
mouse's power supply to reset the mouse, or it may inhibit
communication (by bringing the clock line low). This command is not
buffered, which means "Resend" will never be sent in response to the
"Resend" command.
</li><li>0xF6 (Set Defaults) - The mouse responds with "acknowledge"
(0xFA) then loads the following values: Sampling rate = 100, resolution
= 4 counts/mm, Scaling = 1:1, data reporting = disabled. The mouse then
resets its movement counters and enters stream mode.
</li><li>0xF5 (Disable Data Reporting) - The mouse responds with
"acknowledge" (0xFA) then disables data reporting and resets its
movement counters. This only affects data reporting in stream mode and
does not disable sampling. Disabled stream mode functions the same as
remote mode. </li><li>0xF4 (Enable Data Reporting) - The mouse responds with
"acknowledge" (0xFA) then enables data reporting and resets its
movement counters. This command may be issued while the mouse is in
remote mode, but it will only affect data reporting in stream mode. </li><li>0xF3 (Set Sample Rate) - The mouse responds with
"acknowledge" (0xFA) then reads one more byte from the host. The mouse
saves this byte as the new sample rate. After receiving the sample
rate, the mouse again responds with "acknowledge" (0xFA) and resets its
movement counters. Valid sample rates are 10, 20, 40, 60, 80, 100, and
200 samples/sec. </li><li>0xF2 (Get Device ID) - The mouse responds with "acknowledge"
(0xFA) followed by its device ID (0x00 for the standard PS/2 mouse).
The mouse should also reset its movement counters. </li><li>0xF0 (Set Remote Mode) - The mouse responds with "acknowledge" (0xFA) then resets its movement counters and enters remote mode. 
</li><li>0xEE (Set Wrap Mode) - The mouse responds with "acknowledge" (0xFA) then resets its movement counters and enters wrap mode. 
</li><li>0xEC (Reset Wrap Mode) - The mouse responds with "acknowledge"
(0xFA) then resets its movement counters and enters the mode it was in
prior to wrap mode (stream mode or remote mode). </li><li>0xEB (Read Data) - The mouse responds with "acknowledge"
(0xFA) then sends a movement data packet. This is the only way to read
data in remote mode. After the data packet has successfully been sent,
the mouse resets its movement counters. </li><li>0xEA (Set Stream Mode) - The mouse responds with "acknowledge" (0xFA) then resets its movement counters and enters stream mode. 
</li><li>0xE9 (Status Request) - The mouse responds with "acknowledge"
(0xFA) then sends the following 3-byte status packet (then resets its
movement counters): </li></ul>
<table border="1" cellpadding="4">

<tbody><tr>
<th> </th><th> Bit 7 </th><th> Bit 6 </th><th> Bit 5 </th><th> Bit 4 </th><th> Bit 3 </th><th> Bit 2 </th><th> Bit 1 </th><th> Bit 0
</th></tr>
<tr>
<th> Byte 1
</th><td> Always 0 </td><td> Mode </td><td> Enable </td><td> Scaling </td><td> Always 0 </td><td> Left Btn </td><td> Middle Btn </td><td> Right Btn
</td></tr>
<tr>
<th> Byte 2
</th><td colspan="8" align="center"> Resolution
</td></tr>
<tr>
<th> Byte 3
</th><td colspan="8" align="center"> Sample Rate
</td></tr></tbody></table>
<p>Right, Middle, Left Btn = 1 if button pressed; 0 if button is not pressed. <br>
Scaling = 1 if scaling is 2:1; 0 if scaling is 1:1 (see commands 0xE7 and 0xE6). <br>
Enable = 1 if data reporting is enabled; 0 if data reporting is disabled (see commands 0xF5 and 0xF4). <br>
Mode = 1 if remote mode is enabled; 0 if stream mode is enabled (see commands 0xF0 and 0xEA). <br>
</p>
<ul><li>0xE8 (Set Resolution) - The mouse responds with "acknowledge"
(0xFA) then reads one byte from the host and again responds with
"acknowledge" (0xFA) then resets its movement counters. The byte read
from the host determines the resolution as follows: </li></ul>
<table border="1" cellpadding="4">

<tbody><tr>
<th> Byte Read from Host </th><th> Resolution
</th></tr>
<tr>
<td> 00 </td><td> 1 count/mm
</td></tr>
<tr>
<td> 01 </td><td> 2 count/mm
</td></tr>
<tr>
<td> 02 </td><td> 4 count/mm
</td></tr>
<tr>
<td> 03 </td><td> 8 count/mm
</td></tr></tbody></table>
<ul><li>0xE7 (Set Scaling 2:1) - The mouse responds with "acknowledge" (0xFA) then enables 2:1 scaling.
</li><li>0xE6 (Set Scaling 1:1) - The mouse responds with "acknowledge" (0xFA) then enables 1:1 scaling. 
</li></ul>
<p>The only commands the standard PS/2 mouse will send to the host are "Resend" (FEh) and "Error" (FCh).
</p>
<a name="Initialization"></a><h2> Initialization </h2>
<p>The PS/2 mouse is normally detected/initialized only when the
computer is booting up. That is, the mouse is not hot-pluggable and you
must restart your computer whenever you add/remove a PS/2 mouse.
Adding/removing the PS/2 mouse while the computer is running may
physically damage some motherboards.
</p><p>The initial detection of the PS/2 mouse occurrs during POST. If
a mouse is detected, the BIOS will allow the operating system to
configure/enable the mouse. Otherwise, it will inhibit communication on
the mouse's bus. If you boot the computer with a mouse attached, then
detach/reattach the mouse while in Windows, the OS may be able to
detect the mouse was reattached. Testing this on Win98 SE, it seems to
work about 50% of the time. </p><p>The following is the communication between my computer
(running Win98 SE) and a standard PS/2 mouse during the boot process.
It is fairly typical of how a PS/2 mouse is initialized and if you want
to emulate a PS/2 mouse it must (at minimum) be able to support the
following sequence of commands... </p>

<ul>
     <tt>Power-on Reset:</tt><br>
     <tt>Mouse: AA&nbsp; Self-test passed</tt><br>
     <tt>Mouse: 00&nbsp; Mouse ID</tt><br>
     <tt>Host:&nbsp; FF&nbsp; Reset command</tt><br>
     <tt>Mouse: FA&nbsp; Acknowledge</tt><br>
     <tt>Mouse: AA&nbsp; Self-test passed</tt><br>
     <tt>Mouse: 00&nbsp; Mouse ID</tt><br>
     <tt>Host:&nbsp; FF&nbsp; Reset command</tt><br>
     <tt>Mouse: FA&nbsp; Acknowledge</tt><br>
     <tt>Mouse: AA&nbsp; Self-test passed</tt><br>
     <tt>Mouse: 00&nbsp; Mouse ID</tt><br>
     <tt>Host:&nbsp; FF&nbsp; Reset command</tt><br>
     <tt>Mouse: FA&nbsp; Acknowledge</tt><br>
     <tt>Mouse: AA&nbsp; Self-test passed</tt><br>
     <tt>Mouse: 00&nbsp; Mouse ID</tt><br>
     <tt>Host:&nbsp; F3&nbsp; Set Sample Rate&nbsp;&nbsp; : Attempt to  Enter 
 Microsoft</tt><br>
     <tt>Mouse: FA&nbsp; Acknowledge&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 :  Scrolling Mouse mode</tt><br>
     <tt>Host:&nbsp; C8&nbsp; decimal 200&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
   :</tt><br>

     <tt>Mouse: FA&nbsp; Acknowledge&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 :</tt><br>
     <tt>Host:&nbsp; F3&nbsp; Set Sample Rate&nbsp;&nbsp; :</tt><br>

     <tt>Mouse: FA&nbsp; Acknowledge&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 :</tt><br>
     <tt>Host:&nbsp; 64&nbsp; decimal 100&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
   :</tt><br>

     <tt>Mouse: FA&nbsp; Acknowledge&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 :</tt><br>
     <tt>Host:&nbsp; F3&nbsp; Set Sample Rate&nbsp;&nbsp; :</tt><br>

     <tt>Mouse: FA&nbsp; Acknowledge&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 :</tt><br>
     <tt>Host:&nbsp; 50&nbsp; decimal 80&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
   :</tt><br>

     <tt>Mouse: FA&nbsp; Acknowledge&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 :</tt><br>
     <tt>Host:&nbsp; F2&nbsp; Read Device Type&nbsp; :</tt><br>

     <tt>Mouse: FA&nbsp; Acknowledge&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 :</tt><br>
     <tt>Mouse: 00&nbsp; Mouse ID&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
   : Response 03 if microsoft scrolling mouse</tt><br>
     <tt>Host:&nbsp; F3&nbsp; Set Sample Rate&nbsp;</tt><br>

     <tt>Mouse: FA&nbsp; Acknowledge</tt><br>
     <tt>Host:&nbsp; 0A&nbsp; decimal 10</tt><br>
     <tt>Mouse: FA&nbsp; Acknowledge</tt><br>

     <tt>Host:&nbsp; F2&nbsp; Read Device Type</tt><br>
     <tt>Mouse: FA&nbsp; Acknowledge</tt><br>
     <tt>Mouse: 00&nbsp; Mouse ID</tt><br>

     <tt>Host:&nbsp; E8&nbsp; Set resolution</tt><br>
     <tt>Mouse: FA&nbsp; Acknowledge</tt><br>
     <tt>Host:&nbsp; 03&nbsp; 8 Counts/mm</tt><br>

     <tt>Mouse: FA&nbsp; Acknowledge</tt><br>
     <tt>Host:&nbsp; E6&nbsp; Set Scaling 1:1</tt><br>
     <tt>Mouse: FA&nbsp; Acknowledge</tt><br>

     <tt>Host:&nbsp; F3&nbsp; Set Sample Rate</tt><br>
     <tt>Mouse: FA&nbsp; Acknowledge</tt><br>
     <tt>Host:&nbsp; 28&nbsp; decimal 40</tt><br>

     <tt>Mouse: FA&nbsp; Acknowledge</tt><br>
     <tt>Host:&nbsp; F4&nbsp; Enable</tt><br>
     <tt>Mouse: FA&nbsp; Acknowledge</tt><br>

     <tt>Initialization complete...</tt>         
  <p><tt>If I then press the Left Button...</tt> <br>
             <tt>Mouse: 09 1 1 00001001; bit0 = Left button state; bit3 = 
always   1</tt> <br>
             <tt>Mouse: 00 1 1 No X-movement</tt> <br>
             <tt>Mouse: 00 1 1 No Y-movement</tt> <br>

             <tt>... and release the Left Button:</tt> <br>
             <tt>Mouse: 08 0 1 00001000 bit0 = Left button state; bit3 =
always    1</tt> <br>
             <tt>Mouse: 00 1 1 No X-movement</tt> <br>
             <tt>Mouse: 00 1 1 No Y-movement</tt></p>
     
</ul>

      The following is the communication between my computer (running Win98SE)
   and mouse when it boots up with an (emulated) Intellimouse...&nbsp;  
               
<ul>
     <tt>Power-on Reset:</tt>
     <br>
     <tt>Mouse: AA&nbsp; Self-test passed</tt><br>
     <tt>Mouse: 00&nbsp; Mouse ID</tt><br>

     <tt>Host:&nbsp; FF&nbsp; Reset command</tt><br>
     <tt>Mouse: FA&nbsp; Acknowledge</tt><br>
     <tt>Mouse: AA&nbsp; Self-test passed</tt><br>

     <tt>Mouse: 00&nbsp; Mouse ID</tt><br>
     <tt>Host:&nbsp; FF&nbsp; Reset command</tt><br>
     <tt>Mouse: FA&nbsp; Acknowledge</tt><br>

     <tt>Mouse: AA&nbsp; Self-test passed</tt><br>
     <tt>Mouse: 00&nbsp; Mouse ID</tt><br>
     <tt>Host:&nbsp; FF&nbsp; Reset command</tt><br>

     <tt>Mouse: FA&nbsp; Acknowledge</tt><br>
     <tt>Mouse: AA&nbsp; Self-test passed</tt><br>
     <tt>Mouse: 00&nbsp; Mouse ID</tt><br>
     <tt>Host:&nbsp; F3&nbsp; Set Sample Rate&nbsp;&nbsp; : Attempt to  Enter 
 Microsoft&nbsp;</tt><br>

     <tt>Mouse: FA&nbsp; Acknowledge&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 :  Scrolling Mouse mode</tt><br>
     <tt>Host:&nbsp; C8&nbsp; decimal 200&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
   :</tt><br>

     <tt>Mouse: FA&nbsp; Acknowledge&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 :</tt><br>
     <tt>Host:&nbsp; F3&nbsp; Set Sample Rate&nbsp;&nbsp; :</tt><br>

     <tt>Mouse: FA&nbsp; Acknowledge&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 :</tt><br>
     <tt>Host:&nbsp; 64&nbsp; decimal 100&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
   :</tt><br>

     <tt>Mouse: FA&nbsp; Acknowledge&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 :</tt><br>
     <tt>Host:&nbsp; F3&nbsp; Set Sample Rate&nbsp;&nbsp; :</tt><br>

     <tt>Mouse: FA&nbsp; Acknowledge&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 :</tt><br>
     <tt>Host:&nbsp; 50&nbsp; decimal 80&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
   :</tt><br>

     <tt>Mouse: FA&nbsp; Acknowledge&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 :</tt><br>
     <tt>Host:&nbsp; F2&nbsp; Read Device Type&nbsp; :</tt><br>

     <tt>Mouse: FA&nbsp; Acknowledge&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 :</tt><br>
     <tt>Mouse: 03&nbsp; Mouse ID&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
   : Response 03 if microsoft scrolling mouse</tt><br>
     <tt>Host:&nbsp; E8&nbsp; Set Resolution&nbsp;</tt><br>

     <tt>Mouse: FA&nbsp; Acknowledge&nbsp;</tt><br>
     <tt>Host:&nbsp; 03&nbsp; 8 counts/mm</tt><br>
     <tt>Mouse: FA&nbsp; Acknowledge</tt><br>

     <tt>Host:&nbsp; E6&nbsp; Set scaling 1:1</tt><br>
     <tt>Dev:&nbsp;&nbsp; FA&nbsp; Acknowledge</tt><br>
     <tt>Host:&nbsp; F3&nbsp; Set Sample Rate&nbsp;</tt><br>

     <tt>Mouse: FA&nbsp; Acknowledge</tt><br>
     <tt>Host:&nbsp; 28&nbsp; decimal 40</tt><br>
     <tt>Mouse: FA&nbsp; Acknowledge</tt><br>

     <tt>Host:&nbsp; F4&nbsp; Enable device&nbsp;</tt><br>
     <tt>Mouse: FA&nbsp; Acknowledge</tt>         
  <p><tt>If I then press the left mouse button:</tt> <br>
             <tt>Mouse: 09&nbsp; 00001001 bit0 = Left button state; bit3
=  always   1</tt> <br>

             <tt>Mouse: 00&nbsp; No X-movement</tt> <br>
             <tt>Mouse: 00&nbsp; No Y-movement</tt> <br>
             <tt>Mouse: 00&nbsp; No Z-movement</tt> </p>

           
  <p><tt>...and then release the left mouse button button:</tt> <br>
             <tt>Mouse: 08&nbsp; 00001000 bit0 = Left button state; bit3
=  always   1</tt> <br>
             <tt>Mouse: 00&nbsp; No X-movement</tt> <br>
             <tt>Mouse: 00&nbsp; No Y-movement</tt> <br>

             <tt>Mouse: 00&nbsp; No Z-movement</tt></p>
     
</ul>
      <tt>After I downloaded/installed the Microsoft's Intellimouse drivers 
 with  support for the 4th and 5th buttons, the following sequence was found:</tt>
                   
<blockquote><tt>... (starts same as before) ...</tt> <br>
             <tt>Host:&nbsp; F3&nbsp; Set Sample Rate&nbsp;&nbsp; : Attempt 
 to  Enter Microsoft&nbsp;</tt> <br>

             <tt>Mouse: FA&nbsp; Acknowledge&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
   : Scrolling Mouse mode.</tt> <br>
             <tt>Host:&nbsp; C8&nbsp; decimal 200&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
   :</tt> <br>

             <tt>Mouse: FA&nbsp; Acknowledge&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
   :</tt> <br>
             <tt>Host:&nbsp; F3&nbsp; Set Sample Rate&nbsp;&nbsp; :</tt>

  <br>
             <tt>Mouse: FA&nbsp; Acknowledge&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
   :</tt> <br>
             <tt>Host:&nbsp; 64&nbsp; decimal 100&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;

   :</tt> <br>
             <tt>Mouse: FA&nbsp; Acknowledge&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
   :</tt> <br>
             <tt>Host:&nbsp; F3&nbsp; Set Sample Rate&nbsp;&nbsp; :</tt>

  <br>
             <tt>Mouse: FA&nbsp; Acknowledge&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
   :</tt> <br>
             <tt>Host:&nbsp; 50&nbsp; decimal 80&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;

   :</tt> <br>
             <tt>Mouse: FA&nbsp; Acknowledge&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
   :</tt> <br>
             <tt>Host:&nbsp; F2&nbsp; Read Device Type&nbsp; :</tt> <br>

             <tt>Mouse: FA&nbsp; Acknowledge&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
   :</tt> <br>
             <tt>Mouse: 03&nbsp; Mouse ID&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
   : Response 03 if microsoft scrolling mouse.</tt> <br>

             <tt>Host:&nbsp; F3&nbsp; Set Sample Rate&nbsp;&nbsp; : Attempt 
 to  Enter Microsoft 5-button&nbsp;</tt> <br>
             <tt>Mouse: FA&nbsp; Acknowledge&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
   : Scrolling Mouse mode.</tt> <br>

             <tt>Host:&nbsp; C8&nbsp; decimal 200&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
   :</tt> <br>
             <tt>Mouse: FA&nbsp; Acknowledge&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
   :</tt> <br>

             <tt>Host:&nbsp; F3&nbsp; Set Sample Rate&nbsp;&nbsp; :</tt>
  <br>
             <tt>Mouse: FA&nbsp; Acknowledge&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
   :</tt> <br>

             <tt>Host:&nbsp; C8&nbsp; decimal 200&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
   :</tt> <br>
             <tt>Mouse: FA&nbsp; Acknowledge&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
   :</tt> <br>

             <tt>Host:&nbsp; F3&nbsp; Set Sample Rate&nbsp;&nbsp; :</tt>
  <br>
             <tt>Mouse: FA&nbsp; Acknowledge&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
   :</tt> <br>

             <tt>Host:&nbsp; 50&nbsp; decimal 80&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
   :</tt> <br>
             <tt>Mouse: FA&nbsp; Acknowledge&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
   :</tt> <br>

             <tt>Host:&nbsp; F2&nbsp; Read Device Type&nbsp; :</tt> <br>
             <tt>Mouse: FA&nbsp; Acknowledge&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
   :</tt> <br>

             <tt>Mouse: 04&nbsp; Mouse ID&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
   : Response 04 if 5-button scrolling mouse.</tt> <br>
             <tt>... rest of initialization same as before ...</tt></blockquote>

</body>
</html>
