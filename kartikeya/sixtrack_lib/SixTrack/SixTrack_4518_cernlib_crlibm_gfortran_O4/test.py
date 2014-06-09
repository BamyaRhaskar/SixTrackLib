"""
 usage run python -pylab
 paste line by line at the prompt or type %rn test.py


General introduction:

- http://koen.me/research/teaching-asci/python-workshop-slides.pdf
- https://github.com/jrjohansson/scientific-python-lectures
- [A Crash Course in Python for Scientists](http://nbviewer.ipython.org/gist/rpmuller/5920182)

Introduction to python

- http://jacek.home.cern.ch/jacek/courses/python-intro/course.html


Introduction to Numpy (array library)


- http://wiki.scipy.org/Tentative_NumPy_Tutorial

Introduction to Matplotlib (plot library)


- http://matplotlib.org/1.3.1/users/pyplot_tutorial.html

List of tutorials


- http://datacommunitydc.org/blog/2013/07/python-for-data-analysis-the-landscape-of-tutorials/


"""



from numpy import *
from matplotlib.pyplot import *


from read_fortbin import *



head,part=read_allfortbin(basedir='.')
head1,part1=read_allfortbin(basedir='../../../sixtrack_legacy/SixTrack')

figure()
subplot (211)
for pn in range(1,31):
	subplot (211)
	pdist,x,xp,y,yp,sigma,delta,energy=part[pn].T
	pdist,x1,xp1,y1,yp1,sigma1,delta1,energy1=part1[pn].T
	plot(x-x1,xp-xp1,'.',label='part %d'%pn)

	xlabel('x [mm]')
	ylabel('xp [rad]')

	subplot(212)
	plot (y-y1,yp-yp1,'.',label='part %d' %pn)

	xlabel('y [mm]')
	ylabel('yp [rad]')

savefig.png
