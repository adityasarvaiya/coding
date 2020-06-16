from subprocess import call
import glob

files=glob.glob("tests/*-input-*.txt")
files.sort()
out=glob.glob("tests/*-output-*.txt")
out.sort()

code="./a.out"

for i in range(len(files)):
    print([code,files[i],out[i]])
    call([code,files[i],out[i]])