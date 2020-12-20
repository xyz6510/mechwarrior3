# mechwarrior3
mechwarrior 3 reticle stutter linux wine
<pre>
compile gcc lib.c -fPIC -shared -o lib.so -ldl
LD_PRELOAD="/path_to_lib_so/lib.so" wine mech3.exe
</pre>
