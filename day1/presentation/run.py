import os
import platform

os.system('pdflatex day1.tex')
if platform.system() == 'Darwin':
   os.system('open day1.pdf')
if platform.system() == 'Linux':
   os.system('gnome-open day1.pdf')
os.system('rm *.bib *aux *key *log *nav *out *xml *snm *toc')
