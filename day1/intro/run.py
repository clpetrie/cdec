import os
import platform

os.system('pdflatex intro.tex')
if platform.system() == 'Darwin':
   os.system('open intro.pdf')
if platform.system() == 'Linux':
   os.system('gnome-open intro.pdf')
os.system('rm *.bib *aux *key *log *nav *out *xml *snm *toc')
