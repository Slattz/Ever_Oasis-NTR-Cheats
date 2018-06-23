import sys
import shutil
import os
import datetime
USA_TID_LOW = 0x1A4800
FILE        = "Ever_Oasis-NTR-Cheats.plg"
def printf(string):
    print(datetime.datetime.strftime(datetime.datetime.now(), '%Y-%m-%d %H:%M:%S') + " : " + string);
if not os.path.exists("plugin"):
    for i in range(0, 2):
        os.makedirs("plugin/" + "0004000000" + str(format(USA_TID_LOW + (i * 0x100), 'X')))
printf("Copying files into each folder");
for i in range(0, 2):
    shutil.copy2(FILE, "plugin/" + "0004000000" + str(format(USA_TID_LOW + (i * 0x100), 'X') + "/" + FILE))
shutil.make_archive("E-Oasis-NTR-Cheats", 'zip', "./", "./plugin");
printf("Done!");
