Note: (Please open the .md file and do not view in git as it looks completely different)

.......................................................................................
Syntax for operations are shown below:

ADD
<type> <name>             // type can be file or directory

MOVE
<path>                    // root/dir1/dir2/.../

ALIAS
<name> <path>

TELEPORT
<alias>

FIND
<name>
.......................................................................................

Example:
Suppose you want to create a directory that has the following structure:

root					                                  ______ root ________
>Desktop								  /         |           \
 >Code								    Desktop     Pictures      Documents
>Pictures                                                            |        /     \
 >Beach                                                            Code    Beach   Travel
 >Travel									       /   \
  >France                                                                      France   Italy
   .Image1                                                                     /        /   \
  >Italy                                                                  Image1   Image1   Image2
   .Image1
   .Image2                                                                
>Documents                                                            

This is how the input would be given:

ADD
directory Desktop

ADD
directory Pictures

ADD
directory Documents

MOVE
root/Desktop/

ADD
directory Code

MOVE
root/Pictures/

ADD
directory Beach

ADD
directory Travel

MOVE
root/Pictures/Travel/

ADD
directory France

ADD
directory Italy

MOVE
root/Pictures/Travel/France/

ADD
file
Image1

MOVE
root/Pictures/Travel/Italy/

ADD
file Image1

ADD
file Image2

ALIAS
Pizza root/Pictures/Travel/Italy/                     //a test for correct alias

ALIAS
Pizza root/Pictures/Travel/France/                    //a test for already existing alias

ALIAS
Beer root/Pictures/Travel/Germany/                    //a test for invalid path

ALIAS
Ferrari root/Pictures/Travel/Italy/

TELEPORT                                              //a test for valid alias
Pizza

ADD
file Rome

TELEPORT                                              //a test for invalid alias
Pasta

TELEPORT
Ferrari

FIND
Imag
