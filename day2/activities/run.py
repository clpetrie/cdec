import os
import platform

os.system('pdflatex day2_act.tex')
if platform.system() == 'Darwin':
   os.system('open day2_act.pdf')
if platform.system() == 'Linux':
   os.system('gnome-open day2_act.pdf')
os.system('rm *.bib *aux *key *log *nav *out *xml *snm *toc')
