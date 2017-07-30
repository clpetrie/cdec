import os
import platform

os.system('pdflatex day1_act.tex')
if platform.system() == 'Darwin':
   os.system('open day1_act.pdf')
if platform.system() == 'Linux':
   os.system('gnome-open day1_act.pdf')
os.system('rm *.bib *aux *key *log *nav *out *xml *snm *toc')
