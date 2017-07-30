import os
import platform

os.system('pdflatex day5.tex')
if platform.system() == 'Darwin':
   os.system('open day5.pdf')
if platform.system() == 'Linux':
   os.system('gnome-open day5.pdf')
os.system('rm *.bib *aux *key *log *nav *out *xml *snm *toc')
