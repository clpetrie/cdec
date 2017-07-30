import os
import platform

os.system('pdflatex day3.tex')
if platform.system() == 'Darwin':
   os.system('open day3.pdf')
if platform.system() == 'Linux':
   os.system('gnome-open day3.pdf')
os.system('rm *.bib *aux *key *log *nav *out *xml *snm *toc')
